#include <gtest/gtest.h>
#include <string>

// Khai báo hàm main của sinh viên (sẽ được đổi tên bằng lệnh g++ ở Bước 2)
int student_main();

TEST(HelloWorldTest, KiemTraOutput) {
    // Bắt đầu chặn luồng in ra màn hình (stdout)
    testing::internal::CaptureStdout();

    // Chạy chương trình của sinh viên
    int return_code = student_main();

    // Thu thập tất cả những gì sinh viên đã dùng printf/cout để in ra
    std::string output = testing::internal::GetCapturedStdout();

    // 1. Kiểm tra xem chương trình chạy có lỗi không (return 0 là chuẩn)
    EXPECT_EQ(return_code, 0) << "Hàm main cua sinh vien khong tra ve 0!";

    // 2. Kiểm tra xem kết quả in ra có khớp xác 100% không
    EXPECT_EQ(output, "hello world \n") << "Sinh vien in ra sai ket qua!";
}
