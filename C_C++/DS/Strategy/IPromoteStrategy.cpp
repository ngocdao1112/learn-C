    // Khai báo trước lớp IPromoteStrategy
    class IPromoteStrategy {
    public:
        virtual double DoDiscount(double price) = 0;
        virtual ~IPromoteStrategy() {}
    };