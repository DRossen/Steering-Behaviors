#pragma once
#include "Align.h"

class Face : public Align
{
public:
	Face(Kinematic& aUser);
	~Face();
	SteeringOutput GetSteering(WorldInterface& aWorld) override;
	virtual void SetTarget(Kinematic& aTarget) override { faceTarget = aTarget; };

protected:
	Kinematic faceTarget;
};