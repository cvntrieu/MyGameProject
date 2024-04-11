# The Defender 
 - Game Project "The Defender", Advanced Programming, 2nd Term - Spring 2023-2024 - Class 23, University of Engineering and Technology, Vietnam National University, Hanoi.
 - Sinh viên thực hiện: Cao Vũ Nhật Triều ( MSV: 2302 1740, Lớp QH-2023/I-CQ-CA2)

 # I - Giới thiệu về hình thức Game.
 
 - Tên: The Defender (Người bảo vệ, phòng thủ) - Game chủ yếu dựa trên luật chơi của 1 số tựa game cũ trên điện thoại cục gạch những năm 2010. Tên do sinh viên tự đặt.
 -  Khi mở Game sẽ có giao diện mở đầu như sau.
   ![OfficialMenu1](https://github.com/cvntrieu/MyGameProject/assets/143981579/f70e84ea-f985-4bcc-add0-19867e808697)
   Ta có 3 lựa chọn cho Menu mở đầu: Play (vào chơi luôn), Help (Hướng dẫn chơi), và Exit (Thoát Game).
   Nếu lạ lẫm, người chơi có thể nhấp vào "Help" để xem qua hướng dẫn:
   ![OfficialMenu2](https://github.com/cvntrieu/MyGameProject/assets/143981579/4c1caddd-9b7f-4a98-a0bc-8e59b08515f4)
   Đọc Help xong thì nhấn Back để quay lại Giao diện mở đầu.
   Nhấn vào Play để chơi. Giao diện sẽ có dạng:

   ![Screenshot 2024-04-11 151754](https://github.com/cvntrieu/MyGameProject/assets/143981579/80f858e6-6bd8-45f9-a483-fc2ed1576362)
   
   Màn hình xuất hiện nhân vật chính diện (nhân vật màu hồng, đeo áo choàng), liên tục xuất hiện đối tượng phản diện ( con quỷ đỏ ) hoặc (thỉnh thoảng) hình hộp quà bay ngang từ phải sang trái với tốc độ nhanh.
   Ngoài ra còn hiển thị điểm của bạn hiện tại, số mạng của nhân vật bạn còn ( đứng bên cạnh hình trái tim, bên trên góc trái ), và điểm cao nhất lịch sử chơi ( đứng bên cạnh chữ Top 1, bên trên góc phải ).
   
# II - Luật chơi.   

   Nhiệm vụ của bạn là nhanh chóng nhìn nhận và điều khiển nhân vật tránh va chạm với các con quỷ, đồng thời cố gắng va vào các hình quà để nhận điểm thưởng, bằng 4 phím chỉ hướng tương ứng trên bàn phím máy tính 
   ( ^ để đi lên, V để đi xuống, < để đi trái ngang, > ngang sang phải ).
   
   Cơ chế tính điểm: Cứ mỗi con quỷ đi ra hết khỏi màn hình, bạn được thêm 1 điểm. Nếu ăn được hộp quà, thêm điểm thưởng 5 điểm / 1 quà. Còn cứ mỗi lần bị va chạm với con quỷ thì trừ 1 mạng.
   Khi số mạng đã chỉ còn 0 mà để va chạm thêm lần nữa thì chính thức Game Over và hết lượt chơi này. Giao diện hiện ra:
   ![OfficialMenu3 0](https://github.com/cvntrieu/MyGameProject/assets/143981579/499324a6-43c4-42f9-8f7f-1fc16691b938)
   Người chơi có thể chọn Play Again để chơi lại lượt tiếp, hoặc Exit để thoát ra không chơi nữa.

 # III - Tự đánh giá.
 Về mức điểm, em xác định ngưỡng điểm khoảng 7.5 - 8. Sau đây là các lí do em đưa ra để chứng minh cho ngưỡng điểm này.
 
  # Nhắc lại: Band 7.5 - 8.5: 
(1) Game tự viết có thuật toán nằm ngoài chương trình môn học (điểm đánh giá theo độ khó của thuật toán). hoặc

(2) Game tự viết có đồ họa đơn giản

(3). Game phát triển từ code mẫu nhưng có thay đổi đáng kể về nội dung và bổ sung đáng kể các tính năng mới.  

(điểm của loại (2) và  (3) đánh giá theo số những tính năng tự làm hoặc tự học).

# => Chiếu theo yêu cầu trên, game của em đã đạt được:
# (*) Đã thể hiện các tính năng đồ họa:  ( Xét mục (2) )
 + Tải thành công ảnh nền, ảnh các nhân vật, đối tượng, ảnh các giao diện chuyển tiếp (Menu). Cài thành công text để ghi các điểm số. 
 + Cùng lúc xuất hiện nhiều đối tượng đe dọa, nhưng vị trí xuất hiện của chúng cũng mang tính ngấu nhiên.
   
# (*) Nội dung / hình thức chơi: ( Xét mục (3) )
  + Có tham khảo việc xử lý va chạm từ Tài liệu bổ sung, nhưng bổ sung thêm tính năng: cho phép va chạm tối đa 3 lần ( lần thứu 4 mới chết ) - tức cho thêm mạng;
  hay va chạm với kẻ thù xử lý khác va chạm với quà điểm.
  + Có tham khảo việc xử lý chuyển động từ Tài liệu bổ sung, nhưng bổ sung thêm tính đa dạng với 2 kiểu di chuyển: Di chuyển do ta điều khiển và tự di chuyển xuất hiện liên tục trên màn hình.
  + Trình diện được giao diện ban đầu (Menu), giao diện hướng dẫn chơi ( Help ), giao diện sau khi chơi (Game Over).
  + Xử lý được cơ chế khi ấn các nút Menu ( Nhấn Play Again chơi lại được, Nhấn Exit để thoát, việc chuyển tiếp giữa các giao diện).
  + Lưu được điểm số của lượt chơi hiện tại, điểm số kỷ lục, và tính được số mạng còn lại.
  + Tạo được âm thanh lúc mới vào chơi, nhạc nền lúc đang chơi, âm thanh va chạm, âm thanh báo hiệu Game Over.
# Code và khung chương trình: 
  + Đã chia được thành 3 loại file và Lập trình hướng đối tượng: File Object.h để quản lý các đối tượng ( Thiết kế OOP ), File Object.cpp để định nghĩa các phương thức tương ứng.
Tạo 1 BaseObject làm khung để 1 số object khác kế thừa. Quản lí cả âm thanh và text trong file riêng. Việc gọi ra trong file main.cpp.
  + Xử lý nhận sự kiện bàn phím (PollEvent) kết hợp với các vòng lặp thể hiện logic chương trình.
# Hướng phát triển thêm và Cải thiện: 
  + Rút ngắn file main.cpp hơn nữa.
  + Có thể tạo hiệu ứng Hoạt hình (animation).

# IV. Tài liệu hỗ trợ.
- Các website tra cứu các hàm và cách sử dụng:
 + https://lazyfoo.net/tutorials/SDL/index.php
 + https://cplusplus.com/
 + https://wiki.libsdl.org/SDL2/APIByCategory
 + https://wiki.libsdl.org/SDL2/CategoryAPI
 + https://www.libsdl.org/release/SDL-1.2.15/docs/html/index.html
 + ... và 1 số kết quả tìm kiếm trang Google cũng như diễn đàn khác ( như stackoverflow ).
- Tham khảo cách xây dựng khung chương trình ( chỉ tham khảo để định hướng cách làm sau đó tự code theo nhu cầu riêng của bản thân, không phải là phát triển tiếp từ các dự án mẫu này: )
 + https://phattrienphanmem123az.com/
 + file Tài liệu bổ sung của môn Lập trình nâng cao.
 + Code mẫu (cô Châu, thầy Long).
