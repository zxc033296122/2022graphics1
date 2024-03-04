#include <GL/glut.h>
#include <stdio.h>
float angle = 0;
float teapotX=0, teapotY=0;
void myTeapot(float x,float y);

void display()
{
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///�N�@�ӯ��O
    glPopMatrix();///�٭�x�}

     glutSwapBuffers();
}
void mouse (int button, int state , int x,int y )
{///�ץ�
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}

void motion(int x, int y)
{
    angle=x;
    display();
}
int main(int argc, char** argv)///�D�禡 �i���� �ݤ���
{
    glutInit( &argc, argv);///��ѼƵ�glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///���w�İ�+3D�`�ץ\��
    glutCreateWindow("week03-����");///�}GLUT����

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
