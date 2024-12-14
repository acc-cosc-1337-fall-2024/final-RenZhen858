#ifndef ROLL_H  // Header guard
#define ROLL_H

#include <random>  // For random number generation

class Roll {
public:
    // Constructor, initializes two dice with 6 sides (standard dice)
    Roll();

    // Rolls both dice and stores the result in rolled_value
    void roll_dice();

    // Returns the sum of the rolls from both dice
    int roll_value() const;

private:
    int die1_sides;      // Number of sides on the first die (6 for a standard die)
    int die2_sides;      // Number of sides on the second die (6 for a standard die)
    int rolled_value;    // Sum of the results from both dice

    // Helper method to simulate rolling a single die
    int roll_single_die(int sides);
};

#endif // ROLL_H
