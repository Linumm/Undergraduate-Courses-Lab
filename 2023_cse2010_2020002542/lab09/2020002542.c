#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fin;
FILE *fout;

typedef struct _Queue {
	int* key;
	int first, rear, qsize, max_queue_size;
}Queue;

typedef struct _Graph {
	int size;
	int* node; // Node number
	int** matrix; // For edge
}Graph;

Graph* CreateGraph(int* nodes, int n);
void InsertEdge(Graph* G, int a, int b);
void PrintGraph(Graph* G);
void DeleteGraph(Graph* G);
void Topsort(Graph* G);
Queue* MakeNewQueue(int X); // 
int IsEmpty(Queue* Q);
int Dequeue(Queue* Q);
void Enqueue(Queue* Q, int X);
void DeleteQueue(Queue* Q);
void countInput(int* n, char* str); // X
void parseInput(int* arr, char* str, int n); // X
void checkIndegree(Graph* G, int* idg);
void sort_node(int* arr, int n);



int main(int argc, char* agrv[]) {
	fin = fopen(agrv[1], "r");
	fout = fopen(agrv[2], "w");

	char numbers[100], inputs[150];
	fgets(numbers, 100, fin);
	int n = 0;
	countInput(&n, numbers);
	int* nodes = (int*)malloc(sizeof(int)*n); // nodes set 
	parseInput(nodes, numbers, n);

	Graph* G = CreateGraph(nodes, n);

	fgets(inputs, 100, fin);
	int len = strlen(inputs), i, j;
	for (i = 0; i < len; i += 4) {
		int a = inputs[i] - '0', b = inputs[i + 2] - '0';
		InsertEdge(G, a, b);
	}

	PrintGraph(G);
	Topsort(G);
	DeleteGraph(G);

	fclose(fin);
	fclose(fout);

	return 0;
}

void countInput(int* n, char* str) {
	int len = strlen(str), i;
	for (i = 0; i < len; i++)
		if (0 <= str[i] - '0' && str[i] - '0' < 10) (*n)++;
}

void parseInput(int* arr, char* str, int n) {
	int len = strlen(str), i;
	int cnt = 0;
	for (i = 0; i < len; i++)
	if (0 <= str[i] - '0' && str[i] - '0' < 10) arr[cnt++] = str[i] - '0';
}


//============================================================
Graph* CreateGraph(int* nodes, int n)
{
    Graph* new_graph = malloc(sizeof(Graph));
    new_graph->size = n;
    new_graph->node = malloc(sizeof(int)*n);
    // Sort nodes first
    sort_node(nodes, n);

    // assign nodes value
    for (int i=0; i<n; i++)
        new_graph->node[i] = nodes[i];
    
    // new 2D arr for adjacency matrix
    new_graph->matrix = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        new_graph->matrix[i] = malloc(sizeof(int)*n);
        for (int j=0; j<n; j++)
            new_graph->matrix[i][j] = 0;
    }
    
    //Tracing: printf("Dbg| CreateGraph() done\n");
    
    return new_graph;
}

void InsertEdge(Graph* G, int a, int b) 
{
    // a: src vertex, b: destination vertex
    // Reversing to find index matching with a, b
    int idx_a, idx_b;
    for (int i=0; i<G->size; i++) {
        if (G->node[i] == a)
            idx_a = i;
        if (G->node[i] == b)
            idx_b = i;
    }
    G->matrix[idx_a][idx_b] = 1;
    //Tracing: printf("Dbg| Edge Inserted: %d->%d\n", a, b);
}

void PrintGraph(Graph* G)
{
    int size = G->size;
    fprintf(fout, "   ");
    for (int i=0; i<size; i++)
        fprintf(fout, "%d  ", G->node[i]);
    fprintf(fout, "\n");

    for (int i=0; i<size; i++) {
        fprintf(fout, "%d  ", G->node[i]);
        for (int j=0; j<size; j++)
            fprintf(fout, "%d  ", G->matrix[i][j]);
        fprintf(fout, "\n");
    }
    //Tracing: printf("Dbg| PrintGraph() Done\n");
} 

