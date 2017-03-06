//
//  Block.hpp
//  ctrl-shift-bits
//
//  Created by Jake on 06/03/2017.
//
//
// inherits from GameObject

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include "ofMain.h"
#include "GameObject.hpp"


class Block : public GameObject{
public:
    //constructor
    Block(float x, float y, unsigned long uniqueID);
    
    //virtual destructor for chilren
    virtual ~Block();
    
    //adds size and some test to Display
    float size;
    std::string displayText;
    
    protected:
    //virtual function for draw, children of this object will have this.
    //ready to inheret on the next level
    virtual void draw();
};

#endif /* Block_hpp */
