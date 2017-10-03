#pragma once

#include "ofMain.h"
#include "squares.hpp"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSoundPlayer Alex;
    ofSoundPlayer Beats;
    ofSoundPlayer Grenade;
    ofSoundPlayer Unity;
    
    float * fftSmooth;
    int bands;
    
    vector<Squares> squares;
    
    vector<Squares> squares2;
    
    ofColor colors[3];
    
    ofxPanel panel;
    ofxFloatSlider volume;
    ofxFloatSlider speed;
    
    
   
};

