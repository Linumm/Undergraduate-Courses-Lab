#include <stdio.h>
#include <stdlib.h>

FILE *fin;
FILE *fout;

typedef struct Node *PtrToNode; //Node's pointer type : PtrToNode 
typedef PtrToNode List; 
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
	ElementType element;
	Position next;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void Insert(ElementType X, List L, Position P);
void PrintList(List L);
void Delete(ElementType X, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void DeleteList(List L);


int main(int argc, char **argv)
{
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	char x;

	Position header = NULL, tmp = NULL;
	header = MakeEmpty(header);


	while (fscanf(fin, "%c", &x) != EOF)
	{
		if (x == 'i')
		{
			int a, b;
			fscanf(fin, "%d %d", &a, &b); //duplication check
			tmp = Find(a, header);
			if (tmp != NULL)
			{
				fprintf(fout, "instertion(%d) failed : the key already exists in the list\n", a);
				continue;
			}
			tmp = Find(b, header);
			if (tmp == NULL)
			{
				fprintf(fout, "insertion(%d) failed : can not find the location to be inserted\n", a);
				continue;
			}

			Insert(a, header, tmp);
		}

		else if (x == 'd')
		{
			int a;
			fscanf(fin, "%d", &a);
			Delete(a, header);
		}

		else if (x == 'f')
		{
			int a;
			fscanf(fin, "%d", &a);
			tmp = FindPrevious(a, header);
			if (IsLast(tmp, header))
				fprintf(fout, "finding(%d) failed : element %d is not in the list\n", a, a);
			else
			{
				if (tmp->element > 0)
					fprintf(fout, "key of the previous node of %d is %d\n", a, tmp->element);
				else
					fprintf(fout, "key of the previous node of %d is head\n", a);
			}
		}

		else if (x == 'p') PrintList(header);
	}
	DeleteList(header);
	fclose(fin);
	fclose(fout);

	return 0;
}


List MakeEmpty(List L)
{
	//Create a head node of List L with element -1
	L = malloc(sizeof(struct Node));
	L->element = -1;
	L->next = NULL;
	return L;
}


int IsEmpty(List L)
{
	// if the next node of head node of L is empty, return 1. if not, return 0
	if (L->next == NULL) return 1;
	else return 0;
}


int IsLast(Position P, List L)
{
	Position temp = L;
	while (1)
	{
		if (temp->next == NULL) break;
		else
		{
			temp = temp->next;
		}
	}
	//make 'temp' as a last node and compare it with P.
	if (P == temp) return 1;
	else return 0;
}


void Insert(ElementType X, List L, Position P)
{// Since there're exception catching in main func, we don't need exception
	Position newNode = (struct Node*)malloc(sizeof(struct Node)); //Create a new node
	newNode->element = X; //save data and link to next node of P
	newNode->next = P->next; 
	
	P->next = newNode; //Link P to new node
}


void PrintList(List L)
{
	if (L->next == NULL) // If list is empty
	{
		fprintf(fout, "empty list!\n");
		return;
	}

	Position temp = L->next;
	while (1)
	{
		if (temp->next == NULL)
		{
			break; //There's no print output in tail node.
		}
		else
		{
			fprintf(fout, "key: %d ", temp->element);
			temp = temp->next;
		}
	}
	// Since it escaped at tail node without printing in loop, add output of tail node
	fprintf(fout, "key: %d\n", temp->element);
}


void Delete(ElementType X, List L)
{
	//Find the position of X first, and delete. After delete, if it is not last node, find pvnode and link pvnode.next to nextnode.
	Position temp = Find(X, L);
	if (temp == NULL)
	{
		fprintf(fout, "deletion(%d) failed : element %d is not in the list\n", X, X);
		return;
	}

	Position temp_prev = FindPrevious(X, L); //To make previous node's link change
	if (IsLast(temp, L))
	{
		temp_prev->next = NULL;
		free(temp);
	}
	else
	{
		//find previous node's next and link it to next of temp Node.
		Position temp_prev = FindPrevious(X, L);
		temp_prev->next = temp->next; 
		free(temp);
	}
}


Position Find(ElementType X, List L)
{
	Position temp = L;
	while (1)
	{
		if (temp->element == X) return temp;
		else
		{
			if (temp->next == NULL) break; // The case of head node.
			else
			temp = temp->next;
		}
	}
	return NULL;
}


Position FindPrevious(ElementType X, List L)
{
	Position temp = L;
	while (1)
	{
		if (temp->next == NULL) break; // casse of head or tail
		if ((temp->next)->element == X) break;
		else
			temp = temp->next;
	}
	return temp;
}


void DeleteList(List L)
{	
	if (IsEmpty(L)) //If there exists only a head node.
	{
		free(L);
		return;
	}

	//We will clear memory from head to tail. 
	Position temp = L;
	Position temp2 = NULL;
	while (temp->next !=NULL) //it does not clear memory of tail node.
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(temp); // Clear the tail node.
}
