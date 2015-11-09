//
//  GameManager.cpp
//  Proj1
//
//  Created by Luis Santos on 27/09/15.
//  Copyright © 2015 Luis Santos. All rights reserved.
//

#include "GameManager.hpp"
#define CANDLES 6
int oldTime = 0;
bool day = true;
double orangeVel = 1.4;
GLenum polygonMode = GL_FILL;
GLenum shadeMode = GL_SMOOTH;
bool Candles = true;
bool CalculatingLights = true;
Vector3 ambient_day(0.5, 0.5, 0.5);
Vector3 ambient_night(0.4, 0.4, 0.4);
Vector3 d_day(1.0, 1.0, 1.0);

double track1 [209][3] = {
	{1018.45, 716.482, 0},
	{1003.69, 706.642, 0},
	{985.65, 691.882, 0},
	{969.25, 680.402, 0},
	{947.929, 662.362, 0},
	{924.969, 645.961, 0},
	{905.289, 631.201, 0},
	{880.689, 611.521, 0},
	{857.729, 595.121, 0},
	{842.968, 583.641, 0},
	{823.288, 572.161, 0},
	{811.808, 565.601, 0},
	{715.047, 491.8, 0},
	{693.727, 475.4, 0},
	{674.047, 462.28, 0},
	{654.367, 445.879, 0},
	{634.686, 429.479, 0},
	{613.366, 413.079, 0},
	{592.046, 395.039, 0},
	{570.726, 380.279, 0},
	{539.565, 358.959, 0},
	{524.805, 347.478, 0},
	{500.205, 329.438, 0},
	{482.165, 319.598, 0},
	{467.405, 309.758, 0},
	{455.925, 296.638, 0},
	{436.244, 285.158, 0},
	{401.804, 263.838, 0},
	{377.204, 255.638, 0},
	{344.403, 242.517, 0},
	{305.043, 234.317, 0},
	{270.603, 234.317, 0},
	{223.042, 242.517, 0},
	{198.442, 250.718, 0},
	{168.922, 272.038, 0},
	{145.961, 291.718, 0},
	{129.561, 329.438, 0},
	{119.721, 368.799, 0},
	{109.881, 416.359, 0},
	{103.321, 463.92, 0},
	{104.961, 498.36, 0},
	{101.681, 544.28, 0},
	{96.761, 580.361, 0},
	{96.761, 614.801, 0},
	{98.401, 649.241, 0},
	{104.961, 688.602, 0},
	{118.081, 723.042, 0},
	{139.401, 746.002, 0},
	{162.362, 768.963, 0},
	{182.042, 782.083, 0},
	{209.922, 796.843, 0},
	{239.442, 806.683, 0},
	{272.243, 814.883, 0},
	{313.243, 809.963, 0},
	{349.323, 800.123, 0},
	{373.924, 788.643, 0},
	{388.684, 782.083, 0},
	{408.364, 770.603, 0},
	{426.404, 762.403, 0},
	{442.804, 752.563, 0},
	{455.925, 747.642, 0},
	{477.245, 741.082, 0},
	{493.645, 731.242, 0},
	{505.125, 726.322, 0},
	{526.445, 714.842, 0},
	{544.485, 708.282, 0},
	{565.806, 700.082, 0},
	{590.406, 683.682, 0},
	{611.726, 675.482, 0},
	{636.326, 665.642, 0},
	{656.007, 654.162, 0},
	{674.047, 644.321, 0},
	{695.367, 631.201, 0},
	{711.767, 621.361, 0},
	{824.928, 560.681, 0},
	{847.888, 552.481, 0},
	{864.289, 541, 0},
	{885.609, 531.16, 0},
	{911.849, 519.68, 0},
	{938.089, 504.92, 0},
	{962.69, 495.08, 0},
	{970.89, 488.52, 0},
	{990.57, 478.68, 0},
	{1003.69, 470.48, 0},
	{1026.65, 460.64, 0},
	{1049.61, 455.72, 0},
	{1079.13, 457.36, 0},
	{1108.65, 468.84, 0},
	{1123.41, 490.16, 0},
	{1141.45, 509.84, 0},
	{1151.29, 532.8, 0},
	{1156.21, 563.961, 0},
	{1157.85, 591.841, 0},
	{1157.85, 618.081, 0},
	{1151.29, 650.882, 0},
	{1144.73, 677.122, 0},
	{1134.89, 700.082, 0},
	{1125.05, 719.762, 0},
	{1111.93, 736.162, 0},
	{1097.17, 746.002, 0},
	{1069.29, 749.282, 0},
	{1054.53, 742.722, 0},
	{1034.85, 723.042, 0},
	{962.69, 806.683, 0},
	{951.21, 798.483, 0},
	{924.969, 780.443, 0},
	{906.929, 767.323, 0},
	{892.169, 755.843, 0},
	{879.049, 744.362, 0},
	{864.289, 731.242, 0},
	{847.888, 721.402, 0},
	{831.488, 713.202, 0},
	{813.448, 701.722, 0},
	{792.128, 690.242, 0},
	{775.728, 675.482, 0},
	{756.048, 664.002, 0},
	{739.647, 650.882, 0},
	{723.247, 639.401, 0},
	{711.767, 634.481, 0},
	{700.287, 626.281, 0},
	{601.886, 547.56, 0},
	{587.126, 539.36, 0},
	{569.086, 529.52, 0},
	{544.485, 509.84, 0},
	{524.805, 491.8, 0},
	{505.125, 481.96, 0},
	{477.245, 459, 0},
	{459.205, 442.599, 0},
	{436.244, 432.759, 0},
	{413.284, 419.639, 0},
	{391.964, 395.039, 0},
	{369.004, 391.759, 0},
	{359.164, 386.839, 0},
	{331.283, 365.519, 0},
	{308.323, 362.239, 0},
	{293.563, 362.239, 0},
	{272.243, 368.799, 0},
	{259.123, 388.479, 0},
	{246.002, 411.439, 0},
	{241.082, 432.759, 0},
	{237.802, 465.56, 0},
	{234.522, 501.64, 0},
	{231.242, 521.32, 0},
	{226.322, 542.64, 0},
	{223.042, 562.321, 0},
	{223.042, 585.281, 0},
	{221.402, 596.761, 0},
	{221.402, 616.441, 0},
	{224.682, 636.121, 0},
	{229.602, 657.442, 0},
	{239.442, 675.482, 0},
	{254.203, 686.962, 0},
	{272.243, 696.802, 0},
	{296.843, 696.802, 0},
	{316.523, 696.802, 0},
	{350.964, 682.042, 0},
	{378.844, 667.282, 0},
	{400.164, 657.442, 0},
	{418.204, 645.961, 0},
	{439.524, 636.121, 0},
	{457.565, 624.641, 0},
	{477.245, 611.521, 0},
	{505.125, 598.401, 0},
	{528.085, 585.281, 0},
	{547.765, 575.441, 0},
	{567.446, 565.601, 0},
	{585.486, 559.041, 0},
	{613.366, 547.56, 0},
	{726.527, 488.52, 0},
	{739.647, 478.68, 0},
	{752.768, 470.48, 0},
	{770.808, 460.64, 0},
	{787.208, 452.44, 0},
	{805.248, 440.959, 0},
	{829.848, 432.759, 0},
	{847.888, 424.559, 0},
	{869.209, 413.079, 0},
	{892.169, 401.599, 0},
	{916.769, 390.119, 0},
	{934.809, 380.279, 0},
	{965.97, 362.239, 0},
	{993.85, 350.759, 0},
	{1015.17, 344.198, 0},
	{1052.89, 337.638, 0},
	{1077.49, 337.638, 0},
	{1098.81, 339.278, 0},
	{1133.25, 345.838, 0},
	{1164.41, 365.519, 0},
	{1180.81, 376.999, 0},
	{1200.49, 403.239, 0},
	{1221.81, 432.759, 0},
	{1231.65, 452.44, 0},
	{1244.77, 481.96, 0},
	{1249.69, 513.12, 0},
	{1251.33, 541, 0},
	{1256.25, 582.001, 0},
	{1254.61, 623.001, 0},
	{1243.13, 664.002, 0},
	{1225.09, 708.282, 0},
	{1210.33, 742.722, 0},
	{1197.21, 775.523, 0},
	{1175.89, 801.763, 0},
	{1152.93, 828.003, 0},
	{1125.05, 846.043, 0},
	{1090.61, 854.244, 0},
	{1062.73, 859.164, 0},
	{1029.93, 850.964, 0},
	{1002.05, 831.283, 0},
	{975.81, 814.883, 0}/*,
	{206.6, 560.7, 0},
	{183.6, 560.7, 0},
	{160.6, 560.7, 0},
	{137.6, 560.7, 0},
	{114.6, 560.7, 0},
	{206, 578, 0},
	{183, 578, 0},
	{160, 578, 0},
	{137, 578, 0},
	{114, 578, 0}*/
};


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

