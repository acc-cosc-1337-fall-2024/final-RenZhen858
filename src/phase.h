#ifndef PHASE_H
#define PHASE_H

#include "roll.h"  // Include Roll class header for using Roll pointer

// Enum to represent the outcomes of a roll
enum class RollOutcome {
    natural,
    craps,
    point,
    seven_out,
    nopoint
};

// Abstract Phase class
class Phase {
public:
    virtual RollOutcome get_outcome(Roll* roll) = 0;  // Pure virtual function
    virtual ~Phase() = default;  // Virtual destructor
};

#endif // PHASE_H
