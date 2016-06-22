#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
void InitGL(void)
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
}
void menu_main_func(int id)
{
    if(id==1) std::cout<<"Main one"<<std::endl;
    else if (id==2) exit(0);
}
void menu_lv1_func(int id)
{
    if(id==1) std::cout<<"Sub one"<<std::endl;
    else std::cout<<"Not sub one"<<std::endl;
}
void menu_lv2_func(int id)
{
    if(id==1) std::cout<<"Sub two"<<std::endl;
    else std::cout<<"Not sub two"<<std::endl;
}
void My_menu(void)
{
    int menu_main,menu_lv1,menu_lv2;
    menu_main =glutCreateMenu(menu_main_func);
    menu_lv1 = glutCreateMenu(menu_lv1_func);
    menu_lv2 = glutCreateMenu(menu_lv2_func);

    glutSetMenu(menu_main);
    glutAddSubMenu("level 1",menu_lv1);
    glutAddMenuEntry("button x",1);
    glutAddMenuEntry("exit",2);

    glutSetMenu(menu_lv1);
    glutAddSubMenu("level 2",menu_lv2);
    glutAddMenuEntry("button y",1);

    glutSetMenu(menu_main);
    std::cout<<menu_main<<" "<<menu_lv1<<" "<<menu_lv2<<std::endl;
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void My_Reshape(int w,int h)
{
    GLfloat aspectratio;
}
void My_Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("SimpleApp");

    glutReshapeFunc(My_Reshape);
    glutDisplayFunc(My_Display);
    glutKeyboardFunc();
    glutMouseFunc();
    glutSpecialFunc();
    glutTimerFunc(500,glutPostRedisplay(),0);
    My_menu();
    InitGL();

    glutMainLoop();
    return EXIT_SUCCESS;
}
