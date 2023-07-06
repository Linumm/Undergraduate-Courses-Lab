#include<stdio.h>
#include<stdlib.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct HeapStruct{
	int Capacity;
	int Size;
	int *Elements; // array
}Heap;

Heap* CreateHeap(int heapSize);
void Insert(Heap *heap, int value);
int Find(Heap *heap, int value);
int DeleteMax(Heap* heap);
void PrintHeap(Heap* heap);
int IsFull(Heap *heap);

int main(int argc, char* argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	char cv;
	Heap* maxHeap;
	int heapSize, key, max_element;

	while(!feof(fin)){
		fscanf(fin, "%c", &cv);
		if(feof(fin))
			break;
		switch(cv){
			case 'n':
				fscanf(fin, "%d", &heapSize);
				maxHeap = CreateHeap(heapSize);
				break;
			case 'i':
				fscanf(fin, "%d", &key);
				Insert(maxHeap, key);
				break;
			case 'd':
				max_element = DeleteMax(maxHeap);
				if(max_element != -INF){
					fprintf(fout, "max element : %d deleted\n", max_element);
				}
				break;
			case 'p':
				PrintHeap(maxHeap);
				break;
			case 'f':
				fscanf(fin, "%d", &key);
				if(Find(maxHeap, key)) fprintf(fout, "%d is in the heap\n", key);
				else fprintf(fout, "finding error : %d is not in the heap\n", key);
				break;
		}
	}

	return 0;
}

Heap* CreateHeap(int heapSize){
	/* create a new heap */
	Heap* new_heap = malloc(sizeof(Heap));

	new_heap->Capacity = heapSize;
	new_heap->Elements = malloc(sizeof(heapSize));
	new_heap->Size = 0;

	return new_heap;
}

void Insert(Heap *heap, int value){
	/* insert a value into the heap */
	/* 
		if heap is full, print out error message
		if IsFind is true, print out error message

	*/
	// First, check whether heap is full or not
	if (IsFull(heap)) {
		fprintf(fout, "insert error : heap is full\n");
		return;
	}
	// Second, check whether the value is already in heap
	if (Find(heap, value)) {
		fprintf(fout, "insert error : %d is already in the heap\n", value);
		return;
	}
	// Now insert the input value to the end of array
	heap->Elements[heap->Size] = value;
	int tmp_idx = heap->Size; // Last element index
	int tmp_for_swap;
	// Percolate up
	while (1) {
		if (tmp_idx == 0)
			break;
		if (heap->Elements[(tmp_idx-1)/2] < heap->Elements[tmp_idx]) {
			// Swap
			tmp_for_swap = heap->Elements[tmp_idx];
			heap->Elements[tmp_idx] = heap->Elements[(tmp_idx-1)/2];
			heap->Elements[(tmp_idx-1)/2] = tmp_for_swap;

			tmp_idx = (tmp_idx-1)/2; // Chase the inserted value
		}
		else
			break;
	}
	heap->Size++;
	fprintf(fout, "insert %d\n", value);
}

int Find(Heap* heap, int value){
	/* find a value in the heap */
	for (int i=0; i<heap->Capacity; i++) {
		if (value == heap->Elements[i])
			return 1;
	}
	return 0;
}

int DeleteMax(Heap* heap){
	/* delete Max value from the heap */
	if (heap->Size == 0) {
		fprintf(fout, "delete error : heap is empty\n");
		return -INF;
	}

	// I choose the way that pull the last element to the top and percolate down
	int max_val = heap->Elements[0];
	heap->Elements[0] = heap->Elements[heap->Size-1];
	int tmp_idx = 0;
	int tmp_for_swap;

	while (1) {
		if (tmp_idx * 2 + 1 >= heap->Capacity)
			break;
		if (heap->Elements[tmp_idx*2+1] > heap->Elements[tmp_idx]) {
				tmp_for_swap = heap->Elements[tmp_idx];
			if (heap->Elements[tmp_idx*2+1] > heap->Elements[tmp_idx*2+2]) {
				heap->Elements[tmp_idx] = heap->Elements[tmp_idx*2+1];
				heap->Elements[tmp_idx*2+1] = tmp_for_swap;

				tmp_idx = tmp_idx*2+1;
			}
			else if (heap->Elements[tmp_idx*2+1] < heap->Elements[tmp_idx*2+2]) {
				heap->Elements[tmp_idx] = heap->Elements[tmp_idx*2+2];
				heap->Elements[tmp_idx] = tmp_for_swap;

				tmp_idx = tmp_idx*2+2;
			}
		}
		else
			break;
	}
	heap->Size--;
	return max_val;
}

void PrintHeap(Heap* heap){
	/* print the heap */
	if (heap->Size == 0) {
		fprintf(fout, "print error : heap is empty\n");
		return;
	}
	for (int i=0; i<heap->Size; i++)
		fprintf(fout, "%d ", heap->Elements[i]);
	fprintf(fout, "\n");
}

int IsFull(Heap* heap){ 
	/* check if the heap is full */	
	if (heap->Size == heap->Capacity)
		return 1;
	else
		return 0;
}
