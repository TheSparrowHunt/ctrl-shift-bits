#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    uniqueIDCounter = 0UL;
    font = std::shared_ptr<ofTrueTypeFont>(new ofTrueTypeFont());
    font->load("SCPro-Regular.ttf", 72, true, true, true);
    //DEBUG
    test = new ShiftLeft(0, 0, 100, font, 120, 4);
    //default scaleFactor
    scaleFactor = 1.0f;
    //initialise mouseHeld to NULL
    mouseHeld = NULL;
    //ofEnableSmoothing();
    //testing a vector of blocks
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            blocks.push_back(new ShiftLeft(j*200, i*200, i*j+1, font, 120, 4));
        }
    }
    
    //testing connections
//    blocks[0]->outNode->connections.push_back(blocks[1]->firstInNode);
//    blocks[0]->outNode->connections.push_back(blocks[2]->firstInNode);
//    blocks[0]->outNode->connections.push_back(blocks[3]->firstInNode);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofSetColor(0, 0, 0, 32);
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    ofPopStyle();
    //drawing for the Blocks layer, it scales completely
    //could abstract to a GameState object
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(scaleFactor, scaleFactor);
    //ofBackground(0, 0, 0, 10);
    //iteration to do things with the blocks
    for(auto it = blocks.begin(); it != blocks.end(); ++it) {
        (*it)->draw();
        (*it)->resizeBounds(scaleFactor);
        //(*it)->position.x = (*it)->position.x + ofRandom(-1.0f, 1.0f);
        //(*it)->position.y = (*it)->position.y + ofRandom(-1.0f, 1.0f);
    }
    //mouse selection updates
    if(ofGetMousePressed() && mouseHeld != NULL){
        
        //for the blocks
        if (dynamic_cast<Block*>(mouseHeld) != NULL){
            mouseHeld->position.x = ((float)ofGetMouseX()-ofGetWidth()/2)*1/scaleFactor;
            mouseHeld->position.y = ((float)ofGetMouseY()-ofGetHeight()/2)*1/scaleFactor;
        }
        
        //for the heldBlockNodes
        else if (dynamic_cast<BlockNode*>(mouseHeld) != NULL){
            BlockNode* heldBlockNode = dynamic_cast<BlockNode*>(mouseHeld);
            heldBlockNode->activeConnect.x = ((float)ofGetMouseX()-ofGetWidth()/2)*1/scaleFactor;
            heldBlockNode->activeConnect.y = ((float)ofGetMouseY()-ofGetHeight()/2)*1/scaleFactor;
            
        }
    }
    //test->draw();
    ofPopMatrix();
    //DEBUG
    std::cout << ofGetFrameRate() << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //for highlighting what would be selected if the user clicks now
    for(auto it = blocks.begin(); it != blocks.end(); ++it) {
        (*it)->intersectionCheck(((float)ofGetMouseX())-(ofGetWidth()/2), ((float)ofGetMouseY())-(ofGetHeight()/2));
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //grabing a block object if there's one where the mouse is
    for(auto it = blocks.begin(); it != blocks.end(); ++it) {
        
        //checking the nodes
        if((*it)->outNode->intersectionCheckOut((float) x-ofGetWidth()/2, (float) y-ofGetHeight()/2)){
            mouseHeld = (*it)->outNode;
            BlockNode* heldBlockNode = dynamic_cast<BlockNode*>(mouseHeld);
            heldBlockNode->activeConnection = true;
            break;
        }
        
        if (mouseHeld != NULL){
            break;
        }
        
        //checking the blocks
        if((*it)->intersectionCheckOut((float) x-ofGetWidth()/2, (float) y-ofGetHeight()/2)){
            //store the pointer to that object in mouseHeld to use later to update its position
            mouseHeld = (*it);
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (dynamic_cast<BlockNode*>(mouseHeld) != NULL){
        BlockNode* heldBlockNode = dynamic_cast<BlockNode*>(mouseHeld);
        for(auto it = blocks.begin(); it != blocks.end(); ++it) {
            float x = ((float)ofGetMouseX()-ofGetWidth()/2)*1/scaleFactor;
            float y = ((float)ofGetMouseY()-ofGetHeight()/2)*1/scaleFactor;
            //if the mouse location is close to the position of the any ins
            if ((*it)->firstInNode->position.distance({x, y}) < 10.0f){
            //if ((*it)->firstInNode->position.distance({(float) x-ofGetWidth()/2, (float) y-ofGetHeight()/2}) < 10.0f){
                //push_back the connection
                heldBlockNode->connections.push_back((*it)->firstInNode);
                //set activeConnection to false as it is no longer active.
                heldBlockNode->activeConnection = false;
                break;
            }
            
            heldBlockNode->activeConnect.x = ((float)ofGetMouseX()-ofGetWidth()/2)*1/scaleFactor;
            heldBlockNode->activeConnect.y = ((float)ofGetMouseY()-ofGetHeight()/2)*1/scaleFactor;
        }
    }
    
    mouseHeld = NULL;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){
    //scaling
    scaleFactor += scaleFactor*(scrollY/100);
    //preventing getting stuck at 0
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
