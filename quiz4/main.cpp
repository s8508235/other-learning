/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include "GL/freeglut.h"
#include   "stdio.h"
#include <stdlib.h>
#define MENU_TIMER_START 1
#define MENU_TIMER_STOP 2
#define MENU_EXIT 3
bool timer_enabled = true;
bool case_1 = true, case_2 = false, case_3 = false ,case_4 = false;
/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

const GLfloat mat_bronze[] = {0.2125f,0.1275f, 0.054f,1.0f};

const GLfloat light_bronze_ambient[] = {0.2125f ,	0.1275f ,	0.054f, 1.0f };
const GLfloat light_bronze_diffuse[] = {0.714f ,	0.4284f ,	0.18144f, 1.0f};
const GLfloat light_bronze_specular[] = {0.393548f ,	0.271906f ,	0.166721f, 1.0f};

const GLfloat light_emerald_ambient[] = { 	0.0215f ,	0.1745f ,	0.0215f, 1.0f };
const GLfloat light_emerald_diffuse[] = {0.07568f ,	0.61424f ,	0.07568f, 1.0f};
const GLfloat light_emerald_specular[] = {0.633f 	,0.727811f 	,0.633f, 1.0f};
const GLfloat bronze_shinning = 0.2*128;
const GLfloat emerald_shinngin = 0.6;
GLfloat diffuse0[]={1.0,1.0,1.0, 1.0};
GLfloat ambient0[]={0.25, 0.25, 0.25,1.0};
GLfloat specular0[]={1.0,1.0,1.0, 1.0};
GLfloat light0_pos[]={10000.0,-10000.0,1000, 0.0};
GLfloat lightPos0[] = {0.0f, 300.00f, 1000.8f, 1.0};
GLfloat spot_direction[] = {-1,-1,-1};
GLint spot_expo = 3,spot_cutoff = 180;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 120.0f, 150.0f, 150.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
static void display(void)
{
    printf("%d %d %d %d\n",case_1,case_2,case_3,case_4);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   if(case_1)
   {
        glDisable(GL_LIGHT1);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient0);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
        glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
        glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.8);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   light_bronze_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   light_bronze_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  light_bronze_specular);
        glMaterialf(GL_FRONT, GL_SHININESS,    bronze_shinning);
        glEnable(GL_LIGHT0);
   }
    if(case_2)
    {
        glDisable(GL_LIGHT0);
        glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spot_direction);
        glLighti(GL_LIGHT1,GL_SPOT_EXPONENT,spot_expo);
        glLighti(GL_LIGHT1,GL_SPOT_CUTOFF,spot_cutoff);
        glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT1, GL_POSITION, light_position);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   light_emerald_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   light_emerald_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  light_emerald_specular);
        glMaterialf(GL_FRONT, GL_SHININESS,emerald_shinngin);

        glEnable(GL_LIGHT1);
    }
    if(case_3)
    {
        glDisable(GL_LIGHT1);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient0);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   light_bronze_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   light_bronze_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  light_bronze_specular);
        glMaterialf(GL_FRONT, GL_SHININESS,    bronze_shinning);
    }
    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glutSolidSphere(1,60,60);
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {printf("%c pressed!\n",key);
        case 'a':
            case_1 = true;
            case_2 = false;
            case_3 = false;
            case_4 = false;
            break;
        case 'b':
            case_1 = false;
            case_2 = true;
            case_3 = false;
            case_4 = false;
            break;
        case 'c':
            case_1 = false;
            case_2 = false;
            case_3 = true;
            case_4 = false;
            break;
        case 'd':
            case_1 = false;
            case_2 = false;
            case_3 = false;
            case_4 = true;
            break;
    }

    glutPostRedisplay();
}



/* Program entry point */
void My_Timer(int val)
{
    glutPostRedisplay();
    if(timer_enabled)
    {
        glutTimerFunc(100, My_Timer, val);
    }
glutPostRedisplay();

}
void My_Menu(int id)
{
    	switch (id)
        {
	case MENU_TIMER_START:
		if (!timer_enabled)
		{
			timer_enabled = true;
			glutTimerFunc(100, My_Timer, 0);
		}
		break;
	case MENU_TIMER_STOP:
		timer_enabled = false;
		break;
    default:
        break;
        }
}
void my_menu()
{
    int menu_main = glutCreateMenu(My_Menu);
	int menu_timer = glutCreateMenu(My_Menu);

	glutSetMenu(menu_main);
	glutAddSubMenu("Timer", menu_timer);
	glutSetMenu(menu_timer);
	glutAddMenuEntry("Start", MENU_TIMER_START);
	glutAddMenuEntry("Stop", MENU_TIMER_STOP);

	glutSetMenu(menu_main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    my_menu();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);



    glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
