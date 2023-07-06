#include <iostream>

int main(){
    std::string str1; std::string str2;
    std::cin >> str1;
    std::cin >> str2;
    
    std::string str3= str1 + str2;
    std::cout << str3 << std::endl;
    std::cout << str3[0] << std::endl;
    std::cout << str3[str3.length()-1] << std::endl;

    return 0;
}
