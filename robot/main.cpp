#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* GLUT callback Handlers 184.8*/
unsigned int timer_speed = 16;
bool timer_enabled = true;
#define MENU_TIMER_START 1
#define MENU_TIMER_STOP 2
#define MENU_EXIT 3
#define move_1 4
#define move_2 5
#define move_3 6
float hand_angle = 0;
float left_hand_angle = 0;
int g_cursor_x = 0;
int g_cursor_y = 0;
// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float rx=0.0f,rz=5.0f,ry = 1.f;
float w = 0.0f,s = 0.0f;
bool move_state_1 = false,move_state_2 =  false,move_state_3= false;
float head_angle = 0.0f;
float waving_hand =0.0f;
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 65.0, ar, 1.0, 100.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
void head()
{
    glPushMatrix();
    {
            if(move_state_1)
            {
                glTranslated(2.875,2.875,0);
                 glRotated(head_angle,0,0,1);
                glTranslated(-2.875,-2.875,0);
            }


        glTranslated(1.75,1.75,2);


        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,1.0f);//top
            glVertex3f(2.0f,2.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,2.0f,-5.0f);
            glVertex3f(0.0f,0.0f,-5.0f);
            glVertex3f(2.0f,0.0f,-5.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3ub(50,255,50);//side 1 green
            glVertex3f(2.0f,0.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-5.0f);
            glVertex3f(0.0f,0.0f,-7.0f);
            glVertex3f(2.0f,0.0f,-7.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3ub(50,50,50);//side 2 dim gray
            glVertex3f(2.0f,2.0f,-5.0f);//counter-clock
            glVertex3f(2.0f,0.0f,-5.0f);
            glVertex3f(2.0f,0.0f,-7.0f);
            glVertex3f(2.0f,2.0f,-7.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3ub(0,255,0);//side 3 pure green
            glVertex3f(0.0f,2.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,2.0f,-7.0f);
            glVertex3f(2.0f,2.0f,-7.0f);
            glVertex3f(2.0f,2.0f,-5.0f);
        }
        glEnd();

//side 4

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,1.0f);//blue
            glVertex3f(0.0f,0.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,2.0f,-5.0f);
            glVertex3f(0.0f,2.0f,-7.0f);
            glVertex3f(0.0f,0.0f,-7.0f);
        }
        glEnd();
//back
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(2.0f,2.0f,-7.0f);//counter-clock
            glVertex3f(0.0f,2.0f,-7.0f);
            glVertex3f(0.0f,0.0f,-7.0f);
            glVertex3f(2.0f,0.0f,-7.0f);
        }
        glEnd();
    }
    glPopMatrix();
}
void axis()
{
    glPushMatrix();
    {
        glColor3d(1.0f,1.0f,1.0f);
        glutSolidSphere(0.5,60,60);
    }
    glPopMatrix();
}
void left_lowerhand()
{
    glPushMatrix();
    {
        glTranslated(0,0,-3.5);
        glColor3d(0.0f,0.0f,1.0f);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-4.0f);
            glVertex3f(1.5f,0.0f,-4.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.7f,1.0f,1.0f);//white
            glVertex3f(0.0f,-1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,0.0f);
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,1.0f,0.0f);//green
            glVertex3f(0.0f,-1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,0.0f);
            glVertex3f(1.5f,-1.5f,-4.0f);
            glVertex3f(0.0f,-1.5f,-4.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//yellow
            glVertex3f(1.5f,-1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,-4.0f);
            glVertex3f(1.5f,0.0f,-4.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,-1.5f,0.0f);
            glVertex3f(0.0f,-1.5f,-4.0f);
            glVertex3f(0.0f,0.0f,-4.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,1.0f);//purple
            glVertex3f(0.0f,-1.5f,-4.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,-4.0f);
            glVertex3f(1.5f,0.0f,-4.0f);
            glVertex3f(0.0f,0.0f,-4.0f);
        }
        glEnd();
    }


    glPopMatrix();
}
void left_upperhand()
{
    glPushMatrix();
    {

        glTranslated(2.0f,0.0f,-6.0f);
        if(move_state_1)
        glRotated(left_hand_angle,0,1,0);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-3.0f);
            glVertex3f(1.5f,0.0f,-3.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(1.5f,-1.5f,0.0f);
            glVertex3f(0.0f,-1.5f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,1.0f,0.0f);//Green
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-3.0f);
            glVertex3f(0.0f,-1.5f,-3.0f);
            glVertex3f(0.0f,-1.5f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,1.0f);//blue
            glVertex3f(1.5f,0.0f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,-3.0f);
            glVertex3f(1.5f,-1.5f,-3.0f);
            glVertex3f(1.5f,-1.5f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(1.5f,-1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,-1.5f,-0.0f);
            glVertex3f(0.0f,-1.5f,-3.0f);
            glVertex3f(1.5f,-1.5f,-3.0f);
        }
        glEnd();

        glPushMatrix();
        {
            glTranslated(0.5,-0.75,-3.25);
            if(move_state_1)
            glRotated(left_hand_angle/2+10,0,1.0,0);
            axis();
            glTranslated(-0.5,0.75,3);
            left_lowerhand();
        }
        glPopMatrix();

    }
    glPopMatrix();


}
void right_lowerhand()
{
    glPushMatrix();
    {
        glTranslated(0,0,-3.5);
        glColor3d(0.0f,0.0f,1.0f);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-4.0f);
            glVertex3f(1.5f,0.0f,-4.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.7f,1.0f,1.0f);//white
            glVertex3f(0.0f,-1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,0.0f);
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,1.0f,0.0f);//green
            glVertex3f(0.0f,-1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,0.0f);
            glVertex3f(1.5f,-1.5f,-4.0f);
            glVertex3f(0.0f,-1.5f,-4.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//yellow
            glVertex3f(1.5f,-1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,-4.0f);
            glVertex3f(1.5f,0.0f,-4.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,-1.5f,0.0f);
            glVertex3f(0.0f,-1.5f,-4.0f);
            glVertex3f(0.0f,0.0f,-4.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,1.0f);//purple
            glVertex3f(0.0f,-1.5f,-4.0f);//counter-clock
            glVertex3f(1.5f,-1.5f,-4.0f);
            glVertex3f(1.5f,0.0f,-4.0f);
            glVertex3f(0.0f,0.0f,-4.0f);
        }
        glEnd();
    }


    glPopMatrix();
}
void right_upperhand()
{
    glPushMatrix();
    {

        glTranslated(2.0f,6.5f,-6.0f);
        if(move_state_1)
        glRotated(hand_angle,0,1,0);
        else if (move_state_3)
        {
            glRotated(150.0f,0,1,0);
        }
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-3.0f);
            glVertex3f(1.5f,0.0f,-3.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(1.5f,-1.5f,0.0f);
            glVertex3f(0.0f,-1.5f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,1.0f,0.0f);//Green
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-3.0f);
            glVertex3f(0.0f,-1.5f,-3.0f);
            glVertex3f(0.0f,-1.5f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,1.0f);//blue
            glVertex3f(1.5f,0.0f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,-3.0f);
            glVertex3f(1.5f,-1.5f,-3.0f);
            glVertex3f(1.5f,-1.5f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(1.5f,-1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,-1.5f,-0.0f);
            glVertex3f(0.0f,-1.5f,-3.0f);
            glVertex3f(1.5f,-1.5f,-3.0f);
        }
        glEnd();

        glPushMatrix();
        {
            glTranslated(0.5,-0.75,-3.25);
            if(move_state_1)
            glRotated(hand_angle/2+10,0,1.0,0);
            else if(move_state_3)
            {
                glRotated(waving_hand,1,0,0);
            }
            axis();
            glTranslated(-0.5,0.75,3);
            right_lowerhand();
        }
        glPopMatrix();


    }
    glPopMatrix();
}
void left_lowerleg()
{
    glPushMatrix();
    {
        glScaled(1,1,1.5);
        glTranslated(-0.75,-0.75,-0.25);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//purple
            glVertex3f(1.5f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();
//side 2
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.5f,0.5f);//pink
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
        }
        glEnd();
//side 3
        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(0.0f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,0.0f);
        }
        glEnd();
