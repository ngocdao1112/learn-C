#include <iostream>
#include <string>
#include <cstdlib> // Đối với std::rand
#include <ctime>   // Đối với std::time

    // Hàm GeneratePromoteStrategy
    void GeneratePromoteStrategy(std::rand& random, Ticket& ticket) {
        int strategyIndex = random() % 4;
        switch (strategyIndex) {
            case 0:
                ticket.SetPromoteStrategy(new NoDiscountStrategy());
                break;
            case 1:
                ticket.SetPromoteStrategy(new QuarterDiscountStrategy());
                break;
            case 2:
                ticket.SetPromoteStrategy(new HalfDiscountStrategy());
                break;
            default:
                ticket.SetPromoteStrategy(new EightyDiscountStrategy());
                break;
        }
    }

    // Hàm LogTicketDetails
    void LogTicketDetails(Ticket& ticket) {
        std::cout << "Promoted price of " << ticket.GetName() << " is " << ticket.GetPromotedPrice()
                  << " " << typeid(*(ticket.GetPromoteStrategy())).name() << "\n";
    }

int main() {
    std::cout << "Start getting tickets!\n";

    std::srand(static_cast<unsigned int>(std::time(0))); // Khởi tạo seed cho hàm random

    for (int i = 1; i <= 5; ++i) {
        StrategyPattern::Ticket ticket;
        ticket.SetName("Ticket " + std::to_string(i));
        ticket.SetPrice(50.0 * i);
        StrategyPattern::GeneratePromoteStrategy(std::rand, ticket);
        StrategyPattern::LogTicketDetails(ticket);

        StrategyPattern::GeneratePromoteStrategy(std::rand, ticket);
        StrategyPattern::LogTicketDetails(ticket);
    }

    return 0;
}