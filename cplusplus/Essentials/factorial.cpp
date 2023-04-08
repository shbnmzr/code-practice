//
// Created by Shabnam on 3/27/2023.
//

#include <iostream>

using namespace std;

template <typename T>
T factorial(T num) {
    if(num <= 1) return 1;
    else {
        return num * factorial(num - 1);
    }
}

int main(int argc, char** argv) {
    double number {5.5};
    cout << factorial<double>(number) << endl;

    int num {6};
    cout << factorial<int>(num) << endl;
}
