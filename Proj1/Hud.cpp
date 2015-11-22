//
//  Hud.cpp
//  Proj1
//
//  Created by Luis Santos on 22/11/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Hud.hpp"



Hud::Hud(double lives){
    _lives = lives;
    create_cars();
}

Hud::~Hud() {
    
}

void Hud::update() {
    std::vector<Car*>::iterator car;
    if (_lives > 0) {
        for ( car = _cars.begin() ; car != _cars.end(); ++car){
            (*car)->draw();
        }
    }
}

void Hud::die() {
    _cars.pop_back();
    _lives -= 1;
}

void Hud::create_cars() {
    for (int i = 0; i<_lives; i++) {
        _cars.push_back(new Car());
        _cars[i]->setPosition((1260-i*25), 700, 4);
    }
}

void Hud::pause() {
    
}

void Hud::unpause() {
    
}