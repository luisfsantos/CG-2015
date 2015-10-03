//
//  DynamicObject.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef DynamicObject_hpp
#define DynamicObject_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Vector3.hpp"

class DynamicObject : public GameObject
{
protected:
    Vector3 _speed;
    double _accel;
    double _direction;
public:
    DynamicObject ();
    ~DynamicObject ();
    virtual void update (double);
    virtual void setSpeed (const Vector3&);
    virtual void setSpeed (double, double, double);
    Vector3 getSpeed ();
    double getDirection();
    void setDirection(double);
    double getAccel();
    void setAccel (double);
};


#endif /* DynamicObject_hpp */
