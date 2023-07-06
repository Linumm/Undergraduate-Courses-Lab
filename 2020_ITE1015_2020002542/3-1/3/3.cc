#include <iostream>

int add(int a, int b);
std::string add(std::string a, std::string b);

int main(){
    int p; int q; std::string s1; std::string s2;
    std::cin >> p >> q >> s1 >> s2;
    
    std::cout << add(p, q) << std::endl;
    std::cout << add(s1, s2) << std::endl;

    return 0;
}

int add(int a, int b){
    return a+b;
}

std::string add(std::string a, std::string b){
    return a+"-"+b;
}
