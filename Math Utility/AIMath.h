#pragma once
#define PI 3.14159265359f

class Kinematic;

namespace AIMath
{
	// Returns a value from 0 to 1
	float RandomBinomial();

	// Returns a rotation (0-360) as a normalized direction
	Tga::Vector2f GetRotationVec(float aRotation);

	// Returns a rotation between -PI and PI
	float MapToRange(float aRotation, float aMin = PI, float aMax = PI);

	float DegreeToRadian(float aDegreeAngle);

	// Takes in a position and a dot representing 0 - 1;
	bool WithinVision(Kinematic& aUser, Tga::Vector2f aTarget, float aDot);

	Tga::Vector2f RotateVector(const Tga::Vector2f& v, float angle);

	// Used to draw debug lines for the cone of vision
	void GetConeVectors(const Tga::Vector2f& facing, float dotProduct, Tga::Vector2f& outLeft, Tga::Vector2f& outRight);
}