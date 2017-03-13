//
//  ShiftLeft.cpp
//  ctrl-shift-bits
//
//  Created by Jake on 06/03/2017.
//
//

#include "ShiftLeft.hpp"

ShiftLeft::ShiftLeft(float x, float y, unsigned long ID, std::shared_ptr<ofTrueTypeFont> _font, float _size, unsigned int _bits) : Block(x, y,uniqueID, _font, _size, _bits){
    //two ins, one out
    inNodes = 2;
    outNodes = 1;
    displayText = "<<";
    //uniqueIDs for BlockNodes not important and difficult
    //position x=leftside - leftsidedifference
    firstInNode = new BlockNodeIn(x-(x - boundingBox.getLeft()), boundingBox.getTop()+(size/3), ID);
    firstInNode->parent = this;
    secondInNode = new BlockNodeIn(x-(x - boundingBox.getLeft()), boundingBox.getTop()+2*(size/3), ID);
    secondInNode->parent = this;
    //outNode
    outNode = new BlockNodeOut(x+(x - boundingBox.getLeft()), boundingBox.getTop()+(size/2), ID);
    outNode->parent = this;
}

ShiftLeft::~ShiftLeft(){
    //delete firstInNode;
    //delete secondInNode;
}


void ShiftLeft::behaviour(){
    
    //nothing in the first input
    if (firstIn == NULL){
        outValue = 0U;
    }
    
    //nothing in first and second inputs pass-through
    else if (secondIn == NULL){
        outValue = clearValues(firstIn->outValue);
    }
    
    //something in both first and second inputs
    else{
        
        //outValue is first value shifted by the second value
        outValue = clearValues(firstIn->outValue << secondIn->outValue);
    }
}
