// Write a program that asks the user for a number n and prints the sum of the
// numbers 1 to n

#include <iostream>
#include <string>

int main(void) {
    std::string input;

    std::cout << "Enter a number:\n> ";

    std::cin >> input;

    int number = std::stoi(input);
    int sum = 0;

    for (int i = 1; i <= number; i++) {
        sum += i;
    }

    std::cout << "The sum of all numbers from 1 to " << number << " is ";
    std::cout << sum << "\n";
}
