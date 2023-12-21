#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>
#include "Observer.cpp"
#include "Subject.cpp"

int StockObserver::observerIDTracker = 0;
class StockObserver : public Observer {
    private:
        double ibmPrice;
        double aaplPrice;
        double googPrice;
        static int observerIDTracker;
        int observerID;
        Subject* stockGrabber;
    
    public:
        StockObserver(Subject* stockGrabber) : stockGrabber(stockGrabber) {
            observerID = ++observerIDTracker;
            std::cout << "New Observer " << observerID << std::endl;
            stockGrabber->registerObserver(this);
        }
    
        void update(double ibmPrice, double aaplPrice, double googPrice) override {
            this->ibmPrice = ibmPrice;
            this->aaplPrice = aaplPrice;
            this->googPrice = googPrice;
            printThePrices();
        }
    
        void printThePrices() {
            std::cout << observerID << "\nIBM: " << ibmPrice << "\nAAPL: " << aaplPrice << "\nGOOG: " << googPrice << "\n\n";
        }
    };