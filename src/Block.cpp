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
    boundingBox = ofRectangle(x-size/2, y-size/2, size, size);
    firstIn = NULL;
    secondIn = NULL;
    firstInNode = NULL;
    secondInNode = NULL;
    outNode = NULL;
}

Block::~Block(){
    delete firstInNode;
    delete secondInNode;
    delete outNode;
}

void Block::draw(){
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
            ofDrawRectRounded(-size/2, -size/2, size, size, 10);
    
        ofPopStyle();
    
        //drawing the text into the box
        ofPushStyle();
            //get the bounding box of the textbox
            //DEBUG:
            //ofRectangle textBound = font->getStringBoundingBox(displayText, 0.5*-font->stringWidth(displayText) - font->getSize()/6, font->stringHeight(displayText)/2);
            if (mouseIn){
                ofSetColor(0, 0, 0, 255);
            }
            else{
                ofSetColor(255,255,255, 255);
            }
            
            font->drawStringAsShapes(displayText, -font->stringWidth(displayText)/2 - font->getSize()/6, font->stringHeight(displayText)/2);
    
        ofPopStyle();
    ofPopMatrix();
    
    if (firstInNode != NULL){
        firstInNode->draw();
        firstInNode->position = {position.x-(size/2), position.y - (1*(size/4))};
        
    }
    if (secondInNode != NULL){
        secondInNode->draw();
        secondInNode->position = {position.x-(size/2), position.y + (1*(size/4))};
        //secondInNode->position = {position.x-(position.x - boundingBox.getLeft()), boundingBox.getTop()+2*(size/3)};
    }
    if (outNode != NULL){
        outNode->draw();
        outNode->position = {position.x+(size/2), position.y};
    }
}

void Block::resizeBounds(float resize){
    boundingBox = ofRectangle((position.x-size/2)*resize, (position.y-size/2)*resize, size*resize, size*resize);
    if (firstInNode != NULL){
        firstInNode->resizeBounds(resize);
    }
    if (secondInNode != NULL){
        secondInNode->resizeBounds(resize);
    }
    if (outNode != NULL){
        outNode->resizeBounds(resize);
    }
}

void Block::intersectionCheck(float x, float y){
    ofPoint mouse = ofPoint(x, y);
    mouseIn = boundingBox.intersects(mouse,mouse);
    
    if (firstInNode != NULL){
        firstInNode->intersectionCheck(x, y);
    }
    if (secondInNode != NULL){
        secondInNode->intersectionCheck(x, y);
    }
    if (outNode != NULL){
        outNode->intersectionCheck(x, y);
    }

}
//should get rid of the extra 1s to the left of the amount of bits for the level in which these blocks exist
unsigned int Block::clearValues(unsigned int value){
    return value%((unsigned int)std::powf(2.0f, (float)bits));
}

