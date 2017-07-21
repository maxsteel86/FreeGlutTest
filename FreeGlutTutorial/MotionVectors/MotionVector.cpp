#include "MotionVector.h"

namespace ParticleMotionVector
{
	MotionVector::MotionVector()
	{
		_x = 0;
		_y = 0;
		_z = 0;
	}

	MotionVector::MotionVector(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	float MotionVector::GetX()
	{
		return _x;
	}

	float MotionVector::GetY()
	{
		return _y;
	}

	float MotionVector::GetZ()
	{
		return _z;
	}

	void MotionVector::SetX(float x)
	{
		_x = x;
	}

	void MotionVector::SetY(float y)
	{
		_y = y;
	}

	void MotionVector::SetZ(float z)
	{
		_z = z;
	}
}
