#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h"

class ComeOutPhase : public Phase {
public:
    // No constructor needed as there are no additional parameters
    RollOutcome get_outcome(Roll* roll) override;
};

#endif // COME_OUT_PHASE_H

