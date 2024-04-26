#pragma once
#include "ISteering.h"

class Align : public ISteering
{
public:
	Align(Kinematic& aUser);
	~Align();
	SteeringOutput GetSteering(WorldInterface& aWorld) override;

protected:
	float maxAngularAcceleration = 4.0f;
	float maxRotation = 2.0f;
	float slowRadius = 0.8f;
	float targetRadius = 0.017453f; // 1 degree
	float threshold = 300.f;
	float coneDot = 0.3f;
	float timeToTarget = 0.1f;
};