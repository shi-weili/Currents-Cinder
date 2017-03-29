#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "poScene.h"
#include "poShape.h"

#include "Toggle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class PoSceneTestApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    void onToggleStateChange(bool state);
    
    // Declare scene first
    po::scene::SceneRef mScene;
    
    // Then we have node container, node container can have multiple nodes
    po::scene::NodeContainerRef mNodeContainer;
    
    // Declare toggle which is an node container
    ToggleRef mToggle;
    
    // Background shape
    po::scene::ShapeRef mBackgroundShape;
    
    // Color for background
    ci::Color mNightColor = ci::Color::hex(0x331651);
    ci::Color mDayColor = ci::Color::hex(0xf6fc4f);
    float mAnimationTime = 0.5f;

};

void PoSceneTestApp::setup()
{
    // The node container here is the main container of everything, add it to scene to draw and update them
    mNodeContainer = po::scene::NodeContainer::create();
    mScene = po::scene::Scene::create(mNodeContainer);
    
    // Background shape
    glm::vec2 backgroundSize = ci::app::getWindowSize();
    mBackgroundShape = po::scene::Shape::createRect(backgroundSize.x, backgroundSize.y );
    mBackgroundShape->setFillColor(mNightColor);
    mNodeContainer->addChild(mBackgroundShape);
    
    // Test the setup by drawing a rect
    po::scene::ShapeRef rect = po::scene::Shape::createRect(100.f, 100.f);
    
    // A shpe is a node, it can be added to a node container (for example mNodeContainer)
    mNodeContainer->addChild(rect);
    
    // You can do a lot to a shape view, customize its location, color or assign texture
    // Set position
    rect->setPosition(ci::app::getWindowCenter());
    
    // Draw bound so you know the anchor point and how it is aligned
    rect->setDrawBounds(false);
    
    // Assign aligment
    rect->setAlignment(po::scene::Alignment::CENTER_CENTER);
    
    rect->setAlpha(0.f);
    
    // Toggle
    mToggle = Toggle::create(10.f, 30.f, ci::Color(0.2f, 0.1f, 0.1f), ci::Color(0.5f, 0.5f, 0.1f), ci::Color::gray(0.8f));
    mToggle->setAlignment(po::scene::Alignment::CENTER_CENTER);
    mToggle->setPosition(ci::app::getWindowCenter());
    mNodeContainer->addChild(mToggle);
    
    // Connect signals
    mToggle->getToggleStateChangeSignal().connect(std::bind(&PoSceneTestApp::onToggleStateChange, this, std::placeholders::_1));
    
}

void PoSceneTestApp::mouseDown( MouseEvent event )
{
}

void PoSceneTestApp::onToggleStateChange(bool state)
{
    if(state){
        ci::app::timeline().apply(&mBackgroundShape->getFillColorAnim(), mDayColor, mAnimationTime, ci::EaseOutExpo());
    }else{
        ci::app::timeline().apply(&mBackgroundShape->getFillColorAnim(), mNightColor, mAnimationTime, ci::EaseOutExpo());
    }
}

void PoSceneTestApp::update()
{
    mScene->update();
}

void PoSceneTestApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mScene->draw();
}

CINDER_APP( PoSceneTestApp, RendererGl(RendererGl::Options().msaa( 8 )) )
