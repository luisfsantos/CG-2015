//
//  Obstacle.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Obstacle.hpp"

Obstacle::Obstacle() {
    
}

Obstacle::~Obstacle() {
    
}

void Obstacle::collide(GameObject* car) {
    setDirection(((DynamicObject*)car)->getDirection());
    setAbsSpeed(((DynamicObject*)car)->getAbsSpeed()*0.9);
    update(1);
    setAbsSpeed(0);
    if (((DynamicObject*)car)->getAbsSpeed() > 0) {
        ((DynamicObject*)car)->setAbsSpeed(-2);
    } else {
        ((DynamicObject*)car)->setAbsSpeed(2);
    }
    //((DynamicObject*)car)->setAbsSpeed(-2);
    //((DynamicObject*)car)->setMovement(false, false, false, false);
}