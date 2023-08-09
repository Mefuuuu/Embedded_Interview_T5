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
.Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file ".o" và dùng lệnh `objdump -d -Mintel filename.o` để xem code.

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

***So sánh Stack và Heap?***
- Bộ nhớ: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
  
  . Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên 
    dịch.
  
  . Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)

- Kích thước vùng nhớ:
  
  . Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là 
    con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
  
  . Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
  
- Đặc điểm vùng nhớ
  
  . Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
  
  . Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn 
    phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.
  
***Lưu ý:***

- Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
  
- Vấn đề lỗi xảy ra đối với vùng nhớ Stack: Bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack 
    chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,..

  . VD: về tràn bộ nhớ stack với hàm đệ quy vô hạn:
  
```c
int foo(int x){
 	printf("De quy khong gioi han\n");
 	return foo(x);
 }
```

- Vấn đề lỗi xảy ra đối với vùng nhớ Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

  . VD: trường hợp khởi tạo vùng nhớ Heap quá lớn:

```c
 int *A = (int *)malloc(18446744073709551615); 
```

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
 
 ![Untitledand](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/c1b43504-0e2e-4d14-bf97-0df205d2a67d)

```c
unsigned int a = 5;  // 0101
unsigned int b = 3;  // 0011
unsigned int result = a & b;  // 0001
```
- Biểu thức NOT: Ký hiệu `~`

![Untitlenotd](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/f9aacd8d-e7c8-45c0-abc1-8b5d089133bb)

```c
unsigned int a = 5;  // 0101
unsigned int result = ~a;  // 1010 (đảo ngược các bit)
```
 - Biểu thức OR: Ký hiệu `|`
 
 ![UntitleORd](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/ef081814-cde0-47d7-ab48-e7b2989b0fd0)

```c
unsigned int a = 5;  // 0101
unsigned int b = 3;  // 0011
unsigned int result = a | b;  // 0111
```
 - Biểu thức XOR: Ký hiệu `^`
 
 ![UntiXXXXortled](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/3b2d8ea8-fd1b-4637-a0e4-33c9f6bc4b00)

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
- 
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
  . **Static toàn cục **
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
- Thông qua con trỏ hàm, có thể dùng hàm để làm input parameter của hàm khác

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


 ***4. Pointer to pointer:*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác
 
`int* ptr = 10;` bản chất của nó cũng là biến nên cũng sẽ có địa chỉ và giá trị

`int **ptp = 0xc1;` pointer to pointer là con trỏ lưu địa chỉ của con trỏ
 ```c
 int n = 10;
 int *ptr = &n;     // Con trỏ ptr trỏ đến biến n và giá trị của ptr chính là địa chỉ của biến n
 int **ptp = &ptr;	 // Con trỏ ptp trỏ đến con trỏ ptr và lưu địa chỉ của con trỏ ptr vào ptp

 printf("Giá trị của n: %d\n", *ptr); //Giá trị của n: 10
 printf("Địa chỉ của n: %p\n", ptr); //Địa chỉ của n: 0x7ffee2a697a8 
 printf("Giá trị của n: %d\n", **ptp); //Giá trị của n: 10
 printf("Địa chỉ của ptp: %p\n", ptp); //Địa chỉ của ptr: 0x7ffee2a697a0
 ```
# Bài 8 Class
Class là một cấu trúc dữ liệu tự định nghĩa, nó cho phép lập trình viên tạo ra các đối tượng (objects) mới có cùng bản chất.

Các biến được khai báo trong class được gọi là các property và các hàm được khai báo trong class được gọi là các method
```c
class SinhVien{
    public:
        int tuoi; //property
        int lop;  //property
        void hienThi();//method
};

void SinhVien::hienThi(){
    cout<<"Tuoi: "<<tuoi<<endl; 
    cout<<"Lop:  "<<lop<<endl;
}; //method

int main(){

    SinhVien sv; //object

    sv.tuoi = 10;
    sv.lop = 3;

    sv.hienThi();

    return 0;
```
`Struct` không thể tạo các hàm, chỉ có thể định nghĩa hàm. Nhưng `class` có thể

