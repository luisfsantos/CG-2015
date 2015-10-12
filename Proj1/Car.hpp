//
//  Car.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp
#include <stdlib.h>
#if defined(__APPLE__)|| defined(MACOSX)
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include "DynamicObject.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415
#endif

class Car : public DynamicObject
{
public:
    Car();
    ~Car();
    virtual void draw();
    void drawWheel(int [], Vector3, Vector3);
    void drawCubeObj (int [], Vector3, Vector3);
    void update (double);
};
#endif /* Car_hpp */


