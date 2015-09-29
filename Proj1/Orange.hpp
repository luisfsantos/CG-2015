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
#include <GLUT/GLUT.h>

class Orange : public Obstacle
{
public:
    Orange();
    ~Orange();
    void draw();
};

#endif /* Orange_hpp */
