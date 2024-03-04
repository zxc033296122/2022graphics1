#include <GL/glut.h>
#include <stdio.h>

float mouseX=0, mouseY=0;
void myTeapot(float x,float y)
{
///    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清畫面
    glPushMatrix();///備份舊的位置
        ///移動會累積,因為它會修改矩陣
        glTranslatef(x,y,0);///右上角
        glColor3f(1,1,0);///顏色(RGB)
        glutSolidTeapot(0.3);///就一個神燈
    glPopMatrix();///還原矩陣

}
void display()
{
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0);
     glutSwapBuffers();
}
void mouse (int button, int state , int x,int y )
{

if(state==GLUT_DOWN)///如果左鍵壓下去
{
 printf("(%d-150)/150  -(%d-150)/150\n",x,y);
}///印出座標--->記得要include <stdio.h>


}///印出座標
int main(int argc, char** argv)///主函式 進階版 看不懂
{
    glutInit( &argc, argv);///把參數給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能
    glutCreateWindow("week03-移動");///開GLUT視窗

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
