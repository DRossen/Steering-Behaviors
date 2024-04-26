#include "stdafx.h"
#include "Cohesion.h"
#include "WorldInterface.h"

Cohesion::Cohesion(Kinematic& aUser) : ISteering(aUser) {}
Cohesion::~Cohesion() {}

SteeringOutput Cohesion::GetSteering(WorldInterface& aWorld)
{
	SteeringOutput result;

	target.position = {};
	int count = 0;

	for (Kinematic* actor : aWorld.GetActors())
	{
		if (actor == &character) { continue; }

		float distance = (character.position - actor->position).Length();
		
		if (distance > threshold) continue;
		if (!AIMath::WithinVision(character, actor->position, coneDot)) continue;

		target.position += actor->position;
		count++;
	}

	if (count < 1) {
		return result; 
	}

	target.position /= static_cast<float>(count);

	float distance = (target.position - character.position).Length();
	float strength = character.maxAcceleration * (distance / threshold);

	result.linear = (target.position - character.position) * strength;

	if (result.linear.Length() > character.maxAcceleration)
	{
		result.linear.Normalize();
		result.linear *= character.maxAcceleration;
	}

	return result;
}