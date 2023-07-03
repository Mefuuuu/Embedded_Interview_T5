#include <iostream>
#include <string>

using namespace std;

class BankAcc{
    private:
        int accNum;
        string accName;
        int accBalance;
    public:
        BankAcc(int accNum, string accName, int accBalance);
        void withdraw(int withdrawalAmount);
        void payment(int paymentAmount);
        void printBalance();
};

BankAcc::BankAcc(int accNum, string accName, int accBalance){
    this->accNum = accNum;
    this->accName = accName;
    this->accBalance = accBalance;
}

void BankAcc::withdraw(int withdrawalAmount){
    if (accBalance >= withdrawalAmount){
        accBalance = accBalance - withdrawalAmount;
    }else cout <<"Khong du so du";
}

void BankAcc::payment(int paymentAmount){
    accBalance = accBalance + paymentAmount;
}

void BankAcc::printBalance(){
    cout << "So du tai khoan: " << accBalance << endl;
}

int main()
{
    BankAcc acb(7989, "vinh ky", 50000);
    int paymentAmount,withdrawalAmount; 
    int t;
    cout << "=====Menu===== \n";
    cout << "1. Rut tien \n";
    cout << "2. Nop tien \n";
    cout << "3. Kiem tra so du \n";
    cout << "Nhap lua chon: ";
    cin >> t;

    switch (t)
    {
    case 1:
        cout <<"Nhap so tien muon rut: ";
        cin >> withdrawalAmount;
        acb.withdraw(withdrawalAmount);
        acb.printBalance();
        break;
    case 2:
        cout <<"Xac nhan so tien nop: ";
        cin >> paymentAmount;
        acb.payment(paymentAmount);
        acb.printBalance();
        break;
    case 3:
        acb.printBalance();
        break;
    default:
        cout << "Khong hop le";
        break;
    }

    return 0;
}
