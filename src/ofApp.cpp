//sources: https://www.opencv-srf.com/2010/09/object-detection-using-color-seperation.html

#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void Handyman::setup(){
    hasLearnedBackground = false;
    setupVideoProcessing();
    
    hsvValues.setup();
    setupHsvGui();
    
}

//--------------------------------------------------------------
void Handyman::update(){
    webcam.update();
    if (webcam.isFrameNew()) {
        cameraImage.setFromPixels(webcam.getPixels());
    }
    if (contourFinder.size() > 0) {
        ofVec2f velocity = toOf(contourFinder.getVelocity(0));
        if (velocity.x >= 30) {
            std::cout << "RIGHT" << std::endl;
        }
        else if (velocity.x <= -30) {
            std::cout << "LEFT" << std::endl;
        }
        else if (velocity.y >= 30) {
            std::cout << "UP" << std::endl;
        }
        else if (velocity.y <= -30) {
            std::cout << "DOWN" << std::endl;
        }
    }
    
}

//--------------------------------------------------------------
void Handyman::draw(){
    drawThresholdedImage();
    //for (int i = 0; i < contourFinder.size(); i++) {
    
    if (contourFinder.size() > 0) {
        ofSetColor(255, 0, 0);
        ofPoint currentCentroid = toOf(contourFinder.getCentroid(0));
        ofDrawEllipse(currentCentroid.x, currentCentroid.y, 10.0, 10.0);
    }
}

//--------------------------------------------------------------
void Handyman::keyPressed(int key){
    if (key == 32) {
        hasLearnedBackground = true;
    }
}

//--------------------------------------------------------------
void Handyman::keyReleased(int key){

}

//--------------------------------------------------------------
void Handyman::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Handyman::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Handyman::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Handyman::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Handyman::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Handyman::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Handyman::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Handyman::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Handyman::dragEvent(ofDragInfo dragInfo){

}


//-------------------Private helper methods---------------------
void Handyman::setupVideoProcessing() {
    webcam.setVerbose(true);
    webcam.initGrabber(320,240);
    
    cameraImage.allocate(320,240);
    grayImage.allocate(320,240);
    displayImage.allocate(320, 240, OF_IMAGE_COLOR);
    learnedBackground.allocate(320,240);
    differences.allocate(320,240);
    cameraImage.convertRgbToHsv();
}

void Handyman::setupHsvGui() {
    hsvValues.add(lowH.set("lowH", 0, 0, 179));
    hsvValues.add(highH.set("highH", 0, 0, 179));
    hsvValues.add(lowS.set("lowS", 0, 0, 255));
    hsvValues.add(highS.set("highS", 0, 0, 255));
    hsvValues.add(lowV.set("lowV", 0, 0, 255));
    hsvValues.add(highV.set("highV", 0, 0, 255));
}

std::unique_ptr<cv::Mat> Handyman::updateHandPosition() {
    Mat orignalImage = toCv(cameraImage);
    
    Mat hsvImage;
    cvtColor(orignalImage, hsvImage, COLOR_BGR2HSV);
    
    Mat thresholdedImage;
    inRange(hsvImage, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), thresholdedImage);
    
    //remove small objects in foreground
    erode(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    dilate(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    
    //remove holes in foreground
    dilate(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    erode(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    
    return std::make_unique<cv::Mat>(thresholdedImage);
}

void Handyman::contourHandPosition(cv::Mat thresholdedImage) {
    Mat grayMat = toCv(grayImage);
    Mat backgroundMat = toCv(learnedBackground);
    Mat differenceMat = toCv(displayImage);
    if (webcam.isFrameNew()){
        grayMat = thresholdedImage;
        if (hasLearnedBackground == true) {
            backgroundMat = grayMat; // update the background image
            hasLearnedBackground = false;
        }
        absdiff(backgroundMat, thresholdedImage, differenceMat);
        contourFinder.findContours(differenceMat);
    }
}

void Handyman::drawThresholdedImage() {
    ofSetHexColor(0xffffff);
    cameraImage.draw(0, 0, 320, 240);
    contourFinder.draw();
    
    hsvValues.draw();
    
    std::unique_ptr<cv::Mat> thresholdedImagePtr = updateHandPosition();
    contourHandPosition(*thresholdedImagePtr);
    drawMat(*thresholdedImagePtr, 320, 0);

}


