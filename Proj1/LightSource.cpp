//
//  LightSource.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "LightSource.hpp"

LightSource::LightSource(GLenum number) {
    _num = number;
}

LightSource::~LightSource() {
    //fill this in depending on what its supposed to do
}

bool LightSource::getState() {
    return _state;
}

bool LightSource::setState(bool state) {
    return _state = state;
}

GLenum LightSource::getNum() {
    return _num;
}

void LightSource::setPosition(const Vector3& position) {
    _position = position;
}

void LightSource::setDirection(const Vector3& direction) {
    _direction = direction;
}

void LightSource::setCutOff(double cutoff) {
    _cut_off = cutoff;
}

void LightSource::setExponent(double exponent) {
    _exponent = exponent;
}

void LightSource::setAmbient(const Vector3& ambient) {
    Vector3 aux;
    aux = ambient;
    _ambient[0] = aux.getX();
    _ambient[1] = aux.getY();
    _ambient[2] = aux.getZ();
    _ambient[3] = 1;
}

void LightSource::setDiffuse(const Vector3& diffuse) {
    Vector3 aux;
    aux = diffuse;
    _diffuse[0] = aux.getX();
    _diffuse[1] = aux.getY();
    _diffuse[2] = aux.getZ();
    _diffuse[3] = 1;
}

void LightSource::setSpecular(const Vector3& specular) {
    Vector3 aux;
    aux = specular;
    _specular[0] = aux.getX();
    _specular[1] = aux.getY();
    _specular[2] = aux.getZ();
    _specular[3] = 1;
}

void draw() {
    //fill this in depending on what its supposed to do
}





