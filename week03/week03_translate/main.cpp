#include <GL/glut.h> ///�ϥ�GLUT�~��,²�Ƶ{��
void myTeapot(float x, float y){
    glPushMatrix();///�ƥ��x�}(�ƥ��ª���m)
        ///���ʷ|�ֿn,�]�����|�ק�x�}
        glTranslatef(x,y,0);///�k�W��
        glColor3f(1,1,0);///����
        glutSolidTeapot(0.3);///����
    glPopMatrix();///�٭�x�}
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�e�ϫe, ���M�e��
    myTeapot(0.5, 0.5);
    myTeapot(0.5, -0.5);
    myTeapot(-0.5, -0.5);
    myTeapot(-0.5, 0.5);
    glutSwapBuffers();///�e�n��,�洫�X��
}

int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��Ѽ�,�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�Ű� + 3D�`�ץ\��
    glutCreateWindow("��03�g���{��:����)"); ///�} GLUT ����

    glutDisplayFunc(display); ///�Ψ���ܪ��禡

    glutMainLoop(); ///�D�n���{���j��
}
