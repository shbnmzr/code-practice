//
// Created by Shabnam on 3/29/2023.
//

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    string istr {};

//    cout << "Enter a word:" << endl;
//    cin >> istr;
//    cout << "Input: " << istr << endl;

    char buff[128] {};

    cout << "Enter a line:" << endl;
    cin.getline(buff, sizeof(buff));
    cout << "Input: " << buff << endl;

    for(int i: {1, 2, 3,4 ,5,6})
    return 0;
}
