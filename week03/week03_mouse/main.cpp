#include <GL/glut.h> ///�ϥ�GLUT�~��,²�Ƶ{��
float mouseX=0, mouseY=0;
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
    myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0) ;
    glutSwapBuffers();///�e�n��,�洫�X��
}
void mouse(int button, int state, int x, int y){
    mouseX=x; mouseY=y;
}

int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��Ѽ�,�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�Ű� + 3D�`�ץ\��
    glutCreateWindow("��03�g���{��:�Q�ηƹ�����)"); ///�} GLUT ����

    glutDisplayFunc(display); ///�Ψ���ܪ��禡
    glutMouseFunc(mouse);
    glutMainLoop(); ///�D�n���{���j��
}
