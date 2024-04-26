#include "stdafx.h"
#include "Align.h"
#include "AIMath.h"
#include "WorldInterface.h"

Align::Align(Kinematic& aCharacter) : ISteering(aCharacter) {}
Align::~Align() {}

SteeringOutput Align::GetSteering(WorldInterface& aWorld)
{
	SteeringOutput result;

	float rotation = target.orientation - character.orientation;
	rotation = AIMath::MapToRange(rotation, -PI, PI);

	float rotationSize = abs(rotation);

	if (rotationSize < targetRadius) { 
		return result; 
	}

	float adjustedRotation = maxRotation * (rotationSize / slowRadius);
	float targetRotation = rotationSize > slowRadius ? maxRotation : adjustedRotation;

	targetRotation *= rotation / rotationSize;

	result.angular = targetRotation - character.rotation;
	result.angular /= timeToTarget * aWorld.deltaTime;

	float angularAcceleration = abs(result.angular);

	if (angularAcceleration > maxAngularAcceleration)
	{
		result.angular /= angularAcceleration;
		result.angular *= maxAngularAcceleration;
	}

	result.linear = 0;
	return result;
}
