#include "Particle.h"

Particle::Particle(glm::vec2 startPosition)
{
    // initialize variables
	mPosition = startPosition;
	mVelocity = glm::vec2(0.f, 0.f);
	mAcceleration = glm::vec2(0.f, 0.f);
	mFriction = 0.95f;
}

Particle::~Particle()
{
}

void Particle::update()
{
    // add acc to vel
	mVelocity += mAcceleration;
    // apply mFriction
	mVelocity *= mFriction;
    // apply to mPositions
	mPosition += mVelocity;
    // reset accelration
	mAcceleration *= 0.f;
}

void Particle::bounceForce(float damping, bool isVertical){
    // damping when hit corner
	if (isVertical){
		mVelocity.y = -mVelocity.y * damping;
	}
	else{
		mVelocity.x = -mVelocity.x * damping;
	}
}

void Particle::applyForce(glm::vec2 force)
{
    // apply force to mAcceleration
	mAcceleration += force;
}

void Particle::draw()
{
    // fancy color
    float value = ci::length(abs(mVelocity)) * 100.f;
    glm::clamp(value, 0.f, 1.f);
	ci::gl::color(ci::Color(value, 0.f, 0.7f));
    // draw cricle
    ci::gl::drawSolidCircle(mPosition, 2.f, 4);
}
