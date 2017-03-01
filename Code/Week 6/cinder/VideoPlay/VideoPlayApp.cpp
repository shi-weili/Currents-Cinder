#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
#include "cinder/qtime/QuickTimeGl.h"

using namespace ci;
using namespace ci::app;
using namespace std;



class VideoPlayApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    void getPath();
    void loadVideo();
    
    ci::gl::TextureRef      mFrameTexture;
    ci::qtime::MovieGlRef   mMovie;
    fs::path                mMoviePath;
    
};

void VideoPlayApp::getPath()
{
    try {
        mMoviePath = ci::app::getAssetPath("fingers.mov");
    } catch (exception& e) {
        ci::app::console() << e.what() << std::endl;
    }
}

void VideoPlayApp::loadVideo()
{
    try {
        mMovie = qtime::MovieGl::create( mMoviePath );
        mMovie->setLoop();
        mMovie->play();
    }
    catch( exception& e ) {
        ci::app::console() << e.what() << std::endl;
        mMovie.reset();
    }
}

void VideoPlayApp::setup()
{
    getPath();
    loadVideo();
}

void VideoPlayApp::mouseDown( MouseEvent event )
{
}

void VideoPlayApp::update()
{
    if(mMovie){
        mFrameTexture = mMovie->getTexture();
    }
}

void VideoPlayApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    if(mFrameTexture){
        Rectf centeredRect = Rectf( mFrameTexture->getBounds() ).getCenteredFit( getWindowBounds(), true );
        //Rectf centeredRect = Rectf( mFrameTexture->getBounds() ).getCenteredFill( getWindowBounds(), true );

        gl::draw( mFrameTexture, centeredRect );
    }
}

CINDER_APP( VideoPlayApp, RendererGl )
