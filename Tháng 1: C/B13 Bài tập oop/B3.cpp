#include <iostream>
#include <cmath>

using namespace std;

class cricle{
    private:
        int radius;
    public:
        cricle(int radius_val);
        void getRadius();
        double diameter();
        double area();
};

cricle::cricle(int radius_val) : radius(radius_val){}

void cricle::getRadius(){
    cout <<"Nhap ban kinh:\n";
    cin >> radius;
}

double cricle::diameter(){
    return radius*2*3.14;
}

double cricle::area(){
    return pow(radius,2)*3.14;
}

int main()
{
    cricle ht {3};
    ht.getRadius();

    cout << "========Menu======\n";
    cout << "1. Chu vi\n";
    cout << "2. Dien tich \n"; 

    int t;
    cin >> t;

    switch (t)
    {
    case 1:
        cout << "Chu vi la: " << ht.diameter() << endl;
        break;
    case 2:
        cout << "Dien tich la: " << ht.area() << endl;
        break;
    default:
        cout << "Lua chon khong hop le" << endl;
        break;
    }

    return 0;
}
