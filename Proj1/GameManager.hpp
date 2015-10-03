//
//  GameManager.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Camera.hpp"
#include "GameObject.hpp"
#include "DynamicObject.hpp"
#include "LightSource.hpp"
#include "OrthogonalCamera.hpp"
#include "Orange.hpp"
#include "Car.hpp"
#include <math.h> 
#include <cmath>

class GameManager
{
    
private:
    std::vector<Camera*> _cameras;
    std::vector<GameObject*> _game_objects;
    std::vector<LightSource*> _light_sources;
    std::vector<Car*> _cars;
    Camera* _active_camera;
public:
    GameManager();
    ~GameManager();
    void display();
    void reshape(GLsizei, GLsizei);
    void keyPressed(bool *);
    void onTimer();
    void idle(bool *);
    void update();
    void init();
    
};

#endif /* GameManager_hpp */


