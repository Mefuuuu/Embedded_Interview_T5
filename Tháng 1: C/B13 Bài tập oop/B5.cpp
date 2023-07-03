#include <iostream>
#include <string>

using namespace std;

class People{
    private:
        string name;
        int YoB;
        string address;
        int age;
    public:
        People(string name, int YoB, string address);
        void inFor();
        void Old(int thisYear);
};

People::People(string name, int YoB, string address){
    this->name = name;
    this->YoB = YoB;
    this->address = address;
}

void People::Old(int thisYear){
     age = thisYear - YoB;
}

void People::inFor(){
    cout << "Ten: " << name << endl;
    cout << "Nam sinh: " << YoB << endl;
    cout << "Tuoi : " << age << endl;
    cout << "Dia chi: " << address << endl;
}

int main()
{
    People p1("Dung", 1996, "Ho Chi Minh");

    p1.Old(2023);
    p1.inFor();

    return 0;
}