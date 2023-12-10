#include <iostream>
#include "ATMState.h"  // Assume ATMState class is defined in ATMState.h

class ATMMachine {
private:
    ATMState* hasCard;
    ATMState* noCard;
    ATMState* hasCorrectPin;
    ATMState* atmOutOfMoney;

    ATMState* atmState;

    int cashInMachine;
    bool correctPinEntered;

public:
    ATMMachine() : cashInMachine(2000), correctPinEntered(false) {
        hasCard = new HasCard(this);
        noCard = new NoCard(this);
        hasCorrectPin = new HasPin(this);
        atmOutOfMoney = new NoCash(this);

        atmState = noCard;

        if (cashInMachine < 0) {
            atmState = atmOutOfMoney;
        }
    }

    ~ATMMachine() {
        delete hasCard;
        delete noCard;
        delete hasCorrectPin;
        delete atmOutOfMoney;
    }

    void setATMState(ATMState* newATMState) {
        atmState = newATMState;
    }

    void setCashInMachine(int newCashInMachine) {
        cashInMachine = newCashInMachine;
    }

    void insertCard() {
        atmState->insertCard();
    }

    void ejectCard() {
        atmState->ejectCard();
    }

    void requestCash(int cashToWithdraw) {
        atmState->requestCash(cashToWithdraw);
    }

    void insertPin(int pinEntered) {
        atmState->insertPin(pinEntered);
    }

    ATMState* getYesCardState() const { return hasCard; }
    ATMState* getNoCardState() const { return noCard; }
    ATMState* getHasPin() const { return hasCorrectPin; }
    ATMState* getNoCashState() const { return atmOutOfMoney; }
};
