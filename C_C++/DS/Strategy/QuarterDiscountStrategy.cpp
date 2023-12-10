    class QuarterDiscountStrategy : public IPromoteStrategy {
    public:
        double DoDiscount(double price) override {
            return price * 0.75;
        }
    };