void GameManager::reshape() {
	_active_camera->update();
}

void GameManager::keyPressed(bool *keys) {
	_keys = keys;
	if (_keys[KEY_A]) {
		(polygonMode == GL_LINE) ? glPolygonMode(GL_FRONT_AND_BACK, polygonMode = GL_FILL) : glPolygonMode(GL_FRONT_AND_BACK, polygonMode =GL_LINE);
    }
    if (_keys[KEY_C]) {
        if (Candles) {
            Candles = false;
        } else {
            Candles = true;
        }
        for (int i= 1; i <= CANDLES; i++) {
            _light_sources[i]->setState(Candles);
        }
    }
    if (_keys[KEY_G]) {
        (shadeMode == GL_SMOOTH) ? glShadeModel(GL_FLAT) : glShadeModel(GL_SMOOTH);
        (shadeMode == GL_SMOOTH) ? shadeMode = GL_FLAT : shadeMode = GL_SMOOTH;
    }
    if (_keys[KEY_L]) {
        if (CalculatingLights == true) {
            glDisable(GL_LIGHTING);
            CalculatingLights = false;
        } else {
            glEnable(GL_LIGHTING);
            CalculatingLights = true;
        }
    }
    if (_keys[KEY_N]) {
        if (day == true) {
            _light_sources[0]->setAmbient(ambient_night);
            _light_sources[0]->setDiffuse(ambient_night);
            _light_sources[0]->setSpecular(ambient_night);
            _light_sources[0]->draw();
            day = false;
        } else {
            _light_sources[0]->setAmbient(ambient_day);
            _light_sources[0]->setDiffuse(d_day);
            _light_sources[0]->setSpecular(d_day);
            _light_sources[0]->draw();
            day = true;
        }
    }
	if (_keys[KEY_1]) {
		_active_camera = _cameras[0];
		_active_camera->update();
	}
	if (_keys[KEY_2]){
		_active_camera=_cameras[1];
		_active_camera->update();
	}
	if (_keys[KEY_3]){
		_active_camera=_cameras[2];
		_active_camera->update();
	}
	_cars[0]->setMovement(_keys[KEY_UP], _keys[KEY_DOWN], _keys[KEY_LEFT], _keys[KEY_RIGHT]);
}

