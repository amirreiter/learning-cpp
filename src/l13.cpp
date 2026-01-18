// Write a function that computes the list of the first 100 Fibonacci numbers.
// The first two Fibonacci numbers are 1 and 1. The n+1-st Fibonacci number can
// be computed by adding the n-th and the n-1-th Fibonacci number. The first few
// are therefore 1, 1, 1+1=2, 1+2=3, 2+3=5, 3+5=8.

// This seems like an incorrect definition of fibonacci sequence. As far as I
// can tell 0, 1— not 1, 1

#include <iostream>
#include <span>

#include "l-common.cpp"

std::vector<float> fibonacci(int n) {
    std::vector<float> fibs;
    fibs.reserve(100);
    fibs.push_back(1);
    fibs.push_back(1);

    for (int i = 1; i < n - 1; i++) {
        fibs.push_back(fibs[i] + fibs[i - 1]);
    }

    return fibs;
}

int main(void) {
    std::vector<float> fibs = fibonacci(100);

    std::cout << fibs.size() << "\n";

    assert_one<float>(
        fibs[99],
        354224848179261915075.0,
        "fib #100"
    );

    std::cout << "All tests passed!\n";
}
