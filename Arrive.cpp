#include "Arrive.h"
#include "WorldInterface.h"

Arrive::Arrive(Kinematic& aUser) : ISteering(aUser) {}
Arrive::~Arrive() {}

SteeringOutput Arrive::GetSteering(WorldInterface&)
{
    SteeringOutput result;
   
    Tga::Vector2f direction = target.position - character.position;
    float distance = direction.Length();

    if (distance < targetRadius) {
        character.velocity = {};
        return result; 
    }

    float targetSpeed = distance > slowRadius ? character.maxSpeed : character.maxSpeed * distance / slowRadius;

    Tga::Vector2f targetVelocity = direction.GetNormalized() * targetSpeed;

    result.linear = targetVelocity - character.velocity;
    result.linear /= timeToTarget;

    if (result.linear.Length() > character.maxAcceleration) {
        result.linear.Normalize();
        result.linear *= character.maxAcceleration;
    }

    result.angular = 0;
    return result;
}