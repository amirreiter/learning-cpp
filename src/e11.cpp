// Write a program that computes the sum of an alternating series where each
// element of the series is an expression of the form ((−1)k+1)/(2*k−1) for each
// value of k from 1 to a million, multiplied by 4.

#include <iostream>
#include <cmath>

int main(void) {
    float sum = 0.0;

    for (float i = 1.0; i < 1000000.0; i += 1.0) {
        sum += (powf(-1.0, i + 1.0)/(2.0 * i - 1.0));
    }

    // Oh look its a neat little pi approximation!
    std::cout << sum * 4.0 << "\n";
}
