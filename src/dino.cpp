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
    yPosition = 400;
    isDescending = false;
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
    if (isJumping) {
        int jumpPeak = 350;
        if (yPosition == 400) {
            isJumping = false;
            isDescending = false;
        }
        if (isDescending) {
            yPosition += 2;
        } else if (yPosition > jumpPeak) {
            yPosition -= 2;
        } else {
            isDescending = true;
        }
    }
}

void Dinosaur::draw() {
    if (isDino1) {
        dinoSprite1.draw(50, yPosition, 60, 60);
    } else {
        dinoSprite2.draw(50, yPosition, 60, 60);
    }
}

void Dinosaur::jump() {
    isJumping = true;
    yPosition -= 2;
}
