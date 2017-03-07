//
//  BlockNode.hpp
//  ctrl-shift-bits
//
//  Created by Jake on 07/03/2017.
//
//

#ifndef BlockNode_hpp
#define BlockNode_hpp

#include <stdio.h>
#include "ofMain.h"
#include "GameObject.hpp"

class BlockNode : GameObject{
public:
    BlockNode(float x, float y, unsigned long ID);
    
    float width = 10.0f;
    float height = 10.0f;
    virtual ~BlockNode();
    
    void draw();
    
    void resizeBounds();
    
};

#endif /* BlockNode_hpp */
