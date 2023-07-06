#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

typedef struct BST* Tree;
typedef struct BST{
	int value;
	struct BST* left;
	struct BST* right;
}BST;

Tree insertNode(Tree root, int key);
Tree deleteNode(Tree root, int key);
int findNode(Tree root, int key);
void printInorder(Tree root);
void deleteTree(Tree root);

void main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	char cv;
	int key;

	Tree root = NULL;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
        if (feof(fin))
            break;
		switch(cv){
			case 'i':
				fscanf(fin, "%d", &key);
				root = insertNode(root, key);
				break;
			case 'f':
				fscanf(fin,"%d",&key);
				if(findNode(root, key))
					fprintf(fout, "%d is in the tree\n", key);
				else
					fprintf(fout, "finding error: %d is not in the tree\n", key);
				break;
			case 'd':
				fscanf(fin, "%d", &key);
				if(findNode(root, key)){
					root = deleteNode(root, key);
					fprintf(fout, "delete %d\n", key);
				}
				else{
					fprintf(fout, "deletion error: %d is not in the tree\n", key);
				}
				break;
			case 'p':
				fscanf(fin, "%c", &cv);
				if(cv == 'i'){
					if(root == NULL)
						fprintf(fout, "tree is empty");
					else
						printInorder(root);
				}
				fprintf(fout, "\n");
				break;
		}
	}
	deleteTree(root);
}


//Function implement
Tree insertNode(Tree root, int key) { 

    if (findNode(root, key)) { // Duplication check
        fprintf(fout, "insertion error: %d is already in the tree\n", key);
        return root; // No change
    }
    
    Tree new_node = malloc(sizeof(BST));
    new_node->value = key;
    new_node->left = NULL;
    new_node->right = NULL;

    if(!root)// Case of empty tree
        return new_node;

    Tree tmp = root;
    // Search the position to be inserted and then if the l/r child is empty, insert.
    while (1) {
        if (tmp->value > key) { // Case : left subtree
            if (!tmp->left) {
                tmp->left = new_node;
                fprintf(fout, "insert %d\n", key);
                break;
            }
            else
                tmp = tmp->left;
        }
        else if (tmp->value < key) { // Case : right subtree
            if (!tmp->right) {
                tmp->right = new_node;
                fprintf(fout, "insert %d\n", key);
                break;
            }
            else
                tmp = tmp->right;
        }
    }
    tmp = root;
    return tmp;
    
}

Tree deleteNode(Tree root, int key) { //Recursive form 
    // In process of delete, the Non-existing element is already checked in main()
    if (!root) return NULL;

    if (root->value > key) //left subtree
        root->left = deleteNode(root->left, key);
    else if (root->value < key) //right subtree
        root->right = deleteNode(root->right, key);
    
    else { // Now root : target 
        if (!root->left && !root->right) { // Case 1: No child
            free(root);
            return NULL;
        }
        else if (!root->left && root->right) { // Case 2: only right child
            Tree tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->left && !root->right) { // Case 3: only left child
            Tree tmp = root->left;
            free(root);
            return tmp;
        }

        // Case 4: both child ->find successor first
        Tree successor = root->right; // Since this is the case both child exists, do not check NULL
        while (successor && successor->left)
            successor = successor->left;
        
        root->value = successor->value;
        root->right = deleteNode(root->right, successor->value);
    }

    return root;
}

int findNode(Tree root, int key) {
    if (!root) return 0;
    else {
        if (root->value == key) return 1;
        else if (root->value > key) // Case : left subtree
            findNode(root->left, key);
        else if (root->value < key) // Case : right subtree
            findNode(root->right, key);
    }
}

void printInorder(Tree root) {
    if (!root) return;
    printInorder(root->left);
    fprintf(fout, "%d ", root->value);
    printInorder(root->right);
}

void deleteTree(Tree root) { // By Inorder traversal
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}