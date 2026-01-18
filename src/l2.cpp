// Write function that reverses a list, preferably in place.

#include <iostream>
#include <span>
#include <vector>

#include "l-common.cpp"

void reverse_in_place(std::span<int> list) {
    int len = list.size();
    int last_index = len - 1;

    int a;
    int b;

    for (int i = 0; i < len / 2; i++) {
        a = list[i];
        b = list[last_index - i];

        list[i] = b;
        list[last_index - i] = a;
    }
}

int main(void) {
    int test_odd[] = {1, 2, 3, 4, 5};
    reverse_in_place(std::span{test_odd});
    assert_spans<int>(
        std::span{test_odd},
        {5, 4, 3, 2, 1},
        "Odd"
    );

    int test_even[] = {1, 2, 3, 4};
    reverse_in_place(std::span{test_even});
    assert_spans<int>(
        std::span{test_even},
        {4, 3, 2, 1},
        "Even"
    );

    int test_tiny_even[] = {1, 2};
    reverse_in_place(std::span{test_tiny_even});
    assert_spans<int>(
        std::span{test_tiny_even},
        {2, 1},
        "Tiny Even"
    );

    int test_odd_one[] = {1};
    reverse_in_place(std::span{test_odd_one});
    assert_spans<int>(
        std::span{test_odd_one},
        {1},
        "Odd One"
    );

    std::vector<int> test_zero;
    reverse_in_place(std::span{test_zero});
    assert_spans<int>(
        std::span{test_zero},
        {},
        "Zero"
    );

    std::cout << "All tests passed!\n";
}
