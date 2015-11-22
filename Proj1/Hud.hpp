//
//  Hud.hpp
//  Proj1
//
//  Created by Luis Santos on 22/11/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef Hud_hpp
#define Hud_hpp

#include <stdio.h>
#include "Car.hpp"
#include <vector>

class Hud
{
    double _lives;
    std::vector<Car*> _cars;
    GLuint _paused;
    GLuint _game_over;
public:
    Hud() {};
    Hud(double);
    ~Hud();
    void update();
    void create_cars();
    void die();
    void pause();
    void unpause();
};

#endif /* Hud_hpp */
