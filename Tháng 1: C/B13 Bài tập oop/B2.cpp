#include <iostream>
#include <cmath>

using namespace std;

class hinhChuNhat{
    private:
        int chieuDai;
        int chieuRong;
    public:
        hinhChuNhat(int chieuDai, int chieuRong);
        void getsize();
        int chuVi();
        int dienTich();
        double duongCheo();
        void kiemtra();
};

hinhChuNhat::hinhChuNhat(int chieuDai, int chieuRong) : chieuDai(chieuDai), chieuRong(chieuRong){}

void hinhChuNhat::getsize(){
    cout << "Nhap chieu dai:\n ";
    cin >> chieuDai;
    cout << "Nhap chieu rong:\n" ;
    cin >> chieuRong;
}

int hinhChuNhat::chuVi(){
    return (chieuDai+chieuRong) *2;
}

int hinhChuNhat::dienTich(){
    return chieuDai*chieuRong;
}

double hinhChuNhat::duongCheo(){
    return sqrt(pow(chieuDai,2) + pow(chieuRong,2));
}

void hinhChuNhat::kiemtra(){
    if(chieuDai == chieuRong)
        printf("La hinh vuong");
    else printf("Khong phai hinh vuong");
}

int main(int argc, char const *argv[])
{
    int t;

    hinhChuNhat hcn(4,5);
    
    hcn.getsize();

    printf("Bang Menu\n");
    printf("1. Tinh chu vi\n");
    printf("2. Tinh dien tich\n");
    printf("3. Tinh duong cheo\n");
    printf("4. Kiem tra\n");
    scanf("%d",&t);

    if (t == 1)
    {
        printf("Chu vi hcn la: %d\n",hcn.chuVi());
    }
    else if(t == 2){
        printf("Dien tich hcn la: %d\n",hcn.dienTich());
    }
    else if(t == 3){
        printf("Duong cheo la: %f\n",hcn.duongCheo());
    }else hcn.kiemtra();

    return 0;
}
