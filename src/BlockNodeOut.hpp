//
//  BlockNodeOut.hpp
//  ctrl-shift-bits
//
//  Created by Jake on 07/03/2017.
//
//

#ifndef BlockNodeOut_hpp
#define BlockNodeOut_hpp

#include <stdio.h>
#include "ofMain.h"
#include "BlockNode.hpp"

class BlockNodeOut : public BlockNode{
public:
    BlockNodeOut(float x, float y, unsigned long ID);
    ~BlockNodeOut();
    void childDraw();
private:
    void drawLine(ofPoint end);
};

#endif /* BlockNodeOut_hpp */
