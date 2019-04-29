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

void Cactus::update() {
    if (xPosition <= -5) {
        cactus.clear();
    } else {
        xPosition -= 2;
    }
}

void Cactus::draw() {
    cactus.draw(xPosition, yPosition, 30, 30);
}
