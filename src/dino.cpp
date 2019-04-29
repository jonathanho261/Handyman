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
    xPosition = 50;
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
    if (isDino1 && !isDucking) {
        dinoSprite1.draw(xPosition, yPosition, 60, 60);
    } else if (!isDucking) {
        dinoSprite2.draw(xPosition, yPosition, 60, 60);
    } else if (isDino1) {
        duckDino1.draw(xPosition, yPosition - kDuckingCompensation, 80, 80);
    } else {
        duckDino2.draw(xPosition, yPosition - kDuckingCompensation, 80, 80);
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

std::vector<std::tuple<int, int>> Dinosaur::getCriticalPoints() {
    std::vector<std::tuple<int, int>> criticalPoints;
    if (!isDucking) {
        for (int i = 0; i < 10; ++i) {
            criticalPoints.push_back(std::make_tuple(xPosition + 18, yPosition + 25 + i)); //tail
            criticalPoints.push_back(std::make_tuple(xPosition + 35 + i, yPosition + 25 - i)); //front
        }
        for (int i = 0; i < 2; ++i) {
            criticalPoints.push_back(std::make_tuple(xPosition + 27 + (5 * i), yPosition + 44)); //legs
        }
    } else {
        criticalPoints.push_back(std::make_tuple(xPosition + 30, yPosition + 32));
        criticalPoints.push_back(std::make_tuple(xPosition + 17, yPosition + 26));
        criticalPoints.push_back(std::make_tuple(xPosition + 13, yPosition + 41));
    }
    return criticalPoints;
}

bool Dinosaur::hitObject(std::vector<std::tuple<int, int>> cactusCriticalPoints) {
    std::vector<std::tuple<int, int>> dinoCriticalPoints = getCriticalPoints();
    for (std::tuple<int, int> cactus : cactusCriticalPoints) {
        for (std::tuple<int, int> dino : dinoCriticalPoints) {
            if (get<0>(cactus) == get<0>(dino) && abs(get<1>(cactus) - get<1>(dino)) <= 2) {
                std::cout << get<0>(cactus) << " " << get<1>(cactus) << " " << get<1>(dino) << std::endl;
                return true;
            }
        }
    }
    return false;;
}
