//
//  Cherrio.cpp
//  Proj1
//
//  Created by Luis Santos on 20/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Cherrio.hpp"

Cherrio::Cherrio(){
    _width = 0.6;
}

Cherrio::Cherrio(double x, double y, double z){
    _width = 0.6*0.004;
    setPosition(x, y, z);
}

Cherrio::~Cherrio(){
    
}

void Cherrio::draw(){
    glPushMatrix();
    glColor3ub(255, 204, 102);
    glTranslated(_position.getX(), _position.getY(), _position.getZ()+_width);
    glutSolidTorus(_width, 0.004, 16, 16);
    glPopMatrix();
}