// Write a program that prints a multiplication table for numbers up to 12.

#include <iostream>
#include <string>

std::string rpad_int(int num, int len) {
    std::string output = std::to_string(num);
    int current_len = output.length();

    while (current_len < len) {
        output.append(" ");
        current_len = output.length();
    }
    return output;
}

int main(void) {
    int n = 12;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << rpad_int(i * j, 4) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
