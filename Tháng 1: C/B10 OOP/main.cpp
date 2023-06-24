#include <iostream> 
#include <string> 

using namespace std; 

/*class ToanHoc{
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
}*/

namespace conOngA{
    int A = 10;
    class ToanHoc
    {
        public:
            void tong(int a,int b);
            void tong(int a,int b, int c);
            int tong(int a, double b);
    };
}

namespace conOngB{
    int A = 20; 
}
using namespace conOngA;

void ToanHoc::tong(int a, int b){
    printf("Tong a+b = %d\n",a+b);
}

void ToanHoc::tong(int a, int b, int c){
    printf("Tong a+b+c = %d\n",a+b+c);
}

int ToanHoc::tong(int a, double b){
    return a + (int)b;
}

template <typename var , typename varb> 
varb tong(var a, varb b){
    return (varb)a+b;
}
int main(int argc, char const *argv[])
{
    ToanHoc th; 

    th.tong(3,4);
    th.tong(5,6,7);
    printf("tong la: %d",th.tong(3,5.3));
    return 0;
}