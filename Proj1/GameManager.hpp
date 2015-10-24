//
//  GameManager.hpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp
#define _USE_MATH_DEFINES


#include <stdio.h>
//#include <stdlib.h>
#include <vector>
#include "Camera.hpp"
#include "GameObject.hpp"
#include "DynamicObject.hpp"
#include "LightSource.hpp"
#include "OrthogonalCamera.hpp"
#include "PerspectiveCamera.hpp"
#include "Orange.hpp"
#include "Car.hpp"
#include "Roadside.hpp"
#include "Table.hpp"
#include "Butter.hpp"
#include "Cherrio.hpp"
#include <math.h> 
#include <cmath>
//#include <GL/glut.h>

#define KEY_A               97
#define KEY_B               98
#define KEY_LEFT			256
#define KEY_UP              257
#define KEY_RIGHT			258
#define KEY_DOWN			259
#define KEY_RIGHT_2			102
#define KEY_UP_2            101
#define KEY_LEFT_2			115
#define KEY_DOWN_2			100



class GameManager
{
    
private:
    std::vector<Camera*> _cameras;
    std::vector<GameObject*> _game_objects;
    std::vector<DynamicObject*> _dynamic_objects;
    std::vector<LightSource*> _light_sources;
    std::vector<Car*> _cars;
    Roadside* _road;
    Camera* _active_camera;
    bool* _keys;
public:
    GameManager();
    ~GameManager();
    void display();
    void reshape(GLsizei, GLsizei);
    void keyPressed(bool *);
    void onTimer();
    void idle();
    void update();
    void init();
    void setKeys(bool *);
    
};

#endif /* GameManager_hpp */


