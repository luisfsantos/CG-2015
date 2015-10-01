//
//  GameObject.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

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
};


#endif /* GameObject_hpp */

