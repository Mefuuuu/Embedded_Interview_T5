#include <iostream>
#include <string>

using namespace std;

class Book{
    private:
        string bookTitle;
        string author;
        int publishingYear;
        int quantity;
    public:
        Book(string bookTitle, string author, int publishingYear, int quantity);
        void print();
        void borrowBook(int quanlityBorrow);
        void giveBack(int quanlityGive);
};

Book::Book(string bookTitle, string author, int publishingYear, int quantity){
    this->bookTitle = bookTitle;
    this->author = author;
    this->publishingYear = publishingYear;
    this->quantity = quantity;
}

void Book::print(){
    cout << "Ten sach: " << bookTitle << endl;
    cout << "Tac gia: " << author << endl;
    cout << "Nam xuat ban: " << publishingYear << endl;
    cout << "So luong: " << quantity << endl;
}

void Book::borrowBook(int quanlityBorrow){
    if (quantity != 0)
    {
        quantity -= 1;
        cout << "Sach con lai: " << quantity << endl;
    }
    else cout << "Khong du sach de muon" << endl;
}

void Book::giveBack(int quanlityGive){
    quantity += 1;
    cout << "So sach hien co: " << quantity << endl;
}

int main()
{
    Book sach1("Alchemist","Paulo Coelho",1988, 7);
    int quanlityBorrow, quanlityGive;

    int t;
    cout << "=====Menu===== \n";
    cout << "1. In thong tin sach \n";
    cout << "2. Muon sach \n";
    cout << "3. Tra sach \n";
    cout << "Nhap lua chon: ";
    cin >> t;

    switch (t)
    {
    case 1:
        sach1.print();
        break;
    case 2:
        cout << "Nhap so luong muon muon: \n";
        cin >> quanlityBorrow;
        sach1.giveBack(quanlityBorrow);
        break;
    case 3:
        cout << "Nhap so luong tra: \n";
        cin >> quanlityGive;
        sach1.giveBack(quanlityGive);
        break;
    default:
        cout << "Khong hop le";
        break;
    }

    return 0;
}
