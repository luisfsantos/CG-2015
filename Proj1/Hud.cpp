//
//  Hud.cpp
//  Proj1
//
//  Created by Luis Santos on 22/11/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "Hud.hpp"
#if defined(__APPLE__)|| defined(MACOSX)
#define PAUSED "/Users/luissantos/Documents/IST/3ano/CG/Proj1/Proj1/Paused1.jpg"
#define GAMEOVER "/Users/luissantos/Documents/IST/3ano/CG/Proj1/Proj1/Gameover.jpg"
#else
#define PAUSED "..\\Proj1\\Paused1.jpg"
#define GAMEOVER "..\\Proj1\\Gameover.jpg"
#endif

#include "stb_image.h"


Hud::Hud(double lives){
    int imagex = 0, imagey = 0, imagen = 0;
    unsigned char *data = stbi_load(PAUSED, &imagex, &imagey, &imagen, 0);
    _lives = lives;
    create_cars();
    
    
    glGenTextures( 2, &_paused );
    glBindTexture( GL_TEXTURE_2D, _paused );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, imagex, imagey, GL_RGB, GL_UNSIGNED_BYTE, data );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    
    free( data );
    data = stbi_load(GAMEOVER, &imagex, &imagey, &imagen, 0);
    glGenTextures(3, &_game_over );
    glBindTexture( GL_TEXTURE_2D, _game_over );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, imagex, imagey, GL_RGB, GL_UNSIGNED_BYTE, data );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    
    free( data );
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
    if (_lives > 0) {
        _cars.pop_back();
        _lives -= 1;
    }
    
}

void Hud::create_cars() {
    for (int i = 0; i<_lives; i++) {
        _cars.push_back(new Car());
        _cars[i]->setPosition((1260-i*25), 700, 4);
    }
}

void Hud::pause() {
    int height = 720, width = 1280;
    int imageH = 100, imageW = 512;
    glPushMatrix();
    glBindTexture( GL_TEXTURE_2D, _paused );
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.6);
    glVertex3f((width-imageW)/2, (height-imageH)/2, 190);
    glTexCoord2f(1.0, 0.6);
    glVertex3f((width+imageW)/2, (height-imageH)/2, 190);
    glTexCoord2f(1.0, 0.35);
    glVertex3f((width+imageW)/2, (height+imageH)/2, 190);
    glTexCoord2f(0.0, 0.35);
    glVertex3f((width-imageW)/2, (height+imageH)/2, 190);
    glEnd();
    glPopMatrix();
}

void Hud::gameover() {
    int height = 720, width = 1280;
    int imageH = 512, imageW = 512;
    glPushMatrix();
    glBindTexture( GL_TEXTURE_2D, _game_over);
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 1.0);
    glVertex3f((width-imageW)/2, (height-imageH)/2, 190);
    glTexCoord2f(1.0, 1.0);
    glVertex3f((width+imageW)/2, (height-imageH)/2, 190);
    glTexCoord2f(1.0, 0.0);
    glVertex3f((width+imageW)/2, (height+imageH)/2, 190);
    glTexCoord2f(0.0, 0.0);
    glVertex3f((width-imageW)/2, (height+imageH)/2, 190);
    glEnd();
    glPopMatrix();
}










