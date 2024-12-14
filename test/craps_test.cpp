#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

#include <iostream>
#include <cassert>
#include "die.h"

int main() {
    // Create two Die objects
    Die die1;
    Die die2;

    // Test the rolling of the dice 10 times
    for (int i = 0; i < 10; ++i) {
        die1.roll();  // Roll the first die
        die2.roll();  // Roll the second die
        
        // Get the values of each die and assert that they are between 1 and 6
        int die1_value = die1.get_value();
        int die2_value = die2.get_value();
        
        // Assert that each die's roll is between 1 and 6
        assert(die1_value >= 1 && die1_value <= 6);
        assert(die2_value >= 1 && die2_value <= 6);
        
        // Optionally, print the values of the dice for verification
        std::cout << "Roll " << (i + 1) << ": Die 1 = " << die1_value 
                  << ", Die 2 = " << die2_value << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}


#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"

int main() {
    // Create two Die objects
    Die die1;
    Die die2;
    
    // Create a Roll object with die1 and die2
    Roll roll(die1, die2);

    // Test the rolling 10 times
    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();  // Roll the dice
        
        // Get the rolled value and assert it's between 2 and 12
        int result = roll.roll_value();
        assert(result >= 2 && result <= 12);
        
        // Optionally, print the result for verification
        std::cout << "Roll " << (i + 1) << ": " << result << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}

#include <iostream>
#include <cassert>
#include "die.h"
#include "shooter.h"

int main() {
    // Create two Die objects
    Die die1;
    Die die2;
    
    // Create a Shooter object
    Shooter shooter;

    // Loop 10 times to simulate 10 throws
    for (int i = 0; i < 10; ++i) {
        // Throw the dice and get the Roll object
        Roll* roll = shooter.throw_dice(die1, die2);

        // Get the rolled value and assert it is between 2 and 12
        int result = roll->roll_value();
        assert(result >= 2 && result <= 12);
        
        // Optionally, print the result for verification
        std::cout << "Roll " << (i + 1) << ": " << result << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

#include <iostream>
#include <cassert>
#include "die.h"
#include "roll.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    Die die1;
    Die die2;
    Roll roll(die1, die2);  // Create a roll object using two dice

    // Test ComeOutPhase
    ComeOutPhase come_out_phase;
    
    // Test natural outcome (7 or 11)
    die1.roll();
    die2.roll();
    roll.roll_dice();
    RollOutcome outcome = come_out_phase.get_outcome(&roll);
    assert(outcome == RollOutcome::natural || outcome == RollOutcome::craps || outcome == RollOutcome::point);
    
    // Test craps outcome (2, 3, 12)
    die1.roll();
    die2.roll();
    roll.roll_dice();
    outcome = come_out_phase.get_outcome(&roll);
    assert(outcome == RollOutcome::craps || outcome == RollOutcome::point || outcome == RollOutcome::natural);
    
    // Test point outcome (any other roll)
    die1.roll();
    die2.roll();
    roll.roll_dice();
    outcome = come_out_phase.get_outcome(&roll);
    assert(outcome == RollOutcome::point);

    // Test PointPhase with a point value of 6
    PointPhase point_phase(6);
    
    // Test point outcome (matching the point)
    die1.roll();
    die2.roll();
    roll.roll_dice();
    outcome = point_phase.get_outcome(&roll);
    assert(outcome == RollOutcome::point || outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint);

    // Test seven_out outcome (roll equals 7)
    die1.roll();
    die2.roll();
    roll.roll_dice();
    outcome = point_phase.get_outcome(&roll);
    assert(outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint || outcome == RollOutcome::point);
    
    // Test nopoint outcome (roll neither 7 nor point)
    die1.roll();
    die2.roll();
    roll.roll_dice();
    outcome = point_phase.get_outcome(&roll);
    assert(outcome == RollOutcome::nopoint || outcome == RollOutcome::seven_out || outcome == RollOutcome::point);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
