#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void TriangleFan(void) {
	int i;
	float angle;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(5.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	for (i = 0; i <= 12; i++) {
		angle = i * (360.0f / 12.0f) * 3.14159f / 180.0f;
		glVertex3f(0.6f * cos(angle), 0.6f * sin(angle), 0.0f);
	}
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(TriangleFan);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
