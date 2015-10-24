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
double track1 [219][3] = {
    {1.018450184501845, 0.7164821648216483, 0},
    {1.003690036900369, 0.7066420664206643, 0},
    {0.9856498564985651, 0.6918819188191883, 0},
    {0.969249692496925, 0.6804018040180402, 0},
    {0.9479294792947931, 0.6623616236162362, 0},
    {0.9249692496924969, 0.6459614596145962, 0},
    {0.905289052890529, 0.6312013120131201, 0},
    {0.8806888068880689, 0.6115211152111522, 0},
    {0.8577285772857729, 0.5951209512095121, 0},
    {0.842968429684297, 0.5836408364083641, 0},
    {0.8232882328823289, 0.5721607216072162, 0},
    {0.8118081180811809, 0.5656006560065601, 0},
    {0.7150471504715048, 0.49179991799918, 0},
    {0.6937269372693727, 0.47539975399754, 0},
    {0.6740467404674048, 0.46227962279622803, 0},
    {0.6543665436654368, 0.445879458794588, 0},
    {0.6346863468634687, 0.429479294792948, 0},
    {0.6133661336613367, 0.413079130791308, 0},
    {0.5920459204592047, 0.395038950389504, 0},
    {0.5707257072570726, 0.38027880278802795, 0},
    {0.5395653956539566, 0.3589585895858959, 0},
    {0.5248052480524806, 0.3474784747847479, 0},
    {0.5002050020500206, 0.3294382943829439, 0},
    {0.48216482164821645, 0.3195981959819598, 0},
    {0.4674046740467405, 0.30975809758097583, 0},
    {0.45592455924559244, 0.2966379663796638, 0},
    {0.43624436244362447, 0.2851578515785158, 0},
    {0.40180401804018046, 0.26383763837638374, 0},
    {0.3772037720377204, 0.25563755637556373, 0},
    {0.34440344403444034, 0.2425174251742518, 0},
    {0.3050430504305043, 0.23431734317343178, 0},
    {0.27060270602706027, 0.23431734317343178, 0},
    {0.2230422304223042, 0.2425174251742518, 0},
    {0.19844198441984418, 0.2507175071750718, 0},
    {0.16892168921689216, 0.27203772037720375, 0},
    {0.1459614596145961, 0.29171791717917184, 0},
    {0.12956129561295615, 0.3294382943829439, 0},
    {0.11972119721197212, 0.36879868798687987, 0},
    {0.1098810988109881, 0.41635916359163594, 0},
    {0.1033210332103321, 0.463919639196392, 0},
    {0.10496104961049611, 0.498359983599836, 0},
    {0.1016810168101681, 0.5442804428044281, 0},
    {0.0967609676096761, 0.5803608036080361, 0},
    {0.0967609676096761, 0.6148011480114801, 0},
    {0.09840098400984008, 0.6492414924149241, 0},
    {0.10496104961049611, 0.6886018860188603, 0},
    {0.11808118081180811, 0.7230422304223043, 0},
    {0.13940139401394014, 0.7460024600246002, 0},
    {0.16236162361623613, 0.7689626896268964, 0},
    {0.18204182041820416, 0.7820828208282083, 0},
    {0.2099220992209922, 0.7968429684296844, 0},
    {0.23944239442394422, 0.8066830668306684, 0},
    {0.27224272242722425, 0.8148831488314884, 0},
    {0.3132431324313243, 0.8099630996309963, 0},
    {0.34932349323493234, 0.8001230012300123, 0},
    {0.37392373923739236, 0.7886428864288644, 0},
    {0.3886838868388684, 0.7820828208282083, 0},
    {0.4083640836408364, 0.7706027060270604, 0},
    {0.4264042640426405, 0.7624026240262403, 0},
    {0.4428044280442805, 0.7525625256252564, 0},
    {0.45592455924559244, 0.7476424764247643, 0},
    {0.4772447724477245, 0.7410824108241083, 0},
    {0.4936449364493645, 0.7312423124231243, 0},
    {0.5051250512505125, 0.7263222632226323, 0},
    {0.5264452644526446, 0.7148421484214843, 0},
    {0.5444854448544486, 0.7082820828208283, 0},
    {0.5658056580565807, 0.7000820008200083, 0},
    {0.5904059040590407, 0.6836818368183682, 0},
    {0.6117261172611727, 0.6754817548175482, 0},
    {0.6363263632636327, 0.6656416564165641, 0},
    {0.6560065600656008, 0.6541615416154163, 0},
    {0.6740467404674048, 0.6443214432144322, 0},
    {0.6953669536695368, 0.6312013120131201, 0},
    {0.7117671176711768, 0.6213612136121363, 0},
    {0.8249282492824929, 0.5606806068060681, 0},
    {0.8478884788847889, 0.5524805248052481, 0},
    {0.8642886428864289, 0.5410004100041002, 0},
    {0.885608856088561, 0.531160311603116, 0},
    {0.9118491184911851, 0.5196801968019681, 0},
    {0.938089380893809, 0.504920049200492, 0},
    {0.9626896268962691, 0.49507995079950806, 0},
    {0.970889708897089, 0.48851988519885203, 0},
    {0.990569905699057, 0.47867978679786805, 0},
    {1.003690036900369, 0.47047970479704804, 0},
    {1.026650266502665, 0.46063960639606405, 0},
    {1.049610496104961, 0.455719557195572, 0},
    {1.0791307913079131, 0.457359573595736, 0},
    {1.1086510865108652, 0.46883968839688406, 0},
    {1.1234112341123412, 0.490159901599016, 0},
    {1.1414514145141452, 0.5098400984009841, 0},
    {1.151291512915129, 0.53280032800328, 0},
    {1.1562115621156213, 0.5639606396063961, 0},
    {1.1578515785157852, 0.5918409184091842, 0},
    {1.1578515785157852, 0.6180811808118082, 0},
    {1.151291512915129, 0.6508815088150882, 0},
    {1.1447314473144732, 0.6771217712177122, 0},
    {1.134891348913489, 0.7000820008200083, 0},
    {1.1250512505125052, 0.7197621976219764, 0},
    {1.1119311193111932, 0.7361623616236164, 0},
    {1.0971709717097171, 0.7460024600246002, 0},
    {1.069290692906929, 0.7492824928249283, 0},
    {1.054530545305453, 0.7427224272242723, 0},
    {1.034850348503485, 0.7230422304223043, 0},
    {0.9626896268962691, 0.8066830668306684, 0},
    {0.9512095120951211, 0.7984829848298484, 0},
    {0.9249692496924969, 0.7804428044280444, 0},
    {0.906929069290693, 0.7673226732267323, 0},
    {0.8921689216892169, 0.7558425584255843, 0},
    {0.879048790487905, 0.7443624436244363, 0},
    {0.8642886428864289, 0.7312423124231243, 0},
    {0.8478884788847889, 0.7214022140221403, 0},
    {0.8314883148831489, 0.7132021320213202, 0},
    {0.8134481344813449, 0.7017220172201722, 0},
    {0.7921279212792128, 0.6902419024190243, 0},
    {0.7757277572775728, 0.6754817548175482, 0},
    {0.7560475604756048, 0.6640016400164002, 0},
    {0.7396473964739648, 0.6508815088150882, 0},
    {0.7232472324723248, 0.6394013940139402, 0},
    {0.7117671176711768, 0.6344813448134482, 0},
    {0.7002870028700288, 0.6262812628126282, 0},
    {0.6018860188601887, 0.5475604756047561, 0},
    {0.5871258712587126, 0.5393603936039362, 0},
    {0.5690856908569086, 0.5295202952029521, 0},
    {0.5444854448544486, 0.5098400984009841, 0},
    {0.5248052480524806, 0.49179991799918, 0},
    {0.5051250512505125, 0.481959819598196, 0},
    {0.4772447724477245, 0.45899958999589996, 0},
    {0.4592045920459205, 0.44259942599425994, 0},
    {0.43624436244362447, 0.43275932759327596, 0},
    {0.4132841328413284, 0.419639196391964, 0},
    {0.39196391963919636, 0.395038950389504, 0},
    {0.36900369003690037, 0.3917589175891759, 0},
    {0.3591635916359164, 0.386838868388684, 0},
    {0.33128331283312834, 0.3655186551865519, 0},
    {0.3083230832308323, 0.36223862238622395, 0},
    {0.2935629356293563, 0.36223862238622395, 0},
    {0.27224272242722425, 0.36879868798687987, 0},
    {0.25912259122591225, 0.38847888478884796, 0},
    {0.24600246002460024, 0.411439114391144, 0},
    {0.24108241082410825, 0.43275932759327596, 0},
    {0.23780237802378024, 0.465559655596556, 0},
    {0.23452234522345222, 0.5016400164001641, 0},
    {0.2312423124231242, 0.5213202132021321, 0},
    {0.22632226322263221, 0.5426404264042641, 0},
    {0.2230422304223042, 0.5623206232062321, 0},
    {0.2230422304223042, 0.5852808528085282, 0},
    {0.22140221402214022, 0.5967609676096761, 0},
    {0.22140221402214022, 0.6164411644116441, 0},
    {0.22468224682246823, 0.6361213612136122, 0},
    {0.22960229602296023, 0.6574415744157442, 0},
    {0.23944239442394422, 0.6754817548175482, 0},
    {0.25420254202542025, 0.6869618696186963, 0},
    {0.27224272242722425, 0.6968019680196802, 0},
    {0.2968429684296843, 0.6968019680196802, 0},
    {0.3165231652316523, 0.6968019680196802, 0},
    {0.35096350963509637, 0.6820418204182043, 0},
    {0.37884378843788435, 0.6672816728167282, 0},
    {0.40016400164001636, 0.6574415744157442, 0},
    {0.41820418204182047, 0.6459614596145962, 0},
    {0.4395243952439524, 0.6361213612136122, 0},
    {0.4575645756457564, 0.6246412464124642, 0},
    {0.4772447724477245, 0.6115211152111522, 0},
    {0.5051250512505125, 0.5984009840098401, 0},
    {0.5280852808528086, 0.5852808528085282, 0},
    {0.5477654776547766, 0.5754407544075442, 0},
    {0.5674456744567447, 0.5656006560065601, 0},
    {0.5854858548585486, 0.5590405904059041, 0},
    {0.6133661336613367, 0.5475604756047561, 0},
    {0.7265272652726528, 0.48851988519885203, 0},
    {0.7396473964739648, 0.47867978679786805, 0},
    {0.7527675276752769, 0.47047970479704804, 0},
    {0.7708077080770809, 0.46063960639606405, 0},
    {0.7872078720787209, 0.45243952439524404, 0},
    {0.8052480524805249, 0.44095940959409596, 0},
    {0.8298482984829849, 0.43275932759327596, 0},
    {0.8478884788847889, 0.42455924559245595, 0},
    {0.869208692086921, 0.413079130791308, 0},
    {0.8921689216892169, 0.4015990159901599, 0},
    {0.916769167691677, 0.39011890118901194, 0},
    {0.934809348093481, 0.38027880278802795, 0},
    {0.9659696596965971, 0.36223862238622395, 0},
    {0.9938499384993852, 0.3507585075850759, 0},
    {1.015170151701517, 0.34419844198441985, 0},
    {1.052890528905289, 0.3376383763837639, 0},
    {1.0774907749077491, 0.3376383763837639, 0},
    {1.098810988109881, 0.3392783927839279, 0},
    {1.133251332513325, 0.34583845838458394, 0},
    {1.1644116441164412, 0.3655186551865519, 0},
    {1.1808118081180812, 0.3769987699876999, 0},
    {1.2004920049200491, 0.403239032390324, 0},
    {1.2218122181221813, 0.43275932759327596, 0},
    {1.2316523165231652, 0.45243952439524404, 0},
    {1.2447724477244773, 0.481959819598196, 0},
    {1.2496924969249692, 0.5131201312013121, 0},
    {1.2513325133251332, 0.5410004100041002, 0},
    {1.2562525625256253, 0.5820008200082001, 0},
    {1.2546125461254614, 0.6230012300123002, 0},
    {1.2431324313243133, 0.6640016400164002, 0},
    {1.2250922509225093, 0.7082820828208283, 0},
    {1.2103321033210332, 0.7427224272242723, 0},
    {1.1972119721197212, 0.7755227552275523, 0},
    {1.1758917589175892, 0.8017630176301764, 0},
    {1.152931529315293, 0.8280032800328004, 0},
    {1.1250512505125052, 0.8460434604346044, 0},
    {1.0906109061090612, 0.8542435424354244, 0},
    {1.062730627306273, 0.8591635916359164, 0},
    {1.029930299302993, 0.8509635096350965, 0},
    {1.002050020500205, 0.8312833128331284, 0},
    {0.975809758097581, 0.8148831488314884, 0},
    {0.2066, 0.5607, 0},
    {0.1836, 0.5607, 0},
    {0.1606, 0.5607, 0},
    {0.1376, 0.5607, 0},
    {0.1146, 0.5607, 0},
    {0.2060, 0.5780, 0},
    {0.1830, 0.5780, 0},
    {0.1600, 0.5780, 0},
    {0.1370, 0.5780, 0},
    {0.1140, 0.5780, 0},
    
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
    
    if (_cars[0]->isIntersecting(*_game_objects[2])) {
        _cars[0]->setPosition(105, 300, 0);
        _cars[0]->setAbsSpeed(0);
        _cars[0]->setDirection(90);
    }
}

