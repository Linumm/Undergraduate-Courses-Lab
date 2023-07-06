#include "accounts.h"
#include <iostream>
using namespace std;

void AccountManager::assign_newAcc(int& id) //assign new Account
{
    if (noa==10) {
        cout << "You can't create account anymore (Max Accounts:10)" << endl;
        return;
    }
    if (accounts[id].account_ID!=id) { //check if there exist account
        accounts[id].account_ID=id;
        accounts[id].balance=0;
        cout << "Account for user " << id << " registered" << endl;
        noa=id+1; id++;
    }
}

int AccountManager::check_balance(int id, int user_input)
{
    if (accounts[id].balance+user_input>1000000 || accounts[id].balance+user_input<0)
        return 1; //return 1 by max and min condition.
    else if (user_input> accounts[id].balance)
        return 0; //return 0 if user's input is bigger than balance
}

void AccountManager::deposit(int id, int amount)
{
    if (dwt_limit[id][0]==1) {
        cout << "Fail by deposit limit (1)" << endl;
        return;
    }
    else if (accounts[id].account_ID!=id) {
        cout << "Account does not exist" << endl;
        return;
    }
    else if (check_balance(id, amount)==1) {
        cout << "Failure (Max: 1 million won, Min: 0 won)" << endl;
        return;
    }
    else
        accounts[id].balance+=amount; dwt_limit[id][0]=1;
}

void AccountManager::withdraw(int id, int amount)
{
    if  (dwt_limit[id][1]==1) {
        cout << "Failed by withdraw limit (1)" << endl;
        return;
    }
    else if (accounts[id].account_ID!=id) {
        cout << "Account does not exist" << endl;
        return;
    }
    else if (check_balance(id,amount)==0) {
        cout << "Failure: Withdraw from user " << id << ": " <<amount << endl;
        return;
    }
    else
        accounts[id].balance-=amount; dwt_limit[id][1]=1;
}

void AccountManager::transfer(int sender, int receiver, int amount)
{
    if (dwt_limit[sender][2]==1 || dwt_limit[receiver][2]==1) {
        cout << "Failed by transfer limit (1)" << endl;
        return;
    }
    else if (accounts[sender].account_ID!=sender || accounts[receiver].account_ID!=receiver) {
        cout << "Account does not exist" << endl;
        return;
    }
    if (amount > accounts[sender].balance) {
        cout << "Failure: Transfer from user " << sender << " to " << receiver << amount << endl;
        return;
    }
    accounts[sender].balance-=amount; accounts[receiver].balance+=amount;
    dwt_limit[sender][2]=1; 
}

void AccountManager::print_bal(int id)
{
    if (accounts[id].account_ID==id)
        cout << "Balance of user " << id << ": " << accounts[id].balance << endl;
}