//side 4
        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,0.5f);//dark blue
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
        }
        glEnd();
//back
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(1.5f,1.5f,-2.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();
    }
    glPopMatrix();
}
void left_upperleg()
{
    glPushMatrix();
    {
        glTranslated(1.5,1,-15);
        if(move_state_1)
        glRotated(left_hand_angle,0,1,0);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//purple
            glVertex3f(1.5f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();
//side 2
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.5f,0.5f);//pink
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
        }
        glEnd();
//side 3
        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(0.0f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,0.0f);
        }
        glEnd();
//side 4
        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,0.5f);//dark blue
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
        }
        glEnd();
//back
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(1.5f,1.5f,-2.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();

        glPushMatrix();
        {
            glTranslated(0.75,0.75,-2.25);
            axis();
            left_lowerleg();
        }
        glPopMatrix();
    }
    glPopMatrix();


}
void right_lowerleg()
{
    glPushMatrix();
    {
        glScaled(1,1,1.5);
        glTranslated(-0.75,-0.75,-0.25);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();

        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//purple
            glVertex3f(1.5f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();
//side 2
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.5f,0.5f);//pink
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
        }
        glEnd();
//side 3
        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(0.0f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,0.0f);
        }
        glEnd();
//side 4
        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,0.5f);//dark blue
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
        }
        glEnd();
