#include <iostream>
#include "accounts.h"
using namespace std;

int main() {
    string cmd; AccountManager am; int i=0;
    while (true)
    {
        cout << "Job?" << endl;
        cin >> cmd; //user input (N, D, W, T, Q)

        if (cmd=="Q")
            break;
        else if (cmd=="N") 
            am.assign_newAcc(i);

        else if (cmd=="D") {
            int id; int amount;
            cin >> id >> amount;
            if (amount <0) { cout << "wrong money" << endl; continue;}
            am.deposit(id, amount);
            am.print_bal(id);
        }
        else if (cmd=="W") {
            int id; int amount;
            cin >> id >> amount;
            if (amount <0) { cout << "wrong money" << endl; continue;}
            am.withdraw(id, amount);
            am.print_bal(id);
        }
        else if (cmd=="T") {
            int sender; int receiver; int amount;
            cin >> sender >> receiver >> amount;
            if (amount <0) { cout << "wrong money" << endl; continue;}
            am.transfer(sender, receiver, amount);
            am.print_bal(sender); am.print_bal(receiver);
        }
        cout << endl;
    }

    return 0;
}
