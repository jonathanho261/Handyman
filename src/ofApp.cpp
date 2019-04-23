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
}

//--------------------------------------------------------------
void Handyman::draw(){
    ofSetHexColor(0xffffff);
    cameraImage.draw(0, 0, 320, 240);
    grayDiff.draw(0, 240, 320, 240);
    ofDrawRectangle(320, 0, 320, 240);
    contourFinder.draw(320, 0, 320, 240);
    
    hsvValues.draw();
    
    std::unique_ptr<cv::Mat> thresholdedImagePtr = updateHandPosition();
    contourHandPosition(*thresholdedImagePtr);
    drawMat(*thresholdedImagePtr, 320, 240);
    
    for(int i = 0; i < contourFinder.nBlobs; i++) {
        ofRectangle r = contourFinder.blobs.at(i).boundingRect;
    }
    
    hsvValues.draw();
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
    learnedBackground.allocate(320,240);
    grayDiff.allocate(320,240);
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
    
    //std::cout << "M = "<< std::endl << " "  << hsvImage << std::endl << std::endl;
    
    Mat thresholdedImage;
    inRange(hsvImage, Scalar(8.95, lowS, lowV), Scalar(60.13, 255, 255), thresholdedImage);
    
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
    //Mat differenceMat = toCv(grayDiff);
    if (webcam.isFrameNew()){
        grayMat = thresholdedImage;
        if (hasLearnedBackground == true) {
            backgroundMat = grayMat; // update the background image
            hasLearnedBackground = false;
        }
        grayDiff.absDiff(learnedBackground, grayImage);
        grayDiff.threshold(30);
        contourFinder.findContours(grayDiff, 5, (340*240)/4, 4, false, true);
    }
}

void Handyman::drawThresholdedImage() {
    
}


