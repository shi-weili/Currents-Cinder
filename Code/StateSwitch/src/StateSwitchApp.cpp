#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poScene.h"
#include "poNodeContainer.h"
#include "poShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class StateSwitchApp : public App {
  public:
    
    enum States{
        BLANK,
        CIRCLE,
        RECT
    };
    

	void setup() override;
	void mouseDown( MouseEvent event ) override;
    void keyDown( KeyEvent event ) override;
    void mouseMove( MouseEvent event ) override;

	void update() override;
	void draw() override;
    
    void onStateChange(States state);
    
    po::scene::SceneRef mScene;
    po::scene::NodeContainerRef  mContainer;
    
    
    po::scene::NodeContainerRef  mNodeContainerA;
    po::scene::NodeContainerRef  mNodeContainerB;
    
    
    States mCurrentState;
};

void StateSwitchApp::setup()
{
    
    mContainer = po::scene::NodeContainer::create();
    
    mScene = po::scene::Scene::create(mContainer);
    
    
    mNodeContainerA = po::scene::NodeContainer::create();
    mNodeContainerB = po::scene::NodeContainer::create();
    mContainer->addChild(mNodeContainerA);
    mContainer->addChild(mNodeContainerB);
    
    po::scene::ShapeRef rect = po::scene::Shape::createRect(200.f, 200.f);
    rect->setPosition(glm::vec2(0.f));
    
    po::scene::ShapeRef circle = po::scene::Shape::createCircle(100.f);
    circle->setPosition(ci::app::getWindowCenter());
    circle->setAlignment(po::scene::Alignment::CENTER_CENTER);
    
    mNodeContainerA->addChild(rect);
    mNodeContainerB->addChild(circle);
    
    mNodeContainerA->setAlpha(0.f);
    mNodeContainerB->setAlpha(0.f);
    
    mCurrentState = States::BLANK;

}

void StateSwitchApp::onStateChange(StateSwitchApp::States state)
{
    mCurrentState = state;
    switch (mCurrentState) {
        case States::BLANK:
            mNodeContainerA->setAlpha(0.f);
            mNodeContainerB->setAlpha(0.f);
            break;
        case States::CIRCLE:
            mNodeContainerA->setAlpha(1.f);
            mNodeContainerB->setAlpha(0.f);
            break;
        case States::RECT:
            mNodeContainerA->setAlpha(0.f);
            mNodeContainerB->setAlpha(1.f);
            break;
        default:
            break;
    }
}

void StateSwitchApp::mouseDown( MouseEvent event )
{

    onStateChange(States::BLANK);

}

void StateSwitchApp::keyDown( KeyEvent event )
{
    onStateChange(States::RECT);
}

void StateSwitchApp::mouseMove( MouseEvent event )
{

    onStateChange(States::CIRCLE);

}

void StateSwitchApp::update()
{
    mScene->update();
}

void StateSwitchApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mScene->draw();
}

CINDER_APP( StateSwitchApp, RendererGl )
