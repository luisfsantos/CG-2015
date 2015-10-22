//
//  Roadside.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Roadside.hpp"

int colors[6][3] = {
    {255, 255, 194},
    {204, 102, 255},
    {178, 204, 255},
    {255, 132, 132},
    {194, 255, 173},
    {255, 194, 133}
};

Roadside::Roadside() {
    
}

Roadside::Roadside(double positions[][3], int size) {
    for (int i=0; i<size; i++) {
        _cherrios.push_back(new Cherrio(positions[i][0], positions[i][1], positions[i][2], 0.6*0.004, 0.004));
    }
}

Roadside::~Roadside() {
    
}

void Roadside::draw() {
    std::vector<Cherrio*>::iterator iter;
    drawTable();
    glPushMatrix();
    glTranslatef(_position.getX(), _position.getY(), _position.getZ());
    glScaled(1000, 1000, 800);
    for ( iter = _cherrios.begin() ; iter != _cherrios.end(); ++iter){
        (*iter)->draw();
    }
    glPopMatrix();
    
}

void Roadside::drawTable() {
    bool color = true;
    int w=1280, h=720, n=10, m=5;
    int sw = w/n, sh = h/m; //square width and height respectively
    //for each width and eight draw a rectangle with a specific color
    glPushMatrix();
    glColor3ub(234,234,234);
    glTranslated(w/2,h/2, -10);
    glScaled(w, h, 20);
    glRotated(0, 0, 0, 0);
    glutSolidCube(1);
    glPopMatrix();

     
}
