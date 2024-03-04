#include <GL/glut.h>
#include <stdio.h>
float angle = 0;
float teapotX=0, teapotY=0;

void myTeapot(float x,float y);

void display()
{
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glPushMatrix();
      glTranslatef(teapotX,teapotY,0);
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///�N�@�ӯ��O
    glPopMatrix();///�٭�x�}

     glutSwapBuffers();
}

int method=1;///1 rotate 2 translate
int oldX=0,oldY=0;

void mouse (int button, int state , int x,int y )
{
 oldX=x;
 oldY=y;
}
void keyboard(unsigned char key , int x, int y)
{
    if (key=='e')method=1;///rotate
    if (key=='w')method=2;///transltate
}
void motion(int x, int y)
{
    if(method==1)
    {
        angle+=x-oldX;
    }
    else if(method==2)
    {
        teapotX+=(x-oldX)/150.0;
        teapotY-=(y-oldY)/150.0;
    }

    oldX=x;
    oldY=y;
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
