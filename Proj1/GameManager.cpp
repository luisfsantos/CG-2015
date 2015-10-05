//
//  GameManager.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "GameManager.hpp"

int oldTime = 0;
GLenum polygonMode = GL_FILL;

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
    _keys = keys;
    if (_keys[KEY_A]) {
        (polygonMode == GL_LINE) ? glPolygonMode(GL_FRONT_AND_BACK, polygonMode = GL_FILL) : glPolygonMode(GL_FRONT_AND_BACK, polygonMode =GL_LINE);
    }
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

    if(!keys[KEY_UP] && !keys[KEY_DOWN] && deltaTime > 20 && _cars[0]->getAccel() != 0) {
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
    
    if(!keys[KEY_UP_2] && !keys[KEY_DOWN_2] && deltaTime > 20 && _cars[1]->getAccel() != 0) {
        if (_cars[1]->getAccel() < daccel && _cars[1]->getAccel() > -daccel) {
            _cars[1]->setAccel(0);
        }
        else if (_cars[1]->getAccel() < 0) {
            _cars[1]->setAccel(_cars[1]->getAccel()+daccel);
        }
        else {
            _cars[1]->setAccel(_cars[1]->getAccel()-daccel);
        }
    }
}

void GameManager::update() {
    
    double rate_D = 4;
    double max_A = 5;
    double min_A = -3;
    double rate_A = 0.1;
    
    if(_keys[KEY_UP]) _cars[0]->setAccel(_cars[0]->getAccel()+rate_A);
    if(_keys[KEY_LEFT]) _cars[0]->setDirection(_cars[0]->getDirection()+rate_D);
    if(_keys[KEY_RIGHT]) _cars[0]->setDirection(_cars[0]->getDirection()-rate_D);
    if(_keys[KEY_DOWN]) _cars[0]->setAccel(_cars[0]->getAccel()-rate_A);
    if(_cars[0]->getAccel() > max_A) _cars[0]->setAccel(max_A);
    if(_cars[0]->getAccel() < min_A) _cars[0]->setAccel(min_A);
    
    /**/
    if(_keys[KEY_UP_2]) _cars[1]->setAccel(_cars[1]->getAccel()+rate_A);
    if(_keys[KEY_LEFT_2]) _cars[1]->setDirection(_cars[1]->getDirection()+rate_D);
    if(_keys[KEY_RIGHT_2]) _cars[1]->setDirection(_cars[1]->getDirection()-rate_D);
    if(_keys[KEY_DOWN_2]) _cars[1]->setAccel(_cars[1]->getAccel()-rate_A);
    if(_cars[1]->getAccel() > max_A) _cars[1]->setAccel(max_A);
    if(_cars[1]->getAccel() < min_A) _cars[1]->setAccel(min_A);
    /**/
    
    
    std::vector<GameObject*>::iterator iter;
    for ( iter = _game_objects.begin() ; iter != _game_objects.end(); ++iter){
        (*iter)->update(1);
    }
    //fill this in depending on what its supposed to do
}

void GameManager::init() {
    _active_camera = new OrthogonalCamera(0, 1280, 0, 720, -40., 40.);
    _cameras.push_back(_active_camera);
    _cars.push_back(new Car());
    _cars.push_back(new Car());
    _game_objects.push_back(new Roadside());
    _game_objects.push_back(new Orange());
    _game_objects.push_back(_cars[0]);
    _game_objects.push_back(_cars[1]);
    
    
    _cars[0]->setDirection(90);
    _cars[0]->setAccel(0);
    _cars[1]->setDirection(90);
    _cars[1]->setAccel(0);
    
    _game_objects[0]->setPosition(0, 0, 0);
    _game_objects[1]->setPosition(80, 80, 0);
    _game_objects[2]->setPosition(135, 300, 0);
    _game_objects[3]->setPosition(105, 300, 0);
}

void GameManager::setKeys(bool * keys){
    _keys=keys;
}
