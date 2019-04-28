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
    void jump();
    void duck();
    void stopDucking();
    
private:
    ofImage dinoSprite1;
    ofImage dinoSprite2;
    ofImage duckDino1;
    ofImage duckDino2;
    bool isDino1;
    int animationChange;
    
    int yPosition;
    int jumpSpeed;
    bool isJumping;
    bool isDescending;
    bool isDucking;
};
