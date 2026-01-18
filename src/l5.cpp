// Write a function that computes the running total of a list.

#include <iostream>
#include <span>

#include "l-common.cpp"

int running_total(std::span<int> list) {
    int total = 0;

    for (const auto& v : list) {
        total += v;
    }

    return total;
}

int main(void) {
    int list[] = {1, 2, 3, -4, 5, -6, 7, 8};

    assert_one<int>(
        running_total(std::span{list}),
        16,
        "test1"
    );

    std::cout << "All tests passed!\n";
}
