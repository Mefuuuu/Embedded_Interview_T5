#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum{
    NAM,
    NU
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class SinhVien{
    private:
        int ID;
        string TEN;
        int TUOI;
        TypeGioiTinh GIOI_TINH;
        float TOAN;
        float LY;
        float HOA;
        TypeHocLuc HOC_LUC;
    public:
        SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, float toan, float ly, float hoa);
        int getId();
        float getTrungBinh();
        void setTen(string ten);
        void setGioiTinh(TypeGioiTinh gioi_tinh);
        void setTuoi(int tuoi);
        void setToan(float toan);
        void setLy(float ly);
        void setHoa(float Hoa);
        string getTen();
        int getTuoi();
        TypeGioiTinh getGioiTinh();
        float getToan();
        float getLy();
        float getHoa();
        TypeHocLuc getHocluc();
};

SinhVien::SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh, float toan, float ly, float hoa){
    static int id = 100;
    ID = id;
    id++;
    this->TEN = ten;
    this->TUOI = tuoi;
    this->GIOI_TINH = gioi_tinh;
    this->TOAN = toan;
    this->LY = ly;
    this->HOA = hoa;
}

int SinhVien::getId(){
    return this->ID;
}

float SinhVien::getTrungBinh(){
    return (TOAN + LY + HOA) /3;
}

void SinhVien::setTen(string ten){
    this->TEN = ten;
}

void SinhVien::setGioiTinh(TypeGioiTinh gioi_tinh){
    this->GIOI_TINH = gioi_tinh;
}

void SinhVien::setTuoi(int tuoi){
    this->TUOI = tuoi;
}

void SinhVien::setToan(float toan){
    this->TOAN = toan;
}

void SinhVien::setLy(float ly){
    this->LY = ly;
}

void SinhVien::setHoa(float hoa){
    this->HOA = hoa;
}

string SinhVien::getTen(){
    return this->TEN;
}

int SinhVien::getTuoi(){
    return this->TUOI;
}

TypeGioiTinh SinhVien::getGioiTinh(){
    return this->GIOI_TINH;
}

float SinhVien::getToan(){
    return this->TOAN;
}

float SinhVien::getLy(){
    return this->LY;
}

float SinhVien::getHoa(){
    return this->HOA;
}

TypeHocLuc SinhVien::getHocluc(){
    if (this->getTrungBinh() >= 8.0)
    {
        return GIOI;
    }else if (this->getTrungBinh() >= 6.5)
    {
        return KHA;
    }else if (this->getTrungBinh() >= 5.0)
    {
        return TRUNG_BINH;
    }else return YEU;
}


class Menu{
    private:
        string TEN;
        int TUOI;
        float TOAN;
        float LY;
        float HOA;
        TypeGioiTinh GIOI_TINH;
        TypeHocLuc HOC_LUC;
        list<SinhVien> Database;
    public:
        void themSinhVien();
        void capNhatThongTin();
        void xoaSinhVien();
        void timKiemSinhVienTheoTen();
        void sapXepTheoDiemGpa();
        void sapXepTheoTen();
        void hienThi();
};

void Menu::themSinhVien(){
    cout << "=======Them sinh vien=======\n";
    // nhap ten
    do
    {
        cout << "Nhap ten sinh vien: ";
        cin >> TEN;
        if (TEN.empty())
        {
            cout << "SAI. Nhap lai \n";
        }
    } while (TEN.empty());
    
    // nhap gioi tinh
    string gioi_tinhstr;
    do
    {
        cout << "Nhap gioi tinh (NAM/NU): ";
        cin >> gioi_tinhstr;
        if (gioi_tinhstr != "NAM" && gioi_tinhstr != "NU")
        {
            cout << "SAI. Nhap lai \n";
        }
    } while (gioi_tinhstr != "NAM" && gioi_tinhstr != "NU");
    if (gioi_tinhstr == "NAM")
    {
        GIOI_TINH = NAM;
    }else GIOI_TINH = NU;
    
    // nhap tuoi
    do
    {
        cout << "Nhap tuoi cua sinh vien: ";
        cin >> TUOI;
        if (TUOI <= 0 || TUOI > 100)
        {
            cout << "SAI. Nhap lai \n";
        } 
    } while (TUOI <= 0 || TUOI > 100);
    
    // nhap diem toan
    do
    {
        cout << "Nhap diem Toan (0-10): ";
        cin >> TOAN;
        if (TOAN <= 0 || TOAN > 10)
        {
            cout << "SAI. Nhap lai \n";
        }
    } while (TOAN <= 0 || TOAN > 10);
    
    // nhap diem ly
    do
    {
        cout << "Nhap diem Ly (0-10): ";
        cin >> LY;
        if (LY <= 0 || LY > 10)
        {
            cout << "SAI. Nhap lai \n";
        }
    } while (LY <= 0 || LY > 10);
    
    //nhap diem hoa
    do
    {
        cout << "Nhap diem Hoa (0-10): ";
        cin >> HOA;
        if (HOA <= 0 || HOA > 10)
        {
            cout << "SAI. Nhap lai \n";
        }
    } while (HOA <= 0 || HOA > 10);

    //gan database
    SinhVien sv(TEN,TUOI,GIOI_TINH,TOAN,LY,HOA);
    Database.push_back(sv);
}

