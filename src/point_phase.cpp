#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int roll_value = roll->roll_value();

    if (roll_value == point) {
        return RollOutcome::point;  // Win if roll matches the point
    }
    else if (roll_value == 7) {
        return RollOutcome::seven_out;  // Lose if roll is 7
    }
    else {
        return RollOutcome::nopoint;  // Continue if roll doesn't match the point or 7
    }
}
