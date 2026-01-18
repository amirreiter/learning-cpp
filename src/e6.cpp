// Write a program that asks the user for a number n and gives them the
// possibility to choose between computing the sum and computing the product
// of 1,…,n

#include <iostream>
#include <string>

int main(void) {
    std::string input;
    std::string op;
    bool product = false;

    std::cout << "Enter a number:\n> ";

    std::cin >> input;

    std::cout << "Enter an operation (* or +):\n> ";

    std::cin >> op;

    if (!(op == "*" || op == "+")) {
        std::cout << "That is an invalid operation.\n>";
    } else if (op == "*") {
        product = true;
    }

    int number = std::stoi(input);
    int sum = 0;
    if (product) {
        sum = 1;
    }

    for (int i = 1; i <= number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            // It would be faster to do the conditional outside the loop,
            // but then the loop would have to be repeated twice, and I
            // cannot be bothered.
            if (product) {
                sum *= i;
            } else {
                sum += i;
            }
        }
    }

    std::cout << "The ";

    if (product) {
        std::cout << "product";
    } else {
        std::cout << "sum";
    }

    std::cout << " of all multiples of 3 or 5 from 1 to " << number << " is ";
    std::cout << sum << "\n";
}
