# Công cụ tính subnet IPv4 bằng C++

Công cụ dòng lệnh hỗ trợ sinh viên mạng máy tính kiểm tra kết quả bài tập chia mạng con.

## Chức năng

- Nhận địa chỉ IPv4 theo dạng CIDR, ví dụ `192.168.1.130/26`.
- Tính subnet mask, địa chỉ mạng và broadcast.
- Hiển thị dải host, tổng số địa chỉ và số host theo quy tắc subnet.
- Xử lý riêng `/31` cho liên kết điểm tới điểm và `/32` cho một địa chỉ đơn.
- Báo lỗi khi địa chỉ hoặc prefix không hợp lệ.

## Biên dịch và chạy

Yêu cầu trình biên dịch hỗ trợ C++17.

Mở terminal tại thư mục chứa `main.cpp`, biên dịch:

`g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o subnet.exe`

Chạy trong MSYS2 UCRT64 trên Windows:

`./subnet.exe 192.168.1.130/26`

Kết quả mong đợi: mạng `192.168.1.128`, broadcast `192.168.1.191`, dải host từ `192.168.1.129` đến `192.168.1.190`, gồm 62 host.

## Giới hạn

Công cụ hỗ trợ IPv4. Số host được tính theo quy tắc subnet, chưa loại trừ các dải địa chỉ dành riêng và không phản ánh số thiết bị đang hoạt động.

## Đóng góp và giấy phép

Mọi người có thể báo lỗi qua Issues hoặc đề xuất cải tiến bằng Pull Request.

Dự án sử dụng giấy phép MIT trong tệp LICENSE tại thư mục gốc của kho.