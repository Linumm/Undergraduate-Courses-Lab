#include <iostream>
#include "my_vector2.h"
using namespace std;

int main(void)
{
    string cmd; string oper_;
    MyVector2* pa=NULL; MyVector2* pb=NULL;

    while (true)
    {
        cin >> cmd;
        if (cmd == "quit")
            break;
        else if (cmd == "new") { //------ command "new"
            if (pa != NULL && pb != NULL) {
                delete pa; delete pb;} //==check whether we must deallocate

            int len; cin >> len;
            pa = new MyVector2(len);
            pb = new MyVector2(len);

            cout << "enter a" << endl;
            cin >> *pa;
            cout << "enter b" << endl;
            cin >> *pb;
        }

        else if (cmd == "a" || cmd == "b") {
            cin >> oper_; 
            if (oper_ == "+") { //---------------command "+"
                string object; cin >> object;
                if (isdigit(object[0])) {
                    if (cmd == "a") {
                        MyVector2 temp((*pa) + stoi(object));
                        cout << temp << endl; }
                    else if (cmd == "b") {
                        MyVector2 temp((*pb) + stoi(object));
                        cout << temp << endl; }
                }
                else {
                    if (cmd == "a" && object == "a") {
                        MyVector2 temp((*pa) + (*pa));
                        cout << temp << endl; }
                    else if (cmd == "a" && object == "b") {
                        MyVector2 temp((*pa) + (*pb));
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "a") {
                        MyVector2 temp((*pb) + (*pa));
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "b") {
                        MyVector2 temp((*pb) + (*pb));
                        cout << temp << endl; }
                }
            }
            else if (oper_ == "-") { //----------------command "-"
                string object; cin >> object;
                MyVector2 temp;
                if (isdigit(object[0])) {
                    if (cmd == "a") {
                        MyVector2 temp((*pa) - stoi(object));
                        cout << temp << endl; }
                    else if (cmd == "b") {
                        MyVector2 temp((*pb) - stoi(object));
                        cout << temp << endl; }
                }
                else {
                    if (cmd == "a" && object == "a") {
                        MyVector2 temp((*pa) - (*pa));
                        cout << temp << endl; }
                    else if (cmd == "a" && object == "b") {
                        MyVector2 temp((*pa) - (*pb));
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "a") {
                        MyVector2 temp((*pb) - (*pa));
                        cout << temp << endl; }
                    else if (cmd == "b" && object == "b") {
                        MyVector2 temp((*pb) - (*pb));
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
