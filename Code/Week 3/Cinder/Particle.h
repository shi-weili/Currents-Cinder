#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
class Particle
{
public:
	Particle(glm::vec2 startPosition);
	~Particle();
	void update();
	void draw();
	void applyForce(glm::vec2 force);
	void bounceForce(float damping, bool isVertical);
	glm::vec2 getPosition(){ return mPosition; }
private:
	
	float	  mFriction;
	glm::vec2 mPosition;
	glm::vec2 mVelocity;
	glm::vec2 mAcceleration;

};

