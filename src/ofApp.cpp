//sources: https://www.opencv-srf.com/2010/09/object-detection-using-color-seperation.html

#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    bLearnBackground = false;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
    
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    gui.setup();
    gui.add(lowH.set("lowH", 0, 0, 179));
    gui.add(highH.set("highH", 0, 0, 179));
    gui.add(lowS.set("lowS", 0, 0, 255));
    gui.add(highS.set("highS", 0, 0, 255));
    gui.add(lowV.set("lowV", 0, 0, 255));
    gui.add(highV.set("highV", 0, 0, 255));
    
    image.allocate(320,240);
    image.convertRgbToHsv();
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    if (vidGrabber.isFrameNew()){
        colorImg.setFromPixels(vidGrabber.getPixels());
        grayImage = colorImg; // convert our color image to a grayscale image
        if (bLearnBackground == true) {
            grayBg = grayImage; // update the background image
            bLearnBackground = false;
        }
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(30);
        contourFinder.findContours(grayDiff, 5, (340*240)/4, 4, false, true);
    }
    
    image.setFromPixels(vidGrabber.getPixels());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    colorImg.draw(0, 0, 320, 240);
    grayDiff.draw(0, 240, 320, 240);
    ofDrawRectangle(320, 0, 320, 240);
    contourFinder.draw(320, 0, 320, 240);
    ofColor c(255, 255, 255);
    for(int i = 0; i < contourFinder.nBlobs; i++) {
        ofRectangle r = contourFinder.blobs.at(i).boundingRect;
        r.x += 320; r.y += 240;
        //c.setHsb(i * 64, 255, 255);
        //ofSetColor(c);
        //ofDrawRectangle(r);
    }
    
    Mat orignalImg = toCv(image);
    
    Mat imgHSV;
    cvtColor(orignalImg, imgHSV, COLOR_BGR2HSV);
    
    Mat thresholdedImg;
    inRange(imgHSV, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), thresholdedImg);
    
    //remove small objects in foreground
    erode(thresholdedImg, thresholdedImg, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    dilate(thresholdedImg, thresholdedImg, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    
    //remove holes in foreground
    dilate(thresholdedImg, thresholdedImg, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    erode(thresholdedImg, thresholdedImg, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    
    
    gui.draw();
    drawMat(thresholdedImg, 320, 240);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bLearnBackground = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
