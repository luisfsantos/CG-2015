//
//  Cherrio.cpp
//  Proj1
//
//  Created by Luis Santos on 20/10/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Cherrio.hpp"

Cherrio::Cherrio(){
    _innerR = 0.6;
}

Cherrio::Cherrio(double x, double y, double z, double innerR, double outerR){
    _innerR = innerR;
    _outerR = outerR;
    setPosition(x, y, z);
}

Cherrio::~Cherrio(){
    
}

void Cherrio::draw(){
    glPushMatrix();
    glColor3ub(255, 204, 102);
    glTranslated(_position.getX(), _position.getY(), _position.getZ()+_innerR);
    glutSolidTorus(_innerR, _outerR, 16, 16);
    glPopMatrix();
}