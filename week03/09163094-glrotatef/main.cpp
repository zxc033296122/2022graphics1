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
        glutSolidTeapot(0.3);///就一個神燈
    glPopMatrix();///還原矩陣

     glutSwapBuffers();
}
void mouse (int button, int state , int x,int y )
{///修正
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}

void motion(int x, int y)
{
    angle=x;
    display();
}
int main(int argc, char** argv)///主函式 進階版 看不懂
{
    glutInit( &argc, argv);///把參數給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能
    glutCreateWindow("week03-旋轉");///開GLUT視窗

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
