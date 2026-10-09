Hướng dẫn lưu và chia sẻ thay đổi bằng Git



Tài liệu dành cho người mới học Git, được xây dựng từ bài thực hành chỉnh sửa README và đưa thay đổi lên GitHub.



Chuẩn bị



Bạn cần cài Git, cấu hình tên và email tác giả commit, đồng thời đã clone kho của mình về máy. Các lệnh dưới đây được chạy trong thư mục kho, trên nhánh main. Bạn cần quyền ghi vào kho để push.



Bước 1: Chỉnh sửa tệp



Mở README.md bằng trình soạn thảo, thêm một dòng ghi chú rồi nhấn Ctrl + S để lưu.



Bước 2: Kiểm tra thay đổi



Chạy git status để xem tệp nào thay đổi.



Chạy git diff để xem phần nội dung đã sửa nhưng chưa đưa vào vùng chuẩn bị.



Bước 3: Chọn nội dung cần lưu



Chạy git add README.md để đưa nội dung thay đổi của README vào vùng chuẩn bị cho commit.



Bước 4: Tạo commit



Chạy git commit -m "Cap nhat ghi chu".



Commit ghi nội dung đã chuẩn bị thành một phiên bản trong lịch sử Git trên máy. Dùng git log --oneline -2 để xem hai commit gần nhất.



Bước 5: Đưa commit lên GitHub



Chạy git push origin main, hoàn tất đăng nhập nếu được yêu cầu và chờ lệnh thành công.



Mở trang kho GitHub, tải lại trang rồi kiểm tra nội dung và lịch sử commit.



Những điểm dễ nhầm



Ctrl + S lưu tệp; commit tạo một mốc trong lịch sử Git.



Commit chưa tự đưa thay đổi lên GitHub; cần push.



Nếu git diff không hiện gì, kiểm tra đã sửa và lưu đúng tệp chưa. Nếu đã chạy git add, dùng git diff --staged để xem phần đã chọn.



Trang “Authentication Succeeded” chỉ xác nhận đăng nhập. Cần chuyển về trang kho GitHub để xem kết quả.



Tài liệu tham khảo



Ghi lại thay đổi bằng Git



Làm việc với kho từ xa



Nếu thấy bước chưa rõ, bạn có thể mở Issue trong kho này để góp ý.

