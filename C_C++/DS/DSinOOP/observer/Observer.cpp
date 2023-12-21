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

