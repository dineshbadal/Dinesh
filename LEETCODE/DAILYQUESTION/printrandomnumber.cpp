#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator with the current time
    // This ensures a different sequence of random numbers each time the program runs
    srand(time(0));

    // Generate a random integer
    // rand() returns a pseudo-random integer between 0 and RAND_MAX
    int randomNumber = rand();

    // Print the random number
    std::cout << "Random number: " << randomNumber << std::endl;

    // To generate a random number within a specific range (e.g., 1 to 100):
    // int min = 1;
    // int max = 100;
    // int randomNumberInRange = min + (rand() % (max - min + 1));
    // std::cout << "Random number (1-100): " << randomNumberInRange << std::endl;

    return 0;
}