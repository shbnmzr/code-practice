//
// Created by Shabnam on 3/4/2023.
//

#pragma once

namespace uiuc{
    class Cube{
    public:
        double getVolume() {
            return (length_ * length_ * length_);
        }
        double getSurfaceArea() {
            return (6 * length_ * length_);
        }
        void setLength(double length) {
            length_ = length;
        }
        double getLength() {
            return length_;
        }

    private:
        double length_;
    };
}
