// Modify the previous program such that only multiples of three or five are
// considered in the sum, e.g. 3, 5, 6, 9, 10, 12, 15 for n=17

#include <iostream>
#include <string>

int main(void) {
    std::string input;

    std::cout << "Enter a number:\n> ";

    std::cin >> input;

    int number = std::stoi(input);
    int sum = 0;

    for (int i = 1; i <= number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << "The sum of all multiples of 3 or 5 from 1 to " << number;
    std::cout << " is " << sum << "\n";
}
