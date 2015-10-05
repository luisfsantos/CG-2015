//
//  GameManager.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "GameManager.hpp"

int oldTime = 0;

GameManager::GameManager() {
    //glEnable(GL_DEPTH_TEST);
}

GameManager::~GameManager() {
    //fill this in depending on what its supposed to do
}

void GameManager::display() {
    std::vector<GameObject*>::iterator iter;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for ( iter = _game_objects.begin() ; iter != _game_objects.end(); ++iter){
        (*iter)->draw();
    }
    
    glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
    _active_camera->update(w,h);
}

void GameManager::keyPressed(bool *keys) {
    
    double rate_D = 20;
    double max_A = 4;
    double min_A = -3;
    double rate_A = 0.5;
    
    if(keys['w']) _cars[0]->setAccel(_cars[0]->getAccel()+rate_A);
    if(keys['d']) _cars[0]->setDirection(_cars[0]->getDirection()-rate_D);
    if(keys['a']) _cars[0]->setDirection(_cars[0]->getDirection()+rate_D);
    if(keys['s']) _cars[0]->setAccel(_cars[0]->getAccel()-rate_A);
    if(_cars[0]->getAccel() > max_A) _cars[0]->setAccel(max_A);
    if(_cars[0]->getAccel() < min_A) _cars[0]->setAccel(min_A);
}

void GameManager::onTimer() {
    this->update();
    glutSwapBuffers();
    glutPostRedisplay();// Post re-paint request to activate display()
}

void GameManager::idle(bool *keys) {
    int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeSinceStart - oldTime;
    double daccel = 0.2;
    oldTime = timeSinceStart;
    if(!keys['w'] && !keys['s'] && deltaTime > 20 && _cars[0]->getAccel() != 0) {
        if (_cars[0]->getAccel() < daccel && _cars[0]->getAccel() > -daccel) {
            _cars[0]->setAccel(0);
        }
        else if (_cars[0]->getAccel() < 0) {
            _cars[0]->setAccel(_cars[0]->getAccel()+daccel);
        }
        else {
            _cars[0]->setAccel(_cars[0]->getAccel()-daccel);
        }
    }
}

void GameManager::update() {
    std::vector<GameObject*>::iterator iter;
    _cars[0]->setSpeed(cos(( _cars[0]->getDirection() * M_PI ) / 180.0 ) * _cars[0]->getAccel(), sin(( _cars[0]->getDirection() * M_PI ) / 180.0 )* _cars[0]->getAccel(), 0);
    for ( iter = _game_objects.begin() ; iter != _game_objects.end(); ++iter){
        (*iter)->update(1);
    }
    //fill this in depending on what its supposed to do
}

void GameManager::init() {
    _active_camera = new OrthogonalCamera(0, 1280, 0, 720, -40., 40.);
    _cameras.push_back(_active_camera);
    _cars.push_back(new Car());
    _game_objects.push_back(_cars[0]);
    _game_objects.push_back(new Orange());
    _game_objects.push_back(new Roadside());
    _game_objects[0]->setPosition(150, 300, 0);
    _cars[0]->setDirection(90);
    _cars[0]->setAccel(0);
    _game_objects[1]->setPosition(80, 80, 0);
    _game_objects[2]->setPosition(0, -30, 0);
}
