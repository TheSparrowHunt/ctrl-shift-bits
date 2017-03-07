//
//  ShiftLeft.hpp
//  ctrl-shift-bits
//
//  Created by Jake on 06/03/2017.
//
//

#ifndef ShiftLeft_hpp
#define ShiftLeft_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Block.hpp"

class ShiftLeft : public Block{
public:
    //constructor
    ShiftLeft(float x, float y, unsigned long uniqueID, std::shared_ptr<ofTrueTypeFont> _font, float _size, unsigned int _bits);
    
    //destructor
    ~ShiftLeft();
    
    //non-virtual
    //void draw();
    void behaviour();
    
    
};
#endif /* ShiftLeft_hpp */
