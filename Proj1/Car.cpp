
//
//  Car.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Car.hpp"

Car::Car() {
    setDirection(90);
    setAbsSpeed(0);
}

Car::~Car() {
    
}

void Car::draw() {
    /***************************************
     DECLARING VARIABLES
     Object variables 
     **************************************/
    
    //special colors
    int tecnico_Blue [3] =  {0, 157, 224};
    int tecnico_Gray [3] =  {70, 85, 95};
    
    //main undercarriage
    int *undercarriage_C = tecnico_Blue;
    Vector3 undercarriage_T (0, 0, 0.3+1);
    Vector3 undercarriage_S (3, 7, 1);
    
    //back engine compartment
    int *backEngine_C = tecnico_Gray;
    Vector3 backEngine_T(0, -2, 1.5+1);
    Vector3 backEngine_S(3, 3, 1.4);
    
    //strips on either side of driver
    Vector3 leftStrip_T(-1.1, 1.45, 0.95+1);
    Vector3 rightStrip_T(1.1, 1.45, 0.95+1);
    Vector3 bothStrip_S(0.3, 3.9, 0.3);
    
    
    //wheels
    int allWheel_C [3] = {0, 0, 0};
    Vector3 lbWheel_T(-2, -2.5, 1);
    Vector3 lfWheel_T(-2, 2.15, 1);
    Vector3 rbWheel_T(2, -2.5, 1);
    Vector3 rfWheel_T(2, 2.15, 1);
    Vector3 back_S(0.89, 0.75, 0.75);
    Vector3 front_S(0.69, 0.75, 0.75);
    
    //final scaling of the object
    int scale = 4;
    
    /****************************************
     METHOD CALLS
     Creating the objects
     ***************************************/
    
    
    glPushMatrix();
    
    glTranslated(_position.getX(), _position.getY(), _position.getZ()); //move car around
    glScaled(scale, scale, scale);
    glRotated(_direction-90, 0, 0, 1);
    //glRotated(90, 0, 0, 1);
    //glRotated(90, 0, 1, 0);
    
    // main undercarriage
    this->drawCubeObj(undercarriage_C, undercarriage_T, undercarriage_S);
    
    //head of driver
    glPushMatrix();
    glColor3ub(236, 238, 239);
    glTranslated(0, 0.2, 1.4);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    
    //back engine compartment
    this->drawCubeObj(backEngine_C, backEngine_T, backEngine_S);
    
    
    // strips on either side of the driver
    //1
    this->drawCubeObj(tecnico_Gray, leftStrip_T, bothStrip_S);
    //2
    this->drawCubeObj(tecnico_Gray, rightStrip_T, bothStrip_S);
    
    
    /**********
     WHEELS
     *********/
    // left back
    this->drawWheel(allWheel_C, lbWheel_T, back_S);
    // left front
    this->drawWheel(allWheel_C, lfWheel_T, front_S);
    // right back
    this->drawWheel(allWheel_C, rbWheel_T, back_S);
    // right front
    this->drawWheel(allWheel_C, rfWheel_T, front_S);
    
    glPopMatrix();
}

void Car::drawWheel (int color[], Vector3 translate, Vector3 scale) {
    glPushMatrix();
    glColor3f(color[0], color[1], color[2]);
    glTranslated(translate.getX(), translate.getY(), translate.getZ());
    glScaled(scale.getX(), scale.getY(), scale.getZ());
    glRotated(90, 0, 1, 0);
    glutSolidTorus(0.5, 1, 20, 20);
    glPopMatrix();
}

void Car::drawCubeObj (int color[], Vector3 translate, Vector3 scale) {
    glPushMatrix();
    glColor3ub(color[0], color[1], color[2]);
    glTranslated(translate.getX(), translate.getY(), translate.getZ());
    glScaled(scale.getX(), scale.getY(), scale.getZ());
    glutSolidCube(1);
    glPopMatrix();
}

void Car::update(double delta_t) {
    
    if (_movement[UP]) accelarate(1);
    if (_movement[DOWN]) brake(1);
    if (_movement[LEFT]) turn(L);
    if (_movement[RIGHT]) turn(R);
    
    if (_absSpeed!=0 && !_movement[UP] && !_movement[DOWN]) {
        if (_absSpeed< -_accelaration) accelarate(0.4);
        else if (_absSpeed>_accelaration) brake(0.4);
        else _absSpeed = 0;
    }
    
    setSpeed(cos((getDirection() * M_PI ) / 180.0 ) * getAbsSpeed(), sin((getDirection() * M_PI ) / 180.0 )* getAbsSpeed(), 0);
    _position = _position + _speed * delta_t;
}