- Có 3 phạm vi truy cập trong C++ là public, private và protected.

 . `Public`: Các member được khai báo trong Public thì các Object có thể truy cập trực tiếp tới được. Và các User có thể sử dụng và thay đổi các giá trị trong các member này
 
 . `Private`: Được sử dụng khi bạn muốn chặn User truy cập vào những member khai báo trong phạm vi này, giới hạn truy cập và sửa đổi giá trị của chúng. Sử dụng các member trong Public để truy cập đến các member trong Private.
 
 . `Protected`: Tương tự như Private, nhưng Private thì các class con không thể kết thừa được các member trong Private của class chính, còn Protected thì lại cho phép các class con có thể kế thừa được các member trong protected của class chính.
 
- Constructor

 . Hàm khởi tạo là hàm có tên trùng với tên class, code đầu tiên, nằm ở phạm vi truy cập public, có thể có input parameters hoặc không.
```c
class SinhVien{
	public: 
		SinhVien(int tuoi, int lop); // có tên hàm trùng với tên của class gọi là contructor
		void hienThi(); //method	
	private: 
		int tuoi; //property
		int lop; //property
};

void SinhVien::hienThi(){
	cout<<"Tuoi: "<<tuoi<<endl;  
	cout<<"Lop "<<lop<<endl;
} //method

SinhVien::SinhVien(int tuoi,int lop){
	SinhVien::tuoi = tuoi; //class SinhVien có thể truy cập đến tất cả nhưng member nằm trong nó
	SinhVien::lop = lop;
}

int main(){
	// khi có contructor thì nó luôn luôn chạy đầu tiên khi object được khởi tạo.
	SinhVien sv(20,13); //có thể gán giá trị trực tiếp vào khai báo ở public
	sv.hienThi();
	return 0;
}
```
- Biến static trong class

  . Khai báo trước trong form sau đó khởi tạo bên ngoài

  . Biến static trong class có chung một địa chỉ khởi tạo và tồn tại hết vòng đời chương trình.

```c
class SinhVien{
	public:
		static int tuoi; // phải khởi tạo lần đầu ở ngoài
};

int SinhVien::tuoi; 

int main(){
	
	SinhVien sv1,sv2;
	sv1.tuoi = 10;
	sv2.tuoi = 30;
	printf("%d\n", sv1.tuoi);    // in ra = 30
	////về địa chỉ của hai object thì giống với struct. sv1 và sv2 sẽ được cấp vùng nhớ khác  với kích thước là tổng kích thước của các member và bộ nhớ đệm, địa chỉ của nó sẽ là địa chỉ của member đầu tiên, và các member sẽ mang đỉa chỉ khác nhau như trong struct.
	return 0;
}
```
# Bài 9 OOP
- Có 4 đặc tính: Tính đa hình, tính kế thừa, tính trừu tượng, tính đóng gói.
  
  . `Tính đa hình`: tính đa hình có thể tóm gọn lại là chúng ta có thể tạo nhiều hàm giống nhau (trùng tên) nhưng khác input paramter
```c
class ToanHoc{
    public:
        void tong(int a, int b);
        void tong(int a, int b, int c);
        int tong(double a, double b);
}
```
   . `Tính kế thừa`: Một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó. Chỉ có `Public` và `Protected` mới được kế thừa còn `Private` thì không được kế thừa, muốn kế thừa được các member trong `Private` buộc phải đổi lại `Protected`.

   . `Tính trừu tượng`: Là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Là chỉ những thứ cần thiết mà người dùng cần sử dụng thì được nằm ở `public` còn tính toán phức tạp mà người dùng không quan tâm đến thì nằm ở `private`.
