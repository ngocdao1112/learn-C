#pragma once
#include "State.h"
#include "stdafx.h"
#include "Transition.h"
#include "LinkedList.h"
#include "FSM.h"

class Bulb {
public:
    FSM* fsm;
    int voltage;

    Bulb(){
        voltage = 240;
        fsm = new ESM():
        fsm->AddState(new State(On.&Bulb::OnOn this));
        fsm->AddState(new State (Off.& Bulb::OnOff.this));
        fsm->AddState(new State(Broken & Bulb::OnBroken,this));
        fsm->AddTransition(On, Off, & Bulb:: GuardOn ToOff, this);
        fsm->AddTransition(On.Broken. GuardOnToBroken,this); fsm->AddTransition (Off, Broken, & Bulb:: GuardOffToBroken, this);
        fsm->AddTransition(Off.On.&Bulb:: GuardOffToon, this);
    }

    void OnOn(){
        cout << "OnOn" << endl;
    }
    void OnOff(){
        cout << "OnOff" << endl;
    }
    void OnBroken(){
        cout << "OnBroken" << endl;
    }

    bool GuardOnToOff(){ return voltage == 0; }
    bool GuardOnToBroken(){ return voltage > 300; }
    bool GuardOffToBroken(){ return voltage > 300; }
    bool GuardOffToOn(){ return voltage == 240; }

    void Update() {
        fsm->Check();
    }
};