#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

#define FROMPARENT 0
#define FROMTHREAD 1

typedef struct ThreadedTree* ThreadedPtr;
typedef int ElementType;

struct ThreadedTree {
	int left_thread; // flag if ptr is thread : If leftChild exist, thread=false
	ThreadedPtr left_child;
	ElementType data;
	ThreadedPtr right_child;
	int right_thread; // flag if ptr is thread
}ThreadedTree;

ThreadedPtr CreateTree(){
	ThreadedPtr tree = NULL;
	tree = (ThreadedPtr)malloc(sizeof(ThreadedTree));
	if(tree==NULL){
		fprintf(fout, "Out of Space!\n");
		return NULL;
	}
	tree->data = -1; //Root's data == -1
	tree->left_thread = 1;
	tree->left_child = tree;
	tree->right_thread = 1;
	tree->right_child = tree;
	return tree;
}

int Insert(ThreadedPtr root, int root_idx, ElementType data, int idx){
	ThreadedPtr new_node = malloc(sizeof(ThreadedTree));
	new_node->data = data;
	new_node->left_thread = 1;
	new_node->right_thread = 1;
	new_node->left_child = NULL;
	new_node->right_child = NULL;

	if (new_node == NULL) return 0;

	ThreadedPtr node = root;
	int idx_copy = idx;
	short* reversed_way = malloc(sizeof(short) * idx); //left : 0 , right : 1
	while (idx != 0){
		reversed_way[root_idx] = idx % 2;
		idx = (int)(idx/2);
		root_idx++;
	} // root_idx : length of way;

	/*  Little algorithm to find in-order successor or predecessor
	    If the last is right, the nearest left-way point before the last is successor 
		if the last is left, the nearest right-way point before the right is predecessor
	*/
// 꺾이는 지점이란 소리임. 이 for문 전에 reversed_way에서 추출하는 알고리즘 생각하기!
	int last_way = reversed_way[0];
	int suc_or_pre = -1; // The Point that is successor or predecessor.
	ThreadedPtr point = NULL; //                  "	
	for (int i = 1; i<root_idx; i++) 
		if (reversed_way[i] != last_way) {
			suc_or_pre = i;
			break; // To find the closest one.
		}
	

	for (int i = root_idx-1; i>0; i--) { //Until the direct parent node
		if (i == suc_or_pre) point = node;
		if (reversed_way[i] == 0) node = node->left_child;
		else if (reversed_way[i] == 1) node = node->right_child;
	}
	

	if (last_way == 0) { // Case of left
		node->left_child = new_node;
		node->left_thread = 0;
		//Thread making
		new_node->left_child = point; // Inorder predecessor
		new_node->right_child = node; // Inorder successor 
	}
	else if (last_way == 1) { // Case of right
		node->right_child = new_node;
		node->right_thread = 0;
		//Thread making
		new_node->left_child = node; // Inorder predecessor
		if (suc_or_pre == -1) new_node->right_child = root; // Case of the most right point.
		else new_node->right_child = point; // Inorder successor
	}

	free(reversed_way);
	return 1;
	
}

void printInorder(ThreadedPtr root){
	fprintf(fout, "inorder traversal : ");
    ThreadedPtr node = root;
	ElementType stack[50]; // Since the max num of node is 100. 
	int top = -1; // It's the index of top of stack. 
	int copy_val;

	
	while (node->right_child != root) {
		node = node->right_child;
		if (node->data != stack[top]) {
			while(node->left_thread != 1) {
				stack[++top] = node->data;
				//<>printf("(%d) pushed into Stack, Top(%d)\n", stack[top], top);
				node = node->left_child;
			}
			stack[++top] = node->data; // upper while loop does not push the last node.
			//<>printf("(%d) pushed into Stack, Top(%d)\n", stack[top], top);
		}
		copy_val = stack[top];
		stack[top] = -1;
		top--;
		//<>printf("[%d] popped, Top(%d)\n", copy_val, top);
		fprintf(fout, "%d", copy_val);
		if (node->right_child != root) fprintf(fout, " ");

	}
	
	/* 1) right_child 로 이동
	   2) if current node is top of stack -> pop and print, (3) skip
	      else -> 최좌측으로 이동하면서 push every node to stack.
	   3) Top of stack을 pop and print.
    */
    
}

void DeleteTree(ThreadedPtr root){
	ThreadedPtr node = root;
	ThreadedPtr tmp = root->right_child;
	ElementType stack[50];
	int top = -1; // It's the index of top of stack. 

	
	while (tmp != root) {
		node = tmp;
		if (node->data != stack[top]) {
			while(node->left_thread!= 1) {
				stack[++top] = node->data;
				node = node->left_child;
			}
			stack[++top] = node->data; // upper while loop does not push the last node.
		}
		stack[top] = -1;
		top--;
		tmp = node->right_child;
		free(node);
	}
	
	free(root);
}

int main(int argc, char *argv[]){
	fin=fopen(argv[1], "r");
	fout=fopen(argv[2], "w");

	ThreadedPtr root = CreateTree();

	int NUM_NODES;
	fscanf(fin, "%d", &NUM_NODES);

	int root_idx=0, idx=0;

	while(++idx <= NUM_NODES){
		ElementType data;
		fscanf(fin, "%d", &data);
		
		if(Insert(root, root_idx, data, idx) == 0){
			return 0;
		}
	}

	printInorder(root);
	DeleteTree(root);
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}
