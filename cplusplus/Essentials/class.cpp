//
// Created by Shabnam on 3/28/2023.
//

#include <iostream>

using namespace std;

class A {
    int a {};
    int b {};
    int c {};
public:
    A(int ia, int ib, int ic): a(ia), b(ib), c(ic) {
        cout << "a is: " << ia << " b is: " << ib << " c is: " << ic << endl;
    }

    void seta(int ia) {
        a = ia;
    }
    void setb(int ib) {
        b = ib;
    }
    void setc(int ic) {
        c = ic;
    }

    [[nodiscard]] int geta() const {
        return a;
    }
    [[nodiscard]] int getb() const{
        return b;
    }
    [[nodiscard]] int getc() const{
        return c;
    }
};

int main(int argc, char** argv) {

    A a1{2, 4, 1};

    return 0;
}
