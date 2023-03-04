//
// Created by Shabnam on 3/4/2023.
//
#include "Cube.h"

namespace uiuc{
    double Cube::getVolume() {
        return (length_ * length_ * length_);
    }

    double Cube::getSurfaceArea(){
        return (6 * length_ * length_);
    }

    double Cube::getLength() {
        return length_;
    }

    void Cube::setLength(double length){
        length_ = length;
    }
}
