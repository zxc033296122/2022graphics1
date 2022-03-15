#include <GL/glut.h>
float angle=0,oldX=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M�e��
    glPushMatrix();///�Ƥ��x�}
        glRotatef(angle,0,0,1);///����
        glColor3f(1,0,0);///�C��(RGB)
        glutSolidTeapot(0.3);///�N�@�ӯ��O
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///�e�n����
}
void motion (int x, int y)
{
        angle+=(x-oldX);
        oldX=x;
        display();///�����e��

}
void mouse(int button, int state, int x, int y)
{
    oldX=x;///�w��
}


int main(int argc, char** argv)///�D�禡 �i���� �ݤ���
{
    glutInit( &argc, argv);///��ѼƵ�glutInit ��l��old
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///���w�İ�+3D�`�ץ\��
    glutCreateWindow("�ƹ��i�H��̰�");///�}GLUT����
    glutMotionFunc(motion);///���o��
    glutMouseFunc(mouse);///�W�P��
    glutDisplayFunc(display);///�Ψ���ܪ��禡

    glutMainLoop();
}
