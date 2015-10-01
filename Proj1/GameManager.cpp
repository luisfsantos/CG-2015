//
//  GameManager.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "GameManager.hpp"


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
    //basicamente isto so que com iterador
    glutSwapBuffers();
    glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h) {
    _active_camera->update(w,h);
}

void GameManager::keyPressed() {
    //fill this in depending on what its supposed to do
    //glPolygonMODE()
}

void GameManager::onTimer() {
    //fill this in depending on what its supposed to do
}

void GameManager::idle() {
    //fill this in depending on what its supposed to do
}

void GameManager::update() {
    //fill this in depending on what its supposed to do
}

void GameManager::init() {
    _active_camera = new OrthogonalCamera(0, 200, 0, 200, -40., 40.);
    _cameras.push_back(_active_camera);
    _game_objects.push_back(new Car());
    _game_objects[0]->setPosition(50, 50, 0);
}
