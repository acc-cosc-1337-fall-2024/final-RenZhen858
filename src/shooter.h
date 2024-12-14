#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h"  // Include the Roll class header

class Shooter {
public:
    // Method to throw dice and return a dynamic Roll object
    Roll* throw_dice(Die& die1, Die& die2);
    
    // Method to display the rolled values of all rolls
    void display_rolled_values() const;
    
    // Destructor to clean up dynamically allocated memory
    ~Shooter();
    
private:
    std::vector<Roll*> rolls;  // Vector to store Roll objects
};

#endif // SHOOTER_H
