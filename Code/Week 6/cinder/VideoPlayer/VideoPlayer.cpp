//
//  VideoPlayer.cpp
//  VideoPlayer
//
//  Created by Luobin Wang on 2/28/17.
//
//

#include "VideoPlayer.h"

VideoPlayerRef VideoPlayer::create(){
    VideoPlayerRef ref = std::shared_ptr<VideoPlayer>(new VideoPlayer());
    ref->setup();
    return ref;
}

VideoPlayer::VideoPlayer()
{
}

void VideoPlayer::setup()
{
    
}
void VideoPlayer::setPath(std::string path)
{
    try {
        mMoviePath = ci::app::getAssetPath("fingers.mov");
    } catch (std::exception& e) {
        ci::app::console() << e.what() << std::endl;
    }
}

void VideoPlayer::loadVideo(std::string videoPath)
{
    setPath(videoPath);
    
    try {
        mMovie = ci::qtime::MovieGl::create( mMoviePath );
        mMovie->setLoop();
        mMovie->play();
        mMovie->getEndedSignal().connect(std::bind(&VideoPlayer::onVideoEnded, this));
    }
    catch( std::exception& e ) {
        ci::app::console() << e.what() << std::endl;
        mMovie.reset();
    }
}

void VideoPlayer::update()
{
    if(mMovie){
        mFrameTexture = mMovie->getTexture();
    }
}

void VideoPlayer::play()
{
    if(mMovie){
        mMovie->play();
    }
}

void VideoPlayer::stop()
{
    if(mMovie){
        mMovie->stop();
    }
}

void VideoPlayer::setLoop(bool bIsLoop)
{
    if(mMovie){
        mMovie->setLoop(bIsLoop);
    }
}

void VideoPlayer::onVideoEnded()
{
    mVideoEndedSignal.emit();
}

void VideoPlayer::draw()
{
    if(mFrameTexture){
        ci::Rectf centeredRect = ci::Rectf( mFrameTexture->getBounds() ).getCenteredFit(ci::app::getWindowBounds(), true );
        //Rectf centeredRect = Rectf( mFrameTexture->getBounds() ).getCenteredFill( getWindowBounds(), true );
        
        ci::gl::draw( mFrameTexture, centeredRect );
    }
}


