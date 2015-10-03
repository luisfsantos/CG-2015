//
//  Roadside.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Roadside.hpp"

Roadside::Roadside() {
    
}

Roadside::~Roadside() {
    
}

void Roadside::draw() {
    
}

void Roadside::drawTorus(Vector3 translate) {
    glPushMatrix();
    glColor3ub(245, 231, 22);
    glTranslated(translate.getX(), translate.getY(), translate.getZ());
    glScaled(1, 1, 1);
    glRotated(90, 0, 1, 0);
    glutSolidTorus(0.5, 1, 20, 20);
    glPopMatrix();
}
