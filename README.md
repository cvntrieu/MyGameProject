# Advanced Programming Assignment: The Defender!
Triều Cvn ^^ <3, 2024.
# I - Mở đầu & Giới thiệu chung. (0.5')
* Xin chào cô và các bạn! Bản thân em xin được giới thiệu về Bài tập lớn em thực hiện của môn Lập trình nâng cao - Lớp 23.
 - Game Project "The Defender", Advanced Programming, 2nd Term - Spring 2023-2024 - Class 23, University of Engineering and Technology, Vietnam National University, Hanoi.
 - Sinh viên thực hiện: Cao Vũ Nhật Triều ( MSV: 2302 1740, Lớp QH-2023/I-CQ-CA2, Lớp 23 - Nhóm thực hành 2).
 - Cán bộ - Giảng viên hướng dẫn và chấm bài: Trần Thị Minh Châu, Vương Thị Hải Yến (UET - VNU).
 - Thời gian thực hiện:
   + Tuần 1 - Từ 20/1/2024 - 11/2/2024 ( Ngay sau thi học kì 1 và vào Tuần đầu kì 2 ):
     Bắt đầu nghiên cứu cách cài các thư viện, cấu hình SDL2 cho Visual Studio. Tham khảo trước chương trình chạy thử của thầy Long.
     Bước đầu cài, chạy thành công. Nắm bắt yêu cầu và hình thành - chốt ý tưởng chủ đề Game. Tạo và học git.
   + Tuần 2 -> 9: Từ 11/2/2024 (nghỉ Tết) - 11/4/2024 (giữa kì): Tiến hành làm dần Game ( xem cụ thể miêu tả các Commits, 20 lần commits chính và các lần Clean Code - Readme sau cùng ).
   Cơ bản hoàn thiện vào Tuần 8, sau đó chỉ còn Clean Code và Commit cho Readme.
   + Nộp bài (dự kiến): Thứ 4, Tuần 10 kì 2, 17/4/2024 (cô Yến).
