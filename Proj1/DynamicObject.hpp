//
//  DynamicObject.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef DynamicObject_hpp
#define DynamicObject_hpp
#include <stdlib.h>
#include <stdio.h>
#include "GameObject.hpp"
#include "Vector3.hpp"
#include <math.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415
#endif

#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3

#define LL       1
#define RR       -1



class DynamicObject : public GameObject
{
protected:
    Vector3 _speed;
    double _absSpeed;
    double _accelaration;
    double _maxSpeed;
    double _direction;
    double _rotation;
    double _turnSpeed;
    bool _movement[4]; //0-up 1-down 2-left 3-right
public:
    DynamicObject ();
    ~DynamicObject ();
    void update (double);
    virtual void setSpeed (const Vector3&);
    virtual void setSpeed (double, double, double);
    Vector3 getSpeed ();
    
    double getDirection();
    void setDirection(double);
    double getAbsSpeed();
    void setAbsSpeed (double);
    void accelarate(double);
    void brake(double);
    void turn(int);
    void setRotation(double);
    
    void setMovement(bool, bool, bool, bool);
    virtual void collide(GameObject *) {};
};


#endif /* DynamicObject_hpp */
