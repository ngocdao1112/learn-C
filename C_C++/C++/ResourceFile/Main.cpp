#include <iostream>
#include "../HeaderFile/Food.h"
using namespace std;

int main() {
    cout << "Today i'll eat " << RecommendMeAFood('c') << endl;
    GetPizzaRecipe();

    system("pause > 0");
}
//g++ -o myprogram ../HeaderFile/Food.h Food.cpp Main.cpp