#pragma once
class State;

class Transition {
public:
    State* fromState;
    GP guardFunction;
    Bulb* guardLocation;
    Transition* next;
    State* toState;

};

Transition(State* from, State* to, GP guardFunction, Bulb* guardLocation) {
    this->fromState = from;
    this->toState = to;
    this->guardFunction = guardFunction;
    this->guardLocation = guardLocation;
}

bool InvokeGuard() {
    if(guardFunction !=0 && guardLocation!=0) {
        return (guardLocation->*guardFunction)
    }
    return false;
}

State* GetToState() {
    return toState;
}