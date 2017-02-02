#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

// ------------------
// Currents:Cinder
//
// this example is partially based on cinder image guide
// https://libcinder.org/docs/guides/cinder-images/index.html
//
// for simply implementing shaders
// https://github.com/paulhoux/Cinder-Samples/tree/master/SimpleShader
//
// ------------------

using namespace ci;
using namespace ci::app;
using namespace std;

class ImageUsageApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    void twirl(Surface8u *surface, Area area, float maxAngle);
    // useful function to place a texture, scale is preset so you dont have to fill in this arg everytime
    Rectf getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale = glm::vec2(1.f, 1.f));
    
    gl::TextureRef      mTexture;
    
    ci::Surface8u       mSurface;
    ci::Surface8u       mSurfaceBW;
    ci::Surface8u       mSurfaceTwirl;
    
    gl::TextureRef      mTexFromSurface;
    gl::TextureRef      mTexBWFromSurface;
    gl::TextureRef      mTexTwirlFromSurface;
    gl::TextureRef      mTexClouds;
    
    float               mWidth;
    float               mHeight;
    gl::GlslProgRef     mShader;
};

void ImageUsageApp::setup()
{
    mWidth = 400.f;
    mHeight = 300.f;
    
    ci::app::setWindowSize(glm::vec2(1280.f, 720.f));
    
    // try catch usage here to prevent app from breaking
    try {
        // loadAsset will go asset folder
        // loadResources will go resource folder
        // loadImage will return image source
        mTexture = gl::Texture::create( loadImage( loadAsset( "balloons.jpg" ) ) );
        
        mSurface = loadImage(ci::app::loadAsset("balloons.jpg"));
        mSurfaceBW = mSurface.clone();
        mSurfaceTwirl = mSurface.clone();
        
        mTexClouds = gl::Texture::create( loadImage( loadAsset( "clouds.jpg" ) ) );
        
        // load and compile the shader
        mShader = gl::GlslProg::create( loadAsset( "shader.vert" ), loadAsset( "shader.frag" ) );
        
    } catch (exception& e) {
        // standard cinder method of printing stuff
        ci::app::console() << e.what() << std::endl;
    }
    
    // surface manipulations
    ci::Surface::Iter iter = mSurface.getIter(mSurface.getBounds());
    while(iter.line()){
        while(iter.pixel()){
            iter.r() = 255.f - iter.r();
            iter.g() = 255.f - iter.g();
            iter.b() = 255.f - iter.b();
        }
    }
    
    // surface manipulations (b + w)
    // please try this your self first
    ci::Surface::Iter iterBW = mSurfaceBW.getIter(mSurfaceBW.getBounds());
    while(iterBW.line()){
        while(iterBW.pixel()){
            float averageOfThisPixel = (iterBW.r() + iterBW.g() + iterBW.b()) / 3.f;
            iterBW.r() = averageOfThisPixel;
            iterBW.g() = averageOfThisPixel;
            iterBW.b() = averageOfThisPixel;
        }
    }
    
    // apply twirl to surface
    twirl(&mSurfaceTwirl, mSurfaceTwirl.getBounds(), 10.f);

    
}

void ImageUsageApp::twirl(Surface8u *surface, Area area, float maxAngle)
{
    // clone the surface, or any changes make to *surface will affect directly on the variable
    ci::Surface8u inputSurface = surface->clone();
    
    ci::Surface::Iter inputIter(inputSurface.getIter());
    ci::Surface::Iter outputIter(surface->getIter(area));
    
    // get max radius. usually diagnal distance
    float maxDistance = ci::length((glm::vec2)area.getSize());
    
    glm::vec2 mid = (area.getUL() + area.getLR()) / 2;
    
    
    while( inputIter.line() && outputIter.line() ) {
        while( inputIter.pixel() && outputIter.pixel() ) {
            // getting the current pixel position, and get the distance between it and image center
            glm::vec2 current = (glm::vec2)inputIter.getPos() - mid;
            // get length of a vec2
            float r = length(current);
            
            float twirlAngle = r / maxDistance * maxAngle;
            float angle = atan2(current.x, current.y);
            glm::vec2 outSameple(r * cos( angle + twirlAngle  ), r * sin( angle + twirlAngle ));
            glm::vec2 out = outSameple - current;
            outputIter.r() = inputIter.rClamped( out.x, out.y );
            outputIter.g() = inputIter.gClamped( out.x, out.y );
            outputIter.b() = inputIter.bClamped( out.x, out.y );

        }
    }
}

Rectf ImageUsageApp::getRectf(glm::vec2 startingPoint, glm::vec2 size, glm::vec2 scale)
{
    return Rectf(startingPoint.x, startingPoint.y, (size.x + startingPoint.x) * scale.x, (size.y + startingPoint.y) * scale.y);
}

void ImageUsageApp::mouseDown( MouseEvent event )
{
    
}

void ImageUsageApp::update()
{
    
}

void ImageUsageApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );

    gl::ScopedGlslProg shader( mShader );
    mShader->uniform( "tex0", 0 );
    mShader->uniform( "tex1", 1 );
    
    // set size manually
    gl::draw(mTexture, Rectf(0.f + 10.f, 0.f + 10.f, mWidth + 10.f, mHeight + 10.f));
    
    // set depending on size
    // Rectf imageRect = Rectf(mTexture->getBounds());
    // gl::draw(mTexture, imageRect);
    
    // easy function created by yourself
    gl::draw(mTexture, getRectf(glm::vec2(mWidth + 20.f, 10.f), glm::vec2(mWidth, mHeight)));
    
    // getting texture from surface
    mTexFromSurface = gl::Texture::create(mSurface);
    gl::draw(mTexFromSurface, getRectf(glm::vec2(mWidth * 2.f + 30.f, 10.f), glm::vec2(mWidth, mHeight)));
    
    // getting texture from surface
    mTexBWFromSurface = gl::Texture::create(mSurfaceBW);
    gl::draw(mTexBWFromSurface, getRectf(glm::vec2(10.f, mHeight + 20.f), glm::vec2(mWidth, mHeight)));
    
    // getting texture from surface
       mTexTwirlFromSurface = gl::Texture::create(mSurfaceTwirl);
    gl::draw(mTexTwirlFromSurface, getRectf(glm::vec2(mWidth + 20.f, mHeight + 20.f), glm::vec2(mWidth, mHeight)));
    
    // bind the textures
    gl::ScopedTextureBind tex0( mTexClouds, (uint8_t)0 );
    gl::ScopedTextureBind tex1( mTexture, (uint8_t)1 );
    
    gl::drawSolidRect(getRectf(glm::vec2(mWidth * 2.f + 30.f, mHeight + 20.f), glm::vec2(mWidth, mHeight)));
    
}

CINDER_APP( ImageUsageApp, RendererGl )
