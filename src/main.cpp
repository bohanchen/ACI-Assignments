#include "ofMain.h"
#include "ofApp.h"
/*Created by Bohan Chen 
 Date: Oct 2 2017
 
 This is an interactive programming work developed in openframework, which is trying to depict
 the rhyme of music based on Piet Mondrian's work.
 It is aiming to create a chaos environment in the end that is descriping the situation in New
 York City. 
 
 Music Credits: Guitar On Fire Ð Alex Fox
                Unity - TheFatRat
 */

//========================================================================
int main( ){
	ofSetupOpenGL(1024,1024,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
