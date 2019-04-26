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
    ground.load("ground.png");
    ground.draw(50, 400, 300, 10);
}

void GameEngine::update() {
    dino.update();
}

void GameEngine::draw() {
    dino.draw();
    ground.draw(50, 400, 300, 10);
}
