//
//  BlockNode.cpp
//  ctrl-shift-bits
//
//  Created by Jake on 07/03/2017.
//
//

#include "BlockNode.hpp"


BlockNode::BlockNode(float x, float y, unsigned long ID) : GameObject(x, y, ID){
    //intentionally twice as large as its width and height
    boundingBox = *new ofRectangle(x-width, y-height, width, height);
    activeConnection = false;
    activeConnect = {0.0, 0.0, 0.0};
}

void BlockNode::draw(){
    //push matrix to keep translattion/scale/etc local
    ofPushMatrix();
    //translate to position so we can draw based on local coords
    ofTranslate(position.x, position.y);
    
    //drawing the rectangle around the centre of object
    ofPushStyle();
    if (mouseIn){
        ofFill();
    }
    else{
        ofNoFill();
    }

    //ofDrawRectangle(boundingBox.x, boundingBox.y, boundingBox.width, boundingBox.height);
    ofDrawRectangle(-width/2, -height/2, width, height);
    
    ofPopStyle();
    
    ofPopMatrix();
    childDraw();
}

BlockNode::~BlockNode(){
    
}

void BlockNode::resizeBounds(float resize){
    //intentionally twice as large as its width and height
    boundingBox = ofRectangle((position.x-width)*resize, (position.y-height)*resize, width*resize*2, height*resize*2);
}

void BlockNode::intersectionCheck(float x, float y){
    ofPoint mouse = ofPoint(x, y);
    mouseIn = boundingBox.intersects(mouse,mouse);
}

bool BlockNode::intersectionCheckOut(float x, float y){
    ofPoint mouse = ofPoint(x, y);
    return boundingBox.intersects(mouse,mouse);
}


