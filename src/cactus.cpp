//
//  cactus.cpp
//  Handyman
//
//  Created by Jonathan Ho on 4/26/19.
//

#include <stdio.h>
#include "cactus.h"

Cactus::Cactus() {
    
}

void Cactus::setup(int num) {
    if (num == 1) {
        cactus.load("cactus1.png");
    } else if (num == 2) {
        cactus.load("cactus2.png");
    } else {
        cactus.load("cactus3.png");
    }
    xPosition = 645;
    yPosition = 420;
}

bool Cactus::update() {
    if (xPosition <= -5) {
        return false;
    }
    int speedIncreaseFactor = 0.01;
    xPosition -= (2 + speedIncreaseFactor);
    return true;
}

void Cactus::draw() {
    cactus.draw(xPosition, yPosition, 30, 30);
}

std::vector<std::tuple<int, int>> Cactus::getCriticalPoints() {
    std::vector<std::tuple<int, int>> criticalPoints;
    criticalPoints.push_back(std::make_tuple(xPosition, yPosition - 10));       //far left
    criticalPoints.push_back(std::make_tuple(xPosition - 10, yPosition));       //top middle
    criticalPoints.push_back(std::make_tuple(xPosition + 20, yPosition - 10));  //far right
    return criticalPoints;
}
