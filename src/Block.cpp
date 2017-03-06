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
}

//should get rid of the extra 1s to the left of the amount of bits for the level in which these blocks exist
unsigned int Block::clearValues(unsigned int value){
    return value%((unsigned int)std::powf(2.0f, (float)bits));
}