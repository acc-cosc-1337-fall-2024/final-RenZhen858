#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase {
public:
    PointPhase(int p);  // Constructor to set the point value
    RollOutcome get_outcome(Roll* roll) override;

private:
    int point;  // Store the point value
};

#endif // POINT_PHASE_H
