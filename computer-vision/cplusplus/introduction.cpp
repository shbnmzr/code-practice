//
// Created by Shabnam on 3/4/2023.
//
#include <iostream>
#include "Cube.h"

int main(){
    int i = 4;
    i = i + 2;
    char c = 'a';

    std::cout << i << " " << c << std::endl;

    std::cout << "Here is a user-defined class" << std::endl;

    uiuc::Cube cube;
    cube.setLength(3.5);
    double volume = cube.getVolume();
    double area = cube.getSurfaceArea();

    std::cout << "Volume: " << volume << std::endl;
    std::cout << "Surface Area: " << area << std::endl;

    return 0;
}