// Write a function that combines two lists by alternatingly taking elements,
// e.g. [a,b,c], [1,2,3] → [a,1,b,2,c,3].

#include <iostream>
#include <span>
#include <vector>

#include "l-common.cpp"

template <typename T>
std::vector<T> zip(std::span<T> a, std::span<T> b) {
    int size_a = a.size();
    int size_b = b.size();
    int total_elements = size_a + size_b;

    std::vector<T> result;
    result.reserve(total_elements);

    int i_a = 0;
    int i_b = 0;
    for (int i = 0; i < total_elements; i++) {
        // if A is unfinished
        if (i_a < size_a) {
            result.push_back(a[i_a]);
            i_a += 1;
        }

        // if B is also unfinished
        if (i_b < size_b) {
            result.push_back(b[i_b]);
            i_b += 1;
        }
    }

    return result;
}

int main(void) {
    int list1[] = {1, 2, 3};
    int list2[] = {4, 5, 6};
    std::vector<int> result1a = zip<int>(
        std::span{list1},
        std::span{list2}
    );

    assert_spans<int>(
        result1a,
        {1, 4, 2, 5, 3, 6},
        "integers"
    );

    std::vector<int> result1b = zip<int>(
        std::span{list2},
        std::span{list1}
    );

    assert_spans<int>(
        result1b,
        {4, 1, 5, 2, 6, 3},
        "integers opposite"
    );

    char list3[] = {'a', 'b', 'c'};
    char list4[] = {'d', 'e', 'f'};
    std::vector<char> result2 = zip<char>(
        std::span{list3},
        std::span{list4}
    );

    assert_spans<char>(
        result2,
        {'a', 'd', 'b', 'e', 'c', 'f'},
        "chars"
    );

    int list5[] = {1, 2, 3, 4, 5, 6};
    int list6[] = {7, 8};
    std::vector<int> result3a = zip<int>(
        std::span{list5},
        std::span{list6}
    );

    assert_spans<int>(
        result3a,
        {1, 7, 2, 8, 3, 4, 5, 6},
        "chars"
    );

    std::vector<int> result3b = zip<int>(
        std::span{list6},
        std::span{list5}
    );

    assert_spans<int>(
        result3b,
        {7, 1, 8, 2, 3, 4, 5, 6},
        "chars"
    );

    std::cout << "All tests passed!\n";
}