void Menu::capNhatThongTin(){
    cout << "=======Cap nhat thong tin bang ID=======" << endl;
    cout << "Nhap ID can cap nhat thong tin: ";
    int id;
    cin >> id;
    auto itmp = Database.begin();
    while (itmp != Database.end())
    {
        if (id == itmp->getId())
        {   
            // nhap ten moi
            do
            {
                cout << "Nhap ten moi: ";
                getline(cin,TEN);
                if (TEN.empty())
                {
                    cout << "SAI. Nhap lai \n";
                }               
            } while (TEN.empty());     
            itmp->setTen(TEN);
            
            //nhap gioi tinh
            string gioi_tinhstr;
            do
            {
                cout << "Nhap gioi tinh moi: ";
                cin >> gioi_tinhstr;
                cin.ignore();
                if (gioi_tinhstr != "NAM" && gioi_tinhstr != "NU")
                {
                    cout << "SAI. Nhap lai \n";
                }  
            } while (gioi_tinhstr != "NAM" && gioi_tinhstr != "NU");
            if (gioi_tinhstr == "NAM")
            {
                GIOI_TINH = NAM;
            }else GIOI_TINH = NU;
            itmp->setGioiTinh(GIOI_TINH);

            // nhap tuoi
            do
            {
                cout << "Nhap tuoi moi: ";
                cin >> TUOI;
                if (TUOI <= 0 || TUOI > 100)
                {
                    cout << "SAI. Nhap lai \n";
                }     
            } while (TUOI <= 0 || TUOI > 100);
            itmp->setTuoi(TUOI);

            //nhap diem toan
            do
            {
                cout << "Nhap diem Toan moi: ";
                cin >> TOAN;
                if (TOAN <= 0 || TOAN > 10)
                {
                    cout << "SAI. Nhap lai \n";
                }                
            } while (TOAN <= 0 || TOAN > 10);
            itmp->setToan(TOAN);

            // nhap diem ly
            do
            {
                cout << "Nhap diem Ly moi: ";
                cin >> LY;
                if (LY <= 0 || LY > 10)
                {
                    cout << "SAI. Nhap lai \n";
                }                
            } while (LY <= 0 || LY > 10);
            itmp->setLy(LY);

            // nhap diem hoa
            do
            {
                cout << "Nhap diem Hoa moi: ";
                cin >> HOA;
                if (HOA <= 0 || HOA > 10)
                {
                    cout << "SAI. Nhap lai \n";
                }                
            } while (HOA <= 0 || HOA > 10);
            itmp->setHoa(HOA);
        }  
        itmp ++;
    }
    if (itmp == Database.end())
    {
        cout << "Khong tim thay ai ca!\n";
    }
}

void Menu::xoaSinhVien(){
    int id;
    cout << "=======Xoa sinh vien bang ID=======" << endl;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> id;
    cin.ignore();

    auto itmp = Database.begin();
    while (itmp != Database.end())
    {
        if (id == itmp->getId())
        {
            itmp = Database.erase(itmp);
            return;
        }
        itmp++;
    }
    cout << "Khong tim thay ai ca! \n";
}

void Menu::timKiemSinhVienTheoTen(){
    cout << "=======Tim kiem sinh vien theo ten=======" << endl;
    cout << "Nhap ten can tim kiem: \n";
    string tenTmp;
    cin >> tenTmp;
    cin.ignore();

    auto itmp = Database.begin();
    while (itmp != Database.end())
    {
        if (tenTmp == itmp->getTen())
        {                
            cout << "Sinh vien can tim:" <<endl;
            cout << "Ten: " << itmp->getTen()<< endl;
            cout << "ID: " << itmp->getId() << endl;
            cout << "Tuoi: " << itmp->getTuoi() << endl;
            cout << "Gioi tinh:" << itmp->getGioiTinh() <<endl;
            cout << "Diem Toan: " << itmp ->getToan() << endl;
            cout << "Diem Ly: " << itmp->getLy() << endl;
            cout << "Diem Hoa: " << itmp->getHoa() << endl;
            if (itmp->getHocluc() == GIOI)
            {
                cout << "GPA loai Gioi" << endl;
            }else if (itmp->getHocluc() == KHA)
            {
                cout << "GPA loai Kha" << endl;
            }else if (itmp->getHocluc() == TRUNG_BINH)
            {
                cout << "GPA loai Trung Bình" << endl;
            }else cout << "GPA loai Yeu" << endl;

            return;                                 
        }
        itmp ++;   
    }    
}

