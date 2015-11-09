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
    /* comment the material*/
    
    GLfloat amb[]={0.1f,0.1f,0.1f,1.0f};
    GLfloat diff[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat shine=10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /* comment the material*/
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


void Roadside::drawTable2() {
    /* comment the material*/
    double hw = 720/50;
    double ww = 1280/50;
    GLfloat amb[]={0.1f,0.1f,0.1f,1.0f};
    GLfloat diff[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat spec[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat shine=10;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /* comment the material*/
    bool color = true;
    float x=0, y=0, z = 0;
    int w=1280, h=720, n=10, m=5;
    int sw = w/n, sh = h/m; //square width and height respectively
    //for each width and eight draw a rectangle with a specific color
    glPushMatrix();
    //glColor3ub(234,234,234);
    //glTranslated(w/2,h/2, 0);
    //glScaled(w, h, 20);
    for (y=0; y <= h; y += hw) {
        glBegin(GL_QUADS);
        
        for (x=0; x<=w+ww; x += ww) {
            glNormal3f(0, 0, 1);
            glVertex3f(x, y, z);
            glNormal3f(0, 0, 1);
            glVertex3f(x, y+hw, z);
            glNormal3f(0, 0, 1);
            glVertex3f(x+ww, y+hw, z);
            glNormal3f(0, 0, 1);
            glVertex3f(x+ww, y, z);
            
        }
        glEnd();
    }
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

