//
// Created by Shabnam on 3/10/2023.
//

#include <iostream>
#include <typeinfo>

using namespace std;
const size_t Byte {8};

int main(int argc, char** argv){
    int i {0};
    float f {9.9};
    double df {9.90};
    char c = 'c';
    bool t = true;

    cout << "Size of integer is: " << sizeof(i) * Byte << endl;
    cout << "Size of float is: " << sizeof(f) * Byte << endl;
    cout << "Size of double is: " << sizeof(df) * Byte << endl;
    cout << "Size of character is: " << sizeof(c) * Byte << endl;
    cout << "Size of boolean is: " << sizeof(t) * Byte << endl;

    string str {"This is a string"};
    auto x = str;
    cout << "Type of x is " << typeid(x).name() << endl;


    return 0;
}
