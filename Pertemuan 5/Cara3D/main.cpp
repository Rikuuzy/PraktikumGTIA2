#include <GL/glut.h>
#include <math.h>

// Variabel global untuk menyimpan posisi (camX/Y/Z) dan arah hadap kamera 3D.
float camX = 4.0, camY = 3.0, camZ = 5.0;
float lookX = 0.0, lookY = 0.0, lookZ = 0.0;
float upX = 0.0, upY = 1.0, upZ = 0.0;

// Fungsi ini bertugas mengaktifkan fitur pencahayaan (lighting) dan pengujian kedalaman (Z-buffer) pada OpenGL.
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.5 }; // Parameter Posisi Cahaya (X, Y, Z, W)
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // Parameter Cahaya Lingkungan (Red, Green, Blue, Alpha)
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // Parameter Penerangan (Red, Green, Blue, Alpha)
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // Parameter highlight (Red, Green, Blue, Alpha)

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glClearColor(0.53f, 0.81f, 0.98f, 1.0f); // Sky blue background
}

// Fungsi ini mengatur ulang proyeksi perspektif 3D setiap kali ukuran jendela aplikasi diubah oleh pengguna.
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi ini menangani input keyboard untuk mengubah sudut pandang kamera (1-3) dan menggerakkan posisi kamera (W, A, S, D).
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1': // Isometric view
            camX = 4.0; camY = 3.0; camZ = 5.0;
            lookX = 0.0; lookY = 0.0; lookZ = 0.0;
            upX = 0.0; upY = 1.0; upZ = 0.0;
            break; 
        case '2': // Side view
            camX = 0.0; camY = 0.5; camZ = 7.0;
            lookX = 0.0; lookY = 0.0; lookZ = 0.0;
            upX = 0.0; upY = 1.0; upZ = 0.0;
            break; 
        case '3': // Top view
            camX = 0.0; camY = 7.0; camZ = 0.0;
            lookX = 0.0; lookY = 0.0; lookZ = 0.0;
            upX = 0.0; upY = 0.0; upZ = -1.0;
            break; 
        case 'w': case 'W': // Maju
            camZ -= 0.5f; lookZ -= 0.5f; break;
        case 's': case 'S': // Mundur
            camZ += 0.5f; lookZ += 0.5f; break;
        case 'a': case 'A': // Kiri
            camX -= 0.5f; lookX -= 0.5f; break;
        case 'd': case 'D': // Kanan
            camX += 0.5f; lookX += 0.5f; break;
    }
    glutPostRedisplay();
}

// Fungsi ini adalah cetakan khusus untuk menggambar sebuah roda 3D (ban dan velg) pada posisi x, y, z yang ditentukan.
void drawWheel(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Ban hitam
    glColor3f(0.1f, 0.1f, 0.1f);
    glutSolidTorus(0.1, 0.2, 15, 30);
    
    // Velg
    glColor3f(0.8f, 0.8f, 0.8f);
    glutSolidTorus(0.05, 0.1, 10, 20);
    glPopMatrix();
}

