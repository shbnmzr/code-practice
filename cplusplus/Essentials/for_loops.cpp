//
// Created by Shabnam on 3/10/2023.
//

#include <iostream>

using namespace std;

int main(int argc, char** argv){
    const char str[] {"string"};
    for(int i {0}; str[i]; i++){
        cout << "character " << i << " is " << str[i] << endl;
    }

    for(auto* p = str; *p; p++){
        cout << "element " << p << " is " << *p << endl;
    }

    for(const auto& e: str){
        if(e == 0) break;
        cout << "element is " << e << endl;
    }
    return 0;
}
