#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BNode* BNodePtr;

struct BNode{
    int order;          // max number of children
    int size;           /* number of children = number of keys + 1 */
    BNodePtr *child;    /* children pointers [BNodePtr's array]*/ 
    int *key;           /* keys */
    int is_leaf;        /* if is_leaf , size means only the number of keys + 1 */
}BNode;

BNodePtr CreateTree(int order);

void Insert(BNodePtr* root, int key);
BNodePtr Insert_sub(BNodePtr parent, BNodePtr node, int key, int pos);
BNodePtr split_node(BNodePtr parent, BNodePtr node, int pos);
BNodePtr Createnode(int order);

int Find(BNodePtr root, int key);

void PrintTree(BNodePtr root);

void DeleteTree(BNodePtr root);
void free_node(BNodePtr node);
// my func
int FindPosInIdx(int* key, int key_size, int target);
void insertInArr(int* arr, int current_size, int pos, int target);


int main(int argc, char* argv[]){
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");

    int order;
    fscanf(fin, "%d", &order);
    BNodePtr root = CreateTree(order);

    char cv;
    int key;
    while(!feof(fin)){
        fscanf(fin, "%c", &cv);
        if(feof(fin))
			break;
        switch(cv){
            case 'i':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "insert error : key %d is already in the tree!\n", key);
                else
                    Insert(&root, key);
                break;
            case 'f':
                fscanf(fin, "%d", &key);
                if(Find(root, key))
                    fprintf(fout, "key %d found\n", key);
                else
                    fprintf(fout, "finding error : key %d is not in the tree!\n", key);
                break;
            case 'p':
                if (root->size == 1)
                    fprintf(fout, "print error : tree is empty!");
                else
                    PrintTree(root);
                fprintf(fout, "\n");
                break;
        }
    }
   
    DeleteTree(root);
    fclose(fin);
    fclose(fout);

    return 0;
}

/* 새로운 트리를 생성하는 함수 */
BNodePtr CreateTree(int order)
{
    BNodePtr new_tree = malloc(sizeof(BNode));
    new_tree->order = order;;
    new_tree->size = 1;
    new_tree->child = malloc(sizeof(BNodePtr) * (order+1)); // There's tail spare space for splitting
    new_tree->key = malloc(sizeof(int) * (order)); // max num of keys = order -1, but to easily split, take one more spare space
    new_tree->is_leaf = 1; 

    for (int i=0; i<order+1; i++)
        new_tree->child[i] = NULL;

    return new_tree;
}

/* insert key */
void Insert(BNodePtr* root, int key){ // 루트를 함수 내에서 변경시키기 위해 이중 포인터로 선언
    // root -> 이중 포인터, root 를 가리키는 root
    *root = Insert_sub(*root, *root, key, 0); // 리턴값이 있는 재귀함수 활용, 처음에 root 노드는 현재 노드이자 parent이므로 같이 parent, node 똑같이 매개변수 전달
    /* DEBUGGING TRACE
    BNodePtr tmp = *root;
    printf("ROOT KEY : ");
    for (int i=0; i<tmp->size-1; i++) {
        printf("%d ", tmp->key[i]);
    }
    printf("\n");
    printf("ROOT CHILD KEY: ");
    for (int i=0; i<tmp->size; i++) {
        if (tmp->child[i] != NULL)
            printf("%d ", tmp->child[i]->key[0]);
    }
    printf("\n");
    printf("=======Insert(%d) done========\n", key);
    printf("ROOT->SIZE : %d\n", tmp->size);
    printf("\n");
    printf("\n");
    */
}


