#include <gl/glut.h>
#include <gl/gl.h>

void Quads(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f,  0.0f, 0.0f);
	glVertex3f(0.0f,  0.0f, 0.0f);
	glVertex3f(0.0f,  0.5f, 0.0f);
	glVertex3f(-0.5f,  0.5f, 0.0f);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(Quads);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
