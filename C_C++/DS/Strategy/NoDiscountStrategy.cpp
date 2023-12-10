    // Lớp NoDiscountStrategy
    class NoDiscountStrategy : public IPromoteStrategy {
    public:
        double DoDiscount(double price) override {
            return price;
        }
    };