* Phần trình bày của em gồm các phần: ( Thời gian trình bày dự kiến: khoảng 15' - 20')
  1. Mở đầu & giới thiệu chung.                                           (1    : 0.5'  )
  2. Giới thiệu về giao diện Game.
  3. Luật chơi & Demo cách chơi.                                          (2 + 3: 4.5'  )
  4. Tự đánh giá ( Ngưỡng điểm ).
  5. Tài liệu tham khảo.                                                  (4 + 5: 5'    )
  6. Q&A: Câu hỏi và nhận xét. Kết thúc phần trình bày.                   (6    : 5'-10')
* Sau đây xin mời cô và các bạn đi vào chi tiết.
 # II - Giới thiệu về hình thức Game. (2')
 
 - Tên: The Defender (Người bảo vệ, phòng thủ) - 1 Game đơn giản, chủ yếu dựa trên luật chơi của 1 số tựa game trên điện thoại cục gạch đời cũ. Tên do sinh viên tự đặt.
 -  Khi mở Game sẽ có giao diện mở đầu như sau.
   ![OfficialMenu](https://github.com/cvntrieu/MyGameProject/assets/143981579/20e1778b-c543-4597-a36f-9d6814de66f0)
   Ta có 3 lựa chọn cho Menu mở đầu: Play (vào chơi luôn), Help (Hướng dẫn chơi), và Exit (Thoát Game).
   Nếu lạ lẫm, người chơi có thể nhấp vào "Help" để xem qua hướng dẫn:
   ![OfficialHelp](https://github.com/cvntrieu/MyGameProject/assets/143981579/9a1fe92a-a163-4cee-828f-653a94cd4094)
   Đọc Help xong thì nhấn Back để quay lại Giao diện mở đầu.
   Nhấn vào Play để chơi. Giao diện sẽ có dạng:
   ![Demo](https://github.com/cvntrieu/MyGameProject/assets/143981579/9e76145d-d0bf-4a67-b8e0-40f1fed4d30d)
   Màn hình xuất hiện nhân vật chính diện (nhân vật màu hồng, đeo áo choàng), liên tục xuất hiện đối tượng phản diện ( con quỷ đỏ ) hoặc (thỉnh thoảng) hình hộp quà bay ngang từ phải sang trái với tốc độ nhanh.
   Ngoài ra còn hiển thị điểm của bạn hiện tại, số mạng của nhân vật bạn còn ( đứng bên cạnh hình trái tim, bên trên góc trái ), và điểm cao nhất lịch sử chơi ( đứng bên cạnh chữ Top 1, bên trên góc phải ).
   
# III - Luật chơi & Demo cách chơi. (2.5')

- Nhiệm vụ của bạn là nhanh chóng nhìn nhận và điều khiển nhân vật tránh va chạm với các con quỷ, đồng thời cố gắng va vào các hình quà để nhận điểm thưởng, bằng 4 phím chỉ hướng tương ứng trên bàn phím máy tính 
( ^ để đi lên, V để đi xuống, < để đi trái ngang, > ngang sang phải ).
   
- Cơ chế tính điểm: Cứ mỗi con quỷ đi ra hết khỏi màn hình, bạn được thêm 1 điểm. Nếu ăn được hộp quà, thêm điểm thưởng 5 điểm / 1 quà. Còn cứ mỗi lần bị va chạm với con quỷ thì trừ 1 mạng.
  Khi số mạng đã chỉ còn 0 mà để va chạm thêm lần nữa thì chính thức Game Over và hết lượt chơi này. Giao diện hiện ra:
  ![OfficialOver](https://github.com/cvntrieu/MyGameProject/assets/143981579/5b2a3ec1-e8eb-435e-95ca-0e7e28ae5b09)
- Người chơi có thể chọn Play Again để chơi lại lượt tiếp, hoặc Exit để thoát ra không chơi nữa. 

 # IV - Tự đánh giá. (4.5')
- Về mức điểm, em xác định ngưỡng điểm khoảng 7.5 - 8. Sau đây là các lí do em đưa ra để chứng minh cho ngưỡng điểm này. 
-  Nhắc lại: Band 7.5 - 8.5:
-  
     (1) Game tự viết có thuật toán nằm ngoài chương trình môn học (điểm đánh giá theo độ khó của thuật toán), hoặc
     
     (2) Game tự viết có đồ họa đơn giản.
     
     (3). Game phát triển từ code mẫu nhưng có thay đổi đáng kể về nội dung và bổ sung đáng kể các tính năng mới.  
     
     (điểm của loại (2) và  (3) đánh giá theo số những tính năng tự làm hoặc tự học).

- Chiếu theo yêu cầu trên, game của em đã đạt được:
  
## (*) Đã thể hiện các tính năng đồ họa:  ( Xét mục (2) )

 + Tải thành công ảnh nền, ảnh các nhân vật, đối tượng, ảnh các giao diện chuyển tiếp (Menu). Cài thành công text để ghi các điểm số. 
 + Cùng lúc xuất hiện nhiều đối tượng đe dọa, nhưng vị trí xuất hiện của chúng cũng mang tính ngấu nhiên.
   
## (*) Nội dung / hình thức chơi: ( Xét mục (3) )
  + Bổ sung thêm tính năng với va chạm: cho phép va chạm tối đa 3 lần ( lần thứ 4 mới chết ) - tức cho thêm mạng;
  hay va chạm với kẻ thù xử lý khác va chạm với quà điểm.
  + Bổ sung thêm tính đa dạng với 2 kiểu di chuyển: Di chuyển do ta điều khiển và tự di chuyển xuất hiện liên tục trên màn hình.
    Điều khiển và tinh chỉnh được tốc độ di chuyển / Bước đi.
  + Nhân vật chính kết hợp di chuyển, va chạm và hoạt hình (ANIMATIONS).
  + Trình diện được giao diện ban đầu (Menu), giao diện hướng dẫn chơi ( Help ), giao diện sau khi chơi (Game Over).
  + Xử lý được cơ chế khi ấn các nút Menu. Cho phép chơi nhiều ván ( Nhấn Play Again chơi lại được ván mới, Nhấn Exit để thoát, việc chuyển tiếp giữa các giao diện).
  + Lưu được điểm số của lượt chơi hiện tại, điểm số kỷ lục, và tính được số mạng còn lại.
  + Tạo được âm thanh lúc mới vào chơi, nhạc nền lúc đang chơi, âm thanh va chạm, âm thanh báo hiệu Game Over.
## (*) Code và khung chương trình: 
  + Đã chia được thành 3 loại file và Lập trình hướng đối tượng: File Object.h để quản lý các đối tượng ( Thiết kế OOP ), File Object.cpp để định nghĩa các phương thức tương ứng.
Tạo 1 BaseObject làm khung để 1 số object khác kế thừa. Quản lí cả âm thanh và text trong file riêng. Việc gọi ra trong file main.cpp.
  + Xử lý nhận sự kiện bàn phím (PollEvent) kết hợp với các vòng lặp thể hiện logic chương trình.
  + Sơ đồ UML khung chương trình:
    ![Slide1](https://github.com/cvntrieu/MyGameProject/assets/143981579/723b1f4f-7198-4a21-80e4-d49635137b7b)

  + Sơ đồ khối:
    ![Slide2](https://github.com/cvntrieu/MyGameProject/assets/143981579/9c6daf1e-569a-4a62-ab64-ab6c7cbae716)
## Lưu ý: 
- Rất hiếm khi, nhưng thỉnh thoảng game có thể hơi giật lag hoặc phải nhấn 2 lần vào 1 nút mới chuyển tiếp.
  
# V. Tài liệu hỗ trợ. (0.5')
* Các website tra cứu các hàm và cách sử dụng:
 + https://lazyfoo.net/tutorials/SDL/index.php
 + https://cplusplus.com/
 + https://wiki.libsdl.org/SDL2/APIByCategory
 + https://wiki.libsdl.org/SDL2/CategoryAPI
 + https://www.libsdl.org/release/SDL-1.2.15/docs/html/index.html
 + ... và 1 số kết quả tìm kiếm trang Google cũng như diễn đàn khác ( như stackoverflow ).
* Tham khảo cách xây dựng khung chương trình ( chỉ tham khảo để định hướng cách làm sau đó tự code theo nhu cầu riêng của bản thân, không phải là phát triển tiếp từ các dự án mẫu nêu dưới đây.
  Xin được gửi lời cảm ơn chân thành sâu sắc đến các thầy cô và các tác giả hướng dẫn! )
 + https://phattrienphanmem123az.com/
 + file Tài liệu bổ sung của môn Lập trình nâng cao:
  https://docs.google.com/document/d/1FZ3jTqHxtyZznNWiJmmve0zYu_aSliUqLP2OsMcdehQ/edit#heading=h.n8fowkm18xov
 + Code mẫu (cô Châu, thầy Long):
   - https://github.com/chauttm/advprogram/tree/master
   - https://github.com/tqlong/advprogram
* Các nguồn hình ảnh và âm thanh sử dụng. Xin chân thành cảm ơn các tác giả!
  - MainObject (player, bird): https://freepngimg.com/download/sprite/83127-sprite-area-line-animated-bird-film.png
  - Đối thủ: https://terraria.fandom.com/wiki/Red_Devil
  - Trái tim: https://www.pngall.com/pink-heart-png/
  - Hình quà: https://www.myeventpod.com/
  - Nhạc nền: https://www.youtube.com/watch?v=22NqCb_cwRc&list=PLqi51aibKx1lm0eRcfFsDuv9ZYP1iAPJU&index=4
  - Hình nền: https://www.vecteezy.com/vector-art/7633071-cartoon-colorful-panorama-of-spring-summer-beautiful-nature-green-grasslands-meadow-with-mountains-on-horizon-background-summer-mountain-landscape-dawn-over-the-valley-vector-illustration
  - Âm mở đầu, va chạm và kết thúc: https://www.freesoundeffects.com/
* Và trên đây là toàn bộ phần trình bày của em về Bài tập lớn em đã thực hiện. Xin cảm ơn sự theo dõi của cô và các bạn.

# VI. Câu hỏi bổ sung và nhận xét. Kết thúc phần trình bày. (5' - 10')
- Em xin được trả lời các câu hỏi cô đưa ra.
- Kết thúc.
  #                                                        --- Thank you ^^ The end! ---
