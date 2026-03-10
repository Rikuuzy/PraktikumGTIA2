#include <gl/glut.h>
#include <gl/gl.h>

void KubusBertingkat(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	/* Layer 1 - Dasar - Merah - center x=0.00 */
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.10f, -0.90f);
	glVertex2f( 0.10f, -0.90f);
	glVertex2f( 0.10f, -0.70f);
	glVertex2f(-0.10f, -0.70f);
	glEnd();

	/* Layer 2 - Oranye - geser kiri x=-0.20 */
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.30f, -0.66f);
	glVertex2f(-0.10f, -0.66f);
	glVertex2f(-0.10f, -0.46f);
	glVertex2f(-0.30f, -0.46f);
	glEnd();

	/* Layer 3 - Hijau - tengah x=0.00 */
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.10f, -0.42f);
	glVertex2f( 0.10f, -0.42f);
	glVertex2f( 0.10f, -0.22f);
	glVertex2f(-0.10f, -0.22f);
	glEnd();

	/* Layer 4 - Cyan - geser kanan x=+0.20 */
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f( 0.10f, -0.18f);
	glVertex2f( 0.30f, -0.18f);
	glVertex2f( 0.30f,  0.02f);
	glVertex2f( 0.10f,  0.02f);
	glEnd();

	/* Layer 5 - Puncak - Ungu - tengah x=0.00 */
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.10f,  0.06f);
	glVertex2f( 0.10f,  0.06f);
	glVertex2f( 0.10f,  0.26f);
	glVertex2f(-0.10f,  0.26f);
	glEnd();

	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(KubusBertingkat);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutMainLoop();
	return 0;
}
