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
    boundingBox = *new ofRectangle(x-width, y-height, 1.5*width, 1.5*height);
}

BlockNode::~BlockNode(){
    
}

void BlockNode::draw(){
    
}