#include <GL/glut.h> ///使用GLUT外掛,簡化程式
#include <stdio.h>
float mouseX=0, mouseY=0;
void myTeapot(float x, float y){
    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        glTranslatef(x,y,0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.1);///茶壺
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面
    myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0) ;
    glutSwapBuffers();///畫好後,交換出來
}
void mouse(int button, int state, int x, int y){
    printf("%d %d %d %d", button, state, x, y);
    mouseX=x; mouseY=y;
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第03週的程式:利用滑鼠移動)"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式
    glutMouseFunc(mouse);
    glutMainLoop(); ///主要的程式迴圈
}
