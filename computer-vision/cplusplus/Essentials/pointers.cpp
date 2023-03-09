//
// Created by Shabnam on 3/9/2023.
//
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int x {};
    int* ip;
    ip = &x;
    int y;
    y = *ip; // assigns the value of the variable to which ip points

    cout << "Value of ip: " << ip << endl;
    cout << "Value of *ip: " << *ip << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;

    y = 7;
    x = 8;

    cout << "Value of ip: " << ip << endl;
    cout << "Value of *ip: " << *ip << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;

    int& ref = x;

    cout << "Value of ip: " << ip << endl;
    cout << "Value of *ip: " << *ip << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of ref: " << ref << endl;

    ref = 43;

    cout << "Value of ip: " << ip << endl;
    cout << "Value of *ip: " << *ip << endl;
    cout << "Value of x: " << x << endl;
    cout << "Value of ref: " << ref << endl;
    
    return 0;
}
