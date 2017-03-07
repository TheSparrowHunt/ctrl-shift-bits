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
}

ShiftLeft::~ShiftLeft(){
    
}

void ShiftLeft::draw(){
    ofPushStyle();
        ofNoFill();
        ofDrawRectRounded(position.x - size/2, position.y - size/2, size, size, 10);
    ofPopStyle();
    
    ofPushStyle();
    //get the bounding box of the textbox
    ofRectangle textBound = font->getStringBoundingBox(displayText, position.x, position.y);
    ofPoint topLeft = textBound.getTopLeft();
    ofPoint halfSizeText = {position.x - topLeft.x, position.y - topLeft.y, 0.0f};
        font->drawStringAsShapes(displayText, position.x + halfSizeText.x, position.y);
    ofPopStyle();
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