#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}
void insert_sort(int array[], int size);

int main(void) {
    
    int n;
    cin >> n;
    if (n<1)
        return 0;

    int* arr=new int[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];

    insert_sort(arr,n);
    for (int i=0; i<n; i++)
        cout << arr[i] <<" ";
    cout << endl;

    delete[] arr;
    return 0;
}

void insert_sort(int array[], int size) { //refer insertion_sort
    for (int p=1; p<size; p++) {
        for (int q=p; q>0 && array[q-1]>array[q]; q--) 
            swap(array[q-1], array[q]);
    }
}
