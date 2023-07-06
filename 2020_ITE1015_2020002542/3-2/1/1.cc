#include <iostream>
#include <string>

using namespace std;

int drawer(int x, int y){
    return 6*y+x;
}

void drawer(string& lineRef, int index_num){
    lineRef[index_num]='*';
}

int main(){
    int input_x; int input_y;
    string line=".....\n.....\n.....\n.....\n.....";

    for(int i=0; i<5; i++){
        cin >> input_x >> input_y;
        if ((input_x > 4 || input_x < 0) || (input_y > 4 || input_y <0))
           break;

        int point_index= drawer(input_x, input_y);
        drawer(line, point_index);
        cout << line << endl;
    }

    return 0;
}


