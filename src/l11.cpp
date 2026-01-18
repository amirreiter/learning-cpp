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

    int ia = 0;
    int ib = 0;

    while (result.size() < result.capacity()) {
        if (ia < size_a)  {
            int va = a[ia];

            if (ib < size_b) {
                int vb = b[ib];

                if (va < vb) {
                    result.push_back(va);
                    ia += 1;
                } else {
                    result.push_back(vb);
                    ib += 1;
                }
            } else {
                result.push_back(va);
                ia += 1;
            }
        } else {
            if (ib < size_b) {
                int vb = b[ib];
                result.push_back(vb);
                ib += 1;
            } else {
                break;
            }
        }
    }

    return result;
}

int main(void) {
    int list1[] = {1, 4, 6};
    int list2[] = {2, 3, 5};

    std::vector<int> test1 = merge_sorted(std::span{list1}, std::span{list2});

    assert_spans<int>(
        std::span{test1},
        {1, 2, 3, 4, 5, 6},
        "example"
    );

    int list3[] = {1, 5, 6};
    int list4[] = {2, 3, 4, 7, 8, 9, 10};

    std::vector<int> test2 = merge_sorted(std::span{list3}, std::span{list4});

    assert_spans<int>(
        std::span{test2},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        "uneven 1"
    );

    std::vector<int> test3 = merge_sorted(std::span{list4}, std::span{list3});

    assert_spans<int>(
        std::span{test3},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        "uneven 2"
    );

    std::cout << "All tests passed!\n";
}
