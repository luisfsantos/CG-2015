//
//  Obstacle.hpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp
#include <stdlib.h>
#include <stdio.h>
#include "DynamicObject.hpp"
;
class Obstacle : public DynamicObject
{
public:
    Obstacle();
    ~Obstacle();
    void collide(GameObject *);
};

#endif /* Obstacle_hpp */

