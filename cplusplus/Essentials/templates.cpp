//
// Created by Shabnam on 3/29/2023.
//

#include <iostream>

using namespace std;

template <typename T>
T maxOf(T a, T b) {
    return (a > b ? a : b);
}

int main(int argc, char** argv) {

    int x {56};
    int y {100};

    int z = maxOf<int>(x, y);

    cout << "Max of x and y is " << z << endl;

    return 0;
}