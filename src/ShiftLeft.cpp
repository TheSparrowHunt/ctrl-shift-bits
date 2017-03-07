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
}

ShiftLeft::~ShiftLeft(){
    
}

void ShiftLeft::draw(){
    ofDrawRectRounded(position.x, position.y, size, size, 10);
}

void ShiftLeft::behaviour(){
    //nothing in the first input
    if (firstIn == NULL){
        outValue = 0U;
    }
    //nothing in first and second inputs pass-through
    else if (secondIn == NULL){
        outValue = firstIn->outValue;
    }
    //something in both first and second inputs
    else{
        //outValue is first value shifted by the second value
        outValue = firstIn->outValue << secondIn->outValue;
    }
}