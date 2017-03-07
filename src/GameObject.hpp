//
//  GameObject.hpp
//  ctrl-shift-bits
//
//  Created by Jake on 06/03/2017.
//
//  inspired by Marco Gillies's ShooterInheritanceExample
//  available at: https://github.com/marcogillies/ShooterInheritanceExample

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "ofMain.h"

class GameObject{
    public:
    //constructor
    GameObject(float x, float y, unsigned long ID);
    unsigned long uniqueID;
    
    //virtual destructor for chilren
    virtual ~GameObject();
    protected:
    //variable to test for when an object has completed what it needs to do and can be removed
    bool finished = false;
    
    //position vec2f
    ofVec2f position;
    
    //virtual function for draw, children of this object will have this.
    virtual void draw()=0;
};

#endif /* GameObject_hpp */
