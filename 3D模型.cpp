#include <gl\glut.h>
//6个面的绘制顺序,存储的是顶点的下标
static const GLint quads[][4] = {
	0, 2, 3, 1,
	0, 4, 6, 2,
	0, 1, 5, 4,
	4, 5, 7, 6,
	1, 3, 7, 5,
	2, 6, 7, 3,
};
void draw_cube(GLfloat x, GLfloat y, GLfloat z) {
	//8个顶点
	static const GLfloat vetexs[][3] = {
		 0.0,0.0,0.0,
		 x,0.0,0.0,
		 0.0,y,0.0,
		 x,y,0.0,
		 0.0,0.0,z,
		 x,0.0,z,
		 0.0,y,z,
		 x,y,z
	};
	glClear(GL_COLOR_BUFFER_BIT);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glRotated(15, 1, 0, 0);
	glRotated(15, 0, 1, 0);
	glTranslatef(-x / 2, -y / 2, -z / 2);	//平移至中心
   //画立方体
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);
		glVertex3f(vetexs[quads[i][0]][0], vetexs[quads[i][0]][1], vetexs[quads[i][0]][2]);
		glVertex3f(vetexs[quads[i][1]][0], vetexs[quads[i][1]][1], vetexs[quads[i][1]][2]);
		glVertex3f(vetexs[quads[i][2]][0], vetexs[quads[i][2]][1], vetexs[quads[i][2]][2]);
		glVertex3f(vetexs[quads[i][3]][0], vetexs[quads[i][3]][1], vetexs[quads[i][3]][2]);
		glEnd();
	}
}
void mydisplay() {

	draw_cube(1.0, 1.0, 1.0);
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Cube");
	glutDisplayFunc(&mydisplay);
	glutMainLoop();
	return 0;
}