```c
public: 
	void nhapABC(); -> Người dùng quan tâm và dễ sử dụng 
	void getX1X2();
private: 
	int getdelTa(); -> Chương trình phức tạp người dùng không quan tâm 
```

  . `Tính đóng gói`: trong lập trình hướng đối tượng có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, 
mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên 
ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.
```c
class ToanHoc{
    public:
        void nhapABC();
        void getX1X2(); 
    private:
        int A; // người dùng nhập
        int B; // người dùng nhập
        int C; // người dùng nhập
        int X1; // lấy ra cho người dùng xem, người dùng không được can thiệp 
        int X2; // lấy ra cho người dùng xem, người dùng không được can thiệp 
        int delta; 
        int getDelta();
}
```

## Namespace
`Namespace` là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

Khi tạo `namespace` nếu muốn dùng chung tên biến của các member thì khi khai báo tên của `namespace` thì phải khai báo tên khác nhau

Nếu dùng chung tên của `namespace` thì tên của các member phải khác nhau (dù có chung file hay khác file), Do khai báo cùng tên `namespace` thì dùng chung bộ nhớ nên nếu tên các member cũng giống thì những member giống nhau sẽ cùng chung 1 địa thì sẽ dẫn đến xung đột vùng nhớ

```c
namespace conOngA{
    int A = 10;
}
namspace conOngB{
    int A = 20;
}
```
## Template
Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...

Template trong C++ có 2 loại đó là function template & class template.

Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.
```c
 int tong(int a, int b);
 double tong(double a, double b);
 template<typename var> //thay vì ta code hai hàm riêng để xử lý, thì ta có thể code dùng template chung lại để gọn code hơn.
 	int tong(var a, var b){
 		return (var)(a+b);
 	}
```
# BÀI 10 VECTOR
## Vector

- Vector là một cấu trúc dữ liệu trong C++ dùng để chứa các đối tượng khác. Tương tự như mảng (array), vector cũng có thể chứa nhiều phần tử.

- Các phần tử trong vector được lưu trữ một cách liên tiếp trong bộ nhớ. Điều này cho phép truy cập dễ dàng đến các phần tử bằng cách sử dụng chỉ số (index).

- Vector khác mảng thông thường là kích thước của vector có thể thay đổi trong quá trình thực thi chương trình. Khi cần, vector có thể mở rộng (tăng kích thước) hoặc thu hẹp (giảm kích thước) để chứa thêm hoặc loại bỏ các phần tử.

- Sử dụng thư viện #include<vector>.
- Khai báo vector :
```c
vector <int> array
```
- Các hàm thường dùng

array.push_back(9); -> thêm một phần tử ở phía sau vector

array.size() -> trả về kích thước vector

array.pop_back() -> xóa phần tử phía sau cùng vector

array.insert(array.begin() + 3, 7)  -> thêm phần tử vào vị trí thứ ba, hàm array.begin() trả về địa chỉ đầu tiên

array.clear(); -> Hàm thu hồi bộ nhớ, vector hoạt động dựa trên cấp phát động nên khi dùng xong ta phải thu hồi vùng nhớ

array.erase(array.begin()+2); -> xóa phần tử theo địa chỉ

array.assign(8,5); -> tạo ra một vector có 8 phần tử và gán giá trị bằng 5.

### For each

Có thể sử dụng hàm for sau đây thay cho cách duyệt mảng truyền thống
```c
for (int item : array){
	printf(" i = %d\n",item);
}
```

### Auto

Khi khai báo biến mà không xác định được kiểu dữ liệu thì dùng từ khóa auto sẽ tự kiểm tra dữ liệu được gán là kiểu dữ liệu nào thì nó tự động là kiểu dữ liệu đó, kể cả con trỏ .
```c
int a = 10; 
auto data = &a; 
```
## List
- List là một cấu trúc dữ liệu danh sách liên kết kép (doubly linked list).

