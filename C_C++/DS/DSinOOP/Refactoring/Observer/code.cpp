/**
- What classes does it consist of?
- What roles do these classes play?
- In what way the elements of the pattern are related?

 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>
using namespace std;

class IObserver {
public:
    virtual ~IObserver() {};
    virtual void Update(const string &message_from_subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject : public ISubject {
private:
    list<IObserver *> list_observer_;
    string message_;
public:
    virtual ~Subject() {
        cout << "Goodbye, I was the Subject.\n";
    }
    //The subscription management methods.
    void Attach(IObserver *observer) override {
        list_observer_.push_back(observer);
    }
    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }
    void Notify() override {
        list<IObserver *>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while(iterator != list_observer_.end()) {
            (*iterator) -> Update(message_);
            ++iterator;
        }
    }
    void CreateMessage(string message = "Empty") {
        this->message_ = message;
        Notify();
    }
    void HowManyObserver() {
        cout << "There are " << list_observer_.size() << " observer in the list.\n";
    }

/**
   * Usually, the subscription logic is only a fraction of what a Subject can
   * really do. Subjects commonly hold some important business logic, that
   * triggers a notification method whenever something important is about to
   * happen (or after it).
*/
    void SomBusinessLogic() {
        this->message_ = "change message message";
        Notify();
        cout << "I'm about to do some thing important\n";
    }
};

class Observer : public IObserver { 
private:
    string message_from_subject_;
    Subject &subject_;
    static int static_number_; //dùng chung 1 vùng nhớ và ko cần tạo đối tượng cho lớp đó
    int number_;
public:
    Observer(Subject &subject) : subject_(subject) { //' : ' để bắt đầu danh sách khởi tạo thành viên
        // subject_.Attach(this);
        this->subject_.Attach(this);
        cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        this->number_ = Observer::static_number_; 
    }

    virtual ~Observer() {
        cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const string &message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    void RemoveMeFromTheList() {
        subject_.Detach(this);
        cout << "Observer \"" << number_ << "\" removed from the list.\n";
        
    }

    void PrintInfo() {
        cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }
};

int Observer::static_number_ = 0;

void ClientCode() {
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    // Observer quan sát đối tượng mà con trỏ subject trỏ đến

    // Observer *observer1 = new Observer(subject);
        // Observer quan sát chính đối tượng subject
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;
    
    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

}

int main() {
    ClientCode();

    return 0;
}