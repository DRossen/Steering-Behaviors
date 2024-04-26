#pragma once
#include "ISteering.h"

class Cohesion : public ISteering
{
public:
	Cohesion(Kinematic& aUser);
	~Cohesion();
	SteeringOutput GetSteering(WorldInterface& aWorld);

private:
	float threshold = 180.f;
	float coneDot = 0.2f;
};

