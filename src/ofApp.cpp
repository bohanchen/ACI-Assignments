#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*mondrian Color:
     Background color: 254 246 253
    
     Yellow: 247 197 46
     Blue: 8 26 91
     Red: 183 43 13
     Grey:227 225 228
     
     White: 255 255 255
     Black: 0 0 0  */
    
    Alex.load("Alex.mp3");
    
    fftSmooth = new float [8192];
    for (int i = 0; i<8192; ++i) {
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    
    
    Alex.setLoop(true);
    Alex.setVolume(volume);
    Alex.setSpeed(speed);
    
    Unity.load("Unity.mp3");
    Unity.setVolume(volume);
    Unity.setLoop(true);
    
    Beats.load("sound1.wav");
    //Beats.setSpeed(speed);
    Beats.setVolume(volume);
    
    Grenade.load("Grenade.mp3");
    Grenade.setVolume(volume);
    
    
    //red
    colors[0] = {183, 43, 13};
    //grey
    colors[1] = {227, 225, 228};
    //blue
    colors[2] = {8,26,91};

    //Gui Panel
    panel.setup();
    panel.add(volume.setup("volume", 1.0, 0, 1.0));
    panel.add(speed.setup("speed", 1, -3.0, 3.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(bands);
    
    for (int i = 0; i<bands; i++) {
        fftSmooth[i] *=0.9f;
        
        if (fftSmooth[i]<value[i]){
            fftSmooth[i] = value[i];
        }
        
    }
    
    for (int i = 0; i < squares.size(); ++i) {
        squares[i].scale.x = ofRandom(0.5)+(fftSmooth[i]*5);
        squares[i].scale.y = ofRandom(0.5)+(fftSmooth[i]*5);
    }
    
   
    
    
    for (int i = 0; i<squares2.size(); ++i) {
        squares2[i].scale.x = ofRandom(0.5+(fftSmooth[i]*5));
        squares2[i].scale.y = ofRandom(0.5+(fftSmooth[i]*5));
        squares2[i].update();
    }
    
//    vector<Squares> s2;
//    for (int i = 0; i < squares2.size(); ++i) {
//        squares2[i].update();
//        if(squares2[i].position.length() < 1000) {
//            s2.push_back(squares[i]);
//        }
//    }
//    
//    squares2 = s2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    cout<<"=========="<<endl;
    cout << squares.size() << endl;
    cout<<"=========="<<endl;
    cout << squares2.size() << endl;
   

    
     ofBackground(255);
    //Title
    
    
    //Color of the bar, yellow
    
 
    for (int i = 0; i < bands; ++i) {
        //Horizontal rectangle
        //ofNoFill();
        ofSetColor(247, 197, 46);
        ofDrawRectangle(ofGetWindowWidth(),
                       ofGetWindowHeight()/17,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/6.5,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/3,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/2.5,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/2,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/1.8,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/1.2,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        ofDrawRectangle(ofGetWindowWidth(),
                        ofGetWindowHeight()/1.1,
                        -(fftSmooth[i]*15000),
                        -(fftSmooth[i]*100));
        
        //Vertical rectangle
        
        ofDrawRectangle(ofGetWindowWidth()/14.5,
                        ofGetWindowHeight()/2.56,
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/9,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/5,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/3.5,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.7,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.6,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.3,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.2,
                        ofGetWindowHeight()/2.56,
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.15,
                        ofGetWindowHeight()/2,
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.1,
                        ofGetWindowHeight(),
                        -(fftSmooth[i]*100),
                        -(fftSmooth[i]*15000));
    
    
    //Red rectangle
        ofSetColor(183, 43, 13);
        
        //Medium rectangle

        ofDrawRectangle(ofGetWindowWidth()/3.5,
                        600,
                        -(fftSmooth[i]*400),
                        -(fftSmooth[i]*1000));
        
        ofDrawRectangle(ofGetWindowWidth()/3.5,
                        300,
                        -(fftSmooth[i]*400),
                        -(fftSmooth[i]*1000));
        
        ofDrawRectangle(ofGetWindowWidth()/1.3,
                        200,
                        -(fftSmooth[i]*600),
                        -(fftSmooth[i]*1500));
        
    
    
    
        
    //Blue rectangle
        ofSetColor(8, 26, 91);
        //Medium Square
        ofDrawRectangle(190,
                        260,
                        -(fftSmooth[i]*350),
                        -(fftSmooth[i]*350));
        ofDrawRectangle(190,
                        750,
                        -(fftSmooth[i]*350),
                        -(fftSmooth[i]*350));
        
        ofDrawRectangle(ofGetWindowWidth()/1.3,
                        800,
                        -(fftSmooth[i]*600),
                        -(fftSmooth[i]*1500));
    
    //Grey rectangle
        ofSetColor(227, 225, 228);
        ofDrawRectangle(ofGetWindowWidth()/2,
                        500,
                        -(fftSmooth[i]*400),
                        -(fftSmooth[i]*2000));
        ofDrawRectangle(ofGetWindowWidth()/1.35,
                        750,
                        -(fftSmooth[i]*300),
                        -(fftSmooth[i]*700));
        
        
    
    
    
    }//end of for loop
    
    //Draw square when mouse click: Interaction
    for (int i = 0; i < squares.size(); ++i) {
        squares[i].draw();
    }
    
    for (int i = 0; i < squares2.size(); ++i) {
        ofPushMatrix();
        squares2[i].draw();
        ofPushMatrix();
    }

    
    
    
    
    //Gui
    Alex.setVolume(volume);
    Alex.setSpeed(speed);
    
    Unity.setVolume(volume);
    Unity.setSpeed(speed);
    
    Beats.setVolume(volume);
    
    Grenade.setVolume(volume);
    
    panel.draw();


    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//change speed

    switch (key) {
            
        case 'n':
            ofNoFill();
            break;
            
        case 'f':
            ofFill();
            break;
            
        case 'p':
            Alex.play();
            Unity.stop();
            break;
            
        case 's':
            Alex.stop();
            Unity.play();
            break;
       
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 'u':
            Alex.stop();
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    int ran = floor(ofRandom(3));
    
    //left click
    if (button == 0) {
        Squares s = Squares(ofColor(colors[ran]),
                            ofVec2f(5,5),
                            ofVec2f(x,y),
                            
                            ofVec2f(0,0),
                            ofVec2f(0,0));
        
        
        squares.push_back(s);
        Beats.play();

    }//end of if
    
    
    
    //right click
    if (button == 2){
        
        for (int i = 0; i<100; ++i) {
            Squares s = Squares(ofColor(colors[ran]),
                                ofVec2f(0.5,0.5),
                                ofVec2f(x,y),
                                
                                ofVec2f(ofRandom(-10,10),
                                        ofRandom(-10,10)),
                                
                                ofVec2f(ofRandom(-10,10),
                                        ofRandom(-10,10)));
            
            squares2.push_back(s);
            Grenade.play();
            
        }//end of for loop
    }//end of if
    
}
    
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
