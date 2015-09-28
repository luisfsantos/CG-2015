//
//  main.cpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include <iostream>
#include "Vector3.hpp"
#include "LightSource.hpp"

int main(int argc, const char * argv[]) {
    Vector3::Vector3 vector1(2, 3, 4);
    Vector3::Vector3 vector2;
    LightSource::LightSource ls(1);
    ls.setAmbient(vector1);
    delete vector2;
    double h = 9;
    std::cout << vector1.getX() << " " << vector1.getY() << " " << vector1.getZ() << "\n";
    vector2 = vector1 * h;
    vector2 = vector1 + vector2;
    std::cout << vector2.getX() << " " << vector2.getY() << " " << vector2.getZ() << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}
