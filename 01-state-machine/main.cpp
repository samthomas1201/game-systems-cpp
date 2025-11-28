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
    switch(state) {
        case PlayerState::Idle : return "Idle";
        case PlayerState::Walking : return "Walking";
        case PlayerState::Running : return "Running";
        case PlayerState::Jumping : return "Jumping";
    }
    return "Unknown State";
}

int main() {
    /*This variable sets the starting state of the player at Idle
    which makes sense because when you first spawn in you have no input or animations yet
    */
   PlayerState currentState = PlayerState::Idle;

   /*this is a flag used to control the main loop for 
   the game continuing or breaking out of the loop and ending the program*/
   bool isRunning = true;

   /*main game tool to let players know how to interact
   in a fully fleshed out game this would be UI text
   */
   std::cout << "Simple Player State Machine\n";
   std::cout << "Commands:\n";
   std::cout << "w - Walk\n";
   std::cout << "r - Run\n";
   std::cout << "j - Jump\n";
   std::cout << "s - Stop (Idle)\n";
    std::cout << "q - Quit\n";

    /*the main game loop
    this loop will continue until the isRunning flag
    is set to false by the user inputting 'q' to quit the program
    the loop is in 4 different parts:
    1. check input
    2. update state based on input
    3. display current state
    4. repeat
    */

    while (running) {
        std::cout << "Current State: " << stateToString(currentState) << "\n";
        std::cout << "Enter command: ";
        char cmd;
        std::cin >> cmd;

        switch(cmd) {
            case 'w': 
            //walking command 
            if (currentState == PlayerState::Idle) {
                std::cout << "Transition: Idle -> Walking\n";
                currentState = PlayerState::Walking;
            } else { 
                std::cout << "Cannot walk from current state.\n";
            } 
            break;
            case 'r':
            //running command
            if (currentState == PlayerState::Walking) {
                std:cout << "Transition: Walking -> Running\n";
                currentState = PlayerState::Running;
            } else {
                std::cout << "Cannot run from current state.\n";
            } break;

            case "j":
            //jumping command
            if (currentState == PlayerState::Idle) {
                std::cout << "Transition: Idle -> Jumping\n";
                currentState = PlayerState::Jumping;
            } else if (currentState == PlayerState::Walking) {
                std::cout << "Transition: Walking -> Jumping\n";
                currentState = PlayerState::Jumping;
            }else if (currentState == PlayerState::Running) {
                std::cout << "Transition: Running -> Jumping";
                currentState = PlayerState::Jumping;
            } else {
                std::cout << "Cannot jump from current state.\n";
            }
            break;
            case 's':
            //stop command
            if (currentState == PlayerState::Walking || currentState == PlayerState::Running || currentState == PlayerState::Jumping) {
                std::cout << "Transition to Idle\n";
                currentState = PlayerState::Idle;
            } else {
                std::cout << "Already in Idle state.\n";
            } break;

            case 'q':
            //quit command
            std::cout << "End program.\n";
            isRunning = false;
            break;
            }

            default: {
                std::cout << "Invalid command.\n";
            }
            std::cout << "\n";
        }
        return 0;
    }
        
    
