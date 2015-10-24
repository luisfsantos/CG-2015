//
//  Cherrio.hpp
//  Proj1
//
//  Created by Luis Santos on 20/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Cherrio_hpp
#define Cherrio_hpp
#include <stdlib.h>
#include <stdio.h>
#include "Obstacle.hpp"
#include "Vector3.hpp"

class Cherrio :public Obstacle
{
private:
    double _innerR;
    double _outerR;
public:
    Cherrio();
    Cherrio(double, double, double, double, double);
    ~Cherrio();
    void draw();
    void update(double);
};

#endif /* Cherrio_hpp */
