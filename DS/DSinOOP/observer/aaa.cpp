#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>

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
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void unregisterObserver(Observer* observer) override {
        auto it = observers.begin();
        while (it != observers.end()) {
            if (*it == observer) {
                it = observers.erase(it);
                std::cout << "Observer deleted\n";
            } else {
                ++it;
            }
        }
    }

    void notifyObservers() override {
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

class GetTheStock : public std::thread {
private:
    Subject* stockGrabber;
    std::string stock;
    double price;

public:
    GetTheStock(Subject* stockGrabber, int newStartTime, const std::string& newStock, double newPrice)
        : stockGrabber(stockGrabber), stock(newStock), price(newPrice), std::thread(&GetTheStock::run, this) {}

    void run() {
        for (int i = 1; i <= 20; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(2));

            double randNum = (static_cast<double>(std::rand()) / RAND_MAX * 0.06) - 0.03;
            price = std::stod(std::to_string(price + randNum).substr(0, 5));

            if (stock == "IBM")
                dynamic_cast<StockGrabber*>(stockGrabber)->setIBMPrice(price);
            else if (stock == "AAPL")
                dynamic_cast<StockGrabber*>(stockGrabber)->setAAPLPrice(price);
            else if (stock == "GOOG")
                dynamic_cast<StockGrabber*>(stockGrabber)->setGOOGPrice(price);

            std::cout << stock << ": " << std::fixed << std::setprecision(2) << (price + randNum) << " "
                      << std::fixed << std::setprecision(2) << randNum << "\n\n";
        }
    }
};

int StockObserver::observerIDTracker = 0;

int main() {
    StockGrabber stockGrabber;

    StockObserver observer1(&stockGrabber);
    stockGrabber.setIBMPrice(197.00);
    stockGrabber.setAAPLPrice(677.60);
    stockGrabber.setGOOGPrice(676.40);

    StockObserver observer2(&stockGrabber);
    stockGrabber.setIBMPrice(197.00);
    stockGrabber.setAAPLPrice(677.60);
    stockGrabber.setGOOGPrice(676.40);

    stockGrabber.setIBMPrice(197.00);
    stockGrabber.setAAPLPrice(677.60);
    stockGrabber.setGOOGPrice(676.40);

    GetTheStock getIBM(&stockGrabber, 2, "IBM", 197.00);
    GetTheStock getAAPL(&stockGrabber, 2, "AAPL", 677.60);
    GetTheStock getGOOG(&stockGrabber, 2, "GOOG", 676.40);

    getIBM.join();
    getAAPL.join();
    getGOOG.join();

    return 0;
}
