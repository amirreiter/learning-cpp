// Write a guessing game where the user has to guess a secret number. After
// every guess the program tells the user whether their number was too large or
// too small. At the end the number of tries needed should be printed. It counts
// only as one try if they input the same number multiple times consecutively.

#include <iostream>
#include <unordered_set>
#include <random>

int main(void) {
    std::random_device rng;
    std::mt19937 gen(rng());
    std::uniform_int_distribution<int> dist(1, 100);

    int number = dist(gen);

    std::cout << "I'm thinking of a number between 1 and 100, can you guess ";
    std::cout << "it?! Don't worry, i'll give you hints!\n";

    std::unordered_set<int> guesses;

    while (true) {
        int guess_number = guesses.size() + 1;
        std::string input;

        std::cout << "[Guess " << guess_number << "] > ";
        std::cin >> input;

        int guess = std::stoi(input);
        if (guess == number) {
            std::cout << "You guessed my number in only " << guess_number;
            std::cout << " tries!\n";
            break;
        } else if (guess > number) {
            std::cout << "Hmm... my number is lower than that.\n";
        } else {
            std::cout << "Hmm... my number is higher than that.\n";
        }
        guesses.insert(guess);
    }
}
