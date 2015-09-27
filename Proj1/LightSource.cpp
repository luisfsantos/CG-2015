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
    
}