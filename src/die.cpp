#include "die.h"

Die::Die() : sides(6) {  // Constructor initializing sides to 6
    // No additional initialization needed
}

int Die::roll() {
    // Create a random engine and uniform distribution between 1 and 6
    std::random_device rd;   // Get a random seed from hardware
    std::mt19937 gen(rd());  // Initialize the random engine with the seed
    std::uniform_int_distribution<> dis(1, 6); // Range between 1 and 6
    return dis(gen);  // Generate and return the random number
}
