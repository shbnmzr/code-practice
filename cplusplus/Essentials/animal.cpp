//
// Created by Shabnam on 3/28/2023.
//

#include <iostream>

using namespace std;

class Animal {
    string type {};
    string name {};

public:
    Animal();
    Animal(const string& type, const string& name);
    Animal(const Animal& a);
    ~Animal();
    Animal& operator = (const Animal&);
    void print() const;
};

Animal::Animal(): type("unknown"), name("unknown") {
    cout << "default constructor" << endl;
}

Animal::Animal(const string& type, const string& name): type(type), name(name) {
    cout << "Type: " << type << endl;
    cout << "Name: " << name << endl;
}

Animal::Animal(const Animal& a) {
    cout << "Copy constructor" << endl;
    name = a.name + "-clone";
    type = a.type;
}

Animal::~Animal() {
    cout << "Destructor destroys " << name << endl;
}

Animal& Animal::operator = (const Animal& o) {
    cout << "assignment operator overload" << endl;
    if(this != &o){
        name = "clone-" + o.name;
        type = "clone-" + o.type;
    }
    return *this;
}

void Animal::print() const {
    cout << name << " is " << type << endl;
}

int main(int argc, char** argv) {

    Animal a {};
    a.print();

    Animal b ("goat", "Bob");
    b.print();

    const Animal c {b};
    c.print();

    Animal d {};
    d = a;
    d.print();

    return 0;
}
