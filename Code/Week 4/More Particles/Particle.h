//
//  Particle.hpp
//  MoreParticles
//
//  Created by Luobin Wang on 2/13/17.
//
//

#pragma once
// this is for visual studio
#include <memory>

class Particle;

typedef std::shared_ptr<Particle> ParticleRef;

class Particle {
public:
    static ParticleRef create(glm::vec2 position, float lifespan, glm::vec2 acceleration);
    glm::vec2 getPosition(){return mPosition;}
    // getters
    float getTimerleft();
    float getLifespan(){return mLifespan;};
    void update();
    // apply force, we dont have
    void applyForce(glm::vec2 force);
    ~Particle();
private:
    Particle();
    // have your setup function inline with your smart pointer constructor
    void setup(glm::vec2 position, float lifespan, glm::vec2 acceleration);
    
    // declare all the variables
    glm::vec2 mPosition;
    float     mFriction;
    float     mLifespan;
    glm::vec2 mVelocity;
    glm::vec2 mAcceleration;
    
    ci::Timer mTimer;
};
