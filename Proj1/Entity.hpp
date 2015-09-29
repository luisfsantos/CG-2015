//
//  Entity.hpp
//  Proj1
//
//  Created by Luis Santos on 26/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "Vector3.hpp"


class Entity
{
protected:
    Vector3 _position;
public:
    Entity();
    ~Entity();
    Vector3 getPosition();
    Vector3 setPosition(double, double, double);
    Vector3 setPosition(const Vector3&);
};

#endif /* Entity_hpp */



