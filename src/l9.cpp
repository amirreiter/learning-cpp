// Write a function that concatenates two lists.
// [a,b,c], [1,2,3] → [a,b,c,1,2,3]

// C++ is statically typed so some decision would need to be made on what the
// final type would be if int[] was appended to char[]. Instead, I will enforce
// they be the same type, at least.

#include <iostream>
#include <span>
#include <vector>

#include "l-common.cpp"

template <typename T>
std::vector<T> concat(std::span<T> a, std::span<T> b) {
    std::vector<T> result;
    result.reserve(a.size() + b.size());

    for (const auto& v : a) {
        result.push_back(v);
    }

    for (const auto& v : b) {
        result.push_back(v);
    }

    return result;
}

int main(void) {
    int list1[] = {1, 2, 3};
    int list2[] = {4, 5, 6};
    std::vector<int> result1 = concat<int>(
        std::span{list1},
        std::span{list2}
    );

    assert_spans<int>(
        result1,
        {1, 2, 3, 4, 5, 6},
        "integers"
    );

    char list3[] = {'a', 'b', 'c'};
    char list4[] = {'d', 'e', 'f'};
    std::vector<char> result2 = concat<char>(
        std::span{list3},
        std::span{list4}
    );

    assert_spans<char>(
        result2,
        {'a', 'b', 'c', 'd', 'e', 'f'},
        "chars"
    );

    std::cout << "All tests passed!\n";
}