void Menu::sapXepTheoDiemGpa(){
    list<SinhVien> SapXepGpa;

    for ( auto itmp : Database)
    {
        bool co = false;
        for (auto itmpGpa = SapXepGpa.begin(); itmpGpa != SapXepGpa.end(); itmpGpa++)
        {
            if (itmp.getTrungBinh() > itmpGpa->getTrungBinh())
            {
                SapXepGpa.insert(itmpGpa, itmp);
                co = true;
                break;
            }
        }
        if (co == false)
        {
            SapXepGpa.push_back(itmp);
        }      
    }
    
    cout << "=======Danh sach sau khi sap xep theo GPA=======" << endl;
    for (auto itmp : SapXepGpa)
    {
        cout << "Sinh vien can tim:" <<endl;
        cout << "Ten: " << itmp.getTen()<< endl;
        cout << "ID: " << itmp.getId() << endl;
        cout << "Tuoi: " << itmp.getTuoi() << endl;
        cout << "Gioi tinh:" << itmp.getGioiTinh() <<endl;
        cout << "Diem Toan: " << itmp.getToan() << endl;
        cout << "Diem Ly: " << itmp.getLy() << endl;
        cout << "Diem Hoa: " << itmp.getHoa() << endl;
        if (itmp.getHocluc() == GIOI)
        {
            cout << "GPA loai Gioi" << endl;
        }else if (itmp.getHocluc() == KHA)
        {
            cout << "GPA loai Kha" << endl;
        }else if (itmp.getHocluc() == TRUNG_BINH)
        {
            cout << "GPA loai Trung Binh" << endl;
        }else cout << "GPA loai Yeu" << endl;                 
    }
}

void Menu::sapXepTheoTen(){
    list<SinhVien> SapXepTen;

    for (auto itmp : Database)
    {
        bool co = false;
        for (auto itmpTen = SapXepTen.begin(); itmpTen != SapXepTen.end(); itmpTen++)
        {
            if (itmp.getTen() < itmpTen->getTen())
            {
                SapXepTen.insert(itmpTen,itmp);
                co = true;
                break;
            }
        }
        if (co == false)
        {
            SapXepTen.push_back(itmp);
        }   
    }

    cout << "=======Danh sach sau khi sap xep theo Ten=======" << endl;
    for (auto itmp : SapXepTen)
    {
        cout << "Sinh vien can tim:" <<endl;
        cout << "Ten: " << itmp.getTen()<< endl;
        cout << "ID: " << itmp.getId() << endl;
        cout << "Tuoi: " << itmp.getTuoi() << endl;
        cout << "Gioi tinh:" << itmp.getGioiTinh() <<endl;
        cout << "Diem Toan: " << itmp.getToan() << endl;
        cout << "Diem Ly: " << itmp.getLy() << endl;
        cout << "Diem Hoa: " << itmp.getHoa() << endl;
        if (itmp.getHocluc() == GIOI)
        {
            cout << "GPA loai Gioi" << endl;
        }else if (itmp.getHocluc() == KHA)
        {
            cout << "GPA loai Kha" << endl;
        }else if (itmp.getHocluc() == TRUNG_BINH)
        {
            cout << "GPA loai Trung Binh" << endl;
        }else cout << "GPA loai Yeu" << endl;
                                     
    }    
}

void Menu::hienThi(){
    cout << "=======Danh sach sinh vien=======" << endl;
    for (auto itmp : Database)
    {
        cout << "=============" <<endl;
        cout << "Ten: " << itmp.getTen()<< endl;
        cout << "ID: " << itmp.getId() << endl;
        cout << "Tuoi: " << itmp.getTuoi() << endl;
        cout << "Gioi tinh:" << itmp.getGioiTinh() <<endl;
        cout << "Diem Toan: " << itmp.getToan() << endl;
        cout << "Diem Ly: " << itmp.getLy() << endl;
        cout << "Diem Hoa: " << itmp.getHoa() << endl;
        if (itmp.getHocluc() == GIOI)
        {
            cout << "GPA loai Gioi" << endl;
        }else if (itmp.getHocluc() == KHA)
        {
            cout << "GPA loai Kha" << endl;
        }else if (itmp.getHocluc() == TRUNG_BINH)
        {
            cout << "GPA loai Trung Binh" << endl;
        }else cout << "GPA loai Yeu" << endl;                      
    }    
}

int main()
{
    Menu menu;
    int choice;
    while (1)
    {
        cout << "He thong quan ly sinh vien\n";
        cout << "========Menu======== \n";
        cout << "1. Them sinh vien\n";
        cout << "2. Cap nhat thong tin sinh vien boi ID\n";
        cout << "3. Xoa sinh vien boi ID\n";
        cout << "4. Tim kiem sinh vien theo ten \n";
        cout << "5. Sap xep sinh vien theo diem trung binh GPA \n";
        cout << "6. Sap xep sinh vien theo ten\n";
        cout << "7. Hien thi danh sach sinh vien\n";
        cout << "0. Thoat \n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            menu.themSinhVien();
            break;
        case 2:
            menu.capNhatThongTin();
            break;
        case 3:
            menu.xoaSinhVien();
            break;
        case 4:
            menu.timKiemSinhVienTheoTen();
            break;
        case 5:
            menu.sapXepTheoDiemGpa();
            break;
        case 6:
            menu.sapXepTheoTen();
            break;
        case 7:
            menu.hienThi();
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}
