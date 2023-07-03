#include <iostream>

using namespace std;

class Calendar{
    private:
        int day;
        int month;
        int year;
    public:
        Calendar(int day, int month, int year);
        bool holiday();
        int age(const Calendar& other);
};

Calendar::Calendar(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

bool Calendar::holiday(){
    if (day == 1 && month == 1)
    {
        return true;
    }else if (day == 30 && month == 4)
    {
        return true;
    }else if (day == 1 && month == 5)
    {
        return true;
    } else if (day == 2 && month == 9)
    {
        return true;
    }
    return false;
}

int Calendar::age(const Calendar& other){
    if (this->month > other.month )
    {
        return (other.year - this->year) - 1;
    }
    else  return (other.year - this->year);
}

int main()
{
    Calendar myBirthday(15, 1, 2001);
    Calendar currentDate(2, 7, 2023);

    cout << "Tuoi cua toi la: " << myBirthday.age(currentDate) <<endl;

    if (currentDate.holiday())
    {
        cout << "Day la ngay le";
    }else cout << " Day khong la ngay le";
    
    return 0;
}
