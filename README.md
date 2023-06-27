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
class ToanHoac{
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

# Namespace
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
# Template
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

- Các phần tử cửa nó không được lưu trong các địa liên tiếp mà lưu ở địa chỉ bất kì, và mỗi phần tử trước sẽ lưu kèm địa chỉ của phần tử kế tiếp theo tuần tự. Riêng phần tử cuối cùng sẽ lưu địa chỉ là null
  
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
# B12 Hàm ảo Virtual function 
