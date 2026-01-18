// Write a function that tests whether a string is a palindrome.

#include <iostream>
#include <string_view>

#include "l-common.cpp"

bool is_palindrome(std::string_view string) {
    int last_char = string.length() - 1;

    for (int i = 0; i < last_char / 2; i++) {
        if (string[i] != string[last_char - i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    assert_one(
        is_palindrome("racecar"),
        true,
        "Racecar"
    );
    assert_one(
        is_palindrome("buffalo"),
        false,
        "Buffalo"
    );

    std::cout << "All tests passed!\n";
}
