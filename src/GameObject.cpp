//
//  GameObject.cpp
//  ctrl-shift-bits
//
//  Created by Jake on 06/03/2017.
//
//

#include "GameObject.hpp"

GameObject::GameObject(float x, float y, unsigned long ID){
    position = {x, y};
    //not exclusively unique
    uniqueID = ID;
}

GameObject::~GameObject(){
    
}