- Các phần tử của nó không được lưu trong các địa chỉ liên tiếp mà lưu ở địa chỉ bất kì, và mỗi phần tử trước sẽ lưu kèm địa chỉ của phần tử kế tiếp theo tuần tự. Riêng phần tử cuối cùng sẽ lưu địa chỉ là null
  
- Vì cung cấp một danh sách các phần tử được liên kết với nhau bằng các con trỏ, cho phép thêm, xóa và truy cập các phần tử một cách linh hoạt.

- Dùng thư viện #include<list>.
```c
#include<list>

typedef struct 
{
    int value;
    node *next;
}node;

int main(int argc, char const *argv[])
{
    list<int> array;	// khai báo mảng kiểu int
    array.push_back(4);  //thêm phần tử thứ 0 là 4
    array.push_back(8);  //thêm phần tử thứ 1 là 8
    array.push_back(20);
    array.push_back(15); //thêm phần tử thứ 4 là 15
 
    for(auto item : array){ 
 	    printf("i = %d\n",item);
    }   
    return 0;
}
```
`So sánh` giữa list và mảng thường:

Với mảng thông thường cho phép tốc độ xử lý nhanh, do các địa chỉ liền kề nhau, tuy nhiên nếu phải thêm một phần tử bất kỳ nào đó khiến mảng phải dời ra sau nhiều lần, xử lý chậm hơn do phải thực hiện nhiều lần.

Còn với Linked list thêm 1 giá trị vào rất dễ dàng, tuy nhiên nếu duyệt thì cũng phải tốn nhiều bước hơn, đọc giá trị rồi đọc địa chỉ của giá trị kế tiếp, chậm hơn so với duyệt liên tiếp các địa chỉ liền kề
## Map
- Là một cấu trúc dữ liệu ánh xạ trong thư viện chuẩn của ngôn ngữ. Nó được sử dụng để lưu trữ các cặp key-value, trong đó mỗi key là duy nhất và liên kết với một giá trị (value) tương ứng.

- Key và value có thể là nhiều kiểu dữ liệu khác nhau như string, int, double , ...

- Dùng thư viện #include<map>.
```c
#include <map>
int main(){
map <string, int> Sinhvien; 

    Sinhvien["ID"] = 101;
    Sinhvien["Lop"] = 7; 
    Sinhvien["Tuoi"] = 13; 

    for (auto item : Sinhvien){
        printf("Key: %s, value: %d \n",item.first.c_str(), item.second);
    }
    return 0;
 }
```
## Ưu điểm và nhược điểm của Vector, List và Map:
![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/1df847e7-fe8e-43ef-846f-b0b9bbc40f5e)

# Bài 12 Hàm ảo Virtual function 
Khi 2 hàm giống nhau được gọi trực tiếp từ hàm main mà không có từ khóa virtual để phân biệt thì luôn được gọi từ class cha, khi thêm từ khóa virtual vào thì chương trình sẽ biết mà load lại địa chỉ từ class con.

Từ khóa virtual cũng như thông báo cho PC xem class con có ghi đè hàm hay không.

2 hàm trùng tên tồn tại ở cả class con và class cha thì được gọi là ghi đè (overide)

Khi class con có hàm trùng tên và được gọi từ main thì sẽ load lại địa chỉ từ class con (overloading)

## Tham chiếu và tham trị

Sự khác biệt giữ tham chiếu và tham trị rõ ràng nhất là trong các bài tập về list, vì các thành phần trong list chỉ có thể được thay đổi dựa trên địa chỉ nên khi muốn thay đổi thì phải truyền vào 1 địa chỉ.

Tham trị chẳng qua là hàm sẽ tạo ra một bản sao khác so với biến được truyền vào, thực chất là 2 biến khác nhau và mang 2 địa chỉ riêng biệt, thay đổi giá trị của biến này thì không ảnh hướng đến biến kia và ngược lại.

Tham chiếu có thể được thực hiện ở C++ bằng cách thêm dấu & trước input argument, thì bản chất biến được truyền vào hàm đó chính là nó.

