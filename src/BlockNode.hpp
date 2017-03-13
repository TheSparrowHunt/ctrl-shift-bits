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
class Block;
class BlockNode : public GameObject{
public:
    BlockNode(float x, float y, unsigned long ID);
public:
    float width = 10.0f;
    float height = 10.0f;
    virtual ~BlockNode();
    
    Block* parent;
    std::vector<BlockNode*> connections;
    ofPoint activeConnect;
    bool activeConnection;
    void resizeBounds(float resize);
    void intersectionCheck(float x, float y);
    void draw();
    bool mouseIn;
    bool intersectionCheckOut(float x, float y);
protected:
    virtual void childDraw()=0;
};

#endif /* BlockNode_hpp */
