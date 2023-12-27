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
    bool mounted;
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

*/
void OnFile() {
    rounds--;
}
if(currentState == Loaded && rounds > 0) {
    currentState = Firing;
    OnFile();
}
