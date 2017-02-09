#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "Particle.h"

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update();
	void draw();
	void repulseFrom(glm::vec2 position);
	
private:
	void bounceFromeEdge();

	int                     mParticleNum;
	std::vector<Particle>   mParticles;
	float			mRange;
	float			mRepulsionFactor;
};

