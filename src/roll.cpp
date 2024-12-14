#include "Roll.h"

Roll::Roll() : die1_sides(6), die2_sides(6), rolled_value(0) {}

void Roll::roll_dice() {
    // Roll both dice and store the sum in rolled_value
    rolled_value = roll_single_die(die1_sides) + roll_single_die(die2_sides);
}

// Helper method to simulate rolling a single die
int Roll::roll_single_die(int sides) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, sides);
    return dis(gen);  // Return the randomly generated number for the die roll
}

int Roll::roll_value() const {
    return rolled_value;  // Return the sum of both dice rolls
}
