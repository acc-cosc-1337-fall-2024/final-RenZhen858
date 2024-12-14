#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

#include <iostream>
#include <cassert>
#include "die.h"

int main() {
    Die die;

    // Roll the die 10 times and assert each roll is between 1 and 6
    for (int i = 0; i < 10; ++i) {
        int result = die.roll();
        assert(result >= 1 && result <= 6);  // Assert the result is within the valid range
        std::cout << "Roll " << (i + 1) << ": " << result << std::endl;
    }

    std::cout << "All die rolls are within the valid range!" << std::endl;
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
