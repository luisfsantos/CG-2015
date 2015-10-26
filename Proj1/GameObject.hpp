//
//  GameObject.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp
#include <stdlib.h>
#include <stdio.h>
#include "Entity.hpp"
#if defined(__APPLE__)|| defined(MACOSX)
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

class GameObject : public Entity
{
public:
    GameObject();
    ~GameObject();
    virtual void draw() {};
    virtual void update(double) {};
    virtual void setSpeed(double, double, double) {};
    virtual void setSpeed(Vector3) {};
    virtual void setDirection(double) {};
    virtual void setAbsSpeed(double) {};
    virtual void setRotation(double) {};
    virtual void collide(GameObject *) {};
    virtual void reset(double) {};
};


#endif /* GameObject_hpp */

