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
    setRotation(0);
    setDirection(0);
    setAbsSpeed(0);
    setBoundingBox(outerR, outerR);
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()+_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()+_halfHeight,0));
    
}

Cherrio::~Cherrio(){
    
}

void Cherrio::draw(){
    /* comment the material*/
    GLfloat amb[]={0.34725f,0.2995f,0.1745f,1.0f};
    GLfloat diff[]={0.65164f,0.50648f,0.12648f,1.0f};
    GLfloat spec[]={0.628281f,0.555802f,0.366065f,1.0f};
    GLfloat shine=51.2f;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /*material*/
    glPushMatrix();
    glColor3ub(255, 204, 102);
    glTranslated(_position.getX(), _position.getY(), _position.getZ()+_innerR);
    glutSolidTorus(_innerR, _outerR, 16, 16);
    glPopMatrix();
}

void Cherrio::update(double delta_t) {
    std::vector<Vector3*>::iterator iter;
    int i = 0;
    double _angle = ((_rotation * M_PI ) / 180.0);
    double _angle2 = ((_direction * M_PI ) / 180.0);
    _halfWidth = _Height*std::abs(sin(_angle)) + _Width*std::abs(cos(_angle));
    _halfHeight = _Height*std::abs(cos(_angle)) + _Width*std::abs(sin(_angle));
    
    setSpeed(cos(_angle2) * getAbsSpeed(), sin(_angle2)* getAbsSpeed(), 0);
    _position = _position + _speed * delta_t;
    
    for (iter = _vertices.begin(); iter != _vertices.end(); ++iter, i++) {
        double temp [4][2] = {{-_Width, _Height},{-_Width, -_Height},{_Width, -_Height},{_Width, _Height}};
        double tempX = temp[i][0];
        double tempY = temp[i][1];
        
        // now apply rotation
        float rotatedX = tempX*cos(_angle) - tempY*sin(_angle);
        float rotatedY = tempX*sin(_angle) + tempY*cos(_angle);
        
        // translate back
        (*iter)->set(rotatedX + _position.getX(), rotatedY + _position.getY(), 0);
    }
}

void Cherrio::collide(GameObject* car) {
    setDirection(((DynamicObject*)car)->getDirection());
    setAbsSpeed(((DynamicObject*)car)->getAbsSpeed()*1.5);
    update(1);
    setAbsSpeed(0);
    if (((DynamicObject*)car)->getAbsSpeed() > 0) {
        ((DynamicObject*)car)->setAbsSpeed(-1);
    } else {
        ((DynamicObject*)car)->setAbsSpeed(1);
    }
    ((DynamicObject*)car)->setMovement(false, false, false, false);
}