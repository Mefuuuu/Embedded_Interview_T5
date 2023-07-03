#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction{
    private:
        int nume;
        int denom;
    public:
        Fraction(int nume, int denom);
        void print();
        void plus(const Fraction& other);
        void minus(const Fraction& other);
        void multiplied(const Fraction& other);
        void divided(const Fraction& other);
        void compact();
};

Fraction::Fraction(int nume, int denom){
    Fraction::nume = nume;
    Fraction::denom = denom;
}

void Fraction::print(){
    cout << this->nume << "/" << this->denom << endl; 
}

void Fraction::plus(const Fraction& other){
    int new_nume = this->nume * other.denom + this->denom * other.nume;
    int new_denom = this->denom * other.denom;
    this->nume = new_nume;
    this->denom = new_denom;
}

void Fraction::minus(const Fraction& other){
    int new_nume = this->nume * other.denom - this->denom * other.nume;
    int new_denom = this->denom * other.denom;
    this->nume = new_nume;
    this->denom = new_denom;
}

void Fraction::multiplied(const Fraction& other){
    int new_nume = this->nume * other.nume;
    int new_denom = this->denom * other.denom;
    this->nume = new_nume;
    this->denom = new_denom;
}

void Fraction::divided(const Fraction& other){
    int new_nume = this->nume * other.denom;
    int new_denom = this->denom * other.nume;
    this->nume = new_nume;
    this->denom = new_denom;
}

void Fraction::compact(){
    int tmp = gcd(nume,denom);
    this->nume = this->nume / tmp;
    this->denom = this->denom /tmp;
}

int main()
{
    Fraction t1(1,2);
    Fraction t2(3,4);

    Fraction sum = t1;
    sum.plus(t2);
    sum.compact();

    Fraction sub = t1;
    sub.minus(t2);
    sub.compact();

    Fraction multiplication = t1;
    multiplication.multiplied(t2);
    multiplication.compact();

    Fraction division = t1;
    division.divided(t2);
    division.compact();

    cout <<"Tong: ";
    sum.print();

    cout <<"Hieu: ";
    sub.print();

    cout <<"Tich: ";
    multiplication.print();

    cout <<"Thuong: ";
    division.print();

    return 0;
}
