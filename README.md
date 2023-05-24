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

  . VD: ``` uint8_t* arr = (uint8_t*) malloc(sizeof(uint8_t)*5);``` Như vậy ta có một mảng có kích thước 5 byte.

Chúng ta có thể thay đổi kích thước mảng bằng cách sử dụng hàm `calloc` như sau, 

  . VD: ``` uint8_t* arr = (uint8_t*)calloc(3, sizeof(uint8_t));``` Như vậy ta có một mảng có kích thước là 3 byte.

Sự khác biệt giữa `calloc` và `malloc` là hàm calloc sẽ gán giá trị = 0 một cách tự động cho các phần tử trong mảng mà người dùng khởi tạo. Hơn nữa còn khác biệt về mặt tốc độ. Tuy nhiên trong quá trình làm việc sẽ sử dụng hàm `malloc` nhiều hơn
# Bài 3 Macro Inline Function
- ***Marco***: Xử lý bởi preprocessor

  . Được diễn ra ở quá trình tiền xử lý. Macro thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó.
  
  . VD: 
  ```c
  #define MAX 10 
  
  Khi gặp bất kỳ lời gọi MAX nào thì thay ngay bằng 10
  
  #define SUM(a,b) a + b
  
  Khi gặp bất kỳ lời gọi SUM(L,R) nào thì thay ngay bằng (L+R)
  ```
  . VD:
  ```c
  #define CREATE_FUNC(ten_ham, noi_dung)    \
  void ten_ham(){                           \
    printf("%s\n",noi_dung);               \
  }
  CREATE_FUNC(test,"this is test\n"); 
   /*
  void test(){                           
    printf("%s\n","this is test\n");       
  }
   */
   // Kết quả in ra được sẽ là: this is test
   ```
- ***Function***: 

  . Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
  
  . Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function)
  
- ***Inline***: Xử lý bởi compiler

  . Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compiler
  
- ***So sánh***

  . Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
  
  . Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi.
  
  . Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
  
  . `Macro` khiến code trở nên dài hơn rất nhiều so với bình thường nhưng `thời gian chạy nhanh`.
  
  . Hàm `inline` cũng khiến code dài hơn, tuy nhiên nó làm `giảm thời gian` chạy chương trình.
  
  . Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline `function` nhưng `code ngắn gọn hơn`.
   
   
   
 






































