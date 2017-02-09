#include "ParticleSystem.h"

#include "cinder/Rand.h"
ParticleSystem::ParticleSystem()
{
    // define how many particles you wnat
	mParticleNum = 500;
    // we dont want to initialize at same pos, so random range
	mRange = 10.f;
    // reduce repulsion
	mRepulsionFactor = 0.05f;
    // randomize system clock
	ci::Rand::randomize();
	for (int i = 0; i < mParticleNum; i++)
	{
        // push particles into array
		Particle singleParticle(ci::app::getWindowCenter() + glm::vec2(ci::randFloat(-mRange, mRange), ci::randFloat(-mRange, mRange)));
		mParticles.push_back(singleParticle);
	}
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::repulseFrom(glm::vec2 position)
{
    // repulse function
	for (auto& p : mParticles){
		float distanceDiff = ci::length(p.getPosition() - position);
		if (distanceDiff < 20.f){
			glm::vec2 repulsion = (p.getPosition() - position) * mRepulsionFactor;
			p.applyForce(repulsion);
		}
	}

}

void ParticleSystem::bounceFromeEdge()
{
	for (auto& p : mParticles){
        // define reaction when hit wall
		if (p.getPosition().x <= 0.f || p.getPosition().x >= ci::app::getWindowWidth()){
			p.bounceForce(0.95, false);
		}

		if (p.getPosition().y <= 0.f || p.getPosition().y >= ci::app::getWindowHeight()){
			p.bounceForce(0.95, true);
		}
	}
}

void ParticleSystem::update()
{
	bounceFromeEdge();

	for (int i = 0; i < mParticles.size(); i++){
		for (int j = 0; j < mParticles.size(); j++){
			if (i == j) continue;
			// repel from each other
			float distanceDiff = ci::length(mParticles[i].getPosition() - mParticles[j].getPosition());
			if (distanceDiff < 5.f){
				glm::vec2 repulsion = (mParticles[i].getPosition() - mParticles[j].getPosition()) * mRepulsionFactor;
				mParticles[i].applyForce(repulsion);
			}
		}
	}

	for (auto& p : mParticles){
		p.update();
	}
}


void ParticleSystem::draw()
{
	for (auto& p : mParticles){
		p.draw();
	}
}



