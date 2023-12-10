class Ticket {
    private:
        IPromoteStrategy* _promoteStrategy;
        double _price;
        std::string _name;

    public:
        IPromoteStrategy* GetPromoteStrategy() {
            return _promoteStrategy;
        }

        void SetPromoteStrategy(IPromoteStrategy* value) {
            _promoteStrategy = value;
        }

        double GetPrice() {
            return _price;
        }

        void SetPrice(double value) {
            _price = value;
        }

        std::string GetName() {
            return _name;
        }

        void SetName(std::string value) {
            _name = value;
        }

        Ticket() : _promoteStrategy(nullptr), _price(0.0) {}

        Ticket(IPromoteStrategy* promoteStrategy) : _promoteStrategy(promoteStrategy), _price(0.0) {}

        double GetPromotedPrice() {
            return _promoteStrategy ? _promoteStrategy->DoDiscount(_price) : _price;
        }
    };