#include <iostream>
#include "my_vector.h"
using namespace std;

int main(void)
{
    string cmd; string oper_;
    MyVector* pa=NULL; MyVector* pb=NULL;

    while (true)
    {
        cin >> cmd;
        if (cmd == "quit")
            break;
        else if (cmd == "new") { //------ command "new"
            if (pa != NULL && pb != NULL) {
                delete pa; delete pb;} //==check whether we must deallocate

            int len; cin >> len;
            pa = new MyVector(len);
            pb = new MyVector(len);

            cout << "enter a" << endl;
            cin >> *pa;
            cout << "enter b" << endl;
            cin >> *pb;
        }

        else if (cmd == "a" || cmd == "b") {
            cin >> oper_; 
            if (oper_ == "+") { //---------------command "+"
                string object; cin >> object;
                MyVector temp;
                if (isdigit(object[0])) {
                    if (cmd == "a") {
                        temp = (*pa) + stoi(object);
                        cout << temp << endl; }
                    else if (cmd == "b") {
                        temp = (*pb) + stoi(object);
                        cout << temp << endl; }
                }
                else {
                    if (cmd == "a" && object == "a") {
                        temp = (*pa) + (*pa);
                        cout << temp << endl; }
                    else if (cmd == "a" && object == "b") {
                        temp = (*pa) + (*pb);
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "a") {
                        temp = (*pb) + (*pa);
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "b") {
                        temp = (*pb) + (*pb);
                        cout << temp << endl; }
                }
            }
            else if (oper_ == "-") { //----------------command "-"
                string object; cin >> object;
                MyVector temp;
                if (isdigit(object[0])) {
                    if (cmd == "a") {
                        temp = (*pa) - stoi(object);
                        cout << temp << endl; }
                    else if (cmd == "b") {
                        temp = (*pb) - stoi(object);
                        cout << temp << endl; }
                }
                else {
                    if (cmd == "a" && object == "a") {
                        temp = (*pa) - (*pa);
                        cout << temp << endl; }
                    else if (cmd == "a" && object == "b") {
                        temp = (*pa) - (*pb);
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "a") {
                        temp = (*pb) - (*pa);
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "b") {
                        temp = (*pb) - (*pb);
                        cout << temp << endl; }
                }
            }
        }
    }

    if (pa!=NULL && pb!=NULL) {
        delete pa; delete pb;
    }
    return 0;
}
