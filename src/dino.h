//
//  dino.h
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#pragma once
#include "ofMain.h"
#include <vector>
#include <tuple>

class Dinosaur {
public:
    Dinosaur();
    
    void setup();
    void update();
    void draw();
    void jump();
    void duck();
    void stopDucking();
    std::vector<std::tuple<int, int>> getCriticalPoints();
    bool hitObject(std::vector<std::tuple<int, int>> cactusCriticalPoints);
    
private:
    ofImage dinoSprite1;
    ofImage dinoSprite2;
    ofImage duckDino1;
    ofImage duckDino2;
    bool isDino1;
    int animationChange;
    
    int xPosition;
    int yPosition;
    int jumpSpeed;
    bool isJumping;
    bool isDescending;
    bool isDucking;
    const int kDuckingCompensation = 20;
};
