#include <GL/glut.h>
float teapotX=0, teapotY=0;
void myTeapot(float x,float y)
{
///    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�e��
    glPushMatrix();///�ƥ��ª���m
        ///���ʷ|�ֿn,�]�����|�ק�x�}
        glTranslatef(x,y,0);///�k�W��
        glColor3f(1,1,0);///�C��(RGB)
        glutSolidTeapot(0.3);///�N�@�ӯ��O
    glPopMatrix();///�٭�x�}

}
void display()
{
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushMatrix();///�ƥ��x�}
        glTranslatef(teapotX, teapotY,0);///��y�в���
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
     glutSwapBuffers();
}
void mouse (int button, int state , int x,int y )
{
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}
int main(int argc, char** argv)///�D�禡 �i���� �ݤ���
{
    glutInit( &argc, argv);///��ѼƵ�glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///���w�İ�+3D�`�ץ\��
    glutCreateWindow("week03-����");///�}GLUT����

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
