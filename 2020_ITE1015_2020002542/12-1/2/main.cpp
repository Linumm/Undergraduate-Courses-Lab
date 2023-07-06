#include <iostream>
#include "my_container.h"
using namespace std;

int main(void)
{
    int num_elements;
    cin >> num_elements;

    MyContainer<int> container_i(num_elements); //int container
    cin >> container_i;
    cout << container_i;
    container_i.clear();

    cin >> num_elements;
    MyContainer<double> container_d(num_elements); //double container
    cin >> container_d;
    cout << container_d;
    container_d.clear();

    cin >> num_elements;
    MyContainer<string> container_s(num_elements);
    cin >> container_s;
    cout << container_s;
    container_s.clear();

    return 0;
}
