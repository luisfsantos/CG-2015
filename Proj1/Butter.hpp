//
//  Butter.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Butter_hpp
#define Butter_hpp
#include <stdlib.h>
#include <stdio.h>
#include "Obstacle.hpp"

class Butter : public Obstacle
{
private:
    double _height;
public:
    Butter();
    Butter(double);
    ~Butter();
    virtual void draw();
    void update(double);
    void collide(GameObject*);
};

#endif /* Butter_hpp */

