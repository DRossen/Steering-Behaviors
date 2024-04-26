#include "Wander.h"
#include "AIMath.h"
#include "WorldInterface.h"

Wander::Wander(Kinematic& aCharacter) : Face(aCharacter) {}
Wander::~Wander() {}

SteeringOutput Wander::GetSteering(WorldInterface& aWorld)
{
	SteeringOutput result;
	Kinematic newTarget;

	wanderOrientation += (AIMath::RandomBinomial() - 0.4f) * wanderRate * aWorld.deltaTime;

	newTarget.orientation = wanderOrientation + character.orientation;

	newTarget.position = character.position + wanderOffset * AIMath::GetRotationVec(character.orientation);

	newTarget.position += AIMath::GetRotationVec(character.orientation) * wanderRadius;

	Face::faceTarget = newTarget;
	result = Face::GetSteering(aWorld);
	result.linear = character.maxAcceleration * AIMath::GetRotationVec(character.orientation);

	if (result.linear.Length() > character.maxAcceleration)
	{
		result.linear.Normalize();
		result.linear *= character.maxAcceleration;
	}

	return result;
}
