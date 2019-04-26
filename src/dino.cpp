//
//  dino.cpp
//  Handyman
//
//  Created by Jonathan Ho on 4/25/19.
//

#include <stdio.h>
#include "dino.h"

Dinosaur::Dinosaur() {
    isDino1 = true;
    animationChange = 0;
}

void Dinosaur::setup() {
    dinoSprite1.load("dino1.png");
    dinoSprite2.load("dino2.png");
}

void Dinosaur::update() {
    animationChange++;
    if (animationChange == 10) {
        animationChange = 0;
        isDino1 = !isDino1;
    }
}

void Dinosaur::draw() {
    if (isDino1) {
        dinoSprite1.draw(50, 400, 60, 60);
    } else {
        dinoSprite2.draw(50, 400, 60, 60);
    }
}
