#include "die.h"

Die::Die() : value(1), rng(std::random_device{}()), dist(1, 6) {}

// Rolls the die to generate a new value between 1 and 6
void Die::roll() {
    value = dist(rng);  // Generate a random number between 1 and 6
}

// Returns the current value of the die
int Die::get_value() const {
    return value;
}
