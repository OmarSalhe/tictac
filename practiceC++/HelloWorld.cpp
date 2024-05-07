#include <iostream>
#include <cctype>
#include <cstring>

int main(){
    std::string greeting = "Hello World";

    char answer;
    std::cout << "Yes or No";
    std::cin >> answer;

    if (toupper(answer) == 'Y'){
        std::cout << greeting;
    }
    return 0;
}