//
//  Toggle.hpp
//  PoSceneTest
//
//  Created by Luobin Wang on 3/28/17.
//
//

#pragma once

#include "poNodeContainer.h"
#include "poShape.h"

#include "cinder/Signals.h"

class Toggle;
typedef std::shared_ptr<Toggle> ToggleRef;
typedef ci::signals::Signal<void(bool state)> ToggleStateChangeSignal;

// Toggle is a derived class of node container, so it has all the functiton as a node container
class Toggle : public po::scene::NodeContainer{
public:
    static ToggleRef create(float length, float radius, ci::Color bgColor, ci::Color bgActiveColor, ci::Color toggleColor);
    
    ToggleStateChangeSignal& getToggleStateChangeSignal(){return mToggleStateChangeSignal;}
    
private:
    Toggle();
    void setup(float length, float radius, ci::Color bgColor,ci::Color bgActiveColor, ci::Color toggleColor);
    void addBackground();
    void addToggleCircle();
    void onMouseEvent(po::scene::MouseEvent &event);
    
    // Our background shapes
    po::scene::ShapeRef mBgCircleLeft;
    po::scene::ShapeRef mBgCircleRight;
    po::scene::ShapeRef mBgRect;
    
    // Our toggle shape
    po::scene::ShapeRef mToggleCircle;
    
    // Variables
    float mRadius;
    float mLength;
    ci::Color mBgColor;
    ci::Color mBgActiveColor;
    ci::Color mToggleColor;
    
    glm::vec2 mInactivePosition;
    glm::vec2 mActivePosition;
    
    float mAnimationTime;
    
    // Signal
    ToggleStateChangeSignal mToggleStateChangeSignal;
    
    // Bool
    bool mIsActivated;
    
    
};
