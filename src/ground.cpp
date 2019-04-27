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
}

void Ground::update() {
    xPos += 2;
    if (xPos == 400) {
        xPos = 0;
    }
}

void Ground::draw() {
    ground.draw(initialX - xPos, initialY, 630, 20);
}
