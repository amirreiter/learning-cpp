// Write a function that rotates a list by k elements. For example [1,2,3,4,5,6]
// rotated by two becomes [3,4,5,6,1,2]. Try solving this without creating a
// copy of the list. How many swap or move operations do you need?

#include <iostream>
#include <span>
#include <utility>

#include "l-common.cpp"

// s=0
// r=2
// [1, 2, 3, 4, 5, 6]
//
// [3, 2, 1, 4, 5, 6] Swap 1&3
// [3, 4, 1, 2, 5, 6] Swap 2&4
// [3, 4, 5, 2, 1, 6] Swap 5&1
// [3, 4, 5, 6, 1, 2] Swap 6&2
//
// [3, 4, 5, 6, 1, 2] Correct
//
// Conclusion:
// Doing a swap with size of r and moving down the line seems to work!
// Pretty cool.
void rotate_in_place(std::span<int> list, int r) {
    int length = list.size();

    int head = r;
    int stop = length;

    while (head < stop) {
        std::swap(list[head], list[head - r]);

        head++;
    }
}

int main(void) {
    int list[] = {1, 2, 3, 4, 5, 6};

    rotate_in_place(std::span{list}, 2);

    assert_spans<int>(
        std::span{list},
        {3, 4, 5, 6, 1, 2},
        "example"
    );

    std::cout << "All tests passed!\n";
}
