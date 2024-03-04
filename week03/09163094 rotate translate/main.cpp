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
        glutSolidTeapot(0.3);///就一個神燈
    glPopMatrix();///還原矩陣

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
int main(int argc, char** argv)///主函式 進階版 看不懂
{
    glutInit( &argc, argv);///把參數給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能
    glutCreateWindow("week03-旋轉");///開GLUT視窗

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
