#include <iostream>
#include <vector>
#include "Observer.cpp"
#include "Subject.cpp"
using namespace std;

class Observer {
public:
    virtual void update(double ibmPrice, double aaplPrice, double googPrice) = 0;
};

class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void unregisterObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

class StockGrabber : public Subject {
private:
    std::vector<Observer*> observers;
    double ibmPrice;
    double aaplPrice;
    double googPrice;
public:
    StockGrabber() {
        observers = std::vector<Observer*>();
    }
    void registerObserver(Observer* newObserver) {
        observers.push_back(newObserver);
    }
    void unregisterObserver(Observer* deleteObserver) {
        int observerIndex = -1;
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i] == deleteObserver) {
                observerIndex = i;
                break;
            }
        }
        if (observerIndex != -1) {
            std::cout << "Observer " << (observerIndex + 1) << " deleted" << std::endl;
            observers.erase(observers.begin() + observerIndex);
        }
    }
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(ibmPrice, aaplPrice, googPrice);
        }
    }
    void setIBMPrice(double newIBMPrice) {
        ibmPrice = newIBMPrice;
        notifyObservers();
    }
    void setAAPLPrice(double newAAPLPrice) {
        aaplPrice = newAAPLPrice;
        notifyObservers();
    }
    void setGOOGPrice(double newGOOGPrice) {
        googPrice = newGOOGPrice;
        notifyObservers();
    }
};



