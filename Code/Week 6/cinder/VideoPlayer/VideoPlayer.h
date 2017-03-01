//
//  VideoPlayer.hpp
//  VideoPlayer
//
//  Created by Luobin Wang on 2/28/17.
//
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
#include "cinder/qtime/QuickTimeGl.h"

class VideoPlayer;

typedef std::shared_ptr<VideoPlayer> VideoPlayerRef;
typedef ci::signals::Signal<void()> VideoEndedSignal;

class VideoPlayer{
public:
    static VideoPlayerRef create();
    void loadVideo(std::string videoPath);
    void update();
    void draw();
    void stop();
    void play();
    void setLoop(bool bIsLoop);
    void onVideoEnded();
    
    VideoEndedSignal& getVideoEndedSignal(){return mVideoEndedSignal;}
private:
    VideoPlayer();
    void setup();
    void setPath(std::string path);
    
    VideoEndedSignal        mVideoEndedSignal;
    
    ci::gl::TextureRef      mFrameTexture;
    ci::qtime::MovieGlRef   mMovie;
    ci::fs::path            mMoviePath;
    
};

