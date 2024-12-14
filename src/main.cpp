#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "die.h"    // Include Die class
#include "roll.h"   // Include Roll class
#include "shooter.h" // Include Shooter class
#include "come_out_phase.h" // Include ComeOutPhase class
#include "point_phase.h"  // Include PointPhase class

int main() {
    // Seed the random number generator
    srand(time(0));

    // Create two instances of Die
    Die die1;
    Die die2;

    // Create a Shooter instance
    Shooter shooter;

    // Create a pointer to Roll and get the return value from the shooter
    Roll* roll = shooter.throw_dice(die1, die2);
    int rolled_value = roll->roll_value();

    // Create an instance of ComeOutPhase
    ComeOutPhase come_out_phase;

    // Loop until a valid roll outcome is reached (not natural or craps)
    while (come_out_phase.get_outcome(roll) == RollOutcome::natural || 
           come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        // Display the rolled value and prompt to roll again
        std::cout << "Rolled " << rolled_value << " - Roll again" << std::endl;

        // Get the next roll from the shooter
        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    // Outside the loop, indicate the start of the Point Phase
    std::cout << "Rolled " << rolled_value << " - Start of point phase" << std::endl;
    std::cout << "Roll until " << rolled_value << " or a 7 is rolled" << std::endl;

    // Set the point value to the current roll value
    int point = rolled_value;

    // Get the next roll from the shooter for the Point Phase
    roll = shooter.throw_dice(die1, die2);
    rolled_value = roll->roll_value();

    // Create an instance of PointPhase
    PointPhase point_phase(point);

    // Loop for the Point Phase, rolling until point or 7 is rolled
    while (point_phase.get_outcome(roll) != RollOutcome::seven_out && 
           point_phase.get_outcome(roll) != RollOutcome::nopoint) {
        // Display the rolled value and prompt to roll again
        std::cout << "Rolled " << rolled_value << " - Roll again" << std::endl;

        // Get the next roll from the shooter
        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->roll_value();
    }

    // Outside the loop, display the end of the Point Phase
    std::cout << "Rolled " << rolled_value << " - End of point phase" << std::endl;

    // Display the rolled values
    std::cout << "Rolled values:" << std::endl;
    std::cout << rolled_value << std::endl;

    return 0;
}
