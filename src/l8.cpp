// Write a function on_all that applies a function to every element of a list.
// Use it to print the first twenty perfect squares. The perfect squares can be
// found by multiplying each natural number with itself. The first few perfect
// squares are 1*1= 1, 2*2=4, 3*3=9, 4*4=16. Twelve for example is not a perfect
// square because there is no natural number m so that m*m=12.

#include <iostream>
#include <span>

#include "l-common.cpp"

template <typename F>
void for_each(std::span<int> list, F func) {
    for (auto& v : list) {
        v = func(v);
    }
}

int square(int x) {
    return x * x;
}

int main(void) {
    int list[20] = {};
    for (int i = 1; auto& v : list) {
        v = i;
        i++;
    }

    for_each(list, square);

    assert_spans<int>(
        std::span{list},
        {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256,
            289, 324, 361, 400},
        "test1"
    );

    std::cout << "All tests passed!\n";
}
