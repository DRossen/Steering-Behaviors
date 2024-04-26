#pragma once
#include "SteeringOutput.h"
#include "Kinematic.h"
#include "SteeringTypes.h"

class WorldInterface;

namespace Tga
{
	class DebugDrawer;
}

class ISteering
{
	friend class SteeringController;
	friend class SteeringManager;

public:
	ISteering(Kinematic& aUserData) : character(aUserData) {}
	~ISteering() {}
	virtual SteeringOutput GetSteering(WorldInterface& aWorld) = 0;
	virtual void SetTarget(Kinematic& aTarget) { target = aTarget; };

protected:
	Kinematic target;
	Kinematic& character;
};