#include <iostream>
#include <string>

class phone_number {
private:
    std::string n;

public:
    void input() {
        std::cin >> n;
    }

    void check() {
        // Check if the string is exactly 10 characters long and all are digits
        if (n.length() == 10 && n.find_first_not_of("0123456789") == std::string::npos) {
            std::cout << "Your entered number is: " << n << std::endl;
        } else {
            std::cout << "Entered Phone number is wrong" << std::endl;
        }
    }
};

int main() {
    phone_number ph;
    ph.input();
    ph.check();

    return 0;
}
