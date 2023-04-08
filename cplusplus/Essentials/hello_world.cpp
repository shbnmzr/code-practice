//
// Created by Shabnam on 3/9/2023.
//

#include <iostream>

using namespace std;

int main() {
    const char* hello {"Hello, World!"};
    cout << hello << endl;

    int i {};
    int j;
    char c {};
    char ch;
    double d {};
    bool b {};
    cout << "int = " << i << endl;
    cout << "uninitialized int = " << j << endl;
    cout << "char = " << c << endl;
    cout << "uninitialized char = " << ch << endl;
    cout << "double = " << d << endl;
    cout << "boolean = " << b << endl;
    return 0;
}
