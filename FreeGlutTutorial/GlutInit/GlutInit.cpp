#include <cstdlib>
#include <GL/glut.h>
#include "GlutInit.h"

namespace GlutInitialisation
{
    GlutInit::GlutInit()
    {
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    }
    
    void GlutInit::InitialiseWindow(int width, int height)
    {
		glutInitWindowPosition(100, 100);
        glutInitWindowSize(width, height);
        
		glutCreateWindow("Particles");
	}
    
    void GlutInit::ChangeSize(int w, int h)
    {
        // Prevent a divide by zero, when window is too short
        // (you cant make a window of zero width).
        if (h == 0)
        {
            h = 1;
        }
        
        float ratio =  w * 1.0 / h;

        // Use the Projection Matrix
        glMatrixMode(GL_PROJECTION);

        // Reset Matrix
        glLoadIdentity();

        // Set the viewport to be the entire window
        glViewport(0, 0, w, h);

        // Set the correct perspective.
        gluPerspective(45.0f, ratio, 0.1f, 100.0f);

        // Get Back to the Modelview
        glMatrixMode(GL_MODELVIEW);
    }
    
    void GlutInit::HandleSpecialKey(int key)
    {
        switch (key)
        {
            case GLUT_KEY_UP:
                std::exit(0);
                break;
        }
    }
    
    void GlutInit::HandleRegularKey(unsigned char key)
    {
		switch (key)
		{
			case 27:	// ESCAPE
			std::exit(0);
			break;
		}
	}
}
