#include "Face.h"
#include "WorldInterface.h"

Face::Face(Kinematic& aUser) : Align(aUser) {}
Face::~Face() {}

SteeringOutput Face::GetSteering(WorldInterface& aWorld)
{
	SteeringOutput result;

	Tga::Vector2f direction = (faceTarget.position - character.position);

	if (direction.LengthSqr() == 0) {
		return result;
	}

	Align::target.position = faceTarget.position;
	Align::target.orientation = atan2f(direction.y, direction.x);

	return Align::GetSteering(aWorld);
}
