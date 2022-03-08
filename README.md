# week2
## 1.範例
```
去https://jsyeh.org/3dcg10

載data windows兩個壓縮檔 跟glut32.dll 三個東西

windows解壓縮

其他東西都丟進去windows裡面

開Shapes.exe

可以點右鍵自己玩
```

# #2.從git抓檔案
```
1.去moodle裝 git 
2.一路下一步上勾下不勾
3.cd desktop
4.git clone 你的git網址
5.cd 2022graphicsl (完成後桌面會多一個檔案)
```
## 3.GLUT必要檔案
```
1.到moodle的【上課用軟體】載壓縮檔解壓縮
2.複製一個freeglut\lib\libfreeglut.a
3.把複製的libfreeglut.a改名改成libglut32.a
```
## 4.親手打造GLUT程式
```C++
#include <GL/glut.h>

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清畫面

    glColor3f(0,0,0);///顏色(RGB)
    glutSolidTeapot(0.3);///就一個神燈



    glutSwapBuffers();///畫好提交
}

int main(int argc, char** argv)///主函式 進階版 看不懂
{
    glutInit( &argc, argv);///把參數給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能
    glutCreateWindow("第二周的程式");///開GLUT視窗

    glutDisplayFunc(display);///用來顯示的函式

    glutMainLoop();
}

幾乎看不懂 以後會看懂 執行會看到茶壺
```
## 5.RGB三角形
```
#include <GL/glut.h>



void display()

{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glColor3f(0,0,0);

    ///glutSolidTeapot(0.3);



    glBegin(GL_POLYGON);

        glColor3f(1,0,0); 顏色(RBG)

        glVertex2f(-1,-1); 座標 vertex 頂點



        glColor3f(0,1,0);

        glVertex2f(+1,-1);



        glColor3f(0,0,1);

        glVertex2f(0,+1);



    glEnd();

(紅色為三角型)

    glutSwapBuffers();

}



int main(int argc, char** argv)

{

    glutInit( &argc, argv);

    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );

    glutCreateWindow("第二周的程式");



    glutDisplayFunc(display);



    glutMainLoop();

}
```
#week3
## 1. 範例 

去https://jsyeh.org/3dcg10/
下載 data跟win32
把data丟在win32
執行 Transformation.exe
可以去玩他

## 2 茶壺
```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        glTranslatef(0.5,0.5,0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的程式"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```
## 3.四個茶壺
```c++
#include <GL/glut.h>



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

     myTeapot(0.5,0.5);

     myTeapot(0.5,-0.5);

     myTeapot(-0.5,-0.5);

     myTeapot(-0.5,0.5);

     glutSwapBuffers();

}

int main(int argc, char** argv)///主函式 進階版 看不懂

{

    glutInit( &argc, argv);///把參數給glutInit 初始化

    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能

    glutCreateWindow("week03-移動");///開GLUT視窗



    glutDisplayFunc(display);///用來顯示的函式



    glutMainLoop();

} 
```
## 4.讓茶壺跟者我的滑鼠動
```c++
#include <GL/glut.h>
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
    mouseX=x; mouseY=y;
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
## 5.會幫到你
```c++
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
```
