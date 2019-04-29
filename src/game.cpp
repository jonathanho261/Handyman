//
//  game.cpp
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#include <stdio.h>
#include "game.h"

GameEngine::GameEngine() {
    score = 0;
}

void GameEngine::setup() {
    dino.setup();
    ground1.setup(45, 445);
    ground2.setup(445, 445);
    
    minCactusDistance = 100;
    Cactus firstCactus;
    firstCactus.setup(1);
    cacti.push_back(firstCactus);
}

void GameEngine::update() {
    dino.update();
    ground1.update();
    ground2.update();
    updateCactus();
}

void GameEngine::draw() {
    //draw background
    ofDrawRectangle(25, 360, 650, 150);
    ground1.draw();
    ground2.draw();
    dino.draw();
    for (Cactus cactus : cacti) {
        cactus.draw();
    }
}

void GameEngine::jump() {
    dino.jump();
}

void GameEngine::duck() {
    dino.duck();
}

void GameEngine::stopDucking() {
    dino.stopDucking();
}


void GameEngine::updateCactus() {
    for (int i = 0; i < cacti.size(); i++) {
        if (!cacti[i].update()) {
            cacti.erase(cacti.begin() + i);
            i--;
        }
    }
    if (minCactusDistance < 0) {
        int probablityChecker = 1;
        if (randomNumber(50) == probablityChecker) {
            Cactus cactus;
            cactus.setup(randomNumber(3));
            cacti.push_back(cactus);
            minCactusDistance = 100;
        }
    }
    minCactusDistance--;
}

int GameEngine::randomNumber(int range) {
    return rand() % range + 1;
}
