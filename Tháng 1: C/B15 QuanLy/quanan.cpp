#include <iostream>
#include <string>
#include <list> 

using namespace std;

class MonAn{
    private:
        uint8_t ID;
        string TEN;
        double GIA;
    public:
        MonAn(string ten, double GIA);
        uint8_t getId();
        void setTen(string ten);
        string getTen();
        void setGia(double gia);
        double getGia();
};

MonAn::MonAn(string ten, double GIA){
    static uint8_t id = 100;
    ID = id;
    id++;
}

uint8_t MonAn::getId(){
    return this->ID;
}

void MonAn::setTen(string ten){
    this->TEN = ten;
}

string MonAn::getTen(){
    return this->TEN;
}

void MonAn::setGia(double gia){
    this->GIA = gia;
}

double MonAn::getGia(){
    return this->GIA;
}

class QuanLy{
    private:
        list<MonAn> DATABASE;
        uint8_t SO_BAN;
        void themMon();
        void suaMon();
        void soBan();
    public:
        QuanLy();
        list<MonAn> getDatabase();
        uint8_t getSoBan();
};

QuanLy::QuanLy(){
    int key = 0;

    do
    {
        /* code */
    } while (key);
    
    switch (key)
    {
    case 1:
        themMon();
        break;
    case 2:
        suaMon();
        break;
    case 3:
        soBan();
        break;            
    default:
        break;
    }
}

list<MonAn> QuanLy::getDatabase(){
    return this->DATABASE;
}

class ThongTinBan{
    private:
        uint8_t SO_BAN;
        bool TRANG_THAI;
        typedef struct
        {
            MonAn MON_AN;
            uint8_t SO_LUONG;
        }TypeMon;
        list<TypeMon> DATABASE_MON_AN;
    public:
        ThongTinBan(uint8_t soBan, bool trangThai);
        uint8_t getSoBan();
        bool getTrangThai();
        void danhSachMon();
        void themMon(MonAn mon, uint8_t soLuong);
        void suaMon(uint8_t id, uint8_t soLuong);
        void xoaMon(uint8_t id);
        
};

void ThongTinBan::xoaMon(uint8_t id){

    auto position = DATABASE_MON_AN.begin();

    for (auto item : DATABASE_MON_AN)
    {
        if (item.MON_AN.getId() == id)
        {
            DATABASE_MON_AN.erase(position);
        }
        position ++;
    }
}

class NhanVien{
    private:
        list<MonAn> DATABASE_MON_AN;
        list<ThongTinBan> DATABASE_BAN;
    public:
        NhanVien(list<MonAn> database, uint8_t soBan);
};

NhanVien::NhanVien(list<MonAn> database, uint8_t soBan){
    DATABASE_MON_AN.assign(database.begin(), database.end());

    for ( uint8_t i = 0; i <= soBan; i++)
    {
        ThongTinBan ban(i,false);
        DATABASE_BAN.push_back(ban);

    }
    
}






int main()
{
    
    return 0;
}
