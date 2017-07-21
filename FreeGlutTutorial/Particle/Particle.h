
#ifndef PARTICLE_H
#define PARTICLE_H

#include "../MotionVectors/MotionVector.h"
using namespace ParticleMotionVector;

namespace Particles
{
    class Particle
    {
        private:
			MotionVector _position;

            float _size;
            int _horizontalSlices;
            int _verticalSlices;
        public:
            Particle(float size, int vSlices, int hSlices, MotionVector position);
            
            float GetSize();
            int GetVerticalSlices();
            int GetHorizontalSlices();
			float GetX();
			float GetY();
			float GetZ();

			void UpdateParticle();
    };
}

#endif
