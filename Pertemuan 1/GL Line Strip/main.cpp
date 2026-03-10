#include <gl/glut.h>
#include <gl/gl.h>

void LineStrip(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5.0f);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f( 0.5f,-0.5f);
	glVertex2f( 0.5f, 0.5f);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(LineStrip);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
