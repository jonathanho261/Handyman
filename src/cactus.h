//
//  cactus.h
//  Handyman
//
//  Created by Jonathan Ho on 4/26/19.
//

#pragma once
#include "ofMain.h"
#include <vector>
#include <tuple>

class Cactus {
public:
    Cactus();
    
    void setup(int num);
    bool update();
    void draw();
    std::vector<std::tuple<int, int>> getCriticalPoints();
    
private:
    ofImage cactus;
    int xPosition, yPosition;
};
