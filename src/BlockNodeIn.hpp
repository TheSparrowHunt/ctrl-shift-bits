//
//  BlockNodeIn.hpp
//  ctrl-shift-bits
//
//  Created by Jake on 07/03/2017.
//
//

#ifndef BlockNodeIn_hpp
#define BlockNodeIn_hpp

#include <stdio.h>
#include "ofMain.h"
#include "BlockNode.hpp"

class BlockNodeIn : public BlockNode{
public:
    BlockNodeIn(float x, float y, unsigned long ID);
    ~BlockNodeIn();
    void childDraw();
};
#endif /* BlockNodeIn_hpp */
