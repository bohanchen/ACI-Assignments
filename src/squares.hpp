//
//  squares.hpp
//  Project1
//
//  Created by Bohan Chen  on 9/26/17.
//
//

#ifndef squares_hpp
#define squares_hpp

#include <ofMain.h>

class Squares{
public:
    ofColor color;
    ofVec2f scale;
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    
    Squares();
    
    Squares(ofColor c,
            ofVec2f s,
            ofVec2f p,
            ofVec2f v,
            ofVec2f a);
    
    void update();
    void draw();
    
};

#endif /* squares_hpp */


