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
private:
    Vector3 _speed;
public:
    DynamicObject ();
    ~DynamicObject ();
    void update (double);
    void setSpeed (const Vector3&);
    void setSpeed (double, double, double);
    Vector3 getSpeed ();
};

#endif /* DynamicObject_hpp */
