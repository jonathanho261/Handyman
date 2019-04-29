//
//  game.h
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#pragma once
#include "ofMain.h"
#include "dino.h"
#include "ground.h"
#include "cactus.h"
#include <vector>
#include <cstdlib>

class GameEngine {
public:
    GameEngine();
    
    void setup();
    void update();
    void draw();
    void reset();
    
    //control methods
    void jump();
    void duck();
    void stopDucking();
    
private:
    int score;
    
    Dinosaur dino;
    Ground ground1;
    Ground ground2;

    int minCactusDistance;
    std::vector<Cactus> cacti;
    void updateCactus();
    int randomNumber(int range);
};
