// Write a program that asks the user for their name and greets them with their
// name.

#include <iostream>
#include <string>

int main(void) {
    std::string name;

    std::cout << "What is your name?\n> ";

    std::cin >> name;

    std::cout << "Hello, " << name << "!\n";
}
