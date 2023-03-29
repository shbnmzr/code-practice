//
// Created by Shabnam on 3/29/2023.
//

#include <iostream>

using namespace std;

class Rational {
    int n {0};
    int d {1};

public:
    Rational(int nominator = 0, int denominator = 1): n(nominator), d(denominator) {}
    Rational(const Rational& obj) {}
    ~Rational() = default;

    int nominator() const{
        return n;
    }

    int denominator() const {
        return d;
    }

    string str() const {
        if(d == 0) return "NAN";
        if(d == 1 || n == 0) return std::to_string(n);

        auto abs_n = abs(n);     // absolute value
        if(abs_n > d) {
            auto whole = n / d;
            auto remainder = abs_n % d;
            if(remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
            else return std::to_string(whole);
        } else {
            return reduce().raw_str();
        }
    }

    Rational reduce() const {
        if(n == 0 || d <= 3) return *this;
        for(auto div = d - 1; div; --div) {
            if(n % div == 0 && d % div == 0) {
                return {n / div, d / div };
            }
        }
        return *this;
    }

    string raw_str() const {
        return std::to_string(n) + "/" + std::to_string(d);
    }

    Rational& operator = (const Rational& obj);
    Rational operator * (const Rational& obj) const;

    void print() const {
        cout << "Nominator: " << n << " Denominator: " << d << endl;
    }
};

Rational Rational::operator * (const Rational & obj) const {
    return {obj.n * n, obj.d * d};
}

Rational& Rational::operator = (const Rational& obj) {
    if(this != &obj) {
        n = obj.n;
        d = obj.d;
    }
    return *this;
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return Rational((lhs.nominator() * rhs.denominator()) + (lhs.denominator() * rhs.nominator()), (lhs.denominator() + rhs.denominator()));
}

int main(int argc, char** argv) {

    Rational a {2, 8};
    Rational b {12, 99};

    Rational d {};
    d = a;

    Rational c = (a * b);
    c.print();

    cout << "14 + b: " << (14 + b).str() << endl;


    return 0;
}