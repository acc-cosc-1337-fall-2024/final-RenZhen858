#ifndef DIE_H  // Header Guard
#define DIE_H
#include <random>  // To use random number generation

class Die {
public:
    // Constructor, initializes sides to 6
    Die();

    // roll() function to return a random number between 1 and 6
    int roll();

private:
    int sides;  // The number of sides on the die (defaulted to 6)
};

#endif // DIE_H
