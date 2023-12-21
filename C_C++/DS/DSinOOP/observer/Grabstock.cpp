#include <iostream>
#include <vector>
#include "Observer.cpp"
#include "StockGrabber.cpp"
#include "StockObserver.cpp"
#include "GetTheStock.cpp"

#include <iostream>
#include <thread>

class StockGrabber {
private:
    double IBMPrice;
    double AAPLPrice;
    double GOOGPrice;
public:
    void setIBMPrice(double price) {
        IBMPrice = price;
        std::cout << "IBM Price: " << IBMPrice << std::endl;
    }
    
    void setAAPLPrice(double price) {
        AAPLPrice = price;
        std::cout << "AAPL Price: " << AAPLPrice << std::endl;
    }
    
    void setGOOGPrice(double price) {
        GOOGPrice = price;
        std::cout << "GOOG Price: " << GOOGPrice << std::endl;
    }
};

class StockObserver {
public:
    StockObserver(StockGrabber& stockGrabber) {
        // Observer constructor logic
    }
};

class GetTheStock {
private:
    StockGrabber& stockGrabber;
    int startTime;
    std::string stock;
    double price;
public:
    GetTheStock(StockGrabber& grabber, int time, std::string stk, double prc) : stockGrabber(grabber), startTime(time), stock(stk), price(prc) {
        // GetTheStock constructor logic
    }
    
    void run() {
        // GetTheStock run logic
    }
};

int main() {
    StockGrabber stockGrabber;
    
    StockObserver observer1(stockGrabber);
    stockGrabber.setIBMPrice(197.00);
    stockGrabber.setAAPLPrice(677.60);
    stockGrabber.setGOOGPrice(676.40);
    StockObserver observer2(stockGrabber);
    stockGrabber.setIBMPrice(197.00);
    stockGrabber.setAAPLPrice(677.60);
    stockGrabber.setGOOGPrice(676.40);
    
    stockGrabber.setIBMPrice(197.00);
    stockGrabber.setAAPLPrice(677.60);
    stockGrabber.setGOOGPrice(676.40);
    
    GetTheStock getIBM(stockGrabber, 2, "IBM", 197.00);
    GetTheStock getAAPL(stockGrabber, 2, "AAPL", 677.60);
    GetTheStock getGOOG(stockGrabber, 2, "GOOG", 676.40);
    
    std::thread threadIBM(&GetTheStock::run, &getIBM);
    std::thread threadAAPL(&GetTheStock::run, &getAAPL);
    std::thread threadGOOG(&GetTheStock::run, &getGOOG);
    
    threadIBM.join();
    threadAAPL.join();
    threadGOOG.join();
    
    return 0;
}