void GameManager::onTimer() {
	update();
	glutSwapBuffers();
	glutPostRedisplay();// Post re-paint request to activate display()
}

void GameManager::idle() {
    double timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
    double deltaTime = timeSinceStart - oldTime;
    
    if (deltaTime > 10000) {
        orangeVel += 0.2;
        /*
        _game_objects[2]->setAbsSpeed(orangeVel);
        _game_objects[3]->setAbsSpeed(orangeVel);
        _game_objects[4]->setAbsSpeed(orangeVel);
         */
        oldTime = timeSinceStart;
    }
}

void GameManager::update() {
	std::vector<GameObject*>::iterator iter;
	std::vector<Cherrio*>::iterator iter2;
	std::vector<GameObject*>::iterator iter3;
	std::vector<Camera*>::iterator iter4;
	for ( iter = _game_objects.begin() ; iter != _game_objects.end(); ++iter){
		(*iter)->update(1);
	}

	for ( iter = _game_objects.begin() + 1; iter != _game_objects.end(); ++iter){
		if ((_cars[0])->isIntersecting(**iter)) {
			(*iter)->collide(_cars[0]);
		}
	}
   for ( iter2 = _road->_cherrios.begin(); iter2 !=  _road->_cherrios.end(); ++iter2){
		if ((_cars[0])->isIntersecting(**iter2)) {
			(*iter2)->collide(_cars[0]);
		}
	}
	for( iter3 = _game_objects.begin() + 2; iter3 !=  _game_objects.begin() + 5; ++iter3) {
		if(_road->isIntersecting(**iter3)){
			(*iter3)->reset(orangeVel);
		};
	}
	_cameras[2]->setEye(_cars[0]->getPosition()->getX(), _cars[0]->getPosition()->getY(), _cars[0]->getPosition()->getZ());
	_cameras[2]->setPosition(_cars[0]->getPosition()->getX() - 100*cos(_cars[0]->getDirection()*M_PI/180), _cars[0]->getPosition()->getY() - 100*sin(_cars[0]->getDirection()*M_PI/180), _cars[0]->getPosition()->getZ() + 80);
	_active_camera->update();
}

