#ifndef MOTION_VECTOR_H
#define MOTION_VECTOR_H

namespace ParticleMotionVector
{
	class MotionVector
	{
		private:
			float _x;
			float _y;
			float _z;
		public:
			MotionVector();
			MotionVector(float x, float y, float z);

			float GetX();
			float GetY();
			float GetZ();
			void SetX(float x);
			void SetY(float y);
			void SetZ(float z);
	};
}

#endif