```c
#include <iostream> 
using namespace std; 

void test(int a, int &b, int *c){
    a = 10; 
    b = 20; 
    *c = 30; 
}

int main(int argc, char const *argv[])
{
    int x = 1; 
    int y = 2; 
    int z = 3; 
    test(x,y,&z); 
    cout << x << endl; // x = 1
    cout << y << endl; // y = 20
    cout << z << endl; // z = 30
    return 0;
} 
```
Trong ví dụ trên thì in ra chỉ có y và z là thay đổi giá trị còn x thì không; cách thứ ba là truyền vào hàm 1 con trỏ, bản chất con trỏ là lưu địa chỉ của biến nên có thể thay đổi giá trị mà địa chỉ đó trỏ đến.

## Lambda funtion

Lambda function cho phép định nghĩa và sử dụng 1 hàm ngay trong hàm chính, không cần phải khai báo toàn cục và trỏ tới 1 hàm khác như con trỏ hàm

Cú pháp: capture clause -> return-type { definition of method; };

`VD`:
```c
int a = 10; 
auto test = [a](int b){
    return a - b; 
};
cout << test(6); 
```
```c
auto tong = [](int a, int b){
    return a +b; 
};
```
`Lợi ích`:
- Con trỏ PC không phải trỏ nhiều, liển mạch chương trình -> chạy nhanh hơn
- Không tốn nhiều bộ nhớ (không phải tốn các địa chỉ để lưu hàm như hàm local, global).

`Mở rộng`:

```c
int d;
int f;
int z;

auto tong [=]{
    return d+f+z; 
}
```
Thêm dấu bằng vào thì nó tự hiểu được các biến được dùng trong hàm là các biến được khai báo bên trên, không cần phải liệt kê.

## Iterator

Khi làm việc với list,vector,... chúng được gọi là container, khi duyệt thì ta dùng iterator.

```c
list<int>::interator it; 
for (it = array.begin(); it!= array.end(); ++it){
    cout << *it << endl; 
    if (*it == 6){
        array.erase(it); 
    }
}
```

Iterator sẽ lưu địa chỉ các node.

## Destructor

Hàm hủy

```c

#include <iostream>

using namespace std; 

class SinhVien
{
private:
    int ID;
    int *ptr; 
public:
    SinhVien(/* args */);
    ~SinhVien();
    int getID(){
        return this->ID; 
    }
};

SinhVien::SinhVien(/* args */)
{
    static int id = 100; 
    ID = id; 
    ptr = &id;
    id++; 
}

SinhVien::~SinhVien()
{
    *ptr = 100; 
}

void test1(){
    SinhVien sv1,sv2; 
    cout << sv1.getID() << endl; 
    cout << sv2.getID() << endl; 
}
void test2(){
    SinhVien sv1,sv2; 
    cout << sv1.getID() << endl; 
    cout << sv2.getID() << endl; 
}
int main(int argc, char const *argv[])
{
    test1();
    test2(); 
    return 0;
}
```

Khi khởi tạo 1 object thì vùng nhớ mà nó khởi tạo là vùng nhớ stack khi hủy thì sẽ hoạt động theo kiểu LIFO , Last In First Out, cái nào được khởi tạo cuối cùng thì sẽ được hủy trước, cách hoạt động của stack.

# Bài 13 EMBEDDED
## Giao thức SPI:

- Là 1 chuẩn giao tiếp nối tiếp tốc độ cao.
  
  . Các bit dữ liệu được truyền nối tiếp và có xung clock đồng bộ.
  
  . Giao tiếp song công, có thể truyền và nhận tại cùng một thời điểm.
  
  . Khoảng cách truyền ngắn, tốc độ truyền khoảng vài Mb/s.
  
  . Có thể chỉ gồm 1 master và 1 slave, hoặc 1 master và nhiều slave.

