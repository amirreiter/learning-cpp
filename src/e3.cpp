// Modify the previous program such that only the users Alice and Bob are
// greeted with their names.

#include <iostream>
#include <string>

int main(void) {
    std::string name;

    std::cout << "What is your name?\n> ";

    std::cin >> name;

    if (name == "Alice" || name == "Bob") {
        std::cout << "Hello, " << name << "!\n";
    } else {
        std::cout << "Unfortunately, I cannot say hello to you, " << name;
        std::cout << "\n";
    }
}
