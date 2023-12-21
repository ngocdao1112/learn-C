#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>
#include "StockObserver.cpp"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>

class Subject {
    // implementation of Subject class
};

class StockGrabber : public Subject {
    // implementation of StockGrabber class
};

class GetTheStock : public Runnable {
private:
    std::string stock;
    double price;
    Subject* stockGrabber;

public:
    GetTheStock(Subject* stockGrabber, int newStartTime, std::string newStock, double newPrice) {
        this->stockGrabber = stockGrabber;
        stock = newStock;
        price = newPrice;
    }

    void run() override {
        for (int i = 1; i <= 20; i++) {
            try {
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }
            catch (std::exception& e) {}

            double randNum = (std::rand() / (double)RAND_MAX * 0.06) - 0.03;

            std::cout << std::fixed << std::setprecision(2);
            price = std::stod(std::to_string(price + randNum));

            if (stock == "IBM")
                static_cast<StockGrabber*>(stockGrabber)->setIBMPrice(price);
            if (stock == "AAPL")
                static_cast<StockGrabber*>(stockGrabber)->setAAPLPrice(price);
            if (stock == "GOOG")
                static_cast<StockGrabber*>(stockGrabber)->setGOOGPrice(price);

            std::cout << stock << ": " << std::to_string(price + randNum) << " " << std::to_string(randNum) << std::endl;
            std::cout << std::endl;
        }
    }
};


