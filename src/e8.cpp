// Write a program that prints all prime numbers.

// Hmm, what does "all" mean? I'll just go with a program that could find *any*
// prime number. I suppose you could just remove n and do i++ until int limit is
// reached.

#include <iostream>

// Is this algorithm inefficient?
// Yes.
// Is the algorithm the purpose of this exercise?
// Nope!
bool is_prime(int a) {
    for (int i = 2; i < a / 2 + 1; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n = 100;

    for (int i = 1; i < n; i++) {
        if (is_prime(i)) {
            std::cout << i << " is a prime number!\n";
        }
    }
}
