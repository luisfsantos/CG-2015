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
#include "DynamicObject.hpp"
#include "Vector3.hpp"

class Cherrio :public DynamicObject
{
private:
    double _innerR;
    double _outerR;
public:
    Cherrio();
    Cherrio(double, double, double, double, double);
    ~Cherrio();
    void draw();
};

#endif /* Cherrio_hpp */
