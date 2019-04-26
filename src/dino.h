//
//  dino.h
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#pragma once
#include "ofMain.h"

class Dinosaur {
public:
    Dinosaur();
    
    void setup();
    void update();
    void draw();
    
private:
    ofImage dinoSprite1;
    ofImage dinoSprite2;
    bool isDino1;
    int animationChange;
};
