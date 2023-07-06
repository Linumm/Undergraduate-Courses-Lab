#include <iostream>
#include "intset.h"
#include <vector>
#include <algorithm>
using namespace std;

IntegerSet::IntegerSet() { numbers_.clear(); }
IntegerSet::~IntegerSet() { numbers_.clear(); }

void IntegerSet::AddNumber (int num)
{
    if (binary_search(numbers_.begin(), numbers_.end(), num))
        return;
    else
        numbers_.push_back(num);
}

void IntegerSet::DeleteNumber(int num)
{
    for (int i=0; i<(int)numbers_.size(); i++) {
        if (numbers_[i]==num)
            numbers_.erase(numbers_.begin()+i);
    }
            
}

int IntegerSet::GetItem(int pos)
{
    if (pos >= (int)numbers_.size())
        return -1;
    else if (pos < 0)
        return -1;
    else
        return numbers_[pos];
}

vector<int> IntegerSet::GetAll()
{ return numbers_; }
