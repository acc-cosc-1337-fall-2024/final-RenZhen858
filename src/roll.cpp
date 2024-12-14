#include "roll.h"

// Constructor that initializes the references to the two die objects
Roll::Roll(Die& die1, Die& die2) : die1(die1), die2(die2), rolled_value(0) {}

// Rolls the dice and stores the rolled value (sum of both dice)
void Roll::roll_dice() {
    die1.roll();    // Roll the first die
    die2.roll();    // Roll the second die
    rolled_value = die1.get_value() + die2.get_value();  // Sum the results of both dice
}

// Returns the sum of the dice values
int Roll::roll_value() const {
    return rolled_value;
}
