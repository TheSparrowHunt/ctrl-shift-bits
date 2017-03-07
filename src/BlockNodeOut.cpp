//
//  BlockNodeOut.cpp
//  ctrl-shift-bits
//
//  Created by Jake on 07/03/2017.
//
//

#include "BlockNodeOut.hpp"

BlockNodeOut::BlockNodeOut(float x, float y, unsigned long ID) : BlockNode(x, y, ID){
    
}

BlockNodeOut::~BlockNodeOut(){
    
}

void BlockNodeOut::childDraw(){
    ofPushMatrix();
    //translate to position so we can draw based on local coords
    //ofTranslate(position.x, position.y);
        for(auto it = connections.begin(); it != connections.end(); ++it) {
            //direct line drawing
            //ofDrawLine(this->position.x, this->position.y, (*it)->position.x, (*it)->position.y);
            //split line drawing
            ofDrawLine(this->position.x, this->position.y, this->position.x + ((*it)->position.x - this->position.x)/2, this->position.y);
            ofDrawLine(this->position.x + ((*it)->position.x - this->position.x)/2, this->position.y, this->position.x + ((*it)->position.x - this->position.x)/2, (*it)->position.y);
            ofDrawLine(this->position.x + ((*it)->position.x - this->position.x)/2, (*it)->position.y, (*it)->position.x, (*it)->position.y);
        }
    ofPopMatrix();
}