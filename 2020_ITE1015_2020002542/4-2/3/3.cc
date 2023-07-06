#include <iostream>
using namespace std;

void magicSquare(int* arr, int n);

int main(int argc, char* argv[]) {
    int n= atoi(argv[1]);
    if (n<3 || n%2==0)
        return 0;

    int* board=new int[n*n];
    magicSquare(board, n);

    for (int i=0; i<n*n; i+=n) {
        for (int j=i; j<i+n; j++)
            cout << board[j] << " ";
        cout << endl;
    }

    delete[] board;
    return 0;
}

void magicSquare(int* arr, int n) {
    int row=0; int column=(n-1)/2; int k=1;

    while (k<=n*n) {
        arr[n*column+row]=k;
        if ((k%n) == 0)
            row++;
        else {
            row--; column++;
            if (row<0)
                row=n-1;
            if (column==n)
                column=0;
        }
        k++;
    }
}
