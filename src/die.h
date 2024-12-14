#ifndef DIE_H
#define DIE_H

#include <random>

class Die {
public:
    // Constructor to initialize the die
    Die();
    
    // Rolls the die and stores the rolled value
    void roll();
    
    // Returns the current value of the die
    int get_value() const;

private:
    int value;   // Stores the current value of the die
    std::mt19937 rng;  // Random number generator
    std::uniform_int_distribution<int> dist;  // Distribution for die roll (1-6)
};

#endif // DIE_H
