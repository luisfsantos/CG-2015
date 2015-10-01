//
//  Orange.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Orange_hpp
#define Orange_hpp

#include <stdio.h>
#include "Obstacle.hpp"
#if defined(__APPLE__)|| defined(MACOSX)
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

class Orange : public Obstacle
{
public:
    Orange();
    ~Orange();
    virtual void draw();
};

#endif /* Orange_hpp */

