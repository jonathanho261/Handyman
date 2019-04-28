//
//  ground.cpp
//  Handyman
//
//  Created by Jonathan Ho on 4/26/19.
//

#include <stdio.h>
#include "ground.h"

Ground::Ground() {
    ground.load("ground.png");
}

void Ground::setup(int x, int y) {
    initialX = x;
    initialY = y;
    moveSpeed = 2;
}

void Ground::update() {
    int resetThreshold = 400;
    int speedIncreaseFactor = 0.01;
    xPosition += (moveSpeed + speedIncreaseFactor);
    if (xPosition == resetThreshold) {
        xPosition = 0;
    }
}

void Ground::draw() {
    ground.draw(initialX - xPosition, initialY, 630, 20);
}