- SPI gồm có 4 đường tín hiệu:
  
  . SCK: xung clock
  
  . MOSI: Master Out, Slave In
  
  . MISO: Master In, Slave Out
  
  . SS: Slave select

- Cách truyền và nhận tín hiệu
  
  ![spi](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/b32da950-9081-42e4-8db7-e5bb2a3c5e0e)

  . Master và slave đều có 1 thanh ghi dữ liệu 8 bit chứa dữ liệu cần gửi đi hoặc dữ liệu nhận về.
  
  . Đối với có nhiều slave, master muốn giao tiếp với slave sẽ thông qua chân SS, để giao tiếp với slave nào thì master sẽ kéo chân SS nối với slave đó xuống mức 
    thấp, các chân SS nối với các slave khác sẽ ở mức cao.
  
  ![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/ff6b6a08-265e-4202-9b22-b02008cb49a6)
  
  . Cứ mỗi xung nhịp Clock, một bit trong thanh ghi dữ liệu của Master sẽ được truyền qua Slave thông qua chân MOSI, và 1 bit trong thanh ghi dữ liệu trong Slave sẽ 
    được truyền qua Master thông qua chân MISO.

- Các chế độ hoạt đông: Có 4 chế độ hoạt động sẽ tùy thuộc vào CPOL và CPAL
  
  ![Screenshot 2023-08-04 165022](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/40980859-7986-46df-9b4c-21640f3d3a0c)

  . CPOL:nói về hình dạng xung * CPOL = 0: đầu tiên hình dạng xung ở mức 0 sau đó lên mức 1 và kéo lại xuống 0. * SPOL = 1: khi không truyền data sẽ ở mức 1 sau đó 
    kéo xuống 0 và kéo lại lên 1.
  
  . CPAL: nói về cách truyền data * CPAL = 0: đưa bit vào chân truyền trước sau đó cần xung clock để đẩy bit data đi * CPAL = 1: đưa xung clock trước sau đó mới đưa 
    bit data vào và cần 1 xung clock tiếp theo để đẩy bit data đi.

## Giao thức I2C:

- Chỉ sử dụng 2 dây: SDA (truyền và nhận data) và SCL (xung Clock)

  ![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/dde8e159-b43c-4070-b67d-9e80cf2badbd)

- I2C là một giao thức truyền thông nối tiếp vì vậy dữ liệu sẽ được truyền từng bit dọc theo một đường duy nhất ( đường SDA).

- Khi Master không giao tiếp với Slave thì 2 chân SDA và SCL sẽ ở mức cao

- Cách hoạt động của I2C: dữ liệu sẽ được truyền trong các tin nhắn. Tin nhắn sẽ được chia thành các khung dữ liệu. Mỗi tin nhắn sẽ bao gồm điều kiện khởi động, khung địa chỉ ( address frame), read/write bit, ACK/NACK bit, data frame, điều kiện dừng.

![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/d1c76110-8126-46a2-b62d-ef76a1577aa7)

![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/b4eda1dc-b232-4d62-a7ac-eefbfc21e69a)

  . Start condition: SDA sẽ chuyển từ mức cao xuống mức thấp sau đó SCL sẽ chuyển tử mức cao xuống thấp
  
  . Address frame: gồm 7 hoặc 10 bit để xác định slave khi master muốn giao tiếp với slave đó
  
  . Read/Write bit: giúp xác định Master sẽ truyền dữ liệu ( tức là write khi bit này = 0) hay nhận dữ liệu ( tức là read khi bit này = 1)
  
  . ACK/NACK bit: khi master truyền 1 byte đến slave, lúc này dây SDA sẽ đổi trạng thái đầu vào ra (MASTER sẽ là đầu vào, SLAVE sẽ là đầu ra) sau đó salve sẽ truyền 
    bit 0 đến master để xác nhận rằng slave đã nhận đủ 1 byte, hoặc truyền bit 1 để thông báo không nhận đủ 1 byte.
  
  . Data frame: sau khi nhận được bít ACK từ slave, data sẽ sẵn sàng được gửi đi. khung dữ liệu sẽ có độ dài 8 bit, các bit sẽ được truyền dọc theo dây SDA, và mỗi 
    khung dữ liệu như vậy sẽ có đi kèm theo bít ACK/NACK để xác nhận rằng có gửi thành công hay không
  
  . Stop condition: sau khi đã gửi hết các data, master sẽ gửi một stop bit để dừng quá trình truyền. SCL sẽ chuyển từ mức 0 lên mức 1 sau đó SDA sẽ chuyển tử mức 0 
    lên 1.

