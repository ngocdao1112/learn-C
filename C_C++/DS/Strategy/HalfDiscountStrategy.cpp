    // Lớp HalfDiscountStrategy
    class HalfDiscountStrategy : public IPromoteStrategy {
    public:
        double DoDiscount(double price) override {
            return price * 0.5;
        }
    };