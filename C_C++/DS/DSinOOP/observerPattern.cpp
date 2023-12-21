/*
- Behavioural
    + Observer Pattern
    - Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

- Mỗi đối tượng Car có một danh sách các đối tượng Observer mà nó đang theo dõi. Đây là mối quan hệ "một nhiều".
- Mỗi đối tượng Observer có một con trỏ đến đối tượng Car mà nó đang theo dõi. Đây là mối quan hệ "có một" (has a).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Car {
    int position;
    vector<class Observer*> observerList;
public:
    int getPosition() {
        return position;
    }
    void setPosition(int newPosition) { //state Car change through 'setPosition'
        position = newPosition;
        notify();
    }
    void attach(Observer *obs) { //Các đối tượng Observer được thêm vào danh sách thông qua attach()
        observerList.push_back(obs);
    }
    void detach(Observer *obs) { //được loại bỏ khỏi danh sách thông qua detach().
        observerList.erase(remove(observerList.begin(), observerList.end(), obs), observerList.end());
    }
    void notify(); //notify for all Observer's in list
};

class Observer { //Observer là một lớp abstract định nghĩa phương thức update()
    Car *_car;
public:
    Observer(Car *car) {
        _car = car;
        _car -> attach(this);
    }
    virtual void update() = 0;
protected:
    Car* getCar() {
        return _car;
    }
};

void Car::notify() {
    // for(int i=0; i < observerList.size(); i++) {
    //     observerList[i]->update();
    // }
    for(Observer* obs : observerList) {
        obs->update();
    }
}

class LeftObserver : public Observer {
public:
    LeftObserver(Car *car) : Observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if(pos < 0) {
            cout << "Left side" << endl;
        }
    }
};

class RightObserver : public Observer {
public:
    RightObserver(Car *car) : Observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if(pos > 0) {
            cout << "Right side" << endl;
        }
    }
};

class MiddleObserver : public Observer {
public:
    MiddleObserver(Car *car) : Observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if(pos==0) {
            cout << "Running in middle" << endl;
        }
    }
};
// -1 0 1 available position
//-1 driving left side
//0 driving in middle
//1 driving right side
int main() {
    Car *car = new Car();

    LeftObserver leftObserver(car);
    RightObserver rightObserver(car);
    MiddleObserver middleObserver(car);

    cout << "hit left right button to drive a car in your city!!! and press Esc to close" << endl;

    char pressedButton;
    bool breakLoop = false;

    while(breakLoop == false) {
        cin >> pressedButton;

        switch(pressedButton) {
            case 108:{ //l --> pressed for left side
                car->setPosition(-1);
                break;
            }
            case 99:{ //c --> pressed for center
                car->setPosition(0);
                break;
            }
            case 114:{ //r --> pressed for right side
                car->setPosition(1);
                break;
            }
            case 98:{ //b --> pressed for break
                breakLoop = true;
                break;
            }
            default: {
                cout << "Please drive carfully!" << endl;
                break;
            }
        }
    }
    cout << "Byee..." << endl;
}