void GameManager::init() {
    
    _active_camera = new OrthogonalCamera(0, 1280, 0, 720, -1000, 1000);
    _cameras.push_back(_active_camera);
    _cars.push_back(new Car());
    _game_objects.push_back(new Roadside(track1, 219));
   
    _game_objects.push_back(_cars[0]);
    
    _game_objects.push_back(new Orange(30));
    _game_objects.push_back(new Orange(30));
    _game_objects.push_back(new Orange(55));
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    _game_objects.push_back(new Butter());
    
    _cars[0]->setBoundingBox(6, 3);
    
    _cameras[0]->setPosition(1280/2, -500, 800);
    _game_objects[0]->setPosition(-60, -200, 0);
    _game_objects[1]->setPosition(105, 300, 0);
    
    //orange
    _game_objects[2]->setPosition(800, 360, 0);
    _game_objects[3]->setPosition(130, 640, 0);
    _game_objects[4]->setPosition(1050, 100, 0);
	_game_objects[3]->setSpeed(1, -0.5, 0);
    _game_objects[4]->setSpeed(0, 1, 0);
    
    //butter
    _game_objects[5]->setPosition(400, 220, 0);
    _game_objects[5]->setDirection(45);
    _game_objects[6]->setPosition(200, 450, 0);
    _game_objects[6]->setDirection(40);
    _game_objects[7]->setPosition(850, 425, 0);
    _game_objects[7]->setDirection(130);
    _game_objects[8]->setPosition(1220, 400, 0);
    _game_objects[8]->setDirection(90);
    _game_objects[9]->setPosition(650, 550, 0);

    
}

void GameManager::setKeys(bool * keys){
    _keys=keys;
}


