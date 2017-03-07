#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    uniqueIDCounter = 0UL;
    font = std::shared_ptr<ofTrueTypeFont>(new ofTrueTypeFont());
    font->load("SCPro-Regular.ttf", 72, true, true, true);
    test = new ShiftLeft(0, 0, 100, font, 120, 4);
    scaleFactor = 1.0f;
    mouseHeld = NULL;
    //ofEnableSmoothing();
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            blocks.push_back(new ShiftLeft(j*200, i*200, i*j+1, font, 120, 4));
        }
    }
    
    blocks[0]->outNode->connections.push_back(blocks[1]->firstInNode);
    blocks[0]->outNode->connections.push_back(blocks[2]->firstInNode);
    blocks[0]->outNode->connections.push_back(blocks[3]->firstInNode);
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
        (*it)->position.x = (*it)->position.x + ofRandom(-1.0f, 1.0f);
        (*it)->position.y = (*it)->position.y + ofRandom(-1.0f, 1.0f);
    }
    if (ofGetMousePressed() && mouseHeld != NULL){
        mouseHeld->position.x = ((float)ofGetMouseX()-ofGetWidth()/2)*1/scaleFactor;
        mouseHeld->position.y = ((float)ofGetMouseY()-ofGetHeight()/2)*1/scaleFactor;
    }
    //test->draw();
    ofPopMatrix();
    std::cout << ((float)ofGetMouseX()-ofGetWidth()/2)*-scaleFactor << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    for(auto it = blocks.begin(); it != blocks.end(); ++it) {
        (*it)->intersectionCheck(((float)ofGetMouseX())-(ofGetWidth()/2), ((float)ofGetMouseY())-(ofGetHeight()/2));
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(auto it = blocks.begin(); it != blocks.end(); ++it) {
        if((*it)->intersectionCheckOut((float) x-ofGetWidth()/2, (float) y-ofGetHeight()/2)){
            mouseHeld = (*it);
            break;
        }
    }
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
