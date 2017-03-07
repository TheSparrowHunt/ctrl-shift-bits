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
#include <math.h>


class Block : public GameObject{
public:
    //constructor
    Block(float x, float y, unsigned long uniqueID, std::shared_ptr<ofTrueTypeFont> _font, float _size, unsigned int _bits);
    
    //virtual destructor for chilren
    virtual ~Block();
    
    //adds size and some test to Display and number of in and out nodes
    float size;
    std::shared_ptr<ofTrueTypeFont> font;
    std::string displayText;
    
    unsigned int inNodes;
    unsigned int outNodes;
    
    //vector of block inputs and block outputs
    Block* firstIn;
    Block* secondIn;
    std::vector<Block*> outs;
    
    //outvalue for the next Block
    unsigned int outValue;
    
    //clearing extra values
    unsigned int clearValues(unsigned int value);
    
    //bits for this level
    unsigned int bits;
    protected:
    //virtual function for draw, children of this object will have this.
    //ready to inherit on the next level
    virtual void draw()=0;
    
    virtual void behaviour()=0;
};

#endif /* Block_hpp */
