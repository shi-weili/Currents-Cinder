//
//  Toggle.cpp
//  PoSceneTest
//
//  Created by Luobin Wang on 3/28/17.
//
//

#include "Toggle.h"

ToggleRef Toggle::create(float length, float radius, ci::Color bgColor,ci::Color bgActiveColor, ci::Color toggleColor){
    ToggleRef ref = std::shared_ptr<Toggle>(new Toggle());
    ref->setup(length, radius, bgColor, bgActiveColor, toggleColor);
    return ref;
}

Toggle::Toggle()
:mRadius(0.f)
,mLength(0.f)
,mBgColor(ci::Color::white())
,mToggleColor(ci::Color::white())
,mIsActivated(false)
{
    
}

void Toggle::setup(float length, float radius, ci::Color bgColor, ci::Color bgActiveColor, ci::Color toggleColor)
{
    
    mLength = length;
    mRadius = radius;
    mBgColor = bgColor;
    mToggleColor = toggleColor;
    mBgActiveColor = bgActiveColor;
    mAnimationTime = 0.5f;
    
    mInactivePosition = glm::vec2(0.f);
    mActivePosition = glm::vec2(mRadius * 2.f + mLength, 0.f);
    
    // Combined function so esier to know the structure
    addBackground();
    addToggleCircle();
    
    //	Connect to mouse events
    getSignal(po::scene::MouseEvent::DOWN_INSIDE).connect(std::bind(&Toggle::onMouseEvent, this, std::placeholders::_1));
    getSignal(po::scene::MouseEvent::UP_INSIDE).connect(std::bind(&Toggle::onMouseEvent, this, std::placeholders::_1));
    getSignal(po::scene::MouseEvent::UP).connect(std::bind(&Toggle::onMouseEvent, this, std::placeholders::_1));
}

void Toggle::onMouseEvent(po::scene::MouseEvent &event)
{
    switch (event.getType()) {
        case po::scene::MouseEvent::DOWN_INSIDE:
            mIsActivated = !mIsActivated;
            if (mIsActivated){
                
                // Color transition
                ci::app::timeline().apply(&mBgCircleRight->getFillColorAnim(), mBgActiveColor, mAnimationTime, ci::EaseOutExpo());
                ci::app::timeline().apply(&mBgRect->getFillColorAnim(), mBgActiveColor, mAnimationTime, ci::EaseOutExpo());
                ci::app::timeline().apply(&mBgCircleLeft->getFillColorAnim(), mBgActiveColor, mAnimationTime, ci::EaseOutExpo());

                ci::app::timeline().apply(&mToggleCircle->getPositionAnim(), mActivePosition, mAnimationTime, ci::EaseOutExpo());

                mToggleStateChangeSignal.emit(true);
            }else{
                ci::app::timeline().apply(&mBgCircleRight->getFillColorAnim(), mBgColor, mAnimationTime, ci::EaseOutExpo());
                ci::app::timeline().apply(&mBgRect->getFillColorAnim(), mBgColor, mAnimationTime, ci::EaseOutExpo());
                ci::app::timeline().apply(&mBgCircleLeft->getFillColorAnim(), mBgColor, mAnimationTime, ci::EaseOutExpo());
                
                ci::app::timeline().apply(&mToggleCircle->getPositionAnim(), mInactivePosition, mAnimationTime, ci::EaseOutExpo());

                mToggleStateChangeSignal.emit(false);
            }
            break;
        case po::scene::MouseEvent::UP_INSIDE:

            break;
        case po::scene::MouseEvent::UP:
 
            break;
        default:
            break;
    }
}


void Toggle::addBackground()
{
    mBgCircleLeft = po::scene::Shape::createCircle(mRadius * 2.f);
    mBgCircleRight = po::scene::Shape::createCircle(mRadius * 2.f);
    mBgRect = po::scene::Shape::createRect(mRadius * 2.f + mLength, mRadius * 2.f);
    
    mBgCircleLeft->setPosition(glm::vec2(0.f));
    mBgRect->setPosition(glm::vec2(mRadius, 0.f));
    mBgCircleRight->setPosition(glm::vec2(mRadius * 2.f + mLength, 0.f));
    
    mBgCircleRight->setFillColor(mBgColor);
    mBgRect->setFillColor(mBgColor);
    mBgCircleLeft->setFillColor(mBgColor);
    
    addChild(mBgCircleLeft);
    addChild(mBgRect);
    addChild(mBgCircleRight);
}


void Toggle::addToggleCircle()
{
    mToggleCircle = po::scene::Shape::createCircle(mRadius * 2.f);
    mToggleCircle->setFillColor(mToggleColor);
    addChild(mToggleCircle);

}


