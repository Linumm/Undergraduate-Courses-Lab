#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef int ElementType;

typedef struct AVLNode{
	ElementType element;
	AVLTree left, right;
	int height; // L and R subtree 노드 개수 중 max 
}AVLNode;

AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);
Position SingleRotateWithLeft(Position node);
Position SingleRotateWithRight(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
void PrintInorder(AVLTree T);
void DeleteTree(AVLTree T);

//Additional needed func
int FindNode(AVLTree T, ElementType target);
AVLTree InsertImpl(ElementType X, AVLTree T);
AVLTree DeleteImpl(ElementType X, AVLTree T);
int GetHeight(Position node);
int GetBalanceFactor(Position node); //Get Balance Factor difference
Position Rebalancing(Position node);
int getMax(int a, int b) { return a >= b ? a : b; }


int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	AVLTree Tree = NULL;
	char cv;
	int target;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		switch(cv){
			case 'i':
				fscanf(fin, "%d\n", &target);
				Tree = Insert(target, Tree);
				break;
			case 'd':
				fscanf(fin, "%d\n", &target);
				Tree = Delete(target, Tree);
				break;
		}
		PrintInorder(Tree);
		fprintf(fout, "\n");
	}
	DeleteTree(Tree);
	fclose(fin);
	fclose(fout);

	return 0;
}

AVLTree Insert(ElementType X, AVLTree T)
{
    // Separate the insert process to call recursively
    if (FindNode(T, X)) { // Duplication check
        fprintf(fout, "insertion error : %d is already in the tree!\n", X);
        return T; // No change
    }

    return InsertImpl(X, T);
}

AVLTree Delete(ElementType X, AVLTree T)
{
    // Separate the delete process to call recursively
    if (!FindNode(T, X)) { // Lookup
        fprintf(fout, "deletion error : %d is not in the tree!\n", X);
        return T; // No change
    }
    return DeleteImpl(X, T);
}

void PrintInorder(AVLTree T) {
    if (!T) return;
    PrintInorder(T->left);
    fprintf(fout, "%d(%d) ", T->element, T->height);
    PrintInorder(T->right);
}

void DeleteTree(AVLTree T) { // By Inorder traversal
    if (!T) return;
    DeleteTree(T->left);
    DeleteTree(T->right);
    free(T);
}


int FindNode(AVLTree T, ElementType target)
{
    if (!T) return 0;
    else {
        if (T->element == target) return 1;
        else if (T->element > target) // Case : left subtree
            FindNode(T->left, target);
        else if (T->element < target) // Case : right subtree
            FindNode(T->right, target);
    }
}

AVLTree InsertImpl(ElementType X, AVLTree T)
{
    if (T == NULL) { // When tree is empty or arrived to leaf
        AVLTree new_node = malloc(sizeof(AVLNode));
        new_node->element = X;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 0; // No any subtree

        return new_node;
    }

    if (X > T->element)
        T->right = InsertImpl(X, T->right);
    else if (X < T->element)
        T->left = InsertImpl(X, T->left);
    
    // Height modification [the reason I use function is to block the null pointer acessing case]
    T->height = GetHeight(T);
    // Rebalancing tree
    T = Rebalancing(T);
    return T;
}

AVLTree DeleteImpl(ElementType X, AVLTree T) //BUG POINT
{
    // Since the existence is proved by FindNode()
    if (T == NULL) return NULL;
    if (T->element == X) { // Similar process with BST
        if (!T->left && !T->right) { // Case 1: No child
            free(T);
            return NULL;
        }
        else if (!T->left && T->right) { // Case 2: only right child
            AVLTree tmp = T->right;
            free(T);
            return tmp;
        }
        else if (T->left && !T->right) { // Case 3: only left child
            AVLTree tmp = T->left;
            free(T);
            return tmp;
        }

        // Case 4: both child ->find successor first
        AVLTree successor = T->right; // Since this is the case both child exists, do not check NULL
        while (successor && successor->left)
            successor = successor->left;
        
        T->element = successor->element;
        T->right = DeleteImpl(successor->element, T->right);
    }

    if (X > T->element)
        T->right = DeleteImpl(X, T->right);
    else if (X < T->element)
        T->left = DeleteImpl(X, T->left);

    // Height modification
    T->height = GetHeight(T);
    // Rebalancing
    T = Rebalancing(T);

    return T;
}

int GetHeight(Position node)
{
    if (node == NULL) return -1;

    if (node->left != NULL && node->right != NULL)
        return getMax(node->left->height, node->right->height) + 1;
    else if (node->left == NULL && node->right != NULL)
        return node->right->height + 1;
    else if (node->left != NULL && node->right == NULL)
        return node->left->height + 1;
    else
        return 0;
}

int GetBalanceFactor(Position node) // Return delta bf
{
    // Recursive expression can be pretty and even pass nullptr case, but I assume it will take longer time.
    // <CAUTION> divide nullptr access case
    int left_height, right_height;
    if (node->left == NULL)
        left_height = -1;
    else
        left_height = node->left->height;
    if (node->right == NULL)
        right_height = -1;
    else
        right_height = node->right->height;

    return left_height - right_height;
}

Position Rebalancing(Position node)
{
    int balance_factor = GetBalanceFactor(node);
    int child_bf;

    //4 Cases
    if (balance_factor >= 2) { // Case: Left subtree is deeper
        child_bf = GetBalanceFactor(node->left);
        if (child_bf > -1) // (R)
            return SingleRotateWithLeft(node);
        else if (child_bf <= -1) // (LR)
            return DoubleRotateWithLeft(node);
    }
    else if (balance_factor <= -2) { // Case: Right subtree is deeper
        child_bf = GetBalanceFactor(node->right);
        if (child_bf >= 1) // (RL)
            return DoubleRotateWithRight(node);
        else if (child_bf < 1) // (L)
            return SingleRotateWithRight(node);
    }
    else if (balance_factor >= -1 && balance_factor <= 1)
    //No any change
        return node;
}



// Rotation functions
Position SingleRotateWithLeft(Position node) // "Clockwise(R) rotation"
{
    Position new_axis = node->left;
    if (new_axis->right != NULL)
        node->left = new_axis->right;
    else
        node->left = NULL;
    new_axis->right = node;
    
    // Height modification
    node->height = GetHeight(node);
    new_axis->height = GetHeight(new_axis);

    return new_axis;
}

Position SingleRotateWithRight(Position node) // "Counterclockwise(L) rotation"
{
    Position new_axis = node->right;
    if (new_axis->left !=NULL)
        node->right = new_axis->left;
    else
        node->right = NULL;
    new_axis->left = node;

    // Height modification
    node->height = GetHeight(node);
    new_axis->height = GetHeight(new_axis);

    return new_axis;
}

Position DoubleRotateWithLeft(Position node) // Let this "LR rotation"
{
    node->left = SingleRotateWithRight(node->left);
    return SingleRotateWithLeft(node);
}

Position DoubleRotateWithRight(Position node) // Let this "RL rotation"
{
    node->right = SingleRotateWithLeft(node->right);
    return SingleRotateWithRight(node);
}