## Giao thức UART:

![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/10293572-79e0-4034-8acc-b3820f3f346e)

- Gồm 2 chân: Tx và Rx, khi không truyền thì cả 2 chân đều kéo lên mức 1

- Chân Tx của 1 chip sẽ kết nối trức tiếp với chân Rx của chip kia và ngược lại. UART là giao thức một master và một slave.
  
- Khi gửi trên chân Tx, UART đầu tiên sẽ dịch thông tin song song này thành nối tiếp và truyền đến thiết bị nhận, UART thứ hai nhận dữ liệu này trên chân Rx của nó và biến 
  đổi nó trở lại thành song song để giao tiếp với thiết bị điều khiển của nó.

- Có 3 chế độ truyền UART:
  . Full duplex: Giao tiếp đồng thời đến và đi từ mỗi master và slave
  
  . Half duplex: Dữ liệu đi theo một hướng tại một thời điểm
  
  . Simplex: Chỉ giao tiếp một chiều
  
- Dữ liệu truyền qua UART được tổ chức thành các gói. Mỗi gói chứa 1 bit bắt đầu, 5 đến 9 bit dữ liệu (tùy thuộc vào UART), một bit chẵn lẻ tùy chọn và 1 hoặc 2 bit dừng.
  
  ![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/02cfd8f1-6f31-4d63-ab66-adedaf1573c4)

  ![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/d7ce307b-6ba0-4e3a-96ae-4e674313913d)

  . Start bit: UART thường ở mức cao khi không truyền tín hiệu. Để truyền tín hiệu, UART truyền sẽ kéo Tx từ cao xuống thấp trong 1 chu kì clock, khi UART nhận thấy được thay 
    đổi đó nó sẽ bắt đầu đọc các bit trong khung dữ liệu
  
  . Khung dữ liệu: gồm 5 đến 8 bit nếu có bit chẵn lẻ, hoặc có thể lên đến 9 bit data khi không có bit chẵn lẻ.
  
  . Bit chẵn lẻ: để nhận biết có sự thay đổi dữ liệu trong quá trình truyền hay không. Sau khi nhận được khung data, nó sẽ đếm xem thử số bit 1 là bao nhiêu và kiểm tra xem 
    nó là chẵn hay lẻ. Đối với quy tắc số chẵn, nếu tổng bit 1 trong khung data là số chẵn thì bit chẳn/lẻ = 0, và ngược lại. Đối với quy tắc lẻ, nếu tổng bit 1 trong khung 
    data là số chẵn thì bit chẳn/lẻ = 1, và ngược lại
  
  . Stop bit: để báo hiệu kết thúc gói dữ liệu. Đối với 1 bit stop, Tx sẽ kéo từ 0 lên 1. Đối với 2 bit stop, Tx sẽ kéo từ 0 lên 1, kéo lại xuống mức 0 sau đó delay, rồi kéo 
    lại lên mức 1.

## Ngắt (Interrupt):

- Ngắt là một sự kiện khẩn cấp, buộc vi điều khiển phải tạm dừng chương trình hiện tại, và phục vụ ngay lập tức nhiệm vụ mà ngắt yêu cầu.

- Ngắt có độ ưu tiên cao hơn chương trình chính
  
