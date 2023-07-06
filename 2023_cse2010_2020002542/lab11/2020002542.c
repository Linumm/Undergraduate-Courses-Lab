#include<stdio.h>
#include<stdlib.h>

FILE* fin;
FILE* fout;

typedef struct Array Array;

struct Array{
    int size;
    int* values;
};

Array* CreateArray(int size);
void QuickSort(Array* array, int left, int right, int depth);
int Partition(Array* array, int left, int right, int depth);
void PrintArray(Array* array, int left, int right);
void DeleteArray(Array* array);
void swap(int* a, int* b);

int main(int argc, char *argv[]){
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");

    int size, i;
    Array* array;

    fscanf(fin, "%d", &size);
    array = CreateArray(size);
    for(i = 0; i < size; i++){
        fscanf(fin, "%d", &array->values[i]);
    }

    QuickSort(array, 0, size - 1, 0);

    fprintf(fout, "\nsorting result :\n");
    PrintArray(array, 0, size - 1);

    DeleteArray(array);


	return 0;
}


Array* CreateArray(int size)
{
    Array* new_arr = (Array*)malloc(sizeof(Array));
    new_arr->size = size;
    new_arr->values = (int*)malloc(sizeof(int) * size);

    return new_arr;   
}
void QuickSort(Array* array, int left, int right, int depth)
{
    // 수행은 dfs 형태로
    if (left < right) {
        if (left >= 0 && right < array->size) {
            int pivot = Partition(array, left, right, depth);
            QuickSort(array, left, pivot-1, depth+1); // left-first
            QuickSort(array, pivot+1, right, depth+1);
        }
    }
}
int Partition(Array* array, int left, int right, int depth)
{
    //!!!!!!!!!!! Printing 한 줄로 변경하기
    // pivot은 맨 마지막 원소로
    int pivot = array->values[right];
    int i = left;
    int j = right;
    fprintf(fout, "left : %d, right : %d, pivot : %d\n", i, j, pivot);
    PrintArray(array, left, right);

    while (1) {
        while (array->values[i] <= pivot && i < right)
            i++;
        while (array->values[j] >= pivot && j > left)
            j--;
        if (i >= j)
            break;
        
        swap(&array->values[i], &array->values[j]);
        PrintArray(array, left, right);
    }
    if (i != right) {
        swap(&array->values[i], &array->values[right]);
        PrintArray(array, left, right);
    }
    return i; // Consider index error later
}
void PrintArray(Array* array, int left, int right)
{
    // 현재 파티션에 해당하는 부분만 출력하고, 아닌 부분은 "-"로 출력
    int dontcare_left = left - 1;
    int dontcare_right = right + 1;
    
    for (int i=0; i<=dontcare_left; i++) {
        fprintf(fout, "%-3s", "-");
    }
    for (int i=left; i<=right; i++) {
        fprintf(fout, "%-3d", array->values[i]);
    }
    for (int i=dontcare_right; i<array->size; i++) {
        fprintf(fout, "%-3s", "-");
    }
    fprintf(fout, "\n");
}
void DeleteArray(Array* array)
{
    free(array->values);
    free(array);
}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}