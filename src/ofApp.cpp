#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    uniqueIDCounter = 0UL;
    font = std::shared_ptr<ofTrueTypeFont>(new ofTrueTypeFont());
    font->load("SCProLight.ttf", 72, true, true, true);
    test = new ShiftLeft(0, 0, 100, font, 120, 4);
    scaleFactor = 1.0f;
    ofEnableSmoothing();
    blocks.push_back(new ShiftLeft(0, 0, 100, font, 120, 4));
    blocks.push_back(new ShiftLeft(100, 100, 101, font, 120, 4));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(scaleFactor, scaleFactor);
    ofBackground(0);
    
    for(auto it = blocks.begin(); it != blocks.end(); ++it) {
        (*it)->draw();
        (*it)->resizeBounds(scaleFactor);
        (*it)->intersectionCheck(((float)ofGetMouseX())-(ofGetWidth()/2), ((float)ofGetMouseY())-(ofGetHeight()/2));
    }
    
    //test->draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){
    scaleFactor += scaleFactor*(scrollY/100);
    if (scaleFactor < 0.0001){
        scaleFactor = 0.0001;
    }
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
