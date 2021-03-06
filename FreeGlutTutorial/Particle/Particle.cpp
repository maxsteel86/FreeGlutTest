
#include <cstring>
#include "Particle.h"
#include "../MotionVectors/MotionVector.h"
using namespace ParticleMotionVector;

namespace Particles
{
    Particle::Particle(float size, int vSlices, int hSlices, MotionVector position)
    {
        this->_size = size;
        this->_horizontalSlices = hSlices;
        this->_verticalSlices = vSlices;
		this->_position = position;
    }
    
    float Particle::GetSize()
    {
        return this->_size;
    }
    
    int Particle::GetVerticalSlices()
    {
        return this->_verticalSlices;
    }
    
    int Particle::GetHorizontalSlices()
    {
        return this->_horizontalSlices;
    }

	float Particle::GetX()
	{
		return this->_position.GetX();
	}

	float Particle::GetY()
	{
		return this->_position.GetY();
	}

	float Particle::GetZ()
	{
		return this->_position.GetZ();
	}

	void Particle::UpdateParticle()
	{
		this->_position.SetX(_position.GetX() + 0.0005);
		this->_position.SetY(_position.GetY() + 0.0005);
	}
}
