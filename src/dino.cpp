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
    isDescending = false;
}

void Dinosaur::setup() {
    dinoSprite1.load("dino1.png");
    dinoSprite2.load("dino2.png");
    duckDino1.load("duckDino1.png");
    duckDino2.load("duckDino2.png");
    animationChange = 0;
    yPosition = 400;
    jumpSpeed = 2;
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
            yPosition += jumpSpeed;
        } else if (yPosition > jumpPeak) {
            yPosition -= jumpSpeed;
        } else {
            isDescending = true;
        }
    }
}

void Dinosaur::draw() {
    int duckCompensation = 20;
    if (isDino1 && !isDucking) {
        dinoSprite1.draw(50, yPosition, 60, 60);
    } else if (!isDucking) {
        dinoSprite2.draw(50, yPosition, 60, 60);
    } else if (isDino1) {
        duckDino1.draw(50, yPosition - duckCompensation, 80, 80);
    } else {
        duckDino2.draw(50, yPosition - duckCompensation, 80, 80);
    }
}

void Dinosaur::jump() {
    isJumping = true;
    yPosition -= jumpSpeed;
}

void Dinosaur::duck() {
    isDucking = true;
}

void Dinosaur::stopDucking() {
    isDucking = false;
}
