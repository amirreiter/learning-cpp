// Write a program that prints the next 20 leap years.

// A leap year is defined as once every year divisible by 4, except
// centurial years that are not evenly divisible by 400

#include <iostream>
#include <chrono>

int main(void) {
    // Fetch the current year, because why not?
    std::chrono::time_point<std::chrono::system_clock> now =
            std::chrono::system_clock::now();

    std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm* tm = std::localtime(&t);

    int year = tm->tm_year + 1900;
    int leap_counter = 0;

    while (leap_counter < 20) {
        bool is_leap = false;
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    is_leap = true;
                }
            } else {
                is_leap = true;
            }
        }

        if (is_leap) {
            std::cout << year << " is a leap year.\n";
            leap_counter++;
        }
        year++;
    }
}
