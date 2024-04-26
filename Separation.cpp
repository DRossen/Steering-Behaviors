#include "stdafx.h"
#include "Separation.h"
#include "WorldInterface.h"

Separation::Separation(Kinematic& aUser) : ISteering(aUser) {}
Separation::~Separation() {}

SteeringOutput Separation::GetSteering(WorldInterface& aWorld)
{
	SteeringOutput result;

	for (Kinematic* actor : aWorld.GetActors())
	{
		if (actor == &character) { continue; }
		Tga::Vector2f direction = character.position - actor->position;
		float distance = direction.Length();

		if (distance > threshold) { continue; }
		
		float strength = character.maxAcceleration * (threshold - distance) / threshold;
		
		direction.Normalize();
		result.linear += strength * direction;
	}

	if (result.linear.Length() > character.maxAcceleration)
	{
		result.linear.Normalize();
		result.linear *= character.maxAcceleration;
	}

	return result;
}