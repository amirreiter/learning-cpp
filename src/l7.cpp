// Write three functions that compute the sum of the numbers in a list: using a
// for-loop, a while-loop and recursion.

#include <iostream>
#include <span>

#include "l-common.cpp"

int sum_for(std::span<int> list) {
    int sum = 0;

    for (const auto& v : list) {
        sum += v;
    }

    return sum;
}

int sum_while(std::span<int> list) {
    int sum = 0;

    int i = 0;
    while (i < list.size()) {
        sum += list[i];

        i++;
    };

    return sum;
}

int sum_recursive(std::span<int> list, int index) {
    if (index >= list.size()) {
        return 0;
    }

    return list[index] + sum_recursive(list, index + 1);
}

int main(void) {
    int list[] = {1, 2, 3, 4, 5};

    int result_for = sum_for(std::span{list});
    int result_while = sum_while(std::span{list});
    int result_recursive = sum_recursive(std::span{list}, 0);

    assert_one(
        result_for == result_while && result_while == result_recursive,
        true,
        "test1"
    );

    std::cout << "All tests passed!\n";
}
