#include <iostream>
#include <string>

using namespace std;

class Car{
    private:
        string color;
        string engineType;
        int km;
    public:
        Car(string color, string engineType, int km);
        void maintenance();
        void checkKm();
        void print();
};

Car::Car(string color, string engineType, int km){
    this->color = color;
    this->engineType = engineType;
    this->km = km;
}

void Car::maintenance(){
    if(km >= 3000)
        cout << "Xe can bao duong";
    else cout << "Xe chua can bao duong";    
}

void Car::checkKm(){
    cout << "So km da di: " << km << endl;
}

void Car::print(){
    cout <<"Mau xe: " << color << endl;
    cout <<"Kieu dong co: " << engineType << endl;
    cout <<"So km da di: " << km << endl;
}

int main()
{
    Car toyota("green", "st720", 4000);

    int t;
    cout << "=====Menu===== \n";
    cout << "1. Co nen bao duong xe khong \n";
    cout << "2. So km da di \n";
    cout << "3. In thong tin xe \n";
    cout << "Nhap lua chon: ";
    cin >> t;

    switch (t)
    {
    case 1:
        toyota.maintenance();
        break;
    case 2:
        toyota.checkKm();
        break;
    case 3:
        toyota.print();
        break;
    default:
        cout <<"Khong hop le";
        break;
    }

    return 0;
}
