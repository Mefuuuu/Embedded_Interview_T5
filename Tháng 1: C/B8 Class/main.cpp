#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    public:
        // DoiTuong(); // constructor không có input paramater
        void setThongTin(string ten, int tuoi);
        void hienThi(); // method
    protected:
        int TUOI; //property
        string TEN;
};

void DoiTuong::hienThi(){
    cout<<"Day la class DoiTuong\n";
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl; 
};

void DoiTuong::setThongTin(string ten, int tuoi){
    TEN = ten;
    TUOI = tuoi;
};

// nạp chồng. đây là 1 tính chất của OOP
class SinhVien : public DoiTuong{
    public:
        void setThongTin(string ten, int tuoi, int mssv);
        void hienThi();
    private:
        int MSSV;
};

void SinhVien::setThongTin(string ten, int tuoi, int mssv){
    TEN = ten;
    TUOI = tuoi;
    MSSV = mssv;
};

void SinhVien::hienThi(){
    cout<<"Day la class sinhvien\n";
    cout<<"TEN: "<<TEN<<endl;
    cout<<"TUOI: "<<TUOI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;
}; 

int main(){

    DoiTuong dt;
    
    dt.setThongTin("HOang",17);
    dt.hienThi();

    SinhVien sv;
    
    sv.setThongTin("Phuoc",23, 63);
    sv.hienThi(); 

    return 0;
}