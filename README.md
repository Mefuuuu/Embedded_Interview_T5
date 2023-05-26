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
- ***Function***: Xử lý bởi compiler

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
  
  . Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline `function` nhưng `*code* ngắn gọn hơn`.
# Bài 4 Thao tác bit
 - Biểu thức AND: Ký hiệu `&`
![example](Untitledand.png)
```c
unsigned int a = 5;  // 0101
unsigned int b = 3;  // 0011
unsigned int result = a & b;  // 0001
```
- Biểu thức NOT: Ký hiệu `~`
![example](Untitlenotd.png)
```c
unsigned int a = 5;  // 0101
unsigned int result = ~a;  // 1010 (đảo ngược các bit)
```
 - Biểu thức OR: Ký hiệu `|`
![example](UntitleORd.png)
```c
unsigned int a = 5;  // 0101
unsigned int b = 3;  // 0011
unsigned int result = a | b;  // 0111
```
 - Biểu thức XOR: Ký hiệu `^`
![example](UntiXXXXortled.png)
```c
unsigned int a = 5;  // 0101
unsigned int b = 3;  // 0011
unsigned int result = a ^ b;  // 0110
```
 
 - Dịch trái: Ký hiệu `<<`
```c
unsigned int a = 5;  // 0101
unsigned int result = a << 2;  // 010100 (dịch trái 2 vị trí)   
```
 - Dịch phải: Ký hiệu `>>`
```c
unsigned int a = 5;  // 0101
unsigned int result = a >> 2;  // 0001 (dịch phải 2 vị trí) 
```
# Bài 5 STRUCT - UNION
- ***Struct***
  . In ra size: ```printf("Size: %lu", sizeof(struct typeDate));```
  . Cách tính số size. VD:
```c
struct typeDate
{
    uint8_t arr1[4]; // 1 byte
    uint16_t arr2[2]; // 2 byte
    uint64_t arr3[5]; // 8 byte
    uint32_t arr4[4]; // 4 byte
};
```
Số byte cần quét trong 1 lần = 8 byte(vì uint64_t là lớn nhất)

uint8_t có size 1 byte => arr1[4] cần 1*4 = 4 byte để lưu, mà 1 lần quét là 8 byte

=> arr1[4] = 4byte + 4byte bộ nhớ đệm

uint16_t có size 2 byte => arr2[2] cần 2*2 = 4 byte để lưu, mà ở trên còn dư 4 byte, nên lúc này ta chèn vào byte bộ nhớ đệm ở trên

=> arr2[2] = 4 byte (byte của arr2 vào bộ nhớ đệm trên arr1) + 4 byte (byte của arr1) => dùng 1 lần quét

int64_t có size 8 byte => arr3[5] cần 8*5 = 40 byte để lưu => dùng 5 lần quét

uint32_t có size 4 byte => arr4[4] cần 4*4 = 16  byte để lưu

=> arr4[4] = 2*4 + 2*4 = 16 byte => dùng 2 lần quét

=> Tổng size = 4 byte + 4 byte + 40 byte + 16 byte = 64 byte (= 8 lần quét 8 byte)

- ***UNION***
```c
typedef union
{
   //size union = size thành viên lớn nhất
   uint8_t test1[3]; // 3 byte
   uint8_t test2[2]; // 2 byte
}data_union;
```
- ***So sánh Struct - Union***
Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

  .Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
  . Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
# Bài 6 EXTERN - STATIC
- ***Extern***
  . Biến extern được sử dụng khi một file cụ thể cần truy cập `một biến từ file khác`.
```c
// file main.c
#include <stdio.h>
extern int count; // sử dụng biến count ở file test
extern void dem(); //sử dụng hàm ở file test
int main ()
{
   printf("count: %d\n",count);
   dem();
   dem();
   return 0; 
  /* Dùng lệnh: gcc main.c test.c -o main
              ./main
   Kết quả:   16 
              16
              17 
   */
}
```
```c
// flie test.c  
int count = 16;

void dem(){
    printf("count = %d\n",count);
    count++;
}
```
- ***Static***
  . **Static cục bộ**
    Biến được khởi tạo 1 lần và tồn tại suốt vòng đời chương trình và giá trị không bị mất đi ngay cả khi kết thúc hàm.
  VD:
  ```c
  void test(){
    static int a = 10;
    printf("%d\n", a++);
  }
  test();
  test();
  test();
  Kết quả: 10 11 12
  ```
  . **Static toàn cục ***
  Giống như biến toàn cục nhưng sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không thể truy cập được kể cả dùng từ khóa extern
  VD:
  ```c
  static int a = 10;
  void test(){
    printf("%d\n", a++);
  }
  test();
  test();
  test();
  Kết quả: 10 11 12
# Bài 7 POINTER
- ***Khái niệm***
  . Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.
  . Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.
![bieudien_contro](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/48c4f945-0384-40ab-8c52-5b1db3610eaf)

***1. Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
`int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào`

***2. Con trỏ hàm:*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ
```c
int phepCong(int a, int b) {
 	return a + b;
 }
 int phepTru(int a, int b) {
 	return a - b;
 }

 int main() {
 
 	int (*ptr)(int, int) = phepCong;
 	int result = ptr(5, 3);
 	printf("Result: %d\n", result);

 	ptr = phepTru;
 	result = ptr(5, 3);
 	printf("Result: %d\n", result);

 	return 0;
 }
 ```
 ***3. Con trỏ void:*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
 ```c
int num = 10;
 float f = 3.14;
 void *ptr;
 ptr = &num;
 printf("num = %d\n",(int*)ptr);
 ptr = &f;
 printf("f = %f\n",(float*)ptr);
 ```
***4. Con trỏ hàm:*** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.
```c
 int cong(int a, int b) {
 	return a + b;
 }
 int tru(int a, int b) {
 	return a - b;
 }

 void pheptinh(int a, int b, int (*ptr)(int, int)) {
 	int result = ptr(a, b);
 	printf("Result: %d\n", result);
 }

 int main() {
 	int a = 4, b = 2;

 	pheptinh(a, b, cong);
 	pheptinh(a, b, tru);

 	return 0;
 }
 ```
 ***5. Pointer to pointer:*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác
 ```c
 ```
