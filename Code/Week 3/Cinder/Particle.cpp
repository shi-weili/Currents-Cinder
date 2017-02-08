#include "Particle.h"

Particle::Particle(glm::vec2 startPosition)
{
    // initialize variables
	position = startPosition;
	velocity = glm::vec2(0.f, 0.f);
	acceleration = glm::vec2(0.f, 0.f);
	friction = 0.95f;
}

Particle::~Particle()
{
}

void Particle::update()
{
    // add acc to vel
	velocity += acceleration;
    // apply friction
	velocity *= friction;
    // apply to positions
	position += velocity;
    // reset accelration
	acceleration *= 0.f;
}

void Particle::bounceForce(float damping, bool isVertical){
    // damping when hit corner
	if (isVertical){
		velocity.y = -velocity.y * damping;
	}
	else{
		velocity.x = -velocity.x * damping;
	}
}

void Particle::applyForce(glm::vec2 force)
{
    // apply force to acceleration
	acceleration += force;
}

void Particle::draw()
{
    // fancy color
    float value = ci::length(abs(velocity)) * 100.f;
    glm::clamp(value, 0.f, 1.f);
	ci::gl::color(ci::Color(value, 0.f, 0.7f));
    // draw cricle
    ci::gl::drawSolidCircle(position, 2.f, 4);
}
