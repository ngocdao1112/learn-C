/*1. TestFixture là một Lớp: Trong mô hình kiểm thử xunit (như JUnit, NUnit, Google Test), TestFixture thường được biểu diễn bằng một lớp (class). 
Lớp này chứa các test cases và các phương thức điều kiện (SetUp và TearDown).

2. Môi Trường Thử Nghiệm Chung: TestFixture cung cấp một môi trường thử nghiệm chung cho các test cases của nó. Các phương thức SetUp và TearDown của 
TestFixture được chạy trước và sau mỗi test case, giúp đảm bảo rằng các điều kiện chuẩn bị và giải phóng tài nguyên được thực hiện đúng cách.

3. Phương Thức SetUp và TearDown: Phương thức SetUp được sử dụng để chuẩn bị môi trường trước khi thực hiện mỗi test case. 
Phương thức TearDown được sử dụng để giải phóng tài nguyên và làm sạch môi trường sau khi mỗi test case hoàn thành.

4.Liên Quan Đến Namespace hoặc Module: Trong một số framework, TestFixture có thể liên quan đến một không gian tên (namespace) hoặc một module, 
tức là tất cả các test cases trong cùng một không gian tên sẽ chia sẻ một TestFixture.
*/
/*
#include <gtest/gtest.h>

class MyTestFixture : public ::testing::Test {
protected:
    // SetUp: Phương thức điều kiện đầu vào cho từng test case
    void SetUp() override {
        // Chuẩn bị môi trường trước mỗi test case
        std::cout << "SetUp - This runs before each test method." << std::endl;
    }

    // TearDown: Phương thức điều kiện kết thúc cho từng test case
    void TearDown() override {
        // Giải phóng tài nguyên và làm sạch môi trường sau mỗi test case
        std::cout << "TearDown - This runs after each test method." << std::endl;
    }
};

// Các test cases
TEST_F(MyTestFixture, TestCase1) {
    // Thực hiện các kiểm thử
    ASSERT_EQ(2 + 2, 4);
}

TEST_F(MyTestFixture, TestCase2) {
    // Thực hiện các kiểm thử khác
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    // Khởi tạo Google Test
    ::testing::InitGoogleTest(&argc, argv);

    // Chạy tất cả các test cases
    return RUN_ALL_TESTS();
}

*/




