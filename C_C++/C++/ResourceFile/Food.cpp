#include <iostream>
#include "../HeaderFile/Food.h"
using namespace std;

const char* RecommendMeAFood(char firstLetter) {
    if(firstLetter == 'a' || firstLetter == 'A')
        return "apple";
    else if (firstLetter == 'b' || firstLetter == 'B')
        return "banana";
    else if (firstLetter == 'c' || firstLetter == 'C')
        return "chocolate cake";
    else return "pizza";
    }
void GetPizzaRecipe() {
    cout << "To make pizza you need ...";
}
