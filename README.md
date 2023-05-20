# Embedded_Interview_T5
# Bài 1 Compiler
Compiler hay còn gọi là trình biên dịch giúp chuyển đổi ngôn ngữ code sang ngôn ngữ cho máy tính hiểu

`GCC Compiler` là một trong những Compiler miễn phí có thể dùng khi học

Quá trình này được diễn ra như sau:

- Trước tiên chúng ta có Source code với file có đuôi `.c`, `.h`, `.cpp` qua giai đoạn `Preprocessor` hay còn được gọi là quá trình tiền xử lý sang dạg file `.i` được gọi là `Preprocessed source`. Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.c` để xem code sau khi qua quá trình preprocessor.

 + Quá trình này bao gồm những việc: 

   . Gán define, thay thế giá trị các chỗ gọi marco
  
   . Lấy dữ liệu trong các thư mục thư viện
  
_Các ngôn ngữ lập trình bậc cao như python được thiết kế để giúp lập trình viên viết mã nguồn dễ hiểu và dễ bảo trì hơn. Nhưng máy tính chỉ có thể hiểu được mã máy. Mà ngôn ngữ C gần với ngôn ngữ máy, nên chúng ta không sử dụng ngôn ngữ lập trình bậc cao_

- Compiler là quá trình tiếp theo chuyển file `.i` sang file `.s` hay còn được gọi là file Assembly code. Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code quá trình này

- Quá trình Assembler là quá trình tiếp theo chuyển file `.s` sang file `.o` hoặc `.obj` tại đây thì các file thư viện của âm thanh và hình ảnh sẽ được thêm vào

- Linker là quá trình cuối cùng chuyển dạng file trên thành dạng file `.exe` để người dùng có thể sử dụng

![maxresdefault](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/0f8ca122-dbff-4767-a02c-b0d2bfc138b4)
# Bài 2 Memory Layout
Vùng nhớ `RAM` là nơi dữ liệu khởi tạo

Tài nguyên trên vi điều khiển là không nhiều cho nên cần tối ưu bộ nhớ

**Vùng nhớ**

   ![Unt1321itled](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/85489a2f-d642-4688-a16e-37229df6ba81)
- Text:

  . Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.

  . Chứa khai báo hằng số trong chương trình (.rodata). VD: ```const int a = 100;```

- Data:

  . Quyền truy cập là read-write.
  
  . Chứa biến toàn cục or biến static với giá trị khởi tạo khác không. VD: ```static int b = 100;```
  
  . Được giải phóng khi kết thúc chương trình.

- BSS:

  . Quyền truy cập là read-write.
  
  . Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
  
  . Được giải phóng khi kết thúc chương trình.
  
- Stack:
  . Quyền truy cập là read-write.
  
  . Được sử dụng cấp phát cho biến local, input parameter của hàm,…

  . Sẽ được giải phóng khi ra khỏi block code/hàm
  
- Heap:

  . Quyền truy cập là read-write.
  
  . Được sử dụng để cấp phát bộ nhớ động như: `Malloc`, `Calloc`, ...
  
  . Sẽ được giải phóng khi gọi hàm free, ...
  
------***HINT***------
  
Để cấp phát bộ nhớ động ta có, 

  . VD: ```uint8_t* arr = (uint8_t*) malloc(sizeof(uint8_t)*5);``` Như vậy ta có một mảng có kích thước 5 byte.

Chúng ta có thể thay đổi kích thước mảng bằng cách sử dụng hàm `calloc` như sau, 

  . VD: ``` uint8_t* arr = (uint8_t*)calloc(3, sizeof(uint8_t));``` Như vậy ta có một mảng có kích thước là 3 byte.

Sự khác biệt giữa `calloc` và `malloc` là hàm calloc sẽ gán giá trị = 0 một cách tự động cho các phần tử trong mảng mà người dùng khởi tạo. Hơn nữa còn khác biệt về mặt tốc độ. Tuy nhiên trong quá trình làm việc sẽ sử dụng hàm `malloc` nhiều hơn
# Bài 3 Macro And Function








































