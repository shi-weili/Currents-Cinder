#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "VideoPlayer.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class VideoPlayerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    void onVideoEnded();
    
    VideoPlayerRef mPlayer;
    int            mPlayCount;
};

void VideoPlayerApp::setup()
{
    mPlayCount = 0;
    mPlayer = VideoPlayer::create();
    mPlayer->loadVideo("fingers.mov");
    mPlayer->getVideoEndedSignal().connect(std::bind(&VideoPlayerApp::onVideoEnded, this));
}

void VideoPlayerApp::mouseDown( MouseEvent event )
{
}

void VideoPlayerApp::onVideoEnded()
{
    ci::app::console() << "video has ended" << std::endl;
    mPlayCount += 1;
}

void VideoPlayerApp::update()
{
    mPlayer->update();
}

void VideoPlayerApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    mPlayer->draw();
    ci::gl::drawString(std::to_string(mPlayCount), glm::vec2(10.f, 10.f));
}

CINDER_APP( VideoPlayerApp, RendererGl )
