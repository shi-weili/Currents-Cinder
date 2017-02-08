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
	glm::vec2 getPosition(){ return position; }
private:
	
	float	  friction;
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;

};

