#include <math.h>
#include <GL/glut.h>

#include "SceneBuilder.h"
#include "../Particle/Particle.h"

namespace SceneGenerator
{
    void SceneBuilder::DrawRedParticle(Particle particle)
    {
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
            glTranslated(particle.GetX(), particle.GetY(), particle.GetZ());
            glutSolidSphere(particle.GetSize(), particle.GetVerticalSlices(), particle.GetHorizontalSlices());
        glPopMatrix();
    }
    
    void SceneBuilder::DrawBounds()
    {
        glColor3f(0.0, 0.0, 0.0);
        glPushMatrix();
            glBegin(GL_LINES); //Begin quadrilateral coordinates
            //Trapezoid
            glVertex3f(-2.7f, -2.0f, -5.0f);
            glVertex3f(2.7f, -2.0f, -5.0f);
            
            glVertex3f(2.7f, -2.0f, -5.0f);
            glVertex3f(2.7f, 2.0f, -5.0f);
            
            glVertex3f(2.7f, 2.0f, -5.0f);
            glVertex3f(-2.7f, 2.0f, -5.0f);
            
            glVertex3f(-2.7f, 2.0f, -5.0f);
            glVertex3f(-2.7f, -2.0f, -5.0f);
            glEnd(); //End quadrilateral coordinates
        glPopMatrix();
    }
    
    void SceneBuilder::BuildScene(Particle particle)
    {
        this->DrawRedParticle(particle);
    }
}
