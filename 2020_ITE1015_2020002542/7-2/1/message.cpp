#include "message.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

MessageBook::MessageBook() { messages_.clear(); }
MessageBook::~MessageBook() { messages_.clear(); }

void MessageBook::AddMessage(int number, const string& message)
{
    if (messages_.find(number)==messages_.begin())
        messages_.erase(number);
    messages_.insert(make_pair(number, message));
}

void MessageBook::DeleteMessage(int number)
{
    messages_.erase(number);
}

vector<int> MessageBook::GetNumbers()
{
    vector<int> numVec;
    for (map<int, string>::iterator it=messages_.begin(); it!=messages_.end(); it++)
        numVec.push_back(it->first);
    
    return numVec;
}

const string& MessageBook::GetMessage(int number)
{
    return messages_[number];
}
