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

class BlockNode : public GameObject{
public:
    BlockNode(float x, float y, unsigned long ID);
public:
    float width = 10.0f;
    float height = 10.0f;
    virtual ~BlockNode();
    
    std::vector<BlockNode*> connections;
    void resizeBounds(float resize);
    void intersectionCheck(float x, float y);
    void draw();
    bool mouseIn;
protected:
    virtual void childDraw()=0;
};

#endif /* BlockNode_hpp */
