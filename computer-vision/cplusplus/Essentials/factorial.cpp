//
// Created by Shabnam on 3/27/2023.
//

#include <iostream>

using namespace std;

int factorial(int);

int main(int argc, char** argv) {
    int number {5};
    cout << factorial(number);
}

int factorial(int num) {
    if(num == 1) return 1;
    else {
        return num * factorial(num - 1);
    }
}
