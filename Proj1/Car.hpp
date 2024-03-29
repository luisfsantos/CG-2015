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
#include "LightSource.hpp"


class Car : public DynamicObject
{
private:
    LightSource * _headlights[2];
    double _lives;
public:
    Car();
    Car(LightSource*, LightSource*);
    ~Car();
    virtual void draw();
    void drawWheel(int [], Vector3, Vector3, bool);
    void drawCubeObj (int [], Vector3, Vector3);
    void update(double);
    void drawUnder();
    void drawStrips();
    void drawCage();
    void setLives(double);
    void die();
    double getLives();
    void headlights_toggle(bool);
};
#endif /* Car_hpp */


