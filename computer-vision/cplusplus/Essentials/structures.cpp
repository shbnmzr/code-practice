//
// Created by Shabnam on 3/10/2023.
//

#include <iostream>

using namespace std;

struct S{
    int i {};
    double d {};
    const char* str {};

};

int main(int argc, char** argv){
    S s = {1, 45.45, "structure"};
    cout << s.i << " " << s.d << " " << s.str << endl;

    auto* sp = &s;
    sp->str = "Hello Again";
    cout << s.i << " " << s.d << " " << s.str << endl;
    cout << sp->i << " " << sp->d << " " << sp->str << endl;
    return 0;
}
