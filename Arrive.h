#pragma once
#include "ISteering.h"

class Arrive : public ISteering
{
public:
	Arrive(Kinematic& aUser);
	~Arrive();
	SteeringOutput GetSteering(WorldInterface& aWorld) override;

private:
	float targetRadius = 50.0f;
	float slowRadius = 150.0f;
	float timeToTarget = 0.15f;
};