//
// Created by Shabnam on 3/29/2023.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    string s1 {"Hello"};
    string s2 {"Hello"};

    cout << "Is s1 == s2? " << (s1 == s2) << endl;
    cout << "Size of s1: " << s1.size() << " Length of s1: " << s1.length() << endl;

    s2 = "This is a string";
    s1.replace(s1.begin() + 2, 1, "d");



    return 0;
}
