#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    // Constructor that accepts references to two Die objects
    Roll(Die& die1, Die& die2);
    
    // Rolls the dice and saves the rolled value to the private member
    void roll_dice();
    
    // Returns the sum of the values rolled by die1 and die2
    int roll_value() const;

private:
    Die& die1;             // Reference to the first die
    Die& die2;             // Reference to the second die
    int rolled_value;      // Stores the result of the dice roll
};

#endif // ROLL_H

