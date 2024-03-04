#include <GL/glut.h>
float teapotX=0, teapotY=0;
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
     glPushMatrix();///備份矩陣
        glTranslatef(teapotX, teapotY,0);///把座標移動
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
     glutSwapBuffers();
}
void mouse (int button, int state , int x,int y )
{
    teapotX=(x-150)/150.0;
    teapotY=-(y-150)/150.0;
}
int main(int argc, char** argv)///主函式 進階版 看不懂
{
    glutInit( &argc, argv);///把參數給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能
    glutCreateWindow("week03-移動");///開GLUT視窗

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
