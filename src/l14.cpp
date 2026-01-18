// Write a function that takes a number and returns a list of its digits. So for
// 2342 it should return [2,3,4,2]

#include <iostream>
#include <span>
#include <string>
#include <charconv>

#include "l-common.cpp"

std::vector<int> separate(int n) {
    std::vector<int> result;
    std::string s = std::to_string(n);

    for (int i = 0; i < s.length(); i++) {
        int x;
        std::from_chars(&s[i], &s[i] + 1, x);
        result.push_back(x);
    }

    return result;
}

int main(void) {
    assert_spans<int>(
        separate(2342),
        {2, 3, 4, 2},
        "example"
    );

    std::cout << "All tests passed!\n";
}
