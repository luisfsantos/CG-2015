//
//  Butter.cpp
//  Proj1
//
//  Created by Luis Santos on 28/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Butter.hpp"

Butter::Butter() {
    setAbsSpeed(0);
    setDirection(0);
    setRotation(0);
    setSpeed(0,0,0);
    _height = 25;
    setBoundingBox(_height-4, _height+8);
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()+_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()+_halfHeight,0));
}

Butter::Butter(double height) {
    setAbsSpeed(0);
    setDirection(0);
    setSpeed(0,0,0);
    _height = height;
    setBoundingBox(_height-4, _height+8);
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()-_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()+_halfWidth, _position.getY()+_halfHeight,0));
    _vertices.push_back(new Vector3(_position.getX()-_halfWidth, _position.getY()+_halfHeight,0));
}

Butter::~Butter() {
    
}

void Butter::draw() {
    /* comment the material*/
    GLfloat amb[]={0.34f,0.34f,0.06f,1.0f};
    GLfloat diff[]={0.89f,0.89f,0.36f,1.0f};
    GLfloat spec[]={0.61f,0.61f,0.07f,1.0f};
    GLfloat shine=57;
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    /*material*/
    glPushMatrix();
    glTranslated(_position.getX(), _position.getY(), _position.getZ()+_height/2);
    glRotated(_rotation, 0, 0, 1);
    glScaled(1.628*1.628, 1.628, 1);
    glColor3ub(253, 228, 85);
    glutSolidCube(_height);
    glPopMatrix();
}

void Butter::update(double delta_t) {
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

void Butter::collide(GameObject* car) {
    setDirection(((DynamicObject*)car)->getDirection());
    setAbsSpeed(((DynamicObject*)car)->getAbsSpeed()*0.9);
    update(1);
    setAbsSpeed(0);
    if (((DynamicObject*)car)->getAbsSpeed() > 0) {
        ((DynamicObject*)car)->setAbsSpeed(-2);
    } else {
        ((DynamicObject*)car)->setAbsSpeed(2);
    }
    ((DynamicObject*)car)->setMovement(false, false, false, false);
}