//
//  squares.cpp
//  Project1
//
//  Created by Bohan Chen  on 9/26/17.
//
//

#include "squares.hpp"

Squares::Squares(){
    Squares(ofColor::white,
            ofVec2f(1,1),
            ofVec2f(ofGetWidth()/2, ofGetHeight()/2),
            ofVec2f(0,0),
            ofVec2f(0,0)
            );
}

Squares::Squares(ofColor c,
                 ofVec2f s,
                 ofVec2f p,
                 ofVec2f v,
                 ofVec2f a){
    
    color = c;
    scale = s;
    position = p;
    velocity = v;
    acceleration = a;

    
}


void Squares::update(){
    velocity += acceleration;
    velocity.limit(10);
    position+= velocity;
    
}

void Squares::draw(){
    ofPushMatrix();
    ofTranslate(position.x, position.y);
    ofScale(scale.x, scale.y);
    ofSetColor(color);
    ofDrawRectangle(0,0, 50, 50);
    ofPopMatrix();
}