//back
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(1.5f,1.5f,-2.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();
    }
    glPopMatrix();
}
void right_upperleg()
{
    glPushMatrix();
    {
        glTranslated(1.5,3,-15);
        if(move_state_1)
        glRotated(hand_angle,0,1,0);
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,0.0f);
        }
        glEnd();
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//purple
            glVertex3f(1.5f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();
//side 2
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.5f,0.5f);//pink
            glVertex3f(1.5f,1.5f,0.0f);//counter-clock
            glVertex3f(1.5f,0.0f,0.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
        }
        glEnd();
//side 3
        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(0.0f,1.5f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,-2.0f);
            glVertex3f(1.5f,1.5f,0.0f);
        }
        glEnd();
//side 4
        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,0.5f);//dark blue
            glVertex3f(0.0f,0.0f,0.0f);//counter-clock
            glVertex3f(0.0f,1.5f,0.0f);
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
        }
        glEnd();
//back
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(1.5f,1.5f,-2.0f);//counter-clock
            glVertex3f(0.0f,1.5f,-2.0f);
            glVertex3f(0.0f,0.0f,-2.0f);
            glVertex3f(1.5f,0.0f,-2.0f);
        }
        glEnd();

        glPushMatrix();
        {
            glTranslated(0.75,0.75,-2.25);
            axis();
            right_lowerleg();
        }
        glPopMatrix();
    }
    glPopMatrix();
}
void torso()
{
    glPolygonMode(GL_BACK,GL_LINE);//to see perspective

   // glEnable(GL_LIGHTING);
   // glEnable(GL_LIGHT0);
    glPushMatrix();
    {//front
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.0f,0.0f);//red
            glVertex3f(5.0f,5.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,5.0f,-5.0f);
            glVertex3f(0.0f,0.0f,-5.0f);
            glVertex3f(5.0f,0.0f,-5.0f);
        }
        glEnd();
//side 1
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,0.0f);//purple
            glVertex3f(5.0f,0.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,0.0f,-5.0f);
            glVertex3f(0.0f,0.0f,-15.0f);
            glVertex3f(5.0f,0.0f,-15.0f);
        }
        glEnd();
//side 2
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,0.5f,0.5f);//pink
            glVertex3f(5.0f,5.0f,-5.0f);//counter-clock
            glVertex3f(5.0f,0.0f,-5.0f);
            glVertex3f(5.0f,0.0f,-15.0f);
            glVertex3f(5.0f,5.0f,-15.0f);
        }
        glEnd();
//side 3
        glBegin(GL_QUADS);
        {
            glColor3f(0.5f,0.5f,0.5f);//gray
            glVertex3f(0.0f,5.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,5.0f,-15.0f);
            glVertex3f(5.0f,5.0f,-15.0f);
            glVertex3f(5.0f,5.0f,-5.0f);
        }
        glEnd();
//side 4
        glBegin(GL_QUADS);
        {
            glColor3f(0.0f,0.0f,0.5f);//dark blue
            glVertex3f(0.0f,0.0f,-5.0f);//counter-clock
            glVertex3f(0.0f,5.0f,-5.0f);
            glVertex3f(0.0f,5.0f,-15.0f);
            glVertex3f(0.0f,0.0f,-15.0f);
        }
        glEnd();
//back
        glBegin(GL_QUADS);
        {
            glColor3f(1.0f,1.0f,1.0f);//white
            glVertex3f(5.0f,5.0f,-15.0f);//counter-clock
            glVertex3f(0.0f,5.0f,-15.0f);
            glVertex3f(0.0f,0.0f,-15.0f);
            glVertex3f(5.0f,0.0f,-15.0f);
        }
        glEnd();
    }
    glPopMatrix();
