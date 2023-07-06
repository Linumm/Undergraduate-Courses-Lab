#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *fin;
FILE *fout;

typedef struct _DisjointSet {
    int size_maze;
    int *ptr_arr;
}DisjointSets;

void init(DisjointSets *sets, DisjointSets *maze_print, int num);
void Union(DisjointSets *sets, int i, int j); // Here, I'll pass the root directly
int find(DisjointSets *sets, int i);
void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num);
void printMaze(DisjointSets *maze_print, int num);
void freeMaze(DisjointSets *sets, DisjointSets *maze_print);

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

//my-defined func
void wallBreak(DisjointSets *sets, DisjointSets *maze_print, int i, int j);
int countNumOfRoot(int* arr, int size);

//implement
int main(int argc, char* agrv[]) {
    srand((unsigned int)time(NULL));

    int num, i;
    fin = fopen(agrv[1], "r");
    fout = fopen(agrv[2], "w");

    DisjointSets *sets, *maze_print;
    fscanf(fin, "%d", &num);

    sets = (DisjointSets*)malloc(sizeof(DisjointSets));
    maze_print = (DisjointSets*)malloc(sizeof(DisjointSets));

    init(sets, maze_print, num);
    createMaze(sets, maze_print, num);
    printMaze(maze_print, num);

    freeMaze(sets, maze_print);

    fclose(fin);
    fclose(fout);

    return 0;
}

void init(DisjointSets *sets, DisjointSets *maze_print, int num) {
	int i;

	sets->size_maze = num * num; // 정방행렬 n*n 1~n^2 초기화
	sets->ptr_arr = (int*)malloc(sizeof(int) * (sets->size_maze + 1));
	for (i = 1; i <= sets->size_maze; i++) sets->ptr_arr[i] = 0;

	maze_print->size_maze = num * num * 2;
	maze_print->ptr_arr = (int*)malloc(sizeof(int) * (maze_print->size_maze + 1)); // to start idx from 1

    // if bounded by wall? 1 : 0
	for (i = 1; i <= maze_print->size_maze; i++) maze_print->ptr_arr[i] = 1;
	//maze_print->ptr_arr[(x-1)*2+1 ~ x*2] : two directions(right, down) walls of the number x
    // idx starts from down->right->down->right - - -

	//start and end position have not to have the wall
    maze_print->ptr_arr[0] = 0;
	maze_print->ptr_arr[maze_print->size_maze] = 0; // I set down wall as odd 
    //printf("dbg| init() done\n");
}

void Union(DisjointSets *sets, int i, int j)
{
    // Here, i and j are the root of their sets
    // And the condition is qualified because i and j are the different
    if (sets->ptr_arr[i] <= sets->ptr_arr[j]) {
        sets->ptr_arr[i]--;
        sets->ptr_arr[j] = i;
    }
    else {
        sets->ptr_arr[j]--;
        sets->ptr_arr[i] = j;
    }
}
int find(DisjointSets *sets, int i)
{
    int tmp = i;
    while (sets->ptr_arr[tmp] > 0) {
        tmp = sets->ptr_arr[tmp];
    }
    return tmp;
}
void createMaze(DisjointSets *sets, DisjointSets *maze_print, int num)
{
    while (countNumOfRoot(sets->ptr_arr, sets->size_maze + 1) != 1) { // this countNumOfRoot will make slow..?
        int target_1 = rand() % (num*num) + 1;
        int direction = rand() % 4; // 0: up, 1: right, 2: down, 3: left
        int target_2;
        
        switch(direction) {
            case 0:
                target_2 = target_1 - num;
                if (target_2 >= 1) // if not top
                    wallBreak(sets, maze_print, target_2, target_1);
                break;
            case 1:
                if (target_1 % num != 0) { // if not right-end
                    target_2 = target_1 + 1;
                    wallBreak(sets, maze_print, target_1, target_2);
                }
                break;
            case 2:
                target_2 = target_1 + num;
                if (target_2 <= num*num) // if not bottom
                    wallBreak(sets, maze_print, target_1, target_2);
                break;
            case 3:
                if (target_1 % num != 1) { // if not left-end
                    target_2 = target_1 - 1;
                    wallBreak(sets, maze_print, target_2, target_1);
                }
                break;
            default:
                break;
        }
    }
    //printf("dbg|maze created\n");
}
void printMaze(DisjointSets *maze_print, int num)
{
    /*printf("dbg| ------current wall------\n");
    for (int i=0; i<maze_print->size_maze; i++) {
        printf("%d ", maze_print->ptr_arr[i]);
    }
    printf("\n");
    printf("dbg|printMaze()\n");
    */
    // Ceil print
    fprintf(fout, "+");
    for (int i=0; i<num; i++) {
        fprintf(fout, "---+");
    }
    fprintf(fout, "\n");

    // wall print
    for (int i=0; i<num; i++) {
        if (i == 0 )
            fprintf(fout, " ");
        else
            fprintf(fout, "|");
        for (int j=i*num+1; j<(i+1)*num+1; j++) {
            if (maze_print->ptr_arr[j*2] == 0)
                fprintf(fout, "    ");
            else
                fprintf(fout, "   |");
        }
        fprintf(fout, "\n");
        fprintf(fout, "+");
        for (int j=i*num+1; j<(i+1)*num+1; j++) {
            if (maze_print->ptr_arr[j*2 - 1] == 0)
                fprintf(fout, "   +");
            else
                fprintf(fout, "---+");
        }
        fprintf(fout, "\n");
    }
}
void freeMaze(DisjointSets *sets, DisjointSets *maze_print)
{
    free(sets->ptr_arr);
    free(maze_print->ptr_arr);
    free(sets);
    free(maze_print);
}
void wallBreak(DisjointSets *sets, DisjointSets *maze_print, int i, int j)
{
    // Here, i < j
    int i_root = find(sets, i);
    int j_root = find(sets, j);
    if (i_root == j_root) // if i and j are in the same set
        return;
    
    Union(sets, i_root, j_root);

    // Now remove wall between i and j
    if (j-i == 1) { //left-right -> remove right-wall
        maze_print->ptr_arr[i*2] = 0;
    }
    else {
        maze_print->ptr_arr[i*2 - 1] = 0;
    }
}
int countNumOfRoot(int* arr, int size)
{
    int count = 0;
    for (int i=0; i<size; i++) {
        if (arr[i] <=0)
            count++;
    }
    return count;
}