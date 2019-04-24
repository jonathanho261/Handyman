#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

enum Directions {UP, DOWN, LEFT, RIGHT};

class Handyman : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //private fields for detecting the hand
    bool hasLearnedBackground;
    ofVideoGrabber webcam;
    ofxCvColorImage cameraImage;
    ofxCvGrayscaleImage grayImage, learnedBackground;
    ofImage displayImage;
    ofxCvGrayscaleImage differences;
    ofxCv::ContourFinder contourFinder;
    ofPoint centroid;
    
    //private fields for changing HSV values
    ofxPanel hsvValues;
    ofParameter<float> lowH, highH, lowS, highS, lowV, highV;
    
    //private helper methods for hand motion tracking
    void setupVideoProcessing();
    void setupHsvGui();
    std::unique_ptr<cv::Mat> updateHandPosition();
    void contourHandPosition(cv::Mat thresholdedImage);
    void drawThresholdedImage();
    
    //find ContourFinder helper methods
    ofPoint findAverageCentroid(ofPoint averageCentroid);
    ofVec2f findAverageVelocity(ofVec2f averageVelocity);
};