// Fungsi utama ini akan dipanggil terus-menerus oleh GLUT untuk me-render kamera, lantai, jalan raya, dan keseluruhan bentuk mobil 3D.
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Pengaturan posisi kamera
    gluLookAt(camX, camY, camZ,  lookX, lookY, lookZ,  upX, upY, upZ);

    // Menggambar Lantai / Tanah
    glPushMatrix();
    glColor3f(0.4f, 0.6f, 0.2f); // Warna rumput hijau
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0); // Normal menunjuk ke atas
    glVertex3f(-10.0, -1.0, -10.0);
    glVertex3f(-10.0, -1.0, 10.0);
    glVertex3f(10.0, -1.0, 10.0);
    glVertex3f(10.0, -1.0, -10.0);
    glEnd();
    
    // Menggambar Jalan Raya
    glColor3f(0.5f, 0.35f, 0.2f); // Warna jalan
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-10.0, -0.99, -2.0); // Sedikit di atas tanah agar tidak z-fighting
    glVertex3f(-10.0, -0.99, 2.0);
    glVertex3f(10.0, -0.99, 2.0);
    glVertex3f(10.0, -0.99, -2.0);
    glEnd();
    glPopMatrix();

    // MENGGAMBAR MOBIL
    glPushMatrix();
    
    // 1. Body Bawah Mobil
    glColor3f(0.64f, 0.64f, 0.64f); // Abu-abu
    glPushMatrix();
    glTranslatef(0.0, -0.2, 0.0);
    glScalef(3.0, 0.6, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // 2. Cabin Atas Mobil
    glColor3f(0.64f, 0.64f, 0.64f);
    glPushMatrix();
    glTranslatef(0.5, 0.4, 0.0);
    glScalef(1.2, 0.8, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 3. Kaca Jendela Depan
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam pekat
    glPushMatrix();
    glTranslatef(1.11, 0.4, 0.0);
    glScalef(0.05, 0.6, 1.3);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 4. Kaca Jendela Samping Kanan
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam pekat
    glPushMatrix();
    glTranslatef(0.5, 0.4, 0.76);
    glScalef(0.8, 0.6, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 5. Kaca Jendela Samping Kiri
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam pekat
    glPushMatrix();
    glTranslatef(0.5, 0.4, -0.76);
    glScalef(0.8, 0.6, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // 6. Lampu Depan
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glPushMatrix();
    glTranslatef(1.5, -0.2, 0.5);
    glutSolidSphere(0.15, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.5, -0.2, -0.5);
    glutSolidSphere(0.15, 20, 20);
    glPopMatrix();
    
    // 7. Lampu Belakang
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glPushMatrix();
    glTranslatef(-1.5, -0.2, 0.5);
    glutSolidCube(0.2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.5, -0.2, -0.5);
    glutSolidCube(0.2);
    glPopMatrix();
    
    // 8. Knalpot
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glPushMatrix();
    glTranslatef(-1.6, -0.4, -0.4);
    glScalef(0.4, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 8.5 Asap Knalpot
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam pekat
    glPushMatrix();
    glTranslatef(-1.8, -0.38, -0.4);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.95, -0.35, -0.4);
    glutSolidSphere(0.07, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.15, -0.30, -0.4);
    glutSolidSphere(0.1, 10, 10);
    glPopMatrix();

    // 9. Penyangga Belakang (Pickup Bed bars)
    glColor3f(0.9f, 0.9f, 0.9f); // Putih terang
    
    // Bar Horizontal Atas
    glPushMatrix();
    glTranslatef(-0.75, 0.4, 0.6);
    glScalef(1.3, 0.05, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.75, 0.4, -0.6);
    glScalef(1.3, 0.05, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // Bar Vertikal
    for(float i = -0.2f; i >= -1.2f; i -= 0.33f) {
        glPushMatrix();
        glTranslatef(i, 0.25, 0.6);
        glScalef(0.05, 0.3, 0.05);
        glutSolidCube(1.0);
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(i, 0.25, -0.6);
        glScalef(0.05, 0.3, 0.05);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    
    // Bar Miring Belakang
    glPushMatrix();
    glTranslatef(-1.45, 0.25, 0.6);
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glScalef(0.05, 0.4, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.45, 0.25, -0.6);
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glScalef(0.05, 0.4, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 9.5 Bagasi Belakang (Bumper Extension)
    glColor3f(0.64f, 0.64f, 0.64f);
    glPushMatrix();
    glTranslatef(-1.6, -0.2, 0.0);
    glScalef(0.2, 0.2, 0.8);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 10. Gagang Pintu Kanan
    glColor3f(1.0f, 1.0f, 1.0f); // Putih
    glPushMatrix();
    glTranslatef(0.2, 0.1, 0.76);
    glScalef(0.2, 0.05, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // 11. Gagang Pintu Kiri
    glPushMatrix();
    glTranslatef(0.2, 0.1, -0.76);
    glScalef(0.2, 0.05, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    // 12. Roda Mobil (Total 6 roda, seperti versi 2D)
    drawWheel(1.0, -0.5, 0.8);  // Depan Kanan
    drawWheel(1.0, -0.5, -0.8); // Depan Kiri
    
    drawWheel(-0.5, -0.5, 0.8); // Tengah Kanan
    drawWheel(-0.5, -0.5, -0.8);// Tengah Kiri
    
    drawWheel(-1.2, -0.5, 0.8); // Belakang Kanan
    drawWheel(-1.2, -0.5, -0.8);// Belakang Kiri
    glPopMatrix();

    glutSwapBuffers();
}

// Bagian ini adalah titik masuk utama (entry point) program untuk menginisialisasi window GLUT dan mendaftarkan fungsi-fungsi callback.
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    
    // MENGAKTIFKAN DOUBLE BUFFER DAN DEPTH BUFFER (Z-BUFFER)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D - Hadrian Shandhy Yudha");
    
    init(); // Panggil fungsi inisialisasi kedalaman dan pencahayaan
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); // Panggil fungsi keyboard
    
    glutMainLoop();
    return 0;
}
