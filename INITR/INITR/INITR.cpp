/*KETERANGAN
q/Q = atas
a/A = bawah
w/W = kiri
s/S = kanan
e/E = zoom in
d/D = zoom out
z/Z = Atas 
x/X = Bawah
c/C = Kiri
v/V = Kanan
b/B = Miring kiri
n/N = Miring Kanan

mouse + klik kiri = rotasi
*/

#include <windows.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void myInit() {
    glClearColor((float)0 / 255.0f, (float)33 / 255.0f, (float)110 / 255.0f, 1);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, -100.0f);
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void warna(int r = 1, int g = 1, int b = 1, float a = 1) {
    glColor4f(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

void depanbelakang(int panjang = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, (1 * tinggi) + p_y, 0 + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void kirikanan(int lebar = 1, int tinggi = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, (1 * tinggi) + p_y, 0 + p_z);
    glEnd();
}

void atasbawah(int panjang = 1, int lebar = 1, int p_x = 0, int p_y = 0, int p_z = 0) {

    glBegin(GL_QUADS);
        glVertex3d(0 + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, 0 + p_z);
        glVertex3d((1 * panjang) + p_x, 0 + p_y, (-1 * lebar) + p_z);
        glVertex3d(0 + p_x, 0 + p_y, (-1 * lebar) + p_z);
    glEnd();
}

void rumah() {
	//tanah
	warna(125,82,26);
	atasbawah(300,300,-150,0,100);
	atasbawah(300,300,-150,-20,100);
	warna(242,168,112);
	depanbelakang(300,20,-150,-20,100);
	depanbelakang(300,20,-150,-20,-200);
	kirikanan(300,20,-150,-20,100);
	kirikanan(300,20,150,-20,100);

}

void tampil() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    GLfloat lightColor[] = { 1.0f, 0.9f, 0.8f, 1.0f };
    GLfloat lightPos[] = {0, 250, 250, 2};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glMatrixMode(GL_PROJECTION);

        gluLookAt(-45, 15, 150, 0, 0, 0, 0, 1, 0);
        glRotatef(xrot, 1, 0, 0);
        glRotatef(yrot, 0, 1, 0);
        rumah();
		
    glPopMatrix();

    glutSwapBuffers();
}



void key(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
        case 'W':
            glTranslatef(-1.0, 0.0, 0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(1.0, 0.0, 0.0);
            break;
        case 'e':
        case 'E':
            glTranslatef(0.0, 0.0, 1.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(0.0, 0.0, -1.0);
            break;
        case 'q':
        case 'Q':
            glTranslatef(0.0, 1.0, 0.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(0.0, -1.0, 0.0);
            break;
        case 'v':
        case 'V':
            glRotatef(1.0, 0.0, -5.0, 0.0);
            break;
        case 'c':
        case 'C':
            glRotatef(1.0, 0.0, 5.0, 0.0);
            break;
        case 'b':
        case 'B':
            glRotatef(1.0, 0.0, 0.0, -5.0);
            break;
        case 'n':
        case 'N':
            glRotatef(1.0, 0.0, 0.0, 5.0);
            break;
        case 'x':
        case 'X':
            glRotatef(1.0, -5.0, 0.0, 0.0);
            break;
        case 'z':
        case 'Z':
            glRotatef(1.0, 5.0, 0.0, 0.0);
            break;
    }
    cout << key << endl;
    tampil();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(133, 54);
    glutCreateWindow("rope shovel");
    myInit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(tampil);
    glutKeyboardFunc(key);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}