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
		// �߶��ǵȳ��ģ�����������ϵ�е�y zֵ��ͬ��
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
	// //�ı���ʾ������ʼλ��Ϊ�ͻ��˴������½ǣ�������ԭ�㣩
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//��߱ȸ�Ϊ��ǰֵ��������������Ļ��Сһ�£�
	gluPerspective(45, 1.0*WinWidth / WinHeight, 1, 1000);
	// ����������Ȼ������Ĺ���
	glEnable(GL_DEPTH_TEST);
	// �������ͼ�ۿ����� ��0��5��20�� ����0��0��0����������0��1��0��Ϊ������
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
		Ŀ�ģ������ڳߴ�ı�ʱ��ͼ�α����������仯
		˼·�����ڿ�߱ȸı�ʱ��ͨ���ı䴰����ʾ�����С��������ͶӰ����ı�۲������Сʹ֮��Ӧ�仯��
	*/
	glutReshapeFunc(&Reshape);
	glutDisplayFunc(&Draw);

	glutMainLoop();
	return 0;
}