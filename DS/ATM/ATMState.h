// ATMState.h
#pragma once

class ATMState {
public:
    // Different states expected
    // HasCard, NoCard, HasPin, NoCash
    virtual void insertCard() = 0;
    virtual void ejectCard() = 0;
    virtual void insertPin(int pinEntered) = 0;
    virtual void requestCash(int cashToWithdraw) = 0;
};
