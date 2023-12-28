/*
- Trong ngữ cảnh của unit testing, các macros hỗ trợ thường được sử dụng để tạo ra 
các phần nhỏ của mã mà bạn sử dụng thường xuyên trong các bài kiểm tra (tests). 
Các macros này giúp làm cho mã kiểm tra trở nên ngắn gọn và dễ đọc hơn.
*/

// #include <gtest/gtest.h>

// // Define a helper macro for checking equality with a custom message
// #define EXPECT_EQ_CUSTOM(expected, actual, message) \
//     do { \
//         EXPECT_EQ(expected, actual) << message; \
//     } while (false)

// // Define a helper macro for checking inequality with a custom message
// #define EXPECT_NE_CUSTOM(expected, actual, message) \
//     do { \
//         EXPECT_NE(expected, actual) << message; \
//     } while (false)

// // Unit test example using helper macros
// TEST(MyTestSuite, MyTestCase) {
//     int result = performSomeOperation();

//     // Use the custom equality check with a custom message
//     EXPECT_EQ_CUSTOM(42, result, "The result should be 42");

//     // Use the custom inequality check with a custom message
//     EXPECT_NE_CUSTOM(0, result, "The result should not be 0");
// }

/*
EXPECT_EQ_CUSTOM và EXPECT_NE_CUSTOM là các macros hỗ trợ giúp kiểm tra sự bằng nhau 
và khác nhau với một thông báo tùy chỉnh. Sử dụng các macros này giúp giảm lặp lại mã và 
làm cho mã kiểm thử trở nên dễ đọc và bảo trì hơn.
*/
