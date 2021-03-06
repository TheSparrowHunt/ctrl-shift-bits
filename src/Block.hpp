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
#include "BlockNodeIn.hpp"
#include "BlockNodeOut.hpp"

class Block : public GameObject{
public:
    //constructor
    Block(float x, float y, unsigned long uniqueID, std::shared_ptr<ofTrueTypeFont> _font, float _size, unsigned int _bits);
    
    //virtual destructor for children
    virtual ~Block();
    
    //adds size and some test to Display and number of in and out nodes
    float size;
    std::shared_ptr<ofTrueTypeFont> font;
    std::string displayText;
    
    //number of nodes, might be useful for the future
    unsigned int inNodes;
    unsigned int outNodes;
    
    //vector of block inputs and block outputs
    Block* firstIn;
    Block* secondIn;
    std::vector<Block*> outs;
    
    //blocks displaying the nodes for connection
    BlockNodeIn* firstInNode;
    BlockNodeIn* secondInNode;
    BlockNodeOut* outNode;
    
    //outvalue for the next Block, this is taken by the next block to perform its functions
    unsigned int outValue;
    
    //bits for this level
    unsigned int bits;
    
    //mouse
    bool mouseIn=false;
    
    void draw();
    
    //to resize the bounding boxes after scaling the screen
    void resizeBounds(float resize);
    void intersectionCheck(float x, float y);
    bool intersectionCheckOut(float x, float y);
    //clearing extra values
    unsigned int clearValues(unsigned int value);
    
    protected:
    //virtual function for behaviour, children of this object will have this.
    //ready to inherit on the next level
    virtual void behaviour()=0;
};

#endif /* Block_hpp */
