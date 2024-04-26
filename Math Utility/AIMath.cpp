#include "stdafx.h"
#include "AIMath.h"
#include "Kinematic.h"

// Not specific for AI but used solely by SteeringBehaviours in this project
namespace AIMath
{
	float RandomBinomial()
	{
		return (rand() % 100) / 100.f;
	}

	Tga::Vector2f GetRotationVec(float aRotation)
	{
		Tga::Vector2f direction = { std::cosf(aRotation), std::sinf(aRotation) };
		direction.Normalize();
		return direction;
	}

	float MapToRange(float aRotation, float aMin, float aMax)
	{
		while (aRotation <= aMin) {
			aRotation += 2 * aMax;
		}

		while (aRotation > aMax) {
			aRotation -= 2 * aMax;
		}

		return aRotation;
	}

	float DegreeToRadian(float aDegreeAngle)
	{
		return aDegreeAngle * 0.0174532925f;
	}

	bool WithinVision(Kinematic& aUser, Tga::Vector2f aTarget, float aDot)
	{
		Tga::Vector2f position = (aTarget - aUser.position).GetNormalized();
		Tga::Vector2f facing = { std::cosf(aUser.orientation), std::sinf(aUser.orientation) };
		facing.Normalize();

		return facing.Dot(position) >= aDot ? true : false;
	}

	Tga::Vector2f RotateVector(const Tga::Vector2f& v, float angle)
	{
		float cosA = std::cosf(angle);
		float sinA = std::sinf(angle);

		return {
			v.x * cosA - v.y * sinA,
			v.x * sinA + v.y * cosA
		};
	}

	void GetConeVectors(const Tga::Vector2f& facing, float dotProduct, Tga::Vector2f& outLeft, Tga::Vector2f& outRight)
	{
		dotProduct = std::max(-1.0f, std::min(1.0f, dotProduct));

		float angle = std::acosf(dotProduct);

		outLeft = RotateVector(facing, angle);
		outRight = RotateVector(facing, -angle);

		outLeft.Normalize();
		outRight.Normalize();
	}
}