//end of torso

    head();
    left_upperhand();
    right_upperhand();
    left_upperleg();
    right_upperleg();

}
void lighting()
{
    GLfloat lightParam[] = { 1.0, 1.0, 1.0, 0.0 };    //Light param
    GLfloat ambient0[]={0.25, 0.25, 0.25, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);    //Set light to environment light
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);//Set shader smooth mode
}
float moving = 0;
int mov_flag=0;
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    lighting();
    glLoadIdentity();
	gluLookAt(	rx,ry, rz,rx+lx, ry,rz+lz,0.0f, 1.0f,  0.0f);
    glRotated(w,0,1,0);
    glRotated(s,1,0,0);
    if(move_state_1)
    {
        mov_flag ++;
        moving -=1.0f;
        glTranslated(moving,0,0);
    }
    else if(move_state_2 && mov_flag)
    {
        mov_flag --;
        moving +=1.0f;
        glTranslated(-moving,0,0);
    }
    else if(move_state_3)
    {

    }
    torso();
    glutSwapBuffers();
}
static void key(unsigned char key, int x, int y)
{
   // printf("Key %c is pressed at (%d, %d)\n", key, x, y);

	switch (key)
	{
        case 'w':
        w +=10.0f;
        break;
        case 's':
        w -=10.0f;
        break;
        case 'a':
        s +=10.0f;
        break;
        case 'd':
        s-=10.0f;
        break;
	    printf("key:%d\n",key);
	}

    glutPostRedisplay();
}
void motion(int x,int y)
{
    if(g_cursor_y<y)
    {
        g_cursor_y = y;
        ry+=0.1f;
    }
    else
    {
        g_cursor_y = y;
        ry-=0.1f;
    }

    if(g_cursor_x<x)
    {
         g_cursor_x = x;
         rx-=0.1f;
    }
    else
    {
         g_cursor_x = x;
         rx+=0.1f;
    }
}
void processSpecialKeys(int key, int xx, int yy)
{
	float fraction = 0.1f;
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			rx += lx * fraction;
			rz += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			rx -= lx * fraction;
			rz -= lz * fraction;
			break;
	}
}
void wheelfunc(int wheel, int direction, int x, int y)
{
    if(direction>0)
    {
			rx += lx * 0.3;
			rz += lz * 0.3;
    }
    else
    {
			rx -= lx * 0.3;
			rz -= lz * 0.3;
    }
}
void My_Mouse(int button, int state, int x, int y)
{
    if (button==GLUT_LEFT_BUTTON)
    {

        if (state==GLUT_UP)
        {
            g_cursor_x = x;
            g_cursor_y = y;
        }
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
            g_cursor_x = x;
            g_cursor_y = y;
    }
    glutPostRedisplay();
}
int flag = 0;
int wflag = 0;
void My_Timer(int val)
{
	glutPostRedisplay();
	if(timer_enabled)
	{
	    if(move_state_1)
        {
            head_angle +=5.0f;
            if(hand_angle<30 && !flag)
            {
                flag = 0;
                hand_angle +=5;
                left_hand_angle -=5;
            }
            else if( hand_angle>-30)
            {
                flag = 1;
                hand_angle -=5;
                left_hand_angle +=5;
            }
            else
            {
                flag = 0;
            }
        }
        else if(move_state_2)
        {
            hand_angle = 0;
            left_hand_angle = 0;
            head_angle = 0;
            waving_hand = 0;
        }
        else if(move_state_3)
        {
            if(waving_hand<30 && !wflag)
            {
                wflag = 0;
                waving_hand +=5;
            }
            else if( waving_hand>-30)
            {
                wflag = 1;
                waving_hand -=5;
            }
            else
            {
                wflag = 0;
            }
        }
		glutTimerFunc(100, My_Timer, val);
	}
}
void My_Menu(int id)
{
	switch(id)
	{
	case MENU_TIMER_START:
		if(!timer_enabled)
		{
			timer_enabled = true;
			glutTimerFunc(timer_speed, My_Timer, 0);
		}
		break;
	case MENU_TIMER_STOP:
		timer_enabled = false;
		break;
	case MENU_EXIT:
		exit(0);
		break;
    case move_1:
        move_state_1 = true;
        move_state_2 = false;
        move_state_3 = false;
        break;
    case move_2:
        move_state_1 = false;
        move_state_2 = true;
        move_state_3 = false;
        break;
    case move_3:
        move_state_1 = false;
        move_state_2 = false;
        move_state_3 = true;
        break;
	default:
	    move_state_1 = false;
	    move_state_2 = false;
        move_state_3 = false;
		break;
	}
}
void my_menu()
{
    int menu_main = glutCreateMenu(My_Menu);
	int menu_timer = glutCreateMenu(My_Menu);
    int mov = glutCreateMenu(My_Menu);

	glutSetMenu(menu_main);
	glutAddSubMenu("Timer", menu_timer);
	glutAddSubMenu("Move",mov);
	glutAddMenuEntry("Exit", MENU_EXIT);

	glutSetMenu(menu_timer);
	glutAddMenuEntry("Start", MENU_TIMER_START);
	glutAddMenuEntry("Stop", MENU_TIMER_STOP);

    glutSetMenu(mov);
	glutAddMenuEntry("Move 1", move_1);
	glutAddMenuEntry("Restart", move_2);
    glutAddMenuEntry("Hello",move_3);

	glutSetMenu(menu_main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT ROBOT");

    my_menu();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMouseFunc(My_Mouse);
    glutKeyboardFunc(key);
    glutSpecialFunc(processSpecialKeys);
    glutMotionFunc(motion);
    glutMouseWheelFunc(wheelfunc);
    glutTimerFunc(500,My_Timer,0);
    glClearColor(1.0,1.0,1.0,0);

	glEnable(GL_DEPTH_TEST);


    glutMainLoop();

    return EXIT_SUCCESS;
}
