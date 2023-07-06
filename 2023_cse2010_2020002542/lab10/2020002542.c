#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 1e9

FILE *fin;
FILE *fout;

typedef struct Node {
	int vertex;
	int dist;	//distance
	int prev;
}Node;

typedef struct Graph {
	int size;
	int** vertices;
	Node* nodes;
}Graph;

typedef struct Heap {
	int Capacity;
	int Size;
	Node* Element;
}Heap;

Graph* createGraph(int size);
void deleteGraph(Graph* g);
void printShortestPath(Graph* g);
//Heap
Heap* createMinHeap(int heapSize);
void deleteMinHeap(Heap* minHeap);
void insertToMinHeap(Heap* minHeap, int vertex, int distance);
Node deleteMin(Heap* minHeap);
//My-defined func
void backTrackPrint(Graph* g, int vertex); // Print path with cost


void main(int argc, char *argv[]) {
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

	Graph* g;
	int size;
	fscanf(fin, "%d\n", &size);
	g = createGraph(size + 1);

	char tmp = 0;
	while (tmp != '\n' && tmp != EOF) {
		int node1, node2, weight;
		fscanf(fin, "%d-%d-%d", &node1, &node2, &weight);
		g->vertices[node1][node2] = weight;
		tmp = fgetc(fin);
	}
	printShortestPath(g);

	deleteGraph(g);
}

Graph* createGraph(int size)
{
    Graph* new_graph = malloc(sizeof(Graph));
    new_graph->size = size;
    new_graph->vertices = malloc(sizeof(int*)*size);
    for (int i=1; i<size; i++) {
        new_graph->vertices[i] = malloc(sizeof(int)*size);
        for (int j=1; j<size;j++) {
            new_graph->vertices[i][j] = -1;
        }
    }
    
    new_graph->nodes = malloc(sizeof(Node) * size);
    for (int i=1; i<size; i++) {
        new_graph->nodes[i].vertex = i;
        new_graph->nodes[i].dist = INF;
        new_graph->nodes[i].prev = -1;
    }
    
    return new_graph;
}

void deleteGraph(Graph* g)
{
    free(g->nodes);
    for (int i=0; i<g->size; i++) {
        free(g->vertices[i]);
    }
    free(g->vertices);
    free(g);
}

void printShortestPath(Graph* g)
{
    Heap* min_heap = createMinHeap(g->size);
    g->nodes[1].dist = 0;
    int* visited = malloc(sizeof(int) * g->size);
    for (int i=0; i<g->size; i++) {
        visited[i] = 0;
    }

    insertToMinHeap(min_heap, 1, 0);
    
    while (min_heap->Size != 0) {
        Node current = deleteMin(min_heap);

        if (visited[current.vertex] == 0) {
            visited[current.vertex] = 1;
            for (int i=1; i<g->size; i++) {
                if (g->vertices[current.vertex][i] != -1) {
                    // g->vertices[][] : edge weight
                    int new_distance = current.dist + g->vertices[current.vertex][i];
                    if (new_distance < g->nodes[i].dist) {
                        g->nodes[i].dist = new_distance;
                        g->nodes[i].prev = current.vertex;
                        insertToMinHeap(min_heap, i, new_distance);
                    }
                }
            }
        }
    }

    // Now print out
    for (int i=2; i<g->size; i++) {
        backTrackPrint(g, i);
    }
}

//HEAP
Heap* createMinHeap(int heapSize)
{
    Heap* new_heap = malloc(sizeof(Heap));
    
    new_heap->Capacity = heapSize;
    new_heap->Element = malloc(sizeof(Node) * heapSize);
    new_heap->Size = 0;
}

void deleteMinHeap(Heap* minHeap)
{
    free(minHeap->Element);
    free(minHeap);
}

void insertToMinHeap(Heap* minHeap, int vertex, int distance)
{
    if (minHeap->Size == minHeap->Capacity) {
        printf("Insertion error: Full Heap\n");
        return;
    }
    minHeap->Element[minHeap->Size].vertex = vertex;
    minHeap->Element[minHeap->Size].dist = distance;
    int tmp_idx = minHeap->Size;
    Node tmp_for_swap;
    
    while (1) {
        if (tmp_idx == 0)
            break;
        if (minHeap->Element[(tmp_idx-1)/2].dist > minHeap->Element[tmp_idx].dist) {
            // Swap
            tmp_for_swap = minHeap->Element[tmp_idx];
            minHeap->Element[tmp_idx] = minHeap->Element[(tmp_idx-1)/2];
            minHeap->Element[(tmp_idx-1)/2] = tmp_for_swap;

            tmp_idx = (tmp_idx-1)/2;
        }
        else
            break;
    }
    minHeap->Size++;
}

Node deleteMin(Heap* minHeap)
{
    if (minHeap->Size == 0) {
        printf("Deletion error: Empty Heap\n");
    }

    Node min = minHeap->Element[0];

    if (minHeap->Size == 1) {
        minHeap->Size--;
        return min;
    }
    minHeap->Element[0] = minHeap->Element[minHeap->Size-1];
    int tmp_idx = 0;
    Node tmp_for_swap;

    
    while (1) {
        if (tmp_idx*2+1 >= minHeap->Capacity)
            break;
        if (minHeap->Element[tmp_idx*2+1].dist < minHeap->Element[tmp_idx].dist) {
            tmp_for_swap = minHeap->Element[tmp_idx];
            if (minHeap->Element[tmp_idx*2+1].dist < minHeap->Element[tmp_idx*2+2].dist) {
                minHeap->Element[tmp_idx] = minHeap->Element[tmp_idx*2+2];
                minHeap->Element[tmp_idx*2+1] = tmp_for_swap;

                tmp_idx = tmp_idx*2+1;
            }
            else if (minHeap->Element[tmp_idx*2+1].dist < minHeap->Element[tmp_idx*2+2].dist) {
                minHeap->Element[tmp_idx] = minHeap->Element[tmp_idx*2+2];
                minHeap->Element[tmp_idx] = tmp_for_swap;

                tmp_idx = tmp_idx*2+2;
            }
        }
        else
            break;
    }
    minHeap->Size--;
    return min;
}
//My-defined func
void backTrackPrint(Graph* g, int vertex)
{
    if (g->nodes[vertex].prev == -1) {
        fprintf(fout, "can not reach to node %d\n", g->nodes[vertex].vertex);
        return;
    }

    int* path_save = malloc(sizeof(int) * g->size);
    int count = -1;
    Node tmp = g->nodes[vertex];
    while (1) {
        path_save[++count] = tmp.vertex;
        if (tmp.prev == -1)
            break;
        tmp = g->nodes[tmp.prev];
    }

    for (int i=count; i>=0; i--) {
        if (i != 0)
            fprintf(fout, "%d->", path_save[i]);
        else
            fprintf(fout, "%d", path_save[i]);
    } 

    fprintf(fout, " (cost : %d)\n", g->nodes[vertex].dist);
}