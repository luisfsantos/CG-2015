//
//  Candle.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright  2015 Luis Santos. All rights reserved.
//

#include "Candle.hpp"

Candle::Candle(LightSource *flame){
    _flame = flame;
}

Candle::Candle(double x, double y, double z, LightSource *flame) {
    setPosition(x, y, z);
    _flame = flame;
    _flame->setPosition(x, y, z+60, 1.0);
    _flame->setAmbient(1, 0.58, 0.16, 0.2);
    _flame->setDiffuse(1, 0.58, 0.16, 0.2);
    _flame->setSpecular(1, 0.58, 0.16, 0.2);
    glLightf(_flame->getNum(), GL_LINEAR_ATTENUATION, 0);
    glLightf(_flame->getNum(), GL_QUADRATIC_ATTENUATION, 0.0001);
    _flame->draw();
    
}

Candle::~Candle() {
    
}

void Candle::draw() {
    /* comment the material*/
    GLfloat amb[]={0.2125f,0.1275f,0.054f,1.0f};
    GLfloat diff[]={0.714f,0.4284f,0.18144f,1.0f};
    GLfloat spec[]={0.393548f,0.271906f,0.166721f,1.0f};
    GLfloat shine=25.6;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
    
    /*material*/
    glPushMatrix();
    glColor3f(0.2125f,0.1275f,0.054f);
    glTranslated(_position.getX(), _position.getY(), _position.getZ());
    
    glPushMatrix();
    glTranslated(0, 0, 6.25);
    glScaled(5, 5, 2.5);
    glColor3ub(2, 2, 85);
    glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0, 0, 18.75);
    glScaled(2.5, 2.5, 2.5);
    glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();
    GLfloat amb1[]={0.64f,0.49f,0.1f,1.0f};
    GLfloat diff1[]={1.0f,0.56f,0.13f,1.0f};
    GLfloat spec1[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat shine1=36;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine1);
    
    glTranslated(0, 0, 35);
    glScaled(1, 1, 2.5);
    glutSolidSphere(4, 16, 16);
    glPopMatrix();
    glPopMatrix();
}

void Candle::update(double delta_t) {
}