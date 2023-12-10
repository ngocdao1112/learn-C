#include <iostream>
#include "ATMState.h"  // Assume ATMState class is defined in ATMState.h
#include "ATMMachine.h" // Assume ATMMachine class is defined in ATMMachine.h

class HasPin : public ATMState {
private:
    ATMMachine* atmMachine;

public:
    HasPin(ATMMachine* newATMMachine) : atmMachine(newATMMachine) {}

    void insertCard() override {
        std::cout << "You already entered a card" << std::endl;
    }

    void ejectCard() override {
        std::cout << "Your card is ejected" << std::endl;
        atmMachine->setATMState(atmMachine->getNoCardState());
    }

    void requestCash(int cashToWithdraw) override {
        if (cashToWithdraw > atmMachine->cashInMachine) {
            std::cout << "You don't have that much cash available" << std::endl;
            std::cout << "Your card is ejected" << std::endl;
            atmMachine->setATMState(atmMachine->getNoCardState());
        } else {
            std::cout << cashToWithdraw << " is provided by the machine" << std::endl;
            atmMachine->setCashInMachine(atmMachine->cashInMachine - cashToWithdraw);

            std::cout << "Your card is ejected" << std::endl;
            atmMachine->setATMState(atmMachine->getNoCardState());

            if (atmMachine->cashInMachine <= 0) {
                atmMachine->setATMState(atmMachine->getNoCashState());
            }
        }
    }

    void insertPin(int pinEntered) override {
        std::cout << "You already entered a PIN" << std::endl;
    }
};
