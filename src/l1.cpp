// Write a function that returns the largest element in a list.

#include <iostream>
#include <climits>
#include <span>

#include "l-common.cpp"

// Span is like rust slices, but is only available starting in C++20;
int largest(std::span<const int> span) {
    int largest = INT_MIN;
    for (int i = 0; i < span.size(); i++) {
        int current = span[i];
        if (current > largest) {
            largest = current;
        }
    }
    return largest;
}

int main(void) {
    int test1[] = {1, 2, 3, 4, 5};
    assert_one(
        largest(std::span<const int>{test1}),
        5,
        "test1"
    );

    int test2[] = {5, -24, 239, 1, 2, -34, 34};
    assert_one(
        largest(std::span<const int>{test2}),
        239,
        "test2"
    );

    std::cout << "All tests passed!\n";
}
