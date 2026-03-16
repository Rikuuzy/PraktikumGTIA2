#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846
void drawCircle(float cx, float cy, float r, int seg){
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < seg; i++) {
		float angle = 2.0f * PI * i / seg;
		float x = r * cosf(angle);
		float y = r * sinf(angle);
		glVertex2f(cx + x, cy + y);
	}
	glEnd();
}

void drawHalfCircle(float cx, float cy, float r, int seg){
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= seg; i++) {
		float angle = 1.0f * PI * i / seg;
		float x = r * cosf(angle);
		float y = r * sinf(angle);
		glVertex2f(cx + x, cy + y);
	}
	glEnd();
}


void rectangle(float x1, float y1, float x2, float y2) {
	glRectf(x1, y1, x2, y2);
}

void drawBackground() {
    // LANGIT
    glColor3f(0.53f, 0.81f, 0.98f);
    rectangle(-1.0, 1.0, 1.0, -0.1);
    
    // MATAHARI
    glColor3f(1.0f, 1.0f, 0.0f);
	drawCircle(0.65f, 0.7f, 0.15f, 100);
    
    // RUMPUT
    glColor3f(0.4f, 0.6f, 0.2f);
    rectangle(-1.0, -0.1, 1.0, -1.0);

    // JALAN
    glColor3f(0.5f, 0.35f, 0.2f);
    rectangle(-1.0, -0.35, 1.0, -0.7);

    // BAHU JALAN
    glColor3f(0.0f, 0.0f, 0.0f); // abu terang
    rectangle(-1.0, -0.33, 1.0, -0.37);
    rectangle(-1.0, -0.68, 1.0, -0.72);
}
    
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawBackground();
	
	// PENYANGGA BELAKANG
	glPushMatrix();
	glLineWidth(5.0f);
	glTranslatef(-0.25, 0.15, 0);
	glRotated(90.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glEnd();
	glPopMatrix();
	
	// PENYANGGA BELAKANG MIRING
	glPushMatrix();
	glLineWidth(6.0f);
	glTranslatef(-0.69, -0.1, 0);
	glRotated(-30.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.29, 0.0);
	glEnd();
	glPopMatrix();
	
	// PENYANGGA BELAKANG TEGAK
	// GARIS KANAN
	glPushMatrix();
	glLineWidth(5.0f);
	glTranslatef(-0.4, -0.1, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.25, 0.0);
	glEnd();
	glPopMatrix();
	
	// GARIS TENGAH KIRI
	glPushMatrix();
	glLineWidth(5.0f);
	glTranslatef(-0.45, -0.1, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.25, 0.0);
	glEnd();
	glPopMatrix();
	
	// GARIS TENGAH KANAN
	glPushMatrix();
	glLineWidth(5.0f);
	glTranslatef(-0.5, -0.1, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.25, 0.0);
	glEnd();
	glPopMatrix();
	
	// GARIS KIRI
	glPushMatrix();
	glLineWidth(5.0f);
	glTranslatef(-0.55, -0.1, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.25, 0.0);
	glEnd();
	glPopMatrix();
	
	// PENYANGGA BELAKANG MIRING BAGASI
	glPushMatrix();
	glLineWidth(2.0f);
	glTranslatef(-0.83, -0.3, 0);
	glRotated(-40.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.25, 0.0);
	glEnd();
	glPopMatrix();
	
	// BAGASI BELAKANG
	glPushMatrix();
	glTranslatef(-0.75, -0.3, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.64f, 0.64f, 0.64f);
	rectangle(-0.1, 0.0, 0.1, -0.05);
	glEnd();
	glPopMatrix();
	
	// KNALPOT 
	glPushMatrix();
	glTranslatef(-0.70, -0.43, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	rectangle(-0.05, 0.0, 0.1, -0.03);
	glEnd();
	glPopMatrix();
	
	// ASAP KNALPOT 3
	glPushMatrix();
	glTranslatef(-0.78, -0.44, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.01f, 100);
	glEnd();
	glPopMatrix();
	
	// ASAP KNALPOT 2
	glPushMatrix();
	glTranslatef(-0.81, -0.43, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.01f, 100);
	glEnd();
	glPopMatrix();
	
	// ASAP KNALPOT 1
	glPushMatrix();
	glTranslatef(-0.84, -0.41, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.01f, 100);
	glEnd();
	glPopMatrix();
	
	// ASAP KNALPOT 0
	glPushMatrix();
	glTranslatef(-0.88, -0.42, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.01f, 100);
	glEnd();
	glPopMatrix();
	
	// PINTU MASUK ATAS
	glPushMatrix();
	glTranslatef(-0.28, 0.2, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.88f, 0.88f, 0.88f);
	rectangle(0.0, 0.0, 0.3, 0.03);
	glEnd();
	glPopMatrix();
	
	// OUTLINE PINTU 
	glPushMatrix();
	glTranslatef(-0.28, 0.2, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	rectangle(0.0, 0.0, 0.3, 0.01);
	glEnd();
	glPopMatrix();
	
	// GAGANG PINTU 
	glPushMatrix();
	glTranslatef(-0.14, 0.22, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	rectangle(0.0, 0.0, 0.02, 0.01);
	glEnd();
	glPopMatrix();
	
	// BODY ATAS
	glPushMatrix();
	glTranslatef(-0.05, 0.10, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.64f, 0.64f, 0.64f);
	rectangle(-0.3, 0.1, 0.3, -0.2);
	glEnd();
	glPopMatrix();
	
	
	// JENDELA
	glPushMatrix();
	glTranslatef(0.05, -0.05, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.128f, 0.128f, 0.128f);
	rectangle(0.0, 0.0, 0.2, 0.2);
	glEnd();
	glPopMatrix();
	
	// BODY BAWAH
	glPushMatrix();
	glTranslatef(0.0, -0.15, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.64f, 0.64f, 0.64f);
	rectangle(-0.7, 0.05, 0.45, -0.3);
	glEnd();
	glPopMatrix();
	
	// BODY DEPAN
	glPushMatrix();
	glTranslatef(0.41, -0.3, 0);
	glRotated(-90.0, 0.0, 0.0, 1.0);
	glColor3f(0.64f, 0.64f, 0.64f);
	drawHalfCircle(0.0f, 0.0f, 0.2f, 100);
	glEnd();
	glPopMatrix();
	
	// LAMPU DEPAN
	glPushMatrix();
	glTranslatef(0.56, -0.2, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.02f, 100);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.58, -0.2, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawCircle(0.0f, 0.0f, 0.02f, 100);
	glEnd();
	glPopMatrix();
	
	// TANGKI BENSIN
	glPushMatrix();
	glTranslatef(-0.55, -0.2, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.02f, 100);
	glEnd();
	glPopMatrix();
	
	// FENDER COVER DEPAN
	glPushMatrix();
	glTranslatef(0.3, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawHalfCircle(0.0f, 0.0f, 0.15f, 100);
	glEnd();
	glPopMatrix();
	
	// RODA DEPAN 
	glPushMatrix();
	glTranslatef(0.3, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.1f, 100);
	glEnd();
	glPopMatrix();
	
	// FENDER COVER 1 BELAKANG
	glPushMatrix();
	glTranslatef(-0.42, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawHalfCircle(0.0f, 0.0f, 0.15f, 100);
	glEnd();
	glPopMatrix();
	
	// RODA 1 BELAKANG
	glPushMatrix();
	glTranslatef(-0.42, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.1f, 100);
	glEnd();
	glPopMatrix();
	
	// FENDER COVER 2 BELAKANG
	glPushMatrix();
	glTranslatef(-0.15, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawHalfCircle(0.0f, 0.0f, 0.15f, 100);
	glEnd();
	glPopMatrix();
	
	// RODA 2 BELAKANG
	glPushMatrix();
	glTranslatef(-0.15, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(0.0f, 0.0f, 0.1f, 100);
	glEnd();
	glPopMatrix();
	
	// VELG RODA DEPAN
	glPushMatrix();
	glTranslatef(0.3, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawCircle(0.0f, 0.0f, 0.05f, 100);
	glEnd();
	glPopMatrix();
	
	// VELG RODA 1 BELAKANG
	glPushMatrix();
	glTranslatef(-0.42, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawCircle(0.0f, 0.0f, 0.05f, 100);
	glEnd();
	glPopMatrix();
	
	// VELG RODA 2 BELAKANG
	glPushMatrix();
	glTranslatef(-0.15, -0.5, 0);
	glRotated(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawCircle(0.0f, 0.0f, 0.05f, 100);
	glPopMatrix();
	glEnd();
	glFlush();
}
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hadrian Shandhy Yudha");
	glutDisplayFunc(display);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}
