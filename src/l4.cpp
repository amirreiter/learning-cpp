// Write a function that returns the elements on odd positions in a list.

#include <iostream>
#include <span>

#include "l-common.cpp"

std::vector<int> get_odd_indicies(std::span<int> list) {
    std::vector<int> result;
    result.reserve(list.size() / 2);

    for (int i = 0; i < list.size(); i += 2) {
        result.push_back(list[i]);
    }

    return result;
}

int main(void) {
    int list1[] = {1, 2, 3, -4, 5, -6, 7, 8, -9, 10};
    std::span list1_span = std::span{list1};

    auto test1 = get_odd_indicies(list1_span);
    assert_spans<int>(
        std::span{test1},
        {1, 3, 5, 7, -9},
        "test1"
    );

    int list2[] = {1, 2, 3, -4, 5, -6, 7, 8, -9, 10, 11};
    std::span list2_span = std::span{list2};

    auto test2 = get_odd_indicies(list2_span);
    assert_spans<int>(
        std::span{test2},
        {1, 3, 5, 7, -9, 11},
        "test2"
    );

    std::cout << "All tests passed!\n";
}
