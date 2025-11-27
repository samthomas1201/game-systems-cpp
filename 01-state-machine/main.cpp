//headers for the state machine file
#include <iostream>
#include <string>

/*
Use an enumerated class to use regular naming conventions over defining a player
state as an integer.
an example of this would be int state = 0; which would mean Idle but alot easier to create your own variable with the 
value of "Idle" or "Walking" or "Jumping"*/
enum class PlayerState {
    Idle,
    Walking,
    Running,
    Jumping
};

/*
This function converts the enumerated values to text
we do this because we cannot directly print an enum with std::cout
using a switch case for each is the best method*/
std::string stateToString(PlayerState state) {
    switch(state)
}
}