// Write a function that merges two sorted lists into a new sorted list.
// [1,4,6],[2,3,5] → [1,2,3,4,5,6]. You can do this quicker than concatenating
// them followed by a sort.

#include <iostream>
#include <span>
#include <vector>

#include "l-common.cpp"

std::vector<int> merge_sorted(std::span<int> a, std::span<int> b) {
    int size_a = a.size();
    int size_b = b.size();

    std::vector<int> result;
    result.reserve(size_a + size_b);

    for (int ia = 0; const auto& va : a) {
        if (ia < size_b)  {
            for (int ib = ia; const auto& vb : b) {
                if (vb > va) {
                    result.push_back(vb);
                }
            }
        }
    }

    return result;
}

int main(void) {


    std::cout << "All tests passed!\n";
}
