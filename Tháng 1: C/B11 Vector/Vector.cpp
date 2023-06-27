 #include <iostream>
 #include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> array;	// khai báo mảng kiểu int
    array.push_back(4);  //thêm phần tử thứ 0 là 4
    array.push_back(8);  //thêm phần tử thứ 1 là 8
    array.push_back(20);
    array.push_back(15); //thêm phần tử thứ 4 là 15
 
    for(auto item : array){ 
 	    printf("i = %d\n",item);
    }   
    return 0;
}


