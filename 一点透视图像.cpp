#include <gl\glut.h>    
#include <gl\GLU.h>
#include <gl\GL.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926     
int WinWidth, WinHeight;

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	int i = -100;
	for (int i = -50; i <= 20; i += 5)
	{
		// 线段是等长的，并且在坐标系中的y z值相同的
		glBegin(GL_LINES);
		glVertex3f(-5, 0, i);
		glVertex3f(5, 0, i);
		glEnd();
	}

	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	WinWidth = w;
	WinHeight = h;
	// //改变显示区域，起始位置为客户端窗口左下角（非坐标原点）
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//宽高比改为当前值，视线区域与屏幕大小一致；
	gluPerspective(45, 1.0*WinWidth / WinHeight, 1, 1000);
	// 开启更新深度缓冲区的功能
	glEnable(GL_DEPTH_TEST);
	// 摄像机视图观看，从 （0，5，20） 往（0，0，0）处看，（0，1，0）为正方向
	gluLookAt(0, 5, 20, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char *argv[])
{
	WinWidth = 400;
	WinHeight = 400;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
	//glutInitWindowPosition(100, 100);
	glutInitWindowSize(WinWidth, WinHeight);
	glutCreateWindow("Onepointperspective");

	/*
		目的：当窗口尺寸改变时，图形比例不发生变化
		思路：窗口宽高比改变时，通过改变窗口显示区域大小，并利用投影矩阵改变观测物体大小使之适应变化。
	*/
	glutReshapeFunc(&Reshape);
	glutDisplayFunc(&Draw);

	glutMainLoop();
	return 0;
}