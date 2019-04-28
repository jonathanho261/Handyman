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
}

void GameEngine::update() {
    dino.update();
    ground1.update();
    ground2.update();
}

void GameEngine::draw() {
    //draw background
    ofDrawRectangle(25, 385, 650, 150);
    ground1.draw();
    ground2.draw();
    dino.draw();
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
