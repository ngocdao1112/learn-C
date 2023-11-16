#include <iostream>

// syntax: typedef existing_data_type new_data_type

    // Ex:
    // typedef int INTEGER;
    // int main() {
    //     INTEGER var = 100;
    //     printf("%d", var);

    //     return 0;
    // }

//structure declaration
    // struct car {
    //     char engine[50];
    //     char fuel_type[10];
    //     int fuel_tank_cap;
    //     int seating_cap;
    //     float city_mileage;
    // } c1;
//separate declaration
    // struct car {
    //     char engine[50];
    //     char fuel_type[10];
    //     int fuel_tank_cap;
    //     int seating_cap;
    //     float city_mileage;
    // };
    // int main() {
    //     struct car c1;
    // }
//use of typedef in structures
    // typedef struct car { //-> old type
    //     char engine[50];
    //     char fuel_type[10];
    //     int fuel_tank_cap;
    //     int seating_cap;
    //     float city_mileage;
    // } car; //-> new type

    // int main() {
    //     struct car c1;
    // }
//C typedef 
// struct User {
    // typedef struct {
    //     char name[25];
    //     char password[12];
    //     int id;
    // } User;
    // int main() {
    //     // struct User user1 = {"Bro", "pass123", 12345678};
    //     // struct User user2 = {"Bruh", "pass456", 98675231};
    //     User user1 = {"Bro", "pass123", 12345678};
    //     User user2 = {"Bruh", "pass456", 98675231};

    //     printf("%s\n", user1.name);
    //     printf("%s\n", user1.password);
    //     printf("%s\n", user1.id);
    //     printf("\n");
    //     printf("%s\n", user2.name);
    //     printf("%s\n", user2.password);
    //     printf("%s\n", user2.id);

    //     return 0;
    // }


