#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    char ch = 'w';

    // Use find to check if the character is in the string
    if (str.find(ch) != std::string::npos) {
        std::cout << "Character '" << ch << "' is in the string." << std::endl;
    } else {
        std::cout << "Character '" << ch << "' is not in the string." << std::endl;
    }

    return 0;
}
