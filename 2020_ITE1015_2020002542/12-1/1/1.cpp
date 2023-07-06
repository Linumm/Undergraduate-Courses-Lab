#include <iostream>
using namespace std;

template <typename T>
void myswap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
int main(void)
{
    int int_i, int_j;
    double db_i, db_j;
    string str_i, str_j;

    cin >> int_i >> int_j;
    myswap<int>(int_i, int_j);
    cout << "After calling myswap(): " << int_i << " " << int_j << endl;

    cin >> db_i >> db_j;
    myswap<double>(db_i, db_j);
    cout << "After calling myswap(): " << db_i << " " << db_j << endl;

    cin >> str_i >> str_j;
    myswap<string>(str_i, str_j);
    cout << "After calling myswap(): " << str_i << " " << str_j << endl;

    return 0;
}
