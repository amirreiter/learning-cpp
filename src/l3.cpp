// Write a function that checks whether an element occurs in a list.

#include <iostream>
#include <span>

#include "l-common.cpp"

bool occurs_in_list(std::span<int> list, int search) {
    for (const auto& i : list) {
        if (i == search) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int haystack[] = {1, 2, 3, -4, 5, -6, 7, 8, -9, 10};
    std::span haystack_span = std::span{haystack};

    assert_one(
        occurs_in_list(haystack_span, 1),
        true,
        "test1"
    );

    assert_one(
        occurs_in_list(haystack_span, 4),
        false,
        "test2"
    );

    std::cout << "All tests passed!\n";
}