void GameManager::init() {
    glShadeModel(GL_SMOOTH);
	_active_camera = new OrthogonalCamera(0, 1280, 0, 720, -1000, 1000);
	_cameras.push_back(_active_camera);
	_cameras.push_back(new PerspectiveCamera(70, 16 / 9, 100, 2000, 1280 / 2 , 720 / 2, 0, 0, 1, 0));
	_cameras[1]->setPosition(1280/2, -200,1000);
	
	_cars.push_back(new Car());
	
	_road = new Roadside(track1, 209, -60, -200, 0);
	_game_objects.push_back(_cars[0]);
	_game_objects.push_back(_road);
	_game_objects.push_back(new Orange(800, 360, 0, 30));
	_game_objects.push_back(new Orange(130, 640, 0, 30));
	_game_objects.push_back(new Orange(1050, 100, 0, 55));
	_game_objects.push_back(new Butter());
	_game_objects.push_back(new Butter());
	_game_objects.push_back(new Butter());
	_game_objects.push_back(new Butter());
	_game_objects.push_back(new Butter());
	
	
	
	//non dynamic
	_game_objects[0]->setPosition(105, 300, 0);
	_game_objects[2]->setSpeed(-1, 1, 0);
	_game_objects[3]->setSpeed(1, -1, 0);
	_game_objects[4]->setSpeed(1, 1, 0);
    
  
	/*
	 Dynamic Objects
	 */
	//butter
	_game_objects[5]->setPosition(400, 220, 0);
	_game_objects[5]->setRotation(45);
	_game_objects[6]->setPosition(200, 450, 0);
	_game_objects[6]->setRotation(40);
	_game_objects[7]->setPosition(850, 425, 0);
	_game_objects[7]->setRotation(130);
	_game_objects[8]->setPosition(1220, 400, 0);
	_game_objects[8]->setRotation(90);
	_game_objects[9]->setPosition(650, 550, 0);

	_cameras.push_back(new PerspectiveCamera(75, 1280/720, 10, 2000,
			_cars[0]->getPosition()->getX(), _cars[0]->getPosition()->getY(), 0, 0, 0, 1));
    /*
     LIGHT SOURCES INITIALIZATIONS
     */
    //AMBIENT
    Vector3 ambient_direction (0, 0, -1);
    Vector3 blue(0, 0, 1.0);
    Vector3 red(1.0, 0, 0);
    Vector3 green(0, 1.0, 0);
    Vector3 candle_light(1, 0.58, 0.16);
    _light_sources.push_back(new LightSource(GL_LIGHT0));
    _light_sources[0]->setDirection(ambient_direction);
    _light_sources[0]->setAmbient(ambient_day);
    _light_sources[0]->setPosition(1280/2, 720/2, 1000, 0.0);
    _light_sources[0]->draw();
    //CANDLES
    _light_sources.push_back(new LightSource(GL_LIGHT1));
    _light_sources.push_back(new LightSource(GL_LIGHT2));
    _light_sources.push_back(new LightSource(GL_LIGHT3));
    _light_sources.push_back(new LightSource(GL_LIGHT4));
    _light_sources.push_back(new LightSource(GL_LIGHT5));
    _light_sources.push_back(new LightSource(GL_LIGHT6));
    _game_objects.push_back(new Candle(250, 200, 0, _light_sources[1], candle_light));
    _game_objects.push_back(new Candle(200, 650, 0, _light_sources[2], candle_light));
    _game_objects.push_back(new Candle(1000, 300, 0, _light_sources[3], candle_light));
    _game_objects.push_back(new Candle(1000, 500, 0, _light_sources[4], candle_light));
    _game_objects.push_back(new Candle(650, 250, 0, _light_sources[5], candle_light));
    _game_objects.push_back(new Candle(330, 430, 0, _light_sources[6], candle_light));
    
    
}

void GameManager::setKeys(bool * keys){
	_keys=keys;
}


