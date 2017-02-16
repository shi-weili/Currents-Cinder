#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MoreParticlesApp : public App {
  public:
	void setup() override;
    void mouseMove( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    // have all value that is not going to change in here
    const int	NUM_PARTICLES = 50;
    const float  RANDOM_RANGE = 10.f;
    const float  RANDOM_FORCE_RANGE = 2.f;
    const float LIFE_SPAN = 3.f;
    
    // declare your value
    std::vector<ParticleRef> mParticles;
    Perlin					 mPerlin;
    float                    mTime;
    float                    mFrequency = 1 / 200.0f;
};

void MoreParticlesApp::setup()
{

}

void MoreParticlesApp::mouseMove( MouseEvent event )
{
// this is the part if you want your particle to repel
// take note of how to do normalized value
    
//    for (auto& p: mParticles){
//        glm::vec2 diff = (glm::vec2)event.getPos() - p->getPosition();
//        float lengthDiff = length(diff);
//        if (lengthDiff < 5.f) {
//            p->applyForce(glm::normalize(diff));
//        }
//    }
    
    // init particle whenver there's particle movement
    for (int i = 0; i < NUM_PARTICLES; i++){
        mParticles.push_back(Particle::create((glm::vec2)event.getPos() + glm::vec2(ci::randFloat(-RANDOM_RANGE, RANDOM_RANGE), ci::randFloat(-RANDOM_RANGE, RANDOM_RANGE)), LIFE_SPAN, glm::vec2(ci::randFloat(-RANDOM_FORCE_RANGE, RANDOM_FORCE_RANGE), ci::randFloat(-RANDOM_FORCE_RANGE, RANDOM_FORCE_RANGE))));
    }
    
    
}

void MoreParticlesApp::update()
{
    
    mTime = ci::app::getElapsedSeconds() * 100.f;
    
    for (auto& p: mParticles){
        p->update();
    }
    
    // remove particle if it has passed its lifespan
    for (auto p = mParticles.begin(); p != mParticles.end();)
    {
        if ( (*p)->getTimerleft() < 0) {
            p = mParticles.erase(p);
        } else {
            ++p;
        }
       
    }
    
    
    
}

void MoreParticlesApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::ScopedBlendAdditive blend;
    
    // gl_lines for drawing lines, gl_points for only points, when you draw gl_lines, within context, you will be able to connect dots
    ci::gl::begin(GL_LINES);
    for (auto& p: mParticles){
        ci::gl::color(ci::ColorA(p->getTimerleft()/p->getLifespan() ,0.3f, 1.f - p->getTimerleft()/p->getLifespan(), p->getTimerleft()/p->getLifespan()));
        // get perlin value based on position
        vec3 norm = mPerlin.dfBm( vec3( p->getPosition().x, p->getPosition().y, mTime ) * mFrequency ) * 20.0f;
        vec2 flowForce = normalize( vec2( norm.x, norm.y ) ) * 0.1f;
        p->applyForce(flowForce);
        gl::vertex(p->getPosition());
        gl::vertex(p->getPosition() + glm::vec2(norm.x, norm.y) * 0.3f);
    }
    ci::gl::end();
    gl::drawString( to_string( getAverageFps() ), ci::vec2( 20.f, 20.f ), ci::Color( 0.5f, 0.5f, 0.5f ) );
    gl::drawString( "particle count: " + std::to_string(mParticles.size()) , ci::vec2( 20.f, 30.f ), ci::Color( 0.5f, 0.5f, 0.5f ) );
    
    
// uncomment this part to see the perlin flow field
    
//    for( int y = 0; y < getWindowHeight(); y += 20 ) {
//        for( int x = 0; x < getWindowWidth(); x += 20 ) {
//           ci::gl::begin(GL_LINES);
//            vec3 norm = mPerlin.dfBm( vec3( x, y, mTime ) * mFrequency ) * 20.0f;
//            
//            
//            if( length2( vec2( norm.x, norm.y ) ) > 0 ){
//                 gl::vertex(x, y);
//                gl::vertex(vec2( x, y ) + normalize( vec2( norm.x, norm.y ) ) * 20.0f);
//            }
//            ci::gl::end();
//
//        }
//    }

}

CINDER_APP( MoreParticlesApp, RendererGl )
