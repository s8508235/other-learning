#include <GL/glew.h> // glew.h must be included before gl.h/glu.h/freeglut.h
#include <GL/freeglut.h>
#include <cstdio>
#include <cstdlib>

#define MENU_TIMER_START 1
#define MENU_TIMER_STOP 2
#define MENU_EXIT 3
#define POSE_NUMBER 4
const GLfloat tri_v1[3] = {-0.5f, -0.4f, 0.0f};
const GLfloat tri_v2[3] = { 0.5f, -0.4f, 0.0f};
const GLfloat tri_v3[3] = { 0.0f,  0.6f, 0.0f};
float finger_angle = 0;
GLubyte timer_cnt = 0;
bool timer_enabled = true;
unsigned int timer_speed = 16;
float angle =0;
int flag = 0;
float finger_float_one,finger_float_two,finger_float_three;
bool pose_one=false,pose_two=false,pose_three = false;
// Print OpenGL context related information.
void dumpInfo(void)
{
    printf("Vendor: %s\n", glGetString (GL_VENDOR));
    printf("Renderer: %s\n", glGetString (GL_RENDERER));
    printf("Version: %s\n", glGetString (GL_VERSION));
    printf("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));
}
void finger_1()
{
    glColor3d(0.5f,0.5f,0.5f);
    glPushMatrix();
    glTranslated(-0.6,0.2,0.8);
    if(pose_one==true)
    glRotated(finger_float_two,1,1,0);
    glPushMatrix();
    {


        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);

    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslated(-0.375,0,0);
        glColor3d(1.0,0,0);
        glTranslated(-0.3,0,0);
        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslated(-1.0,0,0);
        glColor3d(1.0,0,0);
        glTranslated(-0.3,0,0);
        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);
    }
    glPopMatrix();

    glPopMatrix();
}
void finger_2()
{
    glColor3d(0.5f,0.5f,0.5f);
    glPushMatrix();
    glTranslated(-0.6,0.2,0.8);

    glPushMatrix();
    {


        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);

    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslated(-0.375,0,0);
        glColor3d(1.0,0,0);
        glTranslated(-0.3,0,0);
        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslated(-1.0,0,0);
        glColor3d(1.0,0,0);
        glTranslated(-0.3,0,0);
        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);
    }
    glPopMatrix();

    glPopMatrix();
}
void finger_3()
{
    glColor3d(0.5f,0.5f,0.5f);
    glPushMatrix();
    glTranslated(-0.6,0.2,0.8);
    if(pose_one==true || pose_two==true)
    glRotated(finger_float_one,1,1,0);
    glPushMatrix();
    {


        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);

    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslated(-0.375,0,0);
        glColor3d(1.0,0,0);
        glTranslated(-0.3,0,0);
        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslated(-1.0,0,0);
        glColor3d(1.0,0,0);
        glTranslated(-0.3,0,0);
        glutSolidSphere(0.1,50,50);
        glColor3d(0.0f,0,0);
        glTranslated(-0.375,0,0);
        glScaled(2,1,1);
        glutSolidSphere(0.15,50,50);
    }
    glPopMatrix();

    glPopMatrix();
}

// GLUT callback. Called to draw the scene.
void My_Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
        glRotated(angle,1.3,0.2,-5);

        glColor3d(0.5f,0.7f,0.0f);
        glPushMatrix();//ball 1
        {
            glTranslated(-3.3,0.1,-5);
            glutSolidSphere(0.8,50,50);
            //finger
            glPushMatrix();
            finger_1();
            glPopMatrix();


            glPushMatrix();
            glTranslated(0.0,-0.3,0);
            glRotated(10.0f,0,0,1);
            finger_2();
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.1,0.15,0);
            glRotated(-15.0f,0,0,1);
            finger_3();
            glPopMatrix();

        }
        glPopMatrix();

            glColor3d(0.5f,0.5f,0.5f);
            glPushMatrix();//arm 1
            {
                glTranslated(-1,0.1,-5);
                glScalef(5.0f,1.0f,1.0f);
                glutSolidSphere(0.5,50,50);
            }
            glPopMatrix();

        glColor3d(1.0f,1.0f,0.0f);//ball 2
        glPushMatrix();
        {
            glTranslated(1.3,0.2,-5);
            glutSolidSphere(0.3,50,50);
        }
        glPopMatrix();

    }
    glPopMatrix();


        glColor3d(0.0f,1.0f,0.5f);//arm
        glPushMatrix();
        {
            glTranslated(4,0.2,-5);
            glScalef(5.0f,1.0f,1.0f);
            glutSolidSphere(0.5,50,50);
        }
        glPopMatrix();


	glutSwapBuffers();
}

