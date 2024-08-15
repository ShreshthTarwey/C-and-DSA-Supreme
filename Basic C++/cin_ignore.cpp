#include <iostream>
int main(){
    char first,last;
    std :: cout<<"Enter your first name followed by your last name:\n";
    first=std::cin.get();
    std::cin.ignore(256,' ');
    last = std::cin.get();
    std::cout<<"Your initials are:"<<first<<last<<std::endl;
}