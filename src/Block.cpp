//
//  Block.cpp
//  ctrl-shift-bits
//
//  Created by Jake on 06/03/2017.
//
//

#include "Block.hpp"

Block::Block(float x, float y, unsigned long ID, std::shared_ptr<ofTrueTypeFont> _font, float _size, unsigned int _bits) : GameObject(x, y, ID){
    //getting a shared pointer to the font
    font = _font;
    size = _size;
    bits = _bits;
    boundingBox = *new ofRectangle(x-size/2, y-size/2, size, size);
}

Block::~Block(){
    
}

void Block::draw(){
    //push matrix to keep translattion/scale/etc local
    ofPushMatrix();
    
        //translate to position so we can draw based on local coords
        ofTranslate(position.x, position.y);
        ofScale(0.5, 0.5);
        //update the bounding box
        boundingBox.scaleFromCenter(0.5);
        //drawing the rectangle around the centre of object
        ofPushStyle();
    
            ofNoFill();
            ofDrawRectRounded(-size/2, -size/2, size, size, 10);
    
        ofPopStyle();
    
        //drawing the text into the box
        ofPushStyle();
            //get the bounding box of the textbox
            //DEBUG:
            //ofRectangle textBound = font->getStringBoundingBox(displayText, 0.5*-font->stringWidth(displayText) - font->getSize()/6, font->stringHeight(displayText)/2);
    
            font->drawStringAsShapes(displayText, -font->stringWidth(displayText)/2 - font->getSize()/6, font->stringHeight(displayText)/2);
        ofPopStyle();
    ofPopMatrix();
}

//should get rid of the extra 1s to the left of the amount of bits for the level in which these blocks exist
unsigned int Block::clearValues(unsigned int value){
    return value%((unsigned int)std::powf(2.0f, (float)bits));
}