//
//  Butter.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Butter_hpp
#define Butter_hpp

#include <stdio.h>
#include "Obstacle.hpp"

class Butter : public Obstacle
{
public:
    Butter();
    ~Butter();
    virtual void draw();
};

#endif /* Butter_hpp */

