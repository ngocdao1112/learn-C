#include "ATMMachine.h" // Assume ATMMachine class is defined in ATMMachine.h

int main() {
    ATMMachine atmMachine;

    atmMachine.insertCard();

    atmMachine.ejectCard();

    atmMachine.insertCard();

    atmMachine.insertPin(1234);

    atmMachine.requestCash(2000);

    atmMachine.insertCard();

    atmMachine.insertPin(1234);

    return 0;
}