- Cần phải có trình phục vụ ngắt (ISR) để đưa ra nhiệm vụ cho vđk khi có ngắt xảy ra.
  
- Bảng vector ngắt chứa các ngắt mà ta muốn sử dụng ( bao gồm reset, ngắt ngoài, ngắt truyền thông, ngắt timer)

- Có rất nhiều loại ngắt, muốn sử dụng ngắt nào thì đăng ký vào bảng vector ngắt thì các ngắt đó mới được hoạt động

  ![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/03370ca3-8937-42c2-923c-3c96340b7897)

- Mỗi ngắt sẽ có 1 địa chỉ khác nhau và stt ngắt càng thấp thì độ ưu tiên càng cao. Khi có ngắt xảy ra, PC sẽ chạy tới địa chỉ ngắt đó và thực hiện.
  
***- Ngắt ngoài:***

- Vi điều khiển sẽ có một số chân hỗ trợ ngắt, ngắt ngoài là một tín hiệu được tạo ra từ bên ngoài vi điều khiển (thường là một ngõ vào hoặc cảm biến) và được sử dụng để tạm dừng thực thi chương trình hiện tại, để thực hiện một hàm xử lý ngắt.
  
- 4 loại trạng thái ngắt
  
  . LOW: kích hoạt trạng thái chân input mức thấp
  
  . HIGH: kích hoạt trạng thái chân input mức cao
  
  . RISING: chân input chuyển từ mức thấp lên cao ( xung cạnh lên)
  
  . FALLING: chân input chuyển từ mức cao lên thấp ( xung cạnh xuống)

- Ngắt truyền thông: là một cơ chế trong vi điều khiển cho phép nhanh chóng xử lý dữ liệu mới nhận được từ các giao tiếp truyền thông. Khi có dữ liệu mới, vi điều khiển tự động dừng công việc hiện tại và xử lý dữ liệu đó mà không cần chờ đợi. Thường dùng cho UART, SPI
  
- Hoạt động của ngắt khi có nhiều ngắt lồng vào:

  ![image](https://github.com/Mefuuuu/Embedded_Interview_T5/assets/133778142/cea57024-5fcd-4374-8300-28f4e98f3f2c)
  
  . Đầu tiên chương trình chạy, khi gặp ngắt 1 thì nó sẽ chạy xong địa chỉ hiện tại và lưu địa chỉ tiếp theo (địa chỉ 1) vào StackPoint. Sau đó con trỏ PC sẽ trỏ đến phần vùng của ngắt 1 và chạy chương trình ngắt 1, nếu trong quá trình chạy gặp phải ngắt 2 thì nó sẽ so sánh mức độ ưu tiên.

  . Nếu ngắt 2 có mức độ ưu tiên cao hơn thì lúc này nó sẽ chạy xong địa chỉ nó dã chạy và lưu địa chỉ tiếp theo (địa chỉ 2)vào StackPoint. Sau đó con trỏ PC trỏ để phân vùng của ngắt 2 và chạy chương trình của ngắt 2, sau khi chạy hết chương trình ngắt 2 thì nó sẽ vào StackPoint để lấy địa chỉ gần nhất được lưu vào trong StackPoint (là địa chỉ 2) để chạy tiếp chương trình, lúc này con trọ PC đang ở phân vùng ngắt 1 sau khi chạy xong chương trình ngắt 1 thì nó sẽ vào StackPoint để lấy (địa chỉ 1) và chạy cho đến hết chương trình.

  . Nếu ngắt 2 có mức độ ưu tiên thấp hơn thì lúc này nó sẽ chạy xong chương trình của ngắt 1, sau đó nó quay lại kiểm tra xem ngắt 2 còn không. Nếu còn thì nó sẽ chạy ngắt 2, sau khi chạy xong chương trình ngắt 2 thì nó sẽ vào StackPoint để nó lấy địa chỉ 1 để nó chạy cho hết chương trình.

## CAN
