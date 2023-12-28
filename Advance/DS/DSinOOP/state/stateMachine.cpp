//https://www.youtube.com/watch?v=Qw0ekxFLMmI
/*
Implementation
- Use enum type to record current state
    enum TState {InActive, Loaded, Firing, Reload};
    TState currentState = InActive;
- If statements to check current state and implement transitions
    if(currentState == InActive && mounted)
        currentState = Loaded;
*/

/*Non object-oriented approach using conditional statements and enums
    enum TStates {InActive, Loaded, Firing, Reload}; 
    int rounds;
    bool mounted; //global variable

    TStates CheckState (TStates currentState) {
        if (currentState == InActive && mounted)
            currentState = Loaded;
            else if (currentState == Loaded && rounds > 0)
            currentState = Firing;
            else if (currentState == Loaded && !mounted)
            currentState == InActive;
            else if (currentState == Firing && rounds == 0)
            currentState = Reload;
            else if (currentState == Firing && !mounted)
            currentState = InActive;
            else if (currentState == Reload && rounds > 0)
            currentState = Loaded;
            return currentState;
        }

    int main() {
        TStates weaponState = InActive;
        rounds = 10;
        mounted = true;
        weaponState = CheckState(weaponState);
        return 0;
    }
*/

/* Call-backs
- Sometimes it is necessary to execute code when a transition occurs
- The statements to be executed could be placed within a call-back function
    void OnFile() {
        rounds--;
    }
    if(currentState == Loaded && rounds > 0) {
        currentState = Firing;
        OnFile();
    }
*/

/* Disadvantages:
    - Its easy to introduce invalid transitions
    - Code may not be centralized and therefore difficult to manage
    - Poor readability and extensibility

Object Approach:
An alternative approach would be to
    • Represent States as Objects.
    • Represent Transitions as Objects.
    • Guards as Functions.
    • The guard function return a bool value to determine if a transition should take place.
    • Each state object is assigned an enum value
    • Each state object would have a list of one or more transitions.

Guard Function
    - Each transition has a pointer to a guard function
    - The Guard determines if the transition can take place
    - The guard function are centrally located in the Bulb object

    OffToOn ---> Bulb
        bool Bulb :: GuardOnToBroken() {
            return voltage > 300;
        }

    Check Guard
        - If the current state is On
        - Iterator through the Linked List checking the transition's guards
        On ----> OnToOff -----> OnToBroken -----> NULL
                    |               |
                          Bulb
    bool Bulb :: GuardOnToOff() {       bool Bulb :: GuardOnToBroken() {                     
        return voltage == 0;                return voltage > 300;
    }                                   }

*/

#include <iostream>
#include "Bulb.h"
#include "FSM.h"
#include "LinkedList.h"
#include "Transition.h"
#include "State.h"

using namespace std;

int main() {
    cout << "======= W8 State Machines =========\n";
    cout << "======= Example ==========\n";

    Bulb* bulb = new Bulb();
    bulb->Update();
    bulb->voltage = 0;
    bulb->Update();
    bulb->voltage = 240;
    bulb->Update();
    bulb->voltage = 500;
    bulb->Update();
    system("pause");

    return 0;
}