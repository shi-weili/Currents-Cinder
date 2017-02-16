//
//  Particle.cpp
//  MoreParticles
//
//  Created by Luobin Wang on 2/13/17.
//
//

#include "Particle.h"
#include "cinder/Rand.h"

ParticleRef Particle::create(glm::vec2 position, float lifespan, glm::vec2 acceleration)
{
    ParticleRef ref = std::shared_ptr<Particle>(new Particle());
    ref->setup(position, lifespan, acceleration);
    return ref;
}

Particle::Particle()
:mFriction(0.98)
,mVelocity(glm::vec2(0))
,mAcceleration(glm::vec2(0))
{
    
}

Particle::~Particle()
{
    mTimer.stop();
}

float Particle::getTimerleft()
{
    // calculating using the elapsed time and set limit
    return (mLifespan - mTimer.getSeconds());
}

void Particle::setup(glm::vec2 position, float lifespan, glm::vec2 acceleration)
{
    // init all the values
    mLifespan = lifespan;
    mPosition = position;
    mAcceleration  = acceleration;
    mVelocity += mAcceleration;
    mTimer.start();
}

void Particle::update()
{
    // we dont recet acceleration anymore since we are actually applying
    mVelocity *= mFriction;
    mPosition += mVelocity;

}

void Particle::applyForce(glm::vec2 force)
{
    mVelocity += force;
}
