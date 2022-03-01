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
