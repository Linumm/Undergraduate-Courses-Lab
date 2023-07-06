#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int* array= new int[n];
    cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4];

    int max=array[0]; int min=array[0];
    for (int i=1; i<n; i++){
        if (array[i] > max)
            max=array[i];
        if (array[i] < min)
            min=array[i];
    }
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    delete[] array;

    return 0;
}
