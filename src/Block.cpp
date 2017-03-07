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
    //default these to NULL
    firstIn = NULL;
    secondIn = NULL;
    firstInNode = NULL;
    secondInNode = NULL;
    outNode = NULL;
}

Block::~Block(){
    //this could get complicated when I get on to deleting Blocks
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
            //draws the String in a scalable format the - font->getSize()/6 fixes a weird bug
            font->drawStringAsShapes(displayText, -font->stringWidth(displayText)/2 - font->getSize()/6, font->stringHeight(displayText)/2);
    
        ofPopStyle();
    ofPopMatrix();
    //if the Nodes aren't empty update and draw them
    if (firstInNode != NULL){
        firstInNode->position = {position.x-(size/2), position.y - (1*(size/4))};
        firstInNode->draw();
        
    }
    if (secondInNode != NULL){
        secondInNode->position = {position.x-(size/2), position.y + (1*(size/4))};
        secondInNode->draw();
    }
    if (outNode != NULL){
        outNode->position = {position.x+(size/2), position.y};
        outNode->draw();
    }
}
//method to resize the bounding box in relation to the scaling
void Block::resizeBounds(float resize){
    
    //update
    boundingBox = ofRectangle((position.x-size/2)*resize, (position.y-size/2)*resize, size*resize, size*resize);
    
    //also resize the nodes, if they exist
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

//collision checking, roughly
void Block::intersectionCheck(float x, float y){
    ofPoint mouse = ofPoint(x, y);
    mouseIn = boundingBox.intersects(mouse,mouse);
    
    //same for the nodes
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

//collision checking from other classes
bool Block::intersectionCheckOut(float x, float y){
    ofPoint mouse = ofPoint(x, y);
    return boundingBox.intersects(mouse,mouse);
}
//should get rid of the extra 1s to the left of the amount of bits for the level in which these blocks exist
//TESTME:
unsigned int Block::clearValues(unsigned int value){
    return value%((unsigned int)std::powf(2.0f, (float)bits));
}