void checkIndegree(Graph* G, int* idg)
{
    // Check by adjacent matrix with column
    // idg is array which has values of each vertex's in-degree
    int count;
    for (int i=0; i<G->size; i++) {
        count = 0;
        for (int j=0; j<G->size; j++) {
            if (G->matrix[j][i] == 1)
                count ++;
        }
        idg[i] = count;
    } 
}

void DeleteGraph(Graph* G)
{
    // Deallocate target : matrix, nodes, Graph
    for (int i=0; i<G->size; i++)
        if (G->matrix[i] != NULL)
            free(G->matrix[i]);
    free(G->matrix);
    free(G->node);
    free(G);
}

void sort_node(int* arr, int n)
{
    //INSERTION SORT
    // sort node with value increasing order
    int tmp_for_swap;

    for (int i=1; i<n; i++) {
        tmp_for_swap = arr[i];
        for (int j=i-1; j>=0; j--) {
            if (arr[j] >= arr[i]) { // swap
                arr[i] = arr[j];
                arr[j] = tmp_for_swap;
            }
        }
    }
}


void Topsort(Graph* G)
{
    int size = G->size;
    int* topsort_order = malloc(sizeof(int)*size+10);
    int count = 0;
    
    // Make queue 
    Queue* queue = MakeNewQueue(size);
    // Initialize in-degree array
    int* idg_arr = malloc(sizeof(int)*size);
    checkIndegree(G, idg_arr);

    //Tracing: printf("Dbg| After checkIndegree()\n");
    // First stage, enqueue every vertex of in-degree 0
    for (int i=0; i<size; i++) {
        if (idg_arr[i] == 0)
            Enqueue(queue, i);
    }
    //Tracing: printf("Dbg| Every idg 0 vertex Enqueued\n");

    if (IsEmpty(queue)) {
        // IF there's no vertex with idg = 0 -> cycle exist
        fprintf(fout, "sorting error : cycle!\n");
        free(idg_arr);
        free(topsort_order);
        DeleteQueue(queue);
        return;
    }

    while (!IsEmpty(queue)) {
        int current = Dequeue(queue);
        //Tracing: printf("Dbg| Current index: %d\n", current);
        // 
        topsort_order[count++] = current;

        for (int i=0; i<size; i++) {
            // Find every destination vertex from edge src:current
            if (G->matrix[current][i] == 1) {
                // then assume cutting that edge -> in-degree of dst vertex -1
                idg_arr[i]--;
                //Tracing: printf("Dbg| %d: idg_arr-- done\n", i);
                if (idg_arr[i] == 0)
                    Enqueue(queue, i);
            }
        }
    }

    //Tracing: printf("Dbg| count: %d\n", count);

    if (count != size) {
        //Tracing: printf("Dbg| Now process in cycle finish\n");
        free(idg_arr);
        free(topsort_order);
        DeleteQueue(queue);
        fprintf(fout, "sorting error : cycle!\n");
        return;
    }
    
    for (int i=0; i<count; i++) 
        fprintf(fout, "%d ", G->node[topsort_order[i]]);
    fprintf(fout, "\n");
    free(idg_arr);
    free(topsort_order);
    DeleteQueue(queue);
}


// QUEUE Impl----------------------------------------------------
Queue* MakeNewQueue(int X)
{
    // Create a new queue with max_queue_size = X
    Queue* new_q = malloc(sizeof(Queue));
    new_q->key = malloc(sizeof(int)*X);
    new_q->max_queue_size = X;
    new_q->qsize = 0;
    new_q->first = 0;
    new_q->rear = -1;
}
int IsEmpty(Queue* Q)
{
    return (Q->qsize == 0) ? 1 : 0;
}
int Dequeue(Queue* Q)
{
    if (Q->qsize == 0) {
        //Tracing: printf("Queue is empty\n");
        return -1;
    }
    int front = Q->key[Q->first];
    Q->key[Q->first++] = 0;
    Q->qsize--;
    //Tracing: printf("Dequeue() : %d\n", front);

    return front;
}
void Enqueue(Queue* Q, int X)
{
    if (Q->qsize == Q->max_queue_size) {
        //Tracing: printf("Queue is full\n");
        return;
    }
    Q->key[++Q->rear] = X;
    Q->qsize++;
}
void DeleteQueue(Queue* Q)
{
    //Tracing: printf("Dbg| DeleteQueue()\n");
    free(Q->key);
    free(Q);
}