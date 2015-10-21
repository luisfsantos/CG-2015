//
//  Cherrio.hpp
//  Proj1
//
//  Created by Luis Santos on 20/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Cherrio_hpp
#define Cherrio_hpp

#include <stdio.h>
#include "StaticObject.hpp"
#include "Vector3.hpp"

class Cherrio :public StaticObject
{
private:
    double _width;
public:
    Cherrio();
    Cherrio(double, double, double);
    ~Cherrio();
    void draw();
};

#endif /* Cherrio_hpp */
