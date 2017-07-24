#include <cstdlib>
#include <math.h>
#include <vector>
#include <GL/glut.h>

#include "GlutInit/GlutInit.h"
#include "SceneBuilder/SceneBuilder.h"
#include "Particle/Particle.h"
#include "MotionVectors/MotionVector.h"

using namespace GlutInitialisation;
using namespace SceneGenerator;
using std::vector;

GlutInit *initialiser = new GlutInit(800, 600);
SceneBuilder *sceneBuilder = new SceneBuilder();
vector<Particle> particleCollection;

void changeSize(int w, int h)
{
	initialiser->ChangeSize(w, h);
}

void InitialiseParticles(int particleCount)
{
	particleCollection.reserve(particleCount);

	for(int i = 0; i < particleCount; i++)
	{
		int randX = rand() % (2 - (-2) + 1) + (-2);
		int randY = rand() % (2 - (-2) + 1) + (-2);

		MotionVector position(randX, randY, -5);
		Particle *particle = new Particle(0.025, 30, 30, position);
		particleCollection.push_back(*particle);
	}
}

void renderScene(void)
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	for(uint i = 0; i < particleCollection.size(); i++)
	{
		Particle *particle = &particleCollection[i];
		particle->UpdateParticle();

		sceneBuilder->BuildScene(particle);
	}

	sceneBuilder->DrawBounds();
	glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{
	initialiser->PressKey(key);
}

int main(int argc, char **argv)
{
	// init GLUT and create window
	glutInit(&argc, argv);
	glutCreateWindow("Particles");
    glutSpecialFunc(pressKey);

	InitialiseParticles(5);

    glClearColor(0.4, 0.4, 0.6, 1.0);
    // register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
