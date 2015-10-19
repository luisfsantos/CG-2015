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
    if (_keys[KEY_B]) {
        init();
    }
    
    _cars[0]->setMovement(_keys[KEY_UP], _keys[KEY_DOWN], _keys[KEY_LEFT], _keys[KEY_RIGHT]);
}

void GameManager::onTimer() {
    update();
    glutSwapBuffers();
    glutPostRedisplay();// Post re-paint request to activate display()
}

void GameManager::idle() {
    
}

void GameManager::update() {
    std::vector<GameObject*>::iterator iter;
    for ( iter = _game_objects.begin() ; iter != _game_objects.end(); ++iter){
        (*iter)->update(1);
    }
    //fill this in depending on what its supposed to do
}

void GameManager::init() {
    _active_camera = new OrthogonalCamera(0, 1280, 0, 720, -1000, 1000);
    _cameras.push_back(_active_camera);
    _cars.push_back(new Car());
    _game_objects.push_back(new Roadside());
   
    _game_objects.push_back(_cars[0]);
    
    _game_objects.push_back(new Orange());
    _game_objects.push_back(new Orange());
    _game_objects.push_back(new Orange());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    
    
    _game_objects[0]->setPosition(0, 0, 0);
    _game_objects[1]->setPosition(105, 300, 0);
    
    //orange
    _game_objects[2]->setPosition(800, 360, 10);
    _game_objects[3]->setPosition(130, 640, 10);
    _game_objects[4]->setPosition(1050, 100, 11);
    
    //butter
    _game_objects[5]->setPosition(400, 220, 2.5);
    _game_objects[5]->setDirection(45);
    _game_objects[6]->setPosition(200, 450, 2.5);
    _game_objects[6]->setDirection(40);
    _game_objects[7]->setPosition(850, 425, 2.5);
    _game_objects[7]->setDirection(130);
    _game_objects[8]->setPosition(1220, 400, 2.5);
    _game_objects[8]->setDirection(90);
    _game_objects[9]->setPosition(650, 550, 2.5);

    
}

void GameManager::setKeys(bool * keys){
    _keys=keys;
}
