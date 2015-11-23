//
//  LightSource.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "LightSource.hpp"

LightSource::LightSource() {
}

LightSource::LightSource(GLenum number) {
    _num = number;
    setPosition(0,0,1.0,1.0);
    //setDirection(Vector3(0,0,1));
    setAmbient(0.0, 0.0, 0.0, 1.0);
    setDiffuse(1.0, 1.0, 1.0, 1.0);
    setSpecular(1.0, 1.0, 1.0, 1.0);
    setState(true);
    setExponent(0);
    setCutOff(180);
}

LightSource::~LightSource() {
    //fill this in depending on what its supposed to do
}

bool LightSource::getState() {
    return _state;
}

bool LightSource::setState(bool state) {
    if (state) {
        glEnable(_num);
    } else {
        glDisable(_num);
    }
    return _state = state;
}

GLenum LightSource::getNum() {
    return _num;
}

void LightSource::setPosition(const Vector3& position) {
    Vector3 aux;
    aux = position;
    _position[0] = aux.getX();
    _position[1] = aux.getY();
    _position[2] = aux.getZ();
    _position[3] = 1.0;
}

void LightSource::setPosition(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _position[0] = x;
    _position[1] = y;
    _position[2] = z;
    _position[3] = w;
}

void LightSource::setDirection(const Vector3& direction) {
    _direction = direction;
}

void LightSource::setDirection(double x, double y, double z) {
    _direction.setX(x);
    _direction.setY(y);
    _direction.setZ(z);
}

void LightSource::setCutOff(GLfloat cutoff) {
    _cut_off = cutoff;
}

void LightSource::setExponent(GLfloat exponent) {
    _exponent = exponent;
}

void LightSource::setAmbient(const Vector3& ambient) {
    Vector3 aux;
    aux = ambient;
    _ambient[0] = aux.getX();
    _ambient[1] = aux.getY();
    _ambient[2] = aux.getZ();
    _ambient[3] = 1.0;
}

void LightSource::setAmbient(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _ambient[0] = x;
    _ambient[1] = y;
    _ambient[2] = z;
    _ambient[3] = w;
}

void LightSource::setDiffuse(const Vector3& diffuse) {
    Vector3 aux;
    aux = diffuse;
    _diffuse[0] = aux.getX();
    _diffuse[1] = aux.getY();
    _diffuse[2] = aux.getZ();
    _diffuse[3] = 1.0;
}

void LightSource::setDiffuse(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _diffuse[0] = x;
    _diffuse[1] = y;
    _diffuse[2] = z;
    _diffuse[3] = w;
}

void LightSource::setSpecular(const Vector3& specular) {
    Vector3 aux;
    aux = specular;
    _specular[0] = aux.getX();
    _specular[1] = aux.getY();
    _specular[2] = aux.getZ();
    _specular[3] = 1.0;
}

void LightSource::setSpecular(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _specular[0] = x;
    _specular[1] = y;
    _specular[2] = z;
    _specular[3] = w;
}

void LightSource::draw() {
    GLfloat direction[] = {static_cast<GLfloat>(_direction.getX()), static_cast<GLfloat>(_direction.getY()), static_cast<GLfloat>(_direction.getZ())};
    glLightfv(_num, GL_AMBIENT, _ambient);
    glLightfv(_num, GL_DIFFUSE, _diffuse);
    glLightfv(_num, GL_SPECULAR, _specular);
    glLightfv(_num, GL_POSITION, _position);
    glLightf(_num, GL_SPOT_CUTOFF, _cut_off);
    glLightfv(_num, GL_SPOT_DIRECTION, direction);
    glLightf(_num, GL_SPOT_EXPONENT, _exponent);

}






