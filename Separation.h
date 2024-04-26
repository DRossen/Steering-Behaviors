#pragma once
#include "ISteering.h"

class Separation : public ISteering
{
public:
	Separation(Kinematic& aUser);
	~Separation();
	SteeringOutput GetSteering(WorldInterface& aWorld) override;

protected:
	float threshold = 60.f;
};