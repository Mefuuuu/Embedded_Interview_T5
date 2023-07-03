#include <iostream>
#include <string>

using namespace std;

class Animal{
    private:
        string name;
        int age;
        float height;
        float weight;
    public:
        Animal(string name, int age, float height, float weight);  //Contructor khởi tạo
        float BMI();         // hàm tính chỉ số BMI
        void compareAge(const Animal& other);  // hàm ss tuổi đối tượng hiện tại và đối tượng other
        void compareWeight(const Animal& other);  // hàm ss cân nặng đối tượng hiện tại và đối tượng other
};

Animal::Animal(string name, int age, float height, float weight){
    Animal::name = name;
    Animal::age = age;
    Animal::height = height;
    Animal::weight = weight;
}

float Animal::BMI(){
    return weight/(height*height);
}

void Animal::compareAge(const Animal& other){
    if (age > other.age)
    {
        printf("%s nang hon %s \n",name.c_str(),other.name.c_str());
    }
    else if (age == other.age)
    {
        printf("%s bang %s \n",name.c_str(),other.name.c_str());
    }
    else {
        printf("%s nang hon %s \n",other.name.c_str(),name.c_str());
    }
    
}

void Animal::compareWeight(const Animal& other){
    if (weight > other.weight)
    {
        printf("%s nang hon %s ",name.c_str(),other.name.c_str());
    }
    else if (weight == other.weight)
    {
        printf("%s bang %s ve can nang ",name.c_str(),other.name.c_str());
    }
    else printf("%s nang hon %s",other.name.c_str(),name.c_str());
}

int main()
{
    Animal cat("Meo", 2, 0.3, 3.5);
    Animal dog("Cho", 3, 0.5, 7.8);

    cout << "BMI cua meo la: " << cat.BMI() << endl;
    cout << "BMI cua cho la: " << dog.BMI() << endl;

    cat.compareAge(dog);
    dog.compareWeight(cat);

    return 0;
}
