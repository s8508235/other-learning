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

#include <GL/glut.h>

#include <stdlib.h>
#include <stdio.h>

/* GLUT callback Handlers */

/* Program entry point */


#define MENU_COLOR_RED 1
#define MENU_COLOR_BLUE 2
#define MENU_EXIT 3

const float COLOR_RED[] = {1.0f, 0.0f, 0.0f};
const float COLOR_BLUE[] = {0.0f, 0.0f, 1.0f};
const float COLOR_GREEN[] = {0.0f, 1.0f, 0.0f};
const float COLOR_YELLO[] = {1.0f, 1.0f, 0.0f};
const float *color_ptr = COLOR_RED;
const float *color_ptr_2 = COLOR_GREEN;

void dumpInfo(void)
{
    printf ("Vendor: %s\n", glGetString (GL_VENDOR));
    printf ("Renderer: %s\n", glGetString (GL_RENDERER));
    printf ("Version: %s\n", glGetString (GL_VERSION));
   // printf ("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	{
		glBegin(GL_TRIANGLES);
		{
			glColor3fv(color_ptr);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.5f, 1.0f, 0.0f);
			glColor3fv(color_ptr_2);
			glVertex3f(-0.5f, 0.0f, -0.1f);
			glVertex3f(0.5f, 0.0f, -0.1f);
			glVertex3f(0.0f, 1.0f, -0.1f);
		}
		glEnd();
	}
	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
}

void menu(int id)
{
	switch(id)
	{
	case MENU_COLOR_RED:
		color_ptr = COLOR_RED;
		glutPostRedisplay();
		break;
	case MENU_COLOR_BLUE:
		color_ptr = COLOR_BLUE;
		glutPostRedisplay();
		break;
	case MENU_EXIT:
		exit(0);
		break;
	default:
		break;
	}
}

void timer(int val)
{
	color_ptr_2 = color_ptr_2 == COLOR_GREEN ? COLOR_YELLO : COLOR_GREEN;
	glutPostRedisplay();
	glutTimerFunc(500, timer, val);
}

void mouse(int button, int state, int x, int y)
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

void keyboard(unsigned char key, int x, int y)
{
	printf("Key %c is pressed at (%d, %d)\n", key, x, y);
}

int main(int argc, char *argv[])
{
	// 初始化GLUT與GLEW，創建視窗
	////////////////////
	glutInit(&argc, argv);
	//glewInit();
	printf("%u \n",GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("quiz1_freeglut"); // 在這一行之後，thread中產生OpenGL Context，才能使用OpenGL function
	dumpInfo();
	////////////////////

	// 設定OpenGL狀態變數初始值
	////////////////////////
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	////////////////////////

	// 創建GLUT選單，並綁定到滑鼠右鍵
	////////////////////////////
	int menu_main = glutCreateMenu(menu);
	int menu_color = glutCreateMenu(menu);

	glutSetMenu(menu_main);
	glutAddSubMenu("Change Color", menu_color);
	glutAddMenuEntry("Exit", MENU_EXIT);

	glutSetMenu(menu_color);
	glutAddMenuEntry("Red", MENU_COLOR_RED);
	glutAddMenuEntry("Blue", MENU_COLOR_BLUE);

	glutSetMenu(menu_main);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	////////////////////////////

	// 綁定GLUT事件callback function
	///////////////////////////////
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(500, timer, 0); // 500毫秒後呼叫timer(0)
	///////////////////////////////

	// 進入主事件迴圈
	//////////////
	glutMainLoop();
	//////////////
	return 0;
}
