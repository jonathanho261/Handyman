//
//  ground.h
//  Handyman
//
//  Created by Jonathan Ho on 4/26/19.
//

#pragma once
#include "ofMain.h"

class Ground {
public:
    Ground();
    
    void setup(int x, int y);
    void update();
    void draw();
    
private:
    int initialX, initialY, xPosition;
    ofImage ground;
    int moveSpeed;
};
