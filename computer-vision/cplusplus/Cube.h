//
// Created by Shabnam on 3/4/2023.
//

#pragma once

namespace uiuc{
    class Cube{
    public:
        double getVolume();
        double getSurfaceArea();
        void setLength(double length);
        double getLength();

    private:
        double length_;
    };
}


