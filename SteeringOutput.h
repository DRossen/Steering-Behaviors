#pragma once
#include <tge/math/vector2.h>

struct SteeringOutput
{
	Tga::Vector2f linear = { 0,0 };
	float angular = 0;

    void operator+=(SteeringOutput other) {
        linear += other.linear;
        angular += other.angular;
    }

    SteeringOutput operator*(float aScalar) {
        SteeringOutput newValue;

        newValue.linear.x = linear.x * aScalar;
        newValue.linear.y = linear.y * aScalar;
        newValue.angular = angular * aScalar;

        return newValue;
    }
};