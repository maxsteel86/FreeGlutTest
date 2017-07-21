#include <cstdlib>
#include <math.h>
#include <GL/glut.h>

#include "GlutInit/GlutInit.h"
#include "SceneBuilder/SceneBuilder.h"
#include "Particle/Particle.h"
#include "MotionVectors/MotionVector.h"

using namespace GlutInitialisation;
using namespace SceneGenerator;

GlutInit *initialiser = new GlutInit(800, 600);
SceneBuilder *sceneBuilder = new SceneBuilder();

void changeSize(int w, int h)
{
	initialiser->ChangeSize(w, h);
}

MotionVector position1(0.6, 0, -5);
MotionVector position2(-0.6, -0.5, -5);
Particle* p1 = new Particle(0.025, 30, 30, position1);
Particle* p2 = new Particle(0.025, 30, 30, position2);

void renderScene(void)
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	p1->UpdateParticle();
	p2->UpdateParticle();

    sceneBuilder->BuildScene(p1);
	sceneBuilder->BuildScene(p2);
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