BNodePtr Insert_sub(BNodePtr parent, BNodePtr node, int key, int p_pos)
{
    if (node->size == 1) { // If root is empty
        node->key[0] = key;
        node->size++;
        node->is_leaf = 1;
        return parent;
    }
    // Insert는 항상 leaf에서 이루어져야 함.
    /* pos : key 배열에 들어갈 "예정" 위치 (p-down할 child idx랑도 같음) */
    int pos = FindPosInIdx(node->key, node->size-1, key);

    if (!node->is_leaf) {
        // leaf node가 아니면 p-down 해야하므로, p-down child 위치로 재귀호출
        node->child[pos] = Insert_sub(node, node->child[pos], key, pos);
    }
    else {
        // Leaf Node에서 insert
        insertInArr(node->key, node->size-1, pos, key);
        node->size++;
    }
    
    if (node->size > node->order) { // If key_arr: FULL ( num of key == order )
        // 중앙값 찾아서 parent에 insert
        int median = node->key[(node->order-1)/2];

        // Split
        BNodePtr splitted_1 = split_node(parent, node, (node->order-1)/2);

        // Root 인 경우 구분해줘야 함
        if (node == parent) {
            BNodePtr new_root = Createnode(node->order);
            new_root->is_leaf = 0;
            new_root->key[0] = median;
            new_root->size = 2;

            new_root->child[0] = node;
            new_root->child[1] = splitted_1;
            return new_root;
        }
        else {
            insertInArr(parent->key, parent->size-1, p_pos, median);
            

            // parent - child control
            for (int i=parent->size-1; i>=p_pos+1; i--) {
                parent->child[i+1] = parent->child[i];
            }
            parent->size++;
            parent->child[p_pos+1] = splitted_1;
        }
        
    }

    return node; // 값만 수정한 자기 자신을 return 하게끔
}

/* CHECK: Split이 어느 시점에서 호출하는지가 관건*/
BNodePtr split_node(BNodePtr parent, BNodePtr node, int pos)
{
    // pos 는 Split-Axis
    // 기존 node 는 포인터로 수정만 해주고, 동시에 쪼개진 새로운 node 반환
    // 계산 편의를 위해, 왼쪽을 기존으로, 오른쪽을 new_node로 리턴
   
    BNodePtr new_node = Createnode(node->order);
    
    // split된 node의 is_leaf는 기존 node를 따라감
    new_node->is_leaf = node->is_leaf;
        
    new_node->size = node->size - pos - 1;

    for (int i=0; i<node->size-1; i++) {
        new_node->key[i] = node->key[pos+1+i];
    }
    
    if (!new_node->is_leaf) { // Child control
        for (int i=0; i<new_node->size; i++) {
            new_node->child[i] = node->child[pos+1+i];
        }
    }

    // 기존 node 수정
    node->size = pos + 1;
    // size로 access control 하므로 key, child 를 여기서 수정시킬 필요는 없음.

    return new_node;
}

/* 노드 하나를 동적할당하는 함수, size, is_leaf는 노드마다 다르므로 초기화하지 않고 공통되는 부분만 초기화 */
BNodePtr Createnode(int order)
{
    BNodePtr new_node = malloc(sizeof(BNode));
    new_node->order = order;
    new_node->child = malloc(sizeof(BNodePtr) * (order+1));
    new_node->key = malloc(sizeof(int) * (order));

    for (int i=0; i<order+1; i++)
        new_node->child[i] = NULL;
    return new_node; 
}

/* find node that has key */
int Find(BNodePtr root, int key)
{
    // First find in its key array and also check case to go down
    if (root == NULL)
        return 0;
    int child_arr_idx = 0; 
    
    for (int i=0; i<root->size-1; i++) {
        if (key < root->key[i])
            break;
        else if (key == root->key[i])
            return 1;
        else if (key > root->key[i])
            child_arr_idx++;
    }

    if (root->is_leaf)
        return 0;
    // If it is not in current key array, go down
    return Find(root->child[child_arr_idx], key);
}

/* print Tree, inorder traversal */
void PrintTree(BNodePtr root)
{
    if (root == NULL) return;
    if (!root->is_leaf) {
        for (int i=0; i<root->size; i++) {
            PrintTree(root->child[i]);
            if (i<root->size-1)
                fprintf(fout, "%d ", root->key[i]);
        }
    }
    else {
        for (int i=0; i<root->size-1; i++) {
            fprintf(fout, "%d ", root->key[i]);
        }
    }
}

/* depth first search -> free memory */
void DeleteTree(BNodePtr root){
    if (root == NULL) return;
    if (!root->is_leaf) {
        for (int i=0; i<root->size; i++) {
            if (root->child[i] != NULL) {
                DeleteTree(root->child[i]);
            }
        }
    }
    free_node(root);
}

/* 노드의 메모리를 해제해주는 helper function */
void free_node(BNodePtr node){
    free(node->child);
    free(node->key);
    free(node);
}

// My func impl
int FindPosInIdx(int* key, int arr_size, int target)
{
    for (int i=0; i<arr_size; i++) {
        if (target < key[i]) {
            return i;
        }
    }
    // Case of biggest among key values
    return arr_size;
}

void insertInArr(int* arr, int current_size, int pos, int target)
{
    for (int i=current_size-1; i > pos-1; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = target;
}