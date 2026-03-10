#include <gl/glut.h>
#include <gl/gl.h>
void SegiEmpat(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-0.2, 0.2, 0.2, -0.2);
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(SegiEmpat);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
