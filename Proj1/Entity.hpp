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
#include <stdlib.h>
#include <vector>
#include "Vector3.hpp"
#include "Projection.hpp"

class Entity
{
protected:
    Vector3 _position;
    double _halfHeight, _Height;
    double _halfWidth, _Width;
    std::vector<Vector3*> _vertices;
public:
    Entity();
    ~Entity();
    Vector3* getPosition();
    Vector3* setPosition(double, double, double);
    Vector3* setPosition(Vector3);
    void setBoundingBox(double, double);
    virtual bool isIntersecting(Entity);
    bool isIntersecting2(Entity);
    double getHalfWidth();
    double getHalfHeight();
    std::vector<Vector3*> getAxis();
    Projection project(Vector3);
};

#endif /* Entity_hpp */