void My_Reshape(int width, int height)
{
    float ar = (float) width / (float) height;
	glViewport(0, 0, (GLsizei)width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    gluPerspective(65.0,ar,1.0,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void My_Timer(int val)
{
	timer_cnt++;
	if(angle<15 && !flag)
    {
        flag = 0;
        angle +=0.1;
    }
	else if( angle>-15)
    {
        flag = 1;
        angle -=0.1;
    }
    else
    {
        flag = 0;
    }
	glutPostRedisplay();
	if(timer_enabled)
	{
		glutTimerFunc(timer_speed, My_Timer, val);
	}
	if(pose_two &&finger_float_one<180 )
    {
        finger_float_one+=10;
        finger_float_two+=10;
    }
    else if (pose_one && finger_float_one<180)
    {
        finger_float_one+=10;
        finger_float_two+=10;
    }
    else if (pose_three && finger_float_one>=0 || finger_float_two>=0 || finger_float_three>=0  )
    {
        finger_float_one-=10;
        finger_float_two-=10;
        finger_float_three-=10;
    }
}


void My_Mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		printf("Mouse %d is pressed at (%d, %d)\n", button, x, y);
	}
	else if(state == GLUT_UP)
	{
		printf("Mouse %d is released at (%d, %d)\n", button, x, y);
	}
}

void My_Keyboard(unsigned char key, int x, int y)
{
	printf("Key %c is pressed at (%d, %d)\n", key, x, y);
}

void My_SpecialKeys(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_F1:
		printf("F1 is pressed at (%d, %d)\n", x, y);
		break;
	case GLUT_KEY_PAGE_UP:
		printf("Page up is pressed at (%d, %d)\n", x, y);
		break;
	case GLUT_KEY_LEFT:
		printf("Left arrow is pressed at (%d, %d)\n", x, y);
		break;
	default:
		printf("Other special key is pressed at (%d, %d)\n", x, y);
		break;
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
    case 11:
        pose_two = false;
        pose_one = true;
        pose_three = false;
        break;
    case 12:
        pose_one= false;
        pose_two = true;
        pose_three = false;
        break;
    case 13:
        pose_one= false;
        pose_two = false;
        pose_three = true;
        break;
	default:
        pose_one= false;
        pose_two = false;
        pose_three = false;
		break;
	}
}

int main(int argc, char *argv[])
{
	// Initialize GLUT and GLEW, then create a window.
	////////////////////
	glutInit(&argc, argv);
	glewInit();
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Quiz Framework"); // You cannot use OpenGL functions before this line; The OpenGL context must be created first by glutCreateWindow()!
	dumpInfo();
	////////////////////

	// Initialize OpenGL states.
	////////////////////////
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	////////////////////////

	// Create a menu and bind it to mouse right button.
	////////////////////////////
	int menu_main = glutCreateMenu(My_Menu);
	int menu_timer = glutCreateMenu(My_Menu);
    int pose = glutCreateMenu(My_Menu);

	glutSetMenu(menu_main);
	glutAddSubMenu("Timer", menu_timer);
	glutAddMenuEntry("Exit", MENU_EXIT);
    glutAddSubMenu("Numbers",pose);

	glutSetMenu(menu_timer);
	glutAddMenuEntry("Start", MENU_TIMER_START);
	glutAddMenuEntry("Stop", MENU_TIMER_STOP);

    glutSetMenu(pose);
    glutAddMenuEntry("one",11);
    glutAddMenuEntry("two",12);
    glutAddMenuEntry("three",13);
	glutSetMenu(menu_main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	////////////////////////////

	// Register GLUT callback functions.
	///////////////////////////////
	glutDisplayFunc(My_Display);
	glutReshapeFunc(My_Reshape);
	glutMouseFunc(My_Mouse);
	glutKeyboardFunc(My_Keyboard);
	glutSpecialFunc(My_SpecialKeys);
	glutTimerFunc(timer_speed, My_Timer, 0);
	///////////////////////////////

	// Enter main event loop.
	//////////////
	glutMainLoop();
	//////////////
	return 0;
}
