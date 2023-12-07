#include <iostream>
using namespace std;

//Virtual Functions, Pure Virtual Functions and Abstract Classes in OOP

//Virtual Functions
    // class Instrument {
    // public:
    //     virtual void MakeSound() {
    //         cout << "Instrument playing...\n";
    //     }
    // };

    // class Accordion: public Instrument {
    // // public:
    // //     void MakeSound() {
    // //         cout << "Accordion playing...\n";
    // //     }
    // };

    // int main() {
    //     Instrument* i1 = new Accordion();
    //     i1->MakeSound();

    //     system("pause > 0");
    // }

// Pure Virtual Functions
    // class Instrument {
    // // public:
    //     // virtual void MakeSound() = 0;
    // public:
    //     void MakeSound() {
    //         cout << "Instrument playing...\n";
    //     }
    // };

    // class Accordion: public Instrument {
    // // public:
    // //     void MakeSound() {
    // //         cout << "Accordion playing...\n";
    // //     }
    // };
    // class Piano: public Instrument {
    //     void MakeSound() {
    //         cout << "Piano playing...\n";
    //     }
    // };

    // int main() {
    //     Accordion* i1 = new Accordion();
    //     i1->MakeSound();
    //     Instrument* i2 = new Piano();
    //     i2->MakeSound();

    //     system("pause > 0");
    // }

//Example polymorphism
    class Instrument {
    public:
        virtual void MakeSound() = 0;
    };

    class Accordion: public Instrument {
    public:
        void MakeSound() {
            cout << "Accordion playing...\n";
        }
    };
    class Piano: public Instrument {
        void MakeSound() {
            cout << "Piano playing...\n";
        }
    };

    int main() {
        Instrument* i1 = new Accordion();
        // i1->MakeSound();
        Instrument* i2 = new Piano();
        // i2->MakeSound();
        Instrument* instruments[2] = {i1, i2};
        for(int i=0; i<2; i++) {
            instruments[i] -> MakeSound();
        }

        system("pause > 0");
    }