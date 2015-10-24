//
//  Roadside.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Roadside.hpp"
#include "Orange.hpp"

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

Roadside::Roadside(double positions[][3], int size, double x, double y, double z) {
    _position.set(x, y, z);
    for (int i=0; i<size; i++) {
        _cherrios.push_back(new Cherrio(positions[i][0]+x, positions[i][1]+y, positions[i][2]+z, 2.4, 4));
    }
}

Roadside::~Roadside() {
    
}

void Roadside::draw() {
    std::vector<Cherrio*>::iterator iter;
    drawTable();
    glPushMatrix();
    //glTranslatef(_position.getX(), _position.getY(), _position.getZ());
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

bool Roadside::isIntersecting(GameObject orange) {
    bool test1 = false, test2 = false;
    test1 = (orange.getPosition()->getX() + orange.getHalfWidth() < 0
            ||
			orange.getPosition()->getX() - orange.getHalfHeight() > 1280);
    test2 = (orange.getPosition()->getY() + orange.getHalfWidth() < 0
            ||
			orange.getPosition()->getY() - orange.getHalfHeight() > 720);
    return test1 || test2;
}

std::vector<Cherrio*> Roadside::getCherrios() {
    return _cherrios;
}

