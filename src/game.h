//
//  game.h
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#pragma once
#include "ofMain.h"
#include "dino.h"

class GameEngine {
public:
    GameEngine();
    
    void setup();
    void update();
    void draw();
    void reset();
    
private:
    Dinosaur dino;
    ofImage ground;
    int score;
};
