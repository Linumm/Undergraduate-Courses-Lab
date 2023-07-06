#include "setfunc.h"
#include <iostream>
#include <string>
#include <set>
#include <ctype.h>
using namespace std;

set<int> parseSet(const string& str)
{
    set<int> return_set; int i=0; int j, k;
    while (i<str.size()) {
        j=1;
        if (str.at(i)=='-') {
             for (j=1; j<str.size(); j++) {
                 if (isdigit(str[i+j])==0)
                     break;
             }
            string temp_=str.substr(i+1,j);
            return_set.insert((-1)*stoi(temp_));
        }
        else if (isdigit(str[i])) {
            for (j=1; j<str.size(); j++) {
                if (isdigit(str[i+j])==0)
                    break;
            }
            string temp=str.substr(i,j);
            return_set.insert(stoi(temp));
        }
        i+=j;
    }
    return return_set;
}
void printSet(const set<int>& set0)
{
    cout << "{ "; set<int>::iterator it;
    for (it=set0.begin(); it!=set0.end(); it++)
        cout << *it << " ";
    cout << "}" << endl;
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1)
{
    set<int> set_inter; set<int>::iterator it0; set<int>::iterator it1;
    for (it0=set0.begin(); it0!=set0.end(); it0++) {
        for (it1=set1.begin(); it1!=set1.end(); it1++) {
            if (*it0==*it1)
                set_inter.insert(*it0);
        }
    }
    return set_inter;
}

set<int> getUnion(const set<int>& set0, const set<int>& set1)
{
    set<int> set_union; int check=0;
    for (set<int>::iterator it0=set0.begin(); it0!=set0.end(); it0++)
        set_union.insert(*it0);
    for (set<int>::iterator it1=set1.begin(); it1!=set1.end(); it1++) {
        for (set<int>::iterator it0=set0.begin(); it0!=set0.end(); it0++) {
            if (*it0==*it1)
                check=1;
        }
        if (check==0)
            set_union.insert(*it1);
        check=0;
    }

    return set_union;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1)
{
    set<int> set_diff; int check=0;
    for (set<int>::iterator it0=set0.begin(); it0!=set0.end(); it0++) {
        for (set<int>::iterator it1=set1.begin(); it1!=set1.end(); it1++) {
            if (*it0==*it1)
                check=1;
        }
        if (check==0) set_diff.insert(*it0);
        check=0;
    }
    return set_diff;
}
