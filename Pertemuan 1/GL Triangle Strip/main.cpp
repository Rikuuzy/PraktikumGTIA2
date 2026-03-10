#include <gl/glut.h>
#include <gl/gl.h>

void TriangleStrip(void) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(5.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f( 0.5,-0.5);
	glVertex2f( 0.5, 0.5);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(TriangleStrip);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
