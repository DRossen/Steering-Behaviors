#pragma once
#include "tge/math/vector2.h"
#include "SteeringOutput.h"
#include "AIMath.h"
#include <algorithm>

class Kinematic
{
public:
	Kinematic() {}
	~Kinematic() {}

	inline void Update(SteeringOutput aSteering, float aTimeDelta)
	{
		position += velocity * aTimeDelta;
		orientation += rotation * aTimeDelta;

		velocity += aSteering.linear * aTimeDelta;
		rotation += aSteering.angular * aTimeDelta;

		if (velocity.Length() > maxSpeed)
		{
			velocity.Normalize();
			velocity *= maxSpeed;
		}
	}

	Tga::Vector2f position = {};
	Tga::Vector2f velocity = {};
	float rotation = 0;
	float orientation = 0;
	float maxRotation = 0;
	float maxAcceleration = 0;
	float maxSpeed = 0;
};