#include <GL/glut.h>

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�e��
    glPushMatrix();///�Ƥ��x�}
        glRotatef(90,0,0,1);///����
        glColor3f(1,0,0);///�C��(RGB)
        glutSolidTeapot(0.3);///�N�@�ӯ��O
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///�e�n����
}

int main(int argc, char** argv)///�D�禡 �i���� �ݤ���
{
    glutInit( &argc, argv);///��ѼƵ�glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///���w�İ�+3D�`�ץ\��
    glutCreateWindow("��4�P���{��");///�}GLUT����

    glutDisplayFunc(display);///�Ψ���ܪ��禡

    glutMainLoop();
}
