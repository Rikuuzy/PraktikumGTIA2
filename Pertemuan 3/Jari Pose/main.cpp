#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0; 
static int elbow    = 0;
static int wrist    = 0;  

static int thumb    = 0;  
static int index    = 0; 
static int middle   = 0; 
static int ring     = 0; 
static int pinky    = 0; 
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

// Membuat jari dengan memanggil fungsi
void drawFinger(int rot, float len, float thk) { // sudut rotasi, panjang, ketebalan
    glRotatef((GLfloat)rot, 0.0f, 0.0f, 1.0f);
    glTranslatef(len / 2.0f, 0.0f, 0.0f);
    glScalef(len, thk, thk);
    glutWireCube(1.0); // gambar kubus 1x1x1
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // LENGAN ATAS
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
        glScalef(2.0f, 0.4f, 0.4f);
        glutWireCube(1.0);
    glPopMatrix();

    // LENGAN BAWAH
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
        glScalef(2.0f, 0.4f, 0.4f);
        glutWireCube(1.0);
    glPopMatrix();

    // PERGELANGAN TANGAN
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)wrist, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.3f, 0.0f, 0.0f);

    // TELAPAK TANGAN
    glColor3f(1.0f, 0.8f, 0.0f);
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.0f);
        glScalef(0.6f, 0.7f, 0.3f);
        glutWireCube(1.0);
    glPopMatrix();

    float palmTip = 0.6f;

    // TELUNJUK
    glColor3f(0.3f, 0.8f, 1.0f);
    glPushMatrix();
        glTranslatef(palmTip,  0.24f, 0.0f);
        drawFinger(index, 0.40f, 0.12f);
    glPopMatrix();

    // JARI TENGAH
    glColor3f(0.3f, 1.0f, 0.5f);
    glPushMatrix();
        glTranslatef(palmTip,  0.08f, 0.0f);
        drawFinger(middle, 0.43f, 0.12f);
    glPopMatrix();

    // JARI MANIS
    glColor3f(0.8f, 0.5f, 1.0f);
    glPushMatrix();
        glTranslatef(palmTip, -0.08f, 0.0f);
        drawFinger(ring, 0.40f, 0.12f);
    glPopMatrix();

    // KELINGKING
    glColor3f(1.0f, 0.6f, 0.2f);
    glPushMatrix();
        glTranslatef(palmTip, -0.24f, 0.0f);
        drawFinger(pinky, 0.30f, 0.10f);
    glPopMatrix();

    // IBU JARI
    glColor3f(1.0f, 0.2f, 0.2f);
    glPushMatrix();
        glTranslatef(0.15f, -0.38f, 0.0f);
        glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
        drawFinger(thumb, 0.35f, 0.13f);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
}


int clampFinger(int val, int delta) {
    int result = val + delta;
    if (result < 0)  result = 0;
    if (result > 80) result = 80;
    return result;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // LENGAN
        case 's': shoulder = (shoulder + 5) % 360; 
		break;
        case 'S': shoulder = (shoulder - 5 + 360) % 360; 
		break;
		
        case 'e': elbow    = (elbow    + 5) % 360; 
		break;
        case 'E': elbow    = (elbow    - 5 + 360) % 360; 
		break;
		
        case 'w': wrist    = (wrist    + 5) % 360; 
		break;
		
        case 'W': wrist    = (wrist    - 5 + 360) % 360; 
		break;

        // JARI - JARI
        case 'f': index  = clampFinger(index,  +5); 
		break;
        case 'F': index  = clampFinger(index,  -5); 
		break;
		
        case 'g': middle = clampFinger(middle, +5); 
		break;
        case 'G': middle = clampFinger(middle, -5); 
		break;
		
        case 'h': ring   = clampFinger(ring,   +5); 
		break;
        case 'H': ring   = clampFinger(ring,   -5); 
		break;
		
        case 'j': pinky  = clampFinger(pinky,  +5); 
		break;
        case 'J': pinky  = clampFinger(pinky,  -5); 
		break;
		
        case 't': thumb  = clampFinger(thumb,  +5); 
		break;
        case 'T': thumb  = clampFinger(thumb,  -5); 
		break;

        case 27: exit(0);
        default: break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hadrian Shandhy Yudha");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
