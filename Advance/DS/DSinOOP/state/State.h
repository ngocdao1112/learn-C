#pragma once
#include "Bulb.h"
#include "stdafx.h"
#include "Transition.h"
#include "LinkedList.h"

class State {
public:
    CBP callBack;
    Bulb* callBackLocation;
    State* next;
    TState state;
    LinkedList<Transition>* transition;

    State(TStates state) {
        this->state = state;
    }

    State(TStates state, CBP callBack, Bulb* callBackLocation) {
        this->state = state;
        this->callBack = callBack;
        this->callBackLocation = callBackLocation;
        transitions = new LinkedList<Transition>();
        next = 0;
    }

    bool operator != (State& rhd) {
        return (this->state != rhd.state);
    }

    bool operator == (State& rhd) {
        return (this->state == rhd.state);
    }

    void AddTransition(State* from* to, GP guard, Bulb* guardLocation) {
        transitions->Insert(new Transition(from, to, guardLocation));
    }
    void InvokeCallBack() {
        (callBackLocation->*callBack)();
    }
    State* CheckGuards(bool* changed) {
        for(int n=0; n < transitions->Count(); n++) {
            //can not overload pointer operators so must dereference linked list to ensure
            if((*transitions)[n]->InvokeGuard()) {
                *changed = true;
                return (*transitions)[n]->GetToState();
            }
        }
        return 0;
    }
};

