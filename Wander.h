#pragma once
#include "Face.h"

class Wander : public Face
{
public:
	Wander(Kinematic& aUser);
	~Wander();
	SteeringOutput GetSteering(WorldInterface& aWorld) override;

protected:
	float wanderOrientation = 0;
	float wanderOffset = 125.0f;
	float wanderRadius = 50.0f;
	float wanderRate = 5.0f;
};