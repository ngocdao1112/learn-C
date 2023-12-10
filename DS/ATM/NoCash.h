#include <iostream>
#include "ATMState.h"  // Assume ATMState class is defined in ATMState.h
#include "ATMMachine.h" // Assume ATMMachine class is defined in ATMMachine.h

class NoCard : public ATMState {
private:
    ATMMachine* atmMachine;

public:
    NoCard(ATMMachine* newATMMachine) : atmMachine(newATMMachine) {}

    void insertCard() override {
        std::cout << "Please enter your pin" << std::endl;
        atmMachine->setATMState(atmMachine->getYesCardState());
    }

    void ejectCard() override {
        std::cout << "You didn't enter a card" << std::endl;
    }

    void requestCash(int cashToWithdraw) override {
        std::cout << "You have not entered your card" << std::endl;
    }

    void insertPin(int pinEntered) override {
        std::cout << "You have not entered your card" << std::endl;
    }
};
