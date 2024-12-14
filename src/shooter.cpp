#include "shooter.h"
#include <iostream>

using namespace std;

// Method to throw the dice, create a new Roll object, and store it in the vector
Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    // Create a new Roll object dynamically
    Roll* new_roll = new Roll(die1, die2);
    
    // Call the roll_dice method to roll the dice and store the result
    new_roll->roll_dice();
    
    // Add the new Roll object to the vector
    rolls.push_back(new_roll);
    
    // Return the Roll object
    return new_roll;
}

// Method to display all rolled values stored in the rolls vector
void Shooter::display_rolled_values() const {
    for (auto roll : rolls) {
        cout << "Rolled value: " << roll->roll_value() << endl;
    }
}

// Destructor to clear dynamically allocated memory
Shooter::~Shooter() {
    for (auto roll : rolls) {
        delete roll;  // Deallocate memory for each Roll object
    }
    rolls.clear();  // Clear the vector
}
