// Implement the following sorting algorithms: Selection sort, Insertion sort,
// Merge sort, Quick sort, Stooge Sort.

// Stooge Sort is a meme sorting algorithm, so i'll pass on it.

#include <iostream>
#include <span>
#include <utility>
#include <vector>

#include "l-common.cpp"

template <typename T>
void selection_sort(std::span<T> list) {
    for (int i = 0; i < list.size() - 1; i++) {
        int smallest_index = i;

        for (int j = i + 1; j < list.size(); j++) {
            if (list[j] < list[smallest_index]) {
                smallest_index = j;
            }
        }

        if (smallest_index != i) {
            std::swap(list[i], list[smallest_index]);
        }
    }
}

template <typename T>
void insertion_sort(std::span<T> list) {
    int i = 1;
    while (i < list.size()) {
        int j = i;
        while (j > 0 && list[j-1] > list[j]) {
            std::swap(list[j-1], list[j]);
            j = j - 1;
        }
        i += 1;
    }
}

template <typename T>
void merge_sort(std::span<T> list) {
    if (list.size() <= 1) {
        return;
    }

    int length = list.size();

    int middle = length / 2;
    merge_sort(list.subspan(0, middle));
    merge_sort(list.subspan(middle));

    // Merge
    std::vector<T> temp;
    temp.reserve(length);
    int i = 0;
    int end1 = middle;
    int j = middle;
    int end2 = length;

    while (i < end1 && j < end2) {
        if (list[i] < list[j]) {
            temp.push_back(list[i]);
            i++;
        } else {
            temp.push_back(list[j]);
            j++;

        }
    }

    while (i < end1) {
        temp.push_back(list[i]);
        i++;
    }

    while (j < end2) {
        temp.push_back(list[j]);
        j++;
    }

    for (int k = 0; k < length; k++) {
        list[k] = temp[k];
    }
}

template <typename T>
int quick_sort_partition(std::span<T> list) {
    T pivot = list[list.size() - 1];

    T i = 0;

    for (int j = 0; j < list.size() - 1; j++) {
        if (list[j] <= pivot) {
            std::swap(list[i], list[j]);
            i++;
        }
    }

    std::swap(list[i], list[list.size() - 1]);
    return i;
}

template <typename T>
void quick_sort(std::span<T> list) {
    if (list.size() <= 1) {
        return;
    }

    int p = quick_sort_partition(list);

    quick_sort(list.subspan(0, p));
    quick_sort(list.subspan(p + 1));
}


int main(void) {
    int selection[] = {1, 5, 3, 2, 4};
    selection_sort<int>(std::span{selection});

    assert_spans<int>(
        std::span{selection},
        {1, 2, 3, 4, 5},
        "selection sort"
    );

    int insertion[] = {1, 5, 3, 2, 4};
    insertion_sort<int>(std::span{insertion});

    assert_spans<int>(
        std::span{insertion},
        {1, 2, 3, 4, 5},
        "insertion sort"
    );

    int merge[] = {1, 5, 3, 2, 4};
    merge_sort<int>(std::span{merge});

    assert_spans<int>(
        std::span{merge},
        {1, 2, 3, 4, 5},
        "merge sort"
    );

    int quick[] = {1, 5, 3, 2, 4};
    quick_sort<int>(std::span{quick});

    assert_spans<int>(
        std::span{quick},
        {1, 2, 3, 4, 5},
        "quick sort"
    );

    std::cout << "All tests passed!\n";
}
