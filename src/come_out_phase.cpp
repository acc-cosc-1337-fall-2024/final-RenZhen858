#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    int roll_value = roll->roll_value();

    if (roll_value == 7 || roll_value == 11) {
        return RollOutcome::natural;  // Natural: Win with 7 or 11
    }
    else if (roll_value == 2 || roll_value == 3 || roll_value == 12) {
        return RollOutcome::craps;  // Craps: Lose with 2, 3, or 12
    }
    else {
        return RollOutcome::point;  // Any other roll becomes the point
    }
}
