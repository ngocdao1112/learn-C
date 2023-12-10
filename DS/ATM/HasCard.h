#include <iostream>
#include "ATMState.h"  // Assume ATMState class is defined in ATMState.h
#include "ATMMachine.h" // Assume ATMMachine class is defined in ATMMachine.h

class HasCard : public ATMState {
private:
    ATMMachine* atmMachine;

public:
    HasCard(ATMMachine* newATMMachine) : atmMachine(newATMMachine) {}

    void insertCard() override {
        std::cout << "You can only insert one card at a time" << std::endl;
    }

    void ejectCard() override {
        std::cout << "Your card is ejected" << std::endl;
        atmMachine->setATMState(atmMachine->getNoCardState());
    }

    void requestCash(int cashToWithdraw) override {
        std::cout << "You have not entered your PIN" << std::endl;
    }

    void insertPin(int pinEntered) override {
        if (pinEntered == 1234) {
            std::cout << "You entered the correct PIN" << std::endl;
            atmMachine->correctPinEntered = true;
            atmMachine->setATMState(atmMachine->getHasPin());
        } else {
            std::cout << "You entered the wrong PIN" << std::endl;
            atmMachine->correctPinEntered = false;
            std::cout << "Your card is ejected" << std::endl;
            atmMachine->setATMState(atmMachine->getNoCardState());
        }
    }
};
