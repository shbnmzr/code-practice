//
// Created by Shabnam on 3/27/2023.
//

#include <iostream>

using namespace std;

int factorial(int, int);

int main(int argc, char** argv) {
    int number {5};
    cout << factorial(number, 1);
}

int factorial(int num, int current_value) {
    if(num == 1) return current_value;
    else {
        current_value *= num;
        factorial(--num, current_value);
    }
}
