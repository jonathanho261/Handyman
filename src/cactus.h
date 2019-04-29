//
//  cactus.h
//  Handyman
//
//  Created by Jonathan Ho on 4/26/19.
//

#pragma once
#include "ofMain.h"

class Cactus {
public:
    Cactus();
    
    void setup(int num);
    void update();
    void draw();
    void getArea();
    
private:
    ofImage cactus;
    int xPosition, yPosition;
};
