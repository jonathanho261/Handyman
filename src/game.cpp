//
//  game.cpp
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#include <stdio.h>
#include "game.h"

GameEngine::GameEngine() {
    isGameInProgress = false;
    isGameOver = false;
}

void GameEngine::setup() {
    timer = 0;
    millisecondsPassed = 0;
    
    dino.setup();
    ground1.setup(45, 445);
    ground2.setup(445, 445);
    
    minCactusDistance = 100;
    Cactus firstCactus;
    firstCactus.setup(1);
    cacti.push_back(firstCactus);
    
}

void GameEngine::update() {
    if (isGameInProgress && !isGameOver) {
        timer += 0.01;
        dino.update();
        ground1.update();
        ground2.update();
        updateCactus();
        if (collisionOccurance()) {
            isGameOver = true;
            isGameInProgress = false;
        }
    }
}

void GameEngine::draw() {
    ofDrawRectangle(25, 360, 650, 150);
    ground1.draw();
    ground2.draw();
    dino.draw();
    for (Cactus cactus : cacti) {
        cactus.draw();
    }
    displayScore();
}

void GameEngine::startGame() {
    isGameInProgress = true;
}

void GameEngine::reset() {
    isGameOver = false;
    timer = 0;
    cacti.clear();
    setup();
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

void GameEngine::displayScore() {
    int score = ((int) timer) % 100;
    std::string scoreString = "Score: " + std::to_string(score);
    ofSetColor(25, 25, 25);
    ofDrawBitmapString(scoreString, 590, 380);
    ofSetColor(255, 255, 255);
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

bool GameEngine::collisionOccurance() {
    for (Cactus cactus : cacti) {
        if (dino.hitObject(cactus.getCriticalPoints())) {
            return true;
        }
    }
    return false;
}
