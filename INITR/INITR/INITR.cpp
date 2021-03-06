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

void shovel() {
	//tanah
	warna(125,82,26);
	atasbawah(300,300,-150,0,100);
	atasbawah(300,300,-150,-20,100);
	warna(242,168,112);
	depanbelakang(300,20,-150,-20,100);
	depanbelakang(300,20,-150,-20,-200);
	kirikanan(300,20,-150,-20,100);
	kirikanan(300,20,150,-20,100);

	//tiang lampu
	warna(0.95,1,0.9);
	depanbelakang(3, 90, 1, 0, -190);
	depanbelakang(3, 90, 1, 0, -193);
	kirikanan(3, 90, 1, 0, -190);
	kirikanan(3, 90, 4, 0, -190);
	glBegin(GL_QUADS);
	glColor3f(31/255.0f, 195/255.0f, 207/255.0f);
	glVertex3f(1.0, 90.0, -190.0);
	glVertex3f(0, 95.0, -189.5);
	glVertex3f(5, 95.0, -189.5);
	glVertex3f(4.0, 90.0, -190.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(31/255.0f, 195/255.0f, 207/255.0f);
	glVertex3f(1.0, 90.0, -193.0);
	glVertex3f(0, 95.0, -193.5);
	glVertex3f(5, 95.0, -193.5);
	glVertex3f(4.0, 90.0, -193.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(71/255.0f, 215/255.0f, 257/255.0f);
	glVertex3f(1.0, 90.0, -190.0);
	glVertex3f(0, 95.0, -189.5);
	glVertex3f(0, 95.0, -193.5);
	glVertex3f(1.0, 90.0, -193.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(71/255.0f, 215/255.0f, 257/255.0f);
	glVertex3f(4.0, 90.0, -190.0);
	glVertex3f(5, 95.0, -189.5);
	glVertex3f(5, 95.0, -193.5);
	glVertex3f(4.0, 90.0, -193.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(201/255.0f, 255/255.0f, 257/255.0f);
	glVertex3f(0.0, 95.0, -189.5);
	glVertex3f(0, 95.0, -193.5);
	glVertex3f(5, 95.0, -193.5);
	glVertex3f(5.0, 95.0, -189.5);
	glEnd();
	
	//rantai kanan
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 218/255.0f, 0/255.0f);
	glVertex3f(26.0, 0.0, 25.0);
	glVertex3f(28.0, 1.0, 25.0);
	glVertex3f(30.0, 4.0, 25.0);
	glVertex3f(30.0, 6.0, 25.0);
	glVertex3f(28.0, 9.0, 25.0);
	glVertex3f(26.0, 10.0, 25.0);
	glVertex3f(-26.0, 10.0, 25.0);
	glVertex3f(-28.0, 9.0, 25.0);
	glVertex3f(-30.0, 6.0, 25.0);
	glVertex3f(-30.0, 4.0, 25.0);
	glVertex3f(-28.0, 1.0, 25.0);
	glVertex3f(-26.0, 0.0, 25.0);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(221/255.0f, 198/255.0f, 0/255.0f);
	glVertex3f(26.0, 0.0, 15.0);
	glVertex3f(28.0, 1.0, 15.0);
	glVertex3f(30.0, 4.0, 15.0);
	glVertex3f(30.0, 6.0, 15.0);
	glVertex3f(28.0, 9.0, 15.0);
	glVertex3f(26.0, 10.0, 15.0);
	glVertex3f(-26.0, 10.0, 15.0);
	glVertex3f(-28.0, 9.0, 15.0);
	glVertex3f(-30.0, 6.0, 15.0);
	glVertex3f(-30.0, 4.0, 15.0);
	glVertex3f(-28.0, 1.0, 15.0);
	glVertex3f(-26.0, 0.0, 15.0);
	glEnd();
	//selimut atas
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, 15.0);
	glVertex3f(26.0, 10.0, 26.0);
	glVertex3f(-26.0, 10.0, 26.0);
	glVertex3f(-26.0, 10.0, 15.0);
	glEnd();
	//selimut bawah
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, 25.0);
	glVertex3f(26.0, 0.0, 26.0);
	glVertex3f(-26.0, 0.0, 26.0);
	glVertex3f(-26.0, 0.0, 25.0);
	glEnd();
	//selimut ataskanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, 15.0);
	glVertex3f(26.0, 10.0, 26.0);
	glVertex3f(28.0, 9.0, 26.0);
	glVertex3f(28.0, 9.0, 15.0);
	glEnd();
	//selimut ataskanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 9.0, 15.0);
	glVertex3f(28.0, 9.0, 26.0);
	glVertex3f(30.0, 6.0, 26.0);
	glVertex3f(30.0, 6.0, 15.0);
	glEnd();
	//selimut sampingkanan
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(30.0, 6.0, 15.0);
	glVertex3f(30.0, 6.0, 26.0);
	glVertex3f(30.0, 4.0, 26.0);
	glVertex3f(30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 1.0, 15.0);
	glVertex3f(28.0, 1.0, 26.0);
	glVertex3f(30.0, 4.0, 26.0);
	glVertex3f(30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, 15.0);
	glVertex3f(26.0, 0.0, 26.0);
	glVertex3f(28.0, 1.0, 26.0);
	glVertex3f(28.0, 1.0, 15.0);
	glEnd();
	//selimut ataskiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 10.0, 15.0);
	glVertex3f(-26.0, 10.0, 26.0);
	glVertex3f(-28.0, 9.0, 26.0);
	glVertex3f(-28.0, 9.0, 15.0);
	glEnd();
	//selimut ataskiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 9.0, 15.0);
	glVertex3f(-28.0, 9.0, 26.0);
	glVertex3f(-30.0, 6.0, 26.0);
	glVertex3f(-30.0, 6.0, 15.0);
	glEnd();
	//selimut sampingkiri
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-30.0, 6.0, 15.0);
	glVertex3f(-30.0, 6.0, 26.0);
	glVertex3f(-30.0, 4.0, 26.0);
	glVertex3f(-30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 1.0, 15.0);
	glVertex3f(-28.0, 1.0, 26.0);
	glVertex3f(-30.0, 4.0, 26.0);
	glVertex3f(-30.0, 4.0, 15.0);
	glEnd();
	//selimut bawahkiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 0.0, 15.0);
	glVertex3f(-26.0, 0.0, 26.0);
	glVertex3f(-28.0, 1.0, 26.0);
	glVertex3f(-28.0, 1.0, 15.0);
	glEnd();

	//rantai kiri
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 218/255.0f, 0/255.0f);
	glVertex3f(26.0, 0.0, -25.0);
	glVertex3f(28.0, 1.0, -25.0);
	glVertex3f(30.0, 4.0, -25.0);
	glVertex3f(30.0, 6.0, -25.0);
	glVertex3f(28.0, 9.0, -25.0);
	glVertex3f(26.0, 10.0, -25.0);
	glVertex3f(-26.0, 10.0, -25.0);
	glVertex3f(-28.0, 9.0, -25.0);
	glVertex3f(-30.0, 6.0, -25.0);
	glVertex3f(-30.0, 4.0, -25.0);
	glVertex3f(-28.0, 1.0, -25.0);
	glVertex3f(-26.0, 0.0, -25.0);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(221/255.0f, 198/255.0f, 0/255.0f);
	glVertex3f(26.0, 0.0, -15.0);
	glVertex3f(28.0, 1.0, -15.0);
	glVertex3f(30.0, 4.0, -15.0);
	glVertex3f(30.0, 6.0, -15.0);
	glVertex3f(28.0, 9.0, -15.0);
	glVertex3f(26.0, 10.0,-15.0);
	glVertex3f(-26.0, 10.0, -15.0);
	glVertex3f(-28.0, 9.0, -15.0);
	glVertex3f(-30.0, 6.0, -15.0);
	glVertex3f(-30.0, 4.0, -15.0);
	glVertex3f(-28.0, 1.0, -15.0);
	glVertex3f(-26.0, 0.0, -15.0);
	glEnd();
	//selimut atas
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, -15.0);
	glVertex3f(26.0, 10.0, -26.0);
	glVertex3f(-26.0, 10.0, -26.0);
	glVertex3f(-26.0, 10.0, -15.0);
	glEnd();
	//selimut bawah
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, -25.0);
	glVertex3f(26.0, 0.0, -26.0);
	glVertex3f(-26.0, 0.0, -26.0);
	glVertex3f(-26.0, 0.0, -25.0);
	glEnd();
	//selimut ataskanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 10.0, -15.0);
	glVertex3f(26.0, 10.0, -26.0);
	glVertex3f(28.0, 9.0, -26.0);
	glVertex3f(28.0, 9.0, -15.0);
	glEnd();
	//selimut ataskanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 9.0, -15.0);
	glVertex3f(28.0, 9.0, -26.0);
	glVertex3f(30.0, 6.0, -26.0);
	glVertex3f(30.0, 6.0, -15.0);
	glEnd();
	//selimut sampingkanan
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(30.0, 6.0, -15.0);
	glVertex3f(30.0, 6.0, -26.0);
	glVertex3f(30.0, 4.0, -26.0);
	glVertex3f(30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkanan2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(28.0, 1.0, -15.0);
	glVertex3f(28.0, 1.0, -26.0);
	glVertex3f(30.0, 4.0, -26.0);
	glVertex3f(30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkanan1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(26.0, 0.0, -15.0);
	glVertex3f(26.0, 0.0, -26.0);
	glVertex3f(28.0, 1.0, -26.0);
	glVertex3f(28.0, 1.0, -15.0);
	glEnd();

	//selimut ataskiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 10.0, -15.0);
	glVertex3f(-26.0, 10.0, -26.0);
	glVertex3f(-28.0, 9.0, -26.0);
	glVertex3f(-28.0, 9.0, -15.0);
	glEnd();
	//selimut ataskiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 9.0, -15.0);
	glVertex3f(-28.0, 9.0, -26.0);
	glVertex3f(-30.0, 6.0, -26.0);
	glVertex3f(-30.0, 6.0, -15.0);
	glEnd();
	//selimut sampingkiri
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-30.0, 6.0, -15.0);
	glVertex3f(-30.0, 6.0, -26.0);
	glVertex3f(-30.0, 4.0, -26.0);
	glVertex3f(-30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkiri1
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-28.0, 1.0, -15.0);
	glVertex3f(-28.0, 1.0, -26.0);
	glVertex3f(-30.0, 4.0, -26.0);
	glVertex3f(-30.0, 4.0, -15.0);
	glEnd();
	//selimut bawahkiri2
	glBegin(GL_POLYGON);
	glColor3f(86/255.0f, 81/255.0f, 75/255.0f);
	glVertex3f(-26.0, 0.0, -15.0);
	glVertex3f(-26.0, 0.0, -26.0);
	glVertex3f(-28.0, 1.0, -26.0);
	glVertex3f(-28.0, 1.0, -15.0);
	glEnd();
	//penghubung rantai
	//dudukan atas bawah
	warna(248, 194, 92);
	atasbawah(35.0, 30.0, -15.0, 8.0, 15.0);
	atasbawah(35.0, 30.0, -15.0, 4.0, 15.0);
	////dudukan kiri kanan
	warna(155,155,155);
	kirikanan(30,4,-15,4,15);
	kirikanan(30,4,20,4,15);
	
	//leher
	//leher belakang
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(-10, 13.0, -3.0);
	glVertex3f(-10, 8.0, -3.0);
	glVertex3f(-3, 8.0, -10.0);
	glVertex3f(-3, 13.0, -10.0);
	glVertex3f(-3, 13.0, -10.0);
	glVertex3f(-3, 8.0, -10.0);
	glVertex3f(3, 8.0, -10.0);
	glVertex3f(3, 13.0, -10.0);
	glVertex3f(3, 13.0, -10.0);
	glVertex3f(3, 8.0, -10.0);
	glVertex3f(10, 8.0,-3.0);
	glVertex3f(10, 13.0, -3.0);
	glEnd();
	//leher depan
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(-10, 13.0, 3.0);
	glVertex3f(-10, 8.0, 3.0);
	glVertex3f(-3, 8.0, 10.0);
	glVertex3f(-3, 13.0, 10.0);
	glVertex3f(-3, 13.0, 10.0);
	glVertex3f(-3, 8.0, 10.0);
	glVertex3f(3, 8.0, 10.0);
	glVertex3f(3, 13.0, 10.0);
	glVertex3f(3, 13.0, 10.0);
	glVertex3f(3, 8.0, 10.0);
	glVertex3f(10, 8.0,3.0);
	glVertex3f(10, 13.0, 3.0);
	glEnd();
	//leher kanan
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(10, 13.0, -3.0);
	glVertex3f(10, 8.0, -3.0);
	glVertex3f(10, 8.0, 3.0);
	glVertex3f(10, 13.0, 3.0);
	glEnd();
	//kiri
	//leher kanan
	glBegin(GL_POLYGON);
	glColor3f(56/255.0f, 60/255.0f, 66/255.0f);
	glVertex3f(-10, 13.0, -3.0);
	glVertex3f(-10, 8.0, -3.0);
	glVertex3f(-10, 8.0, 3.0);
	glVertex3f(-10, 13.0, 3.0);
	glEnd();

	//bodi
	//bodi atas
	glBegin(GL_POLYGON);
	glColor3f(175/255.0f, 155/255.0f, 255/255.0f);
	glVertex3f(16, 35.0, 22.0);
	glVertex3f(16, 35.0, -22.0);
	glVertex3f(-35, 35.0, -22.0);
	glVertex3f(-40, 35.0, -15.0);
	glVertex3f(-40, 35.0, 15.0);
	glVertex3f(-35, 35.0, 22.0);
	glEnd();
	//lantai atas bodi
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(16, 36.0, 22.0);
	glVertex3f(16, 36.0, -22.0);
	glVertex3f(-35, 36.0, -22.0);
	glVertex3f(-40, 36.0, -15.0);
	glVertex3f(-40, 36.0, 15.0);
	glVertex3f(-35, 36.0, 22.0);
	glEnd();
	warna(0, 0,0);
	kirikanan(30, 1, -40, 35, 15);

	warna(0, 0,0);
	kirikanan(44, 1, 16, 35, 22);
	depanbelakang(51, 1, -35, 35, 22);
	depanbelakang(51, 1, -35, 35, -22);
	//bodi depan
	glBegin(GL_POLYGON);
	glColor3f(270/255.0f, 218/255.0f, 0/255.0f);
	glVertex3f(16, 35.0, 22.0);
	glVertex3f(16, 35.0, -22.0);
	glVertex3f(16, 18.0, -22.0);
	glVertex3f(16, 13.0, -15.0);
	glVertex3f(16, 13.0, 15.0);
	glVertex3f(16, 18.0, 22.0);
	glVertex3f(16, 35.0, 22.0);
	glEnd();
	//depan2
	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(10, 35.0, 22.0);
	glVertex3f(10, 35.0, -22.0);
	glVertex3f(10, 18.0, -22.0);
	glVertex3f(10, 13.0, -15.0);
	glVertex3f(10, 13.0, 15.0);
	glVertex3f(10, 18.0, 22.0);
	glVertex3f(10, 35.0, 22.0);
	glEnd();
	//bawah miring kanan
	glBegin(GL_POLYGON);
	glColor3f(240/255.0f, 188/255.0f, 0/255.0f);
	glVertex3f(10, 18.0, 22.0);
	glVertex3f(16, 18.0, 22.0);
	glVertex3f(16, 13.0, 15.0);
	glVertex3f(10, 13.0, 15.0);
	glEnd();
	//bawah miring kiri
	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(10, 18.0, -22.0);
	glVertex3f(16, 18.0, -22.0);
	glVertex3f(16, 13.0, -15.0);
	glVertex3f(10, 13.0, -15.0);
	glEnd();
	//depan kanan kiri
	warna(265, 213, 0);
	depanbelakang(6, 17, 10, 18, -22);
	depanbelakang(6, 17, 10, 18, 22);
	kirikanan(30, 22, -40, 13, 15);

	//belakang miring
	glBegin(GL_POLYGON);
	glColor3f(235/255.0f, 183/255.0f, 0/255.0f);
	glVertex3f(-40, 35.0, 15.0);
	glVertex3f(-40, 13.0, 15.0);
	glVertex3f(-35, 13.0, 22.0);
	glVertex3f(-35, 35.0, 22.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(235/255.0f, 183/255.0f, 0/255.0f);
	glVertex3f(-40, 35.0, -15.0);
	glVertex3f(-40, 13.0, -15.0);
	glVertex3f(-35, 13.0, -22.0);
	glVertex3f(-35, 35.0, -22.0);
	glEnd();

	//belakang2
	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(-28.2, 35.0, 22.0);
	glVertex3f(-28.2, 13.0, 22.0);
	glVertex3f(-28.2, 13.0, -22.0);
	glVertex3f(-28.2, 35.0, -22.0);
	glEnd();
	//belakang bawah
	glBegin(GL_POLYGON);
	glColor3f(145/255.0f, 93/255.0f, 0/255.0f);
	glVertex3f(-28.2, 13.1, 22.0);
	glVertex3f(-35, 13.1, 22.0);
	glVertex3f(-40, 13.1, 15.0);
	glVertex3f(-40, 13.1, -15.0);
	glVertex3f(-35, 13.1, -22.0);
	glVertex3f(-28.2, 13.1, -22.0);
	glEnd();

	//bodi belakang
	warna(265, 213, 0);
	depanbelakang(7, 22, -35, 13, 22);
	depanbelakang(7, 22, -35, 13, -22);

	//bodi tengah
	//depan belakang
	warna(265, 213, 0);
	kirikanan(44,17,9.9,18,22);
	kirikanan(44,17,-28,18,22);
	kirikanan(32,5,9.9,13,16);
	kirikanan(32, 5, -28, 13, 16);
	//kanan kiri
	warna(265, 213, 0);
	depanbelakang(38, 17, -28, 18, 22);
	depanbelakang(38, 17, -28, 18, -22);
	warna(205, 153, 0);
	atasbawah(38, 6.8, -28, 18, 22);
	atasbawah(38, 6.8, -28, 18, -16);
	warna(225, 173, 0);
	depanbelakang(38, 5, -28, 13, 16);
	depanbelakang(38, 5, -28, 13, -16);
	warna(56, 60, 66);
	atasbawah(38, 32, -28, 13, 16);

	//ruang kendali
	depanbelakang(2,12,13,35,22);
	depanbelakang(2,12,-2,35,22);
	depanbelakang(2,12,-2,35,7);
	depanbelakang(2,12,13,35,7);
	depanbelakang(15,3,-2,35,22);
	depanbelakang(15,3,-2,35,7);
	depanbelakang(15,3,-2,44,22);
	depanbelakang(15,3,-2,44,7);
	kirikanan(2,12,15,35,22);
	kirikanan(2,12,-2,35,22);
	kirikanan(2,12,-2,35,9);
	kirikanan(2,12,15,35,9);
	kirikanan(15,3,15,35,22);
	kirikanan(15,3,-2,35,22);
	kirikanan(15,3,-2,44,22);
	kirikanan(15,3,15,44,22);
	warna(0,0,0);
	atasbawah(17,15,-2,47,22);

	//sendi sehat
	warna(56, 60, 66);
	depanbelakang(5, 8, 16, 20, 3);
	depanbelakang(5, 8, 16, 20, -3);
	atasbawah(5, 6, 16, 20, 3);
	atasbawah(5, 6, 16, 28, 3);
	kirikanan(6, 8, 21, 20, 3);
	//tulang
	glBegin(GL_POLYGON);
	glColor3f(50/255.0f, 67/255.0f, 56/255.0f);
	glVertex3f(19, 26, 4);
	glVertex3f(19, 26, -4);
	glVertex3f(80, 61, -4);
	glVertex3f(80, 61, 4);
	glEnd();
	//tulang bawah
	glBegin(GL_POLYGON);
	glColor3f(50/255.0f, 67/255.0f, 56/255.0f);
	glVertex3f(19, 20, 4);
	glVertex3f(19, 20, -4);
	glVertex3f(80, 55, -4);
	glVertex3f(80, 55, 4);
	glEnd();
	//selimut tulang
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(19, 20, 4);
	glVertex3f(19, 20, -4);
	glVertex3f(19, 26, -4);
	glVertex3f(19, 26, 4);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(80, 61, 4);
	glVertex3f(80, 61, -4);
	glVertex3f(80, 55, -4);
	glVertex3f(80, 55, 4);
	glEnd();
	//tulang samping
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(19, 20, 4);
	glVertex3f(19, 26, 4);
	glVertex3f(80, 61, 4);
	glVertex3f(80, 55, 4);
	glEnd();
	//samping kiri
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(19, 20, -4);
	glVertex3f(19, 26, -4);
	glVertex3f(80, 61, -4);
	glVertex3f(80, 55, -4);
	glEnd();
	//batang
	//batang kanan
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(40, 61, 4);
	glVertex3f(44, 61, 4);
	glVertex3f(64, 18, 4);
	glVertex3f(59, 18, 4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(40, 61, 8);
	glVertex3f(44, 61, 8);
	glVertex3f(64, 18, 8);
	glVertex3f(59, 18, 8);
	glEnd();
	//selimut kanan
	glBegin(GL_POLYGON);
	glColor3f(50/255.0f, 67/255.0f, 56/255.0f);
	glVertex3f(40, 61, 8);
	glVertex3f(40, 61, 4);
	glVertex3f(59, 18, 4);
	glVertex3f(59, 18, 8);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(50/255.0f, 67/255.0f, 56/255.0f);
	glVertex3f(44, 61, 8);
	glVertex3f(44, 61, 4);
	glVertex3f(64, 18, 4);
	glVertex3f(64, 18, 8);
	glEnd();
	//batang kiri
	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(40, 61, -4);
	glVertex3f(44, 61, -4);
	glVertex3f(64, 18, -4);
	glVertex3f(59, 18, -4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0/255.0f, 0/255.0f, 0/255.0f);
	glVertex3f(40, 61, -8);
	glVertex3f(44, 61, -8);
	glVertex3f(64, 18, -8);
	glVertex3f(59, 18, -8);
	glEnd();
	//selimut kiri
	glBegin(GL_POLYGON);
	glColor3f(50/255.0f, 67/255.0f, 56/255.0f);
	glVertex3f(40, 61, -4);
	glVertex3f(40, 61, -8);
	glVertex3f(59, 18, -8);
	glVertex3f(59, 18, -4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(50/255.0f, 67/255.0f, 56/255.0f);
	glVertex3f(44, 61, -4);
	glVertex3f(44, 61, -8);
	glVertex3f(64, 18, -8);
	glVertex3f(64, 18, -4);
	glEnd();

	//cakruk
	warna(245, 193, 0);
	atasbawah(15, 18, 53, 18, 9);
	atasbawah(22, 18, 53, 3, 9);
	kirikanan(18, 15, 53, 3, 9);
	warna(145, 93, 0);
	kirikanan(18, 15, 55, 3, 9);
	//cakruk kanan
	glBegin(GL_POLYGON);
	glColor3f(245, 193, 0);
	glVertex3f(53, 18, -9);
	glVertex3f(53, 3, -9);
	glVertex3f(75, 3, -9);
	glVertex3f(68, 9, -9);
	glVertex3f(68, 18, -9);
	glEnd();
	//cakruk kiri
	glBegin(GL_POLYGON);
	glColor3f(245, 193, 0);
	glVertex3f(53, 18, 9);
	glVertex3f(53, 3, 9);
	glVertex3f(75, 3, 9);
	glVertex3f(68, 9, 9);
	glVertex3f(68, 18, 9);
	glEnd();

	//ruang belakang
	warna(0, 0,0);
	kirikanan(30, 5, -40, 36, 15);
	warna(265, 213, 0);
	depanbelakang(20, 10, -40, 36, 15);
	depanbelakang(20, 10, -40, 36, -15);
	depanbelakang(15, 3, -33, 46, 17);
	depanbelakang(15, 3, -33, 46, -17);
	kirikanan(34, 3, -18, 46, 17);
	warna(235, 183, 0);
	kirikanan(30, 5, -40, 41, 15);
	kirikanan(30, 10, -20, 36, 15);
	atasbawah(24, 34, -42, 46, 17);
	atasbawah(15, 34, -33, 49, 17); 

	glBegin(GL_POLYGON);
	glColor3f(245/255.0f, 193/255.0f, 0/255.0f);
	glVertex3f(-42, 46, 17);
	glVertex3f(-42, 46, -17);
	glVertex3f(-33, 49, -17);
	glVertex3f(-33, 49, 17);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(235, 183, 0);
	glVertex3f(-42, 46, 17);
	glVertex3f(-33, 46, 17);
	glVertex3f(-33, 49, 17);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(235, 183, 0);
	glVertex3f(-42, 46, -17);
	glVertex3f(-33, 46, -17);
	glVertex3f(-33, 49, -17);
	glEnd();

	//cagak
	warna(0, 0,0);
	depanbelakang(3, 14, -13, 36, 3);
	depanbelakang(3, 14, -4, 36, 3);
	depanbelakang(3, 14, -13, 36, 5);
	depanbelakang(3, 14, -4, 36, 5);

	depanbelakang(3, 14, -13, 36, -3);
	depanbelakang(3, 14, -4, 36, -3);
	depanbelakang(3, 14, -13, 36, -5);
	depanbelakang(3, 14, -4, 36, -5);

	warna(50, 67, 50);
	kirikanan(2, 14, -13, 36, 5);
	kirikanan(2, 14, -10, 36, 5);
	kirikanan(2, 14, -4, 36, 5);
	kirikanan(2, 14, -1, 36, 5);

	kirikanan(2, 14, -13, 36, -3);
	kirikanan(2, 14, -10, 36, -3);
	kirikanan(2, 14, -4, 36, -3);
	kirikanan(2, 14, -1, 36, -3);

	//alas cagak
	atasbawah(18, 16, -17, 50, 8);
	warna(15, 10,8);
	atasbawah(9, 12, -15, 55, 6);
	warna(0,0,0);
	kirikanan(12, 5, -15, 50, 6);
	kirikanan(12, 5, -6, 50, 6);
	depanbelakang(9, 5, -15, 50, 6);
	depanbelakang(9, 5, -15, 50, -6);

	//alas tangga kanan
	warna(0,0,0);
	atasbawah(50, 5, -35, 20, 27);
	atasbawah(50, 5, -35, 18, 27);
	kirikanan(5, 2, -35, 18, 27); 
	kirikanan(5, 2, 15, 18, 27); 
	warna(50, 67, 50);
	depanbelakang(50, 2, -35, 18, 27);
	depanbelakang(15, 2, -15, 18, 35);
	warna(0,0,0);
	atasbawah(15, 8, -15, 18, 35);
	atasbawah(15, 8, -15, 20, 35);
	kirikanan(8, 2, -15,18, 35);
	kirikanan(8, 2, 0, 18, 35);

	//tangga kanan
	glBegin(GL_POLYGON);
	warna(0,0,0);
	glVertex3f(-30, 0, 34);
	glVertex3f(-30, 0, 29);
	glVertex3f(-15, 20, 29);
	glVertex3f(-15, 20, 34);
	glEnd();

	//alas atas tangga
	atasbawah(15, 8, -35, 35, 30);
	atasbawah(15, 8, -35, 33, 30);
	kirikanan(8, 2, -35, 33, 30);
	kirikanan(8, 2, -20, 33, 30);
	warna(50, 67, 50);
	depanbelakang(15, 2, -35, 33, 30);

	//tangga atas
	glBegin(GL_POLYGON);
	warna(0,0,0);
	glVertex3f(-20, 35, 24);
	glVertex3f(-20, 35, 27);
	glVertex3f(-5, 20, 27);
	glVertex3f(-5, 20, 24);
	glEnd();

	//alas tangga kiri
	warna(0,0,0);
	atasbawah(50, 5, -35, 20, -22);
	atasbawah(50, 5, -35, 18, -22);
	kirikanan(5, 2, -35, 18, -22); 
	kirikanan(5, 2, 15, 18, -22); 
	warna(50, 67, 50);
	depanbelakang(50, 2, -35, 18, -27);

	//pagar kanan
	glBegin(GL_LINE_LOOP);
	warna(265, 213, 0);
	glVertex3f(-34, 35, 22);
	glVertex3f(-34, 35, 29);
	glVertex3f(-34, 40, 29);
	glVertex3f(-34, 40, 22);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-34, 35, 25.5);
	glVertex3f(-34, 40, 25.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	warna(265, 213, 0);
	glVertex3f(-34, 35, 29);
	glVertex3f(-34, 40, 29);
	glVertex3f(-21, 40, 29);
	glVertex3f(-21, 35, 29);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-30.7, 35, 29);
	glVertex3f(-30.7, 40, 29);
	glVertex3f(-27.4, 40, 29);
	glVertex3f(-27.4, 35, 29);
	glVertex3f(-24.1, 35, 29);
	glVertex3f(-24.1, 40, 29);
	glEnd();

	glBegin(GL_LINE_LOOP);
	warna(265, 213, 0);
	glVertex3f(-19, 36, 21);
	glVertex3f(-19, 40, 21);
	glVertex3f(-2, 40, 21);
	glVertex3f(-2, 36, 21);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-16, 36, 21);
	glVertex3f(-16, 40, 21);
	glVertex3f(-13, 40, 21);
	glVertex3f(-13, 36, 21);
	glVertex3f(-10, 36, 21);
	glVertex3f(-10, 40, 21);
	glVertex3f(-7, 40, 21);
	glVertex3f(-7, 36, 21);
	glVertex3f(-4, 36, 21);
	glVertex3f(-4, 40, 21);
	glEnd();

	//pagar kiri
	glBegin(GL_LINE_LOOP);
	warna(265, 213, 0);
	glVertex3f(-35, 36, -21);
	glVertex3f(-35, 40, -21);
	glVertex3f(15, 40, -21);
	glVertex3f(15, 36, -21);
	glEnd();
	glBegin(GL_LINES);
	warna(265, 213, 0);
	glVertex3f(-32, 36, -21);
	glVertex3f(-32, 40, -21);
	glVertex3f(-29, 40, -21);
	glVertex3f(-29, 36, -21);
	glVertex3f(-26, 36, -21);
	glVertex3f(-26, 40, -21);
	glVertex3f(-23, 40, -21);
	glVertex3f(-23, 36, -21);
	glVertex3f(-20, 36, -21);
	glVertex3f(-20, 40, -21);
	glVertex3f(-17, 40, -21);
	glVertex3f(-17, 36, -21);
	glVertex3f(-14, 36, -21);
	glVertex3f(-14, 40, -21);
	glVertex3f(-11, 40, -21);
	glVertex3f(-11, 36, -21);
	glVertex3f(-8, 36, -21);
	glVertex3f(-8, 40, -21);
	glVertex3f(-5, 40, -21);
	glVertex3f(-5, 36, -21);
	glVertex3f(-2, 36, -21);
	glVertex3f(-2, 40, -21);
	glVertex3f(1, 40, -21);
	glVertex3f(1, 36, -21);
	glVertex3f(4, 36, -21);
	glVertex3f(4, 40, -21);
	glVertex3f(7, 40, -21);
	glVertex3f(7, 36, -21);
	glVertex3f(10, 36, -21);
	glVertex3f(10, 40, -21);
	glVertex3f(13, 40, -21);
	glVertex3f(13, 36, -21);
	glEnd();

	glBegin(GL_LINE_LOOP);
	warna(265, 213, 0);
	glVertex3f(15, 36, -21);
	glVertex3f(15, 40, -21);
	glVertex3f(15, 40, 7);
	glVertex3f(15, 36, 7);
	glEnd();
	glBegin(GL_LINES);
	warna(265, 213, 0);
	glVertex3f(15, 36, -18);
	glVertex3f(15, 40, -18);
	glVertex3f(15, 40, -15);
	glVertex3f(15, 36, -15);
	glVertex3f(15, 36, -12);
	glVertex3f(15, 40, -12);
	glVertex3f(15, 40, -9);
	glVertex3f(15, 36, -9);
	glVertex3f(15, 36, -6);
	glVertex3f(15, 40, -6);
	glVertex3f(15, 40, -3);
	glVertex3f(15, 36, -3);
	glVertex3f(15, 36, 0);
	glVertex3f(15, 40, 0);
	glVertex3f(15, 40, 3);
	glVertex3f(15, 36, 3);
	glEnd();

	//jalan
	warna(0,0,0);
	atasbawah(70,35,80,1,20);
	atasbawah(25,100,80,1,20);
	warna(255,255,255);
	atasbawah(5,20,90,1.2,-5);
	atasbawah(5,20,90,1.2,-40);
	
	//truck dump
	//sangga supir
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 19, -15);
	glVertex3f(100, 19, 15);
	glVertex3f(110, 19, 15);
	glVertex3f(110, 19, -15);
	glEnd();
	//sangga kiri
	//depan
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 20, 10);
	glVertex3f(100, 19, 10);
	glVertex3f(100, 19, 15);
	glVertex3f(100, 20, 15);
	glEnd();
	//luar
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 19, 15);
	glVertex3f(100, 20, 15);
	glVertex3f(110, 20, 15);
	glVertex3f(110, 19, 15);
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(110, 20, 10);
	glVertex3f(110, 19, 10);
	glVertex3f(110, 19, 15);
	glVertex3f(110, 20, 15);
	glEnd();
	//sangga kanan
	//depan
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 20, -10);
	glVertex3f(100, 19, -10);
	glVertex3f(100, 19, -15);
	glVertex3f(100, 20, -15);
	glEnd();
	//luar
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 19, -15);
	glVertex3f(100, 20, -15);
	glVertex3f(110, 20, -15);
	glVertex3f(110, 19, -15);
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(110, 20, -10);
	glVertex3f(110, 19, -10);
	glVertex3f(110, 19, -15);
	glVertex3f(110, 20, -15);
	glEnd();

	//depan
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 5, -10);
	glVertex3f(100, 20, -10);
	glVertex3f(100, 20, 10);
	glVertex3f(100, 5, 10);
	glEnd();
	//depan hitam
	glBegin(GL_POLYGON);
	glColor3f(31/255.0f, 31/255.0f, 31/255.0f);
	glVertex3f(99.9, 6, -9);
	glVertex3f(99.9, 19, -9);
	glVertex3f(99.9, 19, 9);
	glVertex3f(99.9, 6, 9);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(100, 20, -15);
	glVertex3f(100, 20, 15);
	glVertex3f(110, 20, 15);
	glVertex3f(110, 20, -15);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(271/255.0f, 239/255.0f, 30/255.0f);
	glVertex3f(120, 5, -10);
	glVertex3f(110, 20, -10);
	glVertex3f(110, 20, 10);
	glVertex3f(120, 5, 10);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(100, 5, 10);
	glVertex3f(100, 20, 10);
	glVertex3f(110, 20, 10);
	glVertex3f(120, 5, 10);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(100, 5, -10);
	glVertex3f(100, 20, -10);
	glVertex3f(110, 20, -10);
	glVertex3f(120, 5, -10);
	glEnd();
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(100, 5, -10);
	glVertex3f(100, 5, 10);
	glVertex3f(120, 5, 10);
	glVertex3f(120, 5, -10);
	glEnd();
	//badan bawah
	//bawah
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(120, 5, -10);
	glVertex3f(120, 5, 10);
	glVertex3f(135, 5, 10);
	glVertex3f(135, 5, -10);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(115, 7, -10);
	glVertex3f(115, 7, 10);
	glVertex3f(135, 7, 10);
	glVertex3f(135, 7, -10);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(115, 5, 10);
	glVertex3f(115, 7, 10);
	glVertex3f(135, 7, 10);
	glVertex3f(135, 5, 10);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(115, 5, -10);
	glVertex3f(115, 7, -10);
	glVertex3f(135, 7, -10);
	glVertex3f(135, 5, -10);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(271/255.0f, 239/255.0f, 20/255.0f);
	glVertex3f(135, 5, 10);
	glVertex3f(135, 7, 10);
	glVertex3f(135, 7, -10);
	glVertex3f(135, 5, -10);
	glEnd();

	//ban
	//ban depan kiri
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(108.5, 0, 10);
	glVertex3f(111.5, 0, 10);
	glVertex3f(115, 3.5, 10);
	glVertex3f(115, 6.5, 10);
	glVertex3f(111.5, 10, 10);
	glVertex3f(108.5, 10, 10);
	glVertex3f(105, 6.5, 10);
	glVertex3f(105, 3.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(108.5, 0, 15);
	glVertex3f(111.5, 0, 15);
	glVertex3f(115, 3.5, 15);
	glVertex3f(115, 6.5, 15);
	glVertex3f(111.5, 10, 15);
	glVertex3f(108.5, 10, 15);
	glVertex3f(105, 6.5, 15);
	glVertex3f(105, 3.5, 15);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(108.5, 0, 10);
	glVertex3f(108.5, 0, 15);
	glVertex3f(105, 3.5, 15);
	glVertex3f(105, 3.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(105, 3.5, 10);
	glVertex3f(105, 3.5, 15);
	glVertex3f(105, 6.5, 15);
	glVertex3f(105, 6.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(105, 6.5, 10);
	glVertex3f(105, 6.5, 15);
	glVertex3f(108.5, 10, 15);
	glVertex3f(108.5, 10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(108.5, 10, 10);
	glVertex3f(108.5, 10, 15);
	glVertex3f(111.5, 10, 15);
	glVertex3f(111.5, 10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(111.5, 0, 10);
	glVertex3f(111.5, 0, 15);
	glVertex3f(115, 3.5, 15);
	glVertex3f(115, 3.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(115, 3.5, 10);
	glVertex3f(115, 3.5, 15);
	glVertex3f(115, 6.5, 15);
	glVertex3f(115, 6.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(115, 6.5, 10);
	glVertex3f(115, 6.5, 15);
	glVertex3f(111.5, 10, 15);
	glVertex3f(111.5, 10, 10);
	glEnd();
	//ban depan kanan
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(108.5, 0, -10);
	glVertex3f(111.5, 0, -10);
	glVertex3f(115, 3.5, -10);
	glVertex3f(115, 6.5, -10);
	glVertex3f(111.5, 10, -10);
	glVertex3f(108.5, 10, -10);
	glVertex3f(105, 6.5, -10);
	glVertex3f(105, 3.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(108.5, 0, -15);
	glVertex3f(111.5, 0, -15);
	glVertex3f(115, 3.5, -15);
	glVertex3f(115, 6.5, -15);
	glVertex3f(111.5, 10,-15);
	glVertex3f(108.5, 10, -15);
	glVertex3f(105, 6.5, -15);
	glVertex3f(105, 3.5, -15);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(108.5, 0, -10);
	glVertex3f(108.5, 0, -15);
	glVertex3f(105, 3.5, -15);
	glVertex3f(105, 3.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(105, 3.5, -10);
	glVertex3f(105, 3.5, -15);
	glVertex3f(105, 6.5, -15);
	glVertex3f(105, 6.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(105, 6.5, -10);
	glVertex3f(105, 6.5, -15);
	glVertex3f(108.5, 10,-15);
	glVertex3f(108.5, 10, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(108.5, 10, -10);
	glVertex3f(108.5, 10, -15);
	glVertex3f(111.5, 10, -15);
	glVertex3f(111.5, 10, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(111.5, 0, -10);
	glVertex3f(111.5, 0, -15);
	glVertex3f(115, 3.5, -15);
	glVertex3f(115, 3.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(115, 3.5, -10);
	glVertex3f(115, 3.5, -15);
	glVertex3f(115, 6.5, -15);
	glVertex3f(115, 6.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(115, 6.5, -10);
	glVertex3f(115, 6.5, -15);
	glVertex3f(111.5, 10,-15);
	glVertex3f(111.5, 10, -10);
	glEnd();
	//ban belakang kiri
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(133.5, 0, 10);
	glVertex3f(136.5, 0, 10);
	glVertex3f(140, 3.5, 10);
	glVertex3f(140, 6.5, 10);
	glVertex3f(136.5, 10, 10);
	glVertex3f(133.5, 10, 10);
	glVertex3f(130, 6.5, 10);
	glVertex3f(130, 3.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(133.5, 0, 15);
	glVertex3f(136.5, 0, 15);
	glVertex3f(140, 3.5, 15);
	glVertex3f(140, 6.5, 15);
	glVertex3f(136.5, 10, 15);
	glVertex3f(133.5, 10, 15);
	glVertex3f(130, 6.5, 15);
	glVertex3f(130, 3.5, 15);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(133.5, 0, 10);
	glVertex3f(133.5, 0, 15);
	glVertex3f(130, 3.5, 15);
	glVertex3f(130, 3.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(130, 3.5, 10);
	glVertex3f(130, 3.5, 15);
	glVertex3f(130, 6.5, 15);
	glVertex3f(130, 6.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(130, 6.5, 10);
	glVertex3f(130, 6.5, 15);
	glVertex3f(133.5, 10, 15);
	glVertex3f(133.5, 10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(133.5, 10, 10);
	glVertex3f(133.5, 10, 15);
	glVertex3f(136.5, 10, 15);
	glVertex3f(136.5, 10, 10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(136.5, 0, 10);
	glVertex3f(136.5, 0, 15);
	glVertex3f(140, 3.5, 15);
	glVertex3f(140, 3.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(140, 3.5, 10);
	glVertex3f(140, 3.5, 15);
	glVertex3f(140, 6.5, 15);
	glVertex3f(140, 6.5, 10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(140, 6.5, 10);
	glVertex3f(140, 6.5, 15);
	glVertex3f(136.5, 10, 15);
	glVertex3f(136.5, 10, 10);
	glEnd();
	//ban belakang kanan
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(133.5, 0, -10);
	glVertex3f(136.5, 0, -10);
	glVertex3f(140, 3.5, -10);
	glVertex3f(140, 6.5, -10);
	glVertex3f(136.5, 10, -10);
	glVertex3f(133.5, 10, -10);
	glVertex3f(130, 6.5, -10);
	glVertex3f(130, 3.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(133.5, 0, -15);
	glVertex3f(136.5, 0, -15);
	glVertex3f(140, 3.5, -15);
	glVertex3f(140, 6.5, -15);
	glVertex3f(136.5, 10, -15);
	glVertex3f(133.5, 10, -15);
	glVertex3f(130, 6.5, -15);
	glVertex3f(130, 3.5, -15);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(133.5, 0, -10);
	glVertex3f(133.5, 0, -15);
	glVertex3f(130, 3.5, -15);
	glVertex3f(130, 3.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(130, 3.5, -10);
	glVertex3f(130, 3.5, -15);
	glVertex3f(130, 6.5, -15);
	glVertex3f(130, 6.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(130, 6.5, -10);
	glVertex3f(130, 6.5, -15);
	glVertex3f(133.5, 10, -15);
	glVertex3f(133.5, 10, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(133.5, 10, -10);
	glVertex3f(133.5, 10, -15);
	glVertex3f(136.5, 10, -15);
	glVertex3f(136.5, 10, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(136.5, 0, -10);
	glVertex3f(136.5, 0, -15);
	glVertex3f(140, 3.5, -15);
	glVertex3f(140, 3.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(140, 3.5, -10);
	glVertex3f(140, 3.5, -15);
	glVertex3f(140, 6.5, -15);
	glVertex3f(140, 6.5, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(45/255.0f, 45/255.0f, 45/255.0f);
	glVertex3f(140, 6.5, -10);
	glVertex3f(140, 6.5, -15);
	glVertex3f(136.5, 10, -15);
	glVertex3f(136.5, 10, -10);
	glEnd();
	//tempat sopir
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(100, 20, 15);
	glVertex3f(100, 20, 5);
	glVertex3f(100, 25, 5);
	glVertex3f(100, 25, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(110, 20, 15);
	glVertex3f(110, 20, 5);
	glVertex3f(107, 25, 5);
	glVertex3f(107, 25, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(100, 20, 15);
	glVertex3f(100, 25, 15);
	glVertex3f(107, 25, 15);
	glVertex3f(110, 20, 15);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(55/255.0f, 55/255.0f, 55/255.0f);
	glVertex3f(100, 20, 5);
	glVertex3f(100, 25, 5);
	glVertex3f(107, 25, 5);
	glVertex3f(110, 20, 5);
	glEnd();
	//bak
	//depan atas
	glBegin(GL_POLYGON);
	glColor3f(231/255.0f, 199/255.0f, 0/255.0f);
	glVertex3f(100, 25, -15);
	glVertex3f(100, 25, 15);
	glVertex3f(110, 25, 15);
	glVertex3f(110, 25, -15);
	glEnd();
	//depan
	glBegin(GL_POLYGON);
	glColor3f(255/255.0f, 255/255.0f, 20/255.0f);
	glVertex3f(110, 25, -15);
	glVertex3f(110, 25, 15);
	glVertex3f(120, 7, 15);
	glVertex3f(120, 7, -15);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glColor3f(235/255.0f, 235/255.0f, 20/255.0f);
	glVertex3f(120, 7, -15);
	glVertex3f(120, 7, 15);
	glVertex3f(150, 22, 15);
	glVertex3f(150, 22, -15);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(112.6, 20, 15);
	glVertex3f(120, 7, 15);
	glVertex3f(150, 22, 15);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glColor3f(251/255.0f, 219/255.0f, 20/255.0f);
	glVertex3f(112.6, 20, -15);
	glVertex3f(120, 7, -15);
	glVertex3f(150, 22, -15);
	glEnd();

	//conveyor
		//alas
	warna(130, 130, 130);
	atasbawah(10,50,57,13,80);
		//selimut
	warna(255, 0, 0);
	depanbelakang(10,5,57,13,80);
	kirikanan(50,5,67,13,80);
	kirikanan(50,5,68,13,80);
	atasbawah(1,50,67,13,80);
	atasbawah(1,50,67,18,80);
	kirikanan(40,5,57,13,70);
	kirikanan(40,5,56,13,70);
	atasbawah(1,40,56,13,70);
	atasbawah(1,40,56,18,70);
	kirikanan(50,5,-130,60,80);
	kirikanan(40,5,-120,60,70);
		//kaki
	warna(255, 204, 0);
	depanbelakang(1,13,57,0,80);
	depanbelakang(1,13,57,0,79);
	kirikanan(1,13,57,0,80);
	kirikanan(1,13,58,0,80);
	depanbelakang(1,13,67,0,80);
	depanbelakang(1,13,67,0,79);
	kirikanan(1,13,67,0,80);
	kirikanan(1,13,68,0,80);
		warna(255, 204, 0);
	depanbelakang(1,13,57,0,31);
	depanbelakang(1,13,57,0,30);
	kirikanan(1,13,57,0,31);
	kirikanan(1,13,58,0,31);
	depanbelakang(1,13,67,0,31);
	depanbelakang(1,13,67,0,30);
	kirikanan(1,13,67,0,31);
	kirikanan(1,13,68,0,31);
		warna(255, 204, 0);
	depanbelakang(1,13,57,0,50);
	depanbelakang(1,13,57,0,49);
	kirikanan(1,13,57,0,50);
	kirikanan(1,13,58,0,50);
	depanbelakang(1,13,67,0,50);
	depanbelakang(1,13,67,0,49);
	kirikanan(1,13,67,0,50);
	kirikanan(1,13,68,0,50);
	warna(255, 204, 0);
	depanbelakang(1,13,57,0,65);
	depanbelakang(1,13,57,0,64);
	kirikanan(1,13,57,0,65);
	kirikanan(1,13,58,0,65);
	depanbelakang(1,13,67,0,65);
	depanbelakang(1,13,67,0,64);
	kirikanan(1,13,67,0,65);
	kirikanan(1,13,68,0,65);

	depanbelakang(1,60,-130,0,31);
	depanbelakang(1,60,-130,0,30);
	kirikanan(1,60,-130,0,31);
	kirikanan(1,60,-129,0,31);
	depanbelakang(1,60,-121,0,31);
	depanbelakang(1,60,-121,0,30);
	kirikanan(1,60,-121,0,31);
	kirikanan(1,60,-120,0,31);

	glBegin(GL_POLYGON);
	warna(130, 130, 130);
	glVertex3f(57,13,80);
	glVertex3f(57,13,70);
	glVertex3f(-80,60,70);
	glVertex3f(-80,60,80);
	glEnd();
	glBegin(GL_POLYGON);
	warna(255, 0, 0);
	glVertex3f(57,13,80);
	glVertex3f(-80,60,80);
	glVertex3f(-80,65,80);
	glVertex3f(57,18,80);
	glEnd();
	glBegin(GL_POLYGON);
	warna(255, 0, 0);
	glVertex3f(57,13,70);
	glVertex3f(-80,60,70);
	glVertex3f(-80,65,70);
	glVertex3f(57,18,70);
	glEnd();

	warna(130, 130, 130);
	atasbawah(50,10,-130,60,80);
	atasbawah(10,50,-130,60,80);
	warna(255, 0, 0);
	depanbelakang(50,5,-130,60,80);
	depanbelakang(40,5,-120,60,70);
	//kaki
	warna(255, 204, 0);
	depanbelakang(1,32,0,0,80);
	depanbelakang(1,32,0,0,79);
	kirikanan(1,32,0,0,80);
	kirikanan(1,32,1,0,80);
	depanbelakang(1,32,0,0,71);
	depanbelakang(1,32,0,0,70);
	kirikanan(1,32,0,0,71);
	kirikanan(1,32,1,0,71);
	depanbelakang(1,59,-80,0,80);
	depanbelakang(1,59,-80,0,79);
	kirikanan(1,59,-80,0,80);
	kirikanan(1,59,-79,0,80);
	depanbelakang(1,59,-80,0,71);
	depanbelakang(1,59,-80,0,70);
	kirikanan(1,59,-80,0,71);
	kirikanan(1,59,-79,0,71);

	depanbelakang(1,60,-130,0,80);
	depanbelakang(1,60,-130,0,79);
	kirikanan(1,60,-130,0,80);
	kirikanan(1,60,-129,0,80);
	depanbelakang(1,60,-130,0,71);
	depanbelakang(1,60,-130,0,70);
	kirikanan(1,60,-130,0,71);
	kirikanan(1,60,-129,0,71);

	//gunungbatubara
	glBegin(GL_POLYGON);
	warna(0, 0, 0);
	glVertex3f(-100,0,20);
	glVertex3f(-150,0,20);
	glVertex3f(-120,60,-10);
	glEnd();
	glBegin(GL_POLYGON);
	warna(0, 0, 0);
	glVertex3f(-100,0,-30);
	glVertex3f(-150,0,-30);
	glVertex3f(-120,60,-10);
	glEnd();
	glBegin(GL_POLYGON);
	warna(0, 0, 0);
	glVertex3f(-100,0,20);
	glVertex3f(-100,0,-30);
	glVertex3f(-120,60,-10);
	glEnd();
	glBegin(GL_POLYGON);
	warna(0, 0, 0);
	glVertex3f(-150,0,-30);
	glVertex3f(-150,0,20);
	glVertex3f(-120,60,-10);
	glEnd();

	//kantor
	warna(189, 190, 191);
	depanbelakang(50,30,20,0,-100);
	depanbelakang(50,30,20,0,-150);
	kirikanan(50,30,20,0,-100);
	kirikanan(50,30,70,0,-100);
	//pintu
	warna(255, 132, 18);
	depanbelakang(15,20,30,0,-99.9);
	warna(0,0,0);
	depanbelakang(1,1,40,8,-99.8);
	//atap
	glBegin(GL_POLYGON);
	warna(201, 87, 0);
	glVertex3f(20,30,-100);
	glVertex3f(70,30,-100);
	glVertex3f(45,45,-100);
	glEnd();
	glBegin(GL_POLYGON);
	warna(201, 87, 0);
	glVertex3f(20,30,-150);
	glVertex3f(70,30,-150);
	glVertex3f(45,45,-150);
	glEnd();
	glBegin(GL_POLYGON);
	warna(196, 113, 49);
	glVertex3f(20,30,-100);
	glVertex3f(20,30,-150);
	glVertex3f(45,45,-150);
	glVertex3f(45,45,-100);
	glEnd();
	glBegin(GL_POLYGON);
	warna(199, 122, 62);
	glVertex3f(70,30,-100);
	glVertex3f(70,30,-150);
	glVertex3f(45,45,-150);
	glVertex3f(45,45,-100);
	glEnd();

	//tower kereta gantung
	warna(1,1,1);
	atasbawah(40, 60, -145, 90, -130);
	atasbawah(40, 60, -145, 86, -130);
	kirikanan(60, 4, -145, 86, -130);
	kirikanan(60, 4, -105, 86, -130);
	depanbelakang(40, 4, -145, 86, -130);
	depanbelakang(40, 4, -145, 86, -190);

	//tiang2
	kirikanan(5, 86, -135, 0, -140);
	kirikanan(5, 86, -135, 0, -180);
	kirikanan(5, 86, -115, 0, -140);
	kirikanan(5, 86, -115, 0, -180);

	kirikanan(5, 86, -140, 0, -140);
	kirikanan(5, 86, -140, 0, -180);
	kirikanan(5, 86, -110, 0, -140);
	kirikanan(5, 86, -110, 0, -180);

	depanbelakang(5, 86, -140, 0, -140);
	depanbelakang(5, 86, -140, 0, -145);
	depanbelakang(5, 86, -140, 0, -180);
	depanbelakang(5, 86, -140, 0, -185);

	depanbelakang(5, 86, -115, 0, -140);
	depanbelakang(5, 86, -115, 0, -145);
	depanbelakang(5, 86, -115, 0, -180);
	depanbelakang(5, 86, -115, 0, -185);

	//cagak kereta atas
	warna(255,0,0);
	kirikanan(3, 30, -135, 90,-158); 
	kirikanan(3, 30, -132, 90,-158); 
	depanbelakang(3, 30, -135, 90, -158);
	depanbelakang(3, 30, -135, 90, -161);
	kirikanan(20, 3, -135, 120,-150);
	kirikanan(20, 3, -132, 120,-150);
	depanbelakang(3, 3,-135, 120,-150);
	depanbelakang(3, 3, -135, 120,-170);
	atasbawah(3, 20, -135, 123,-150);

	//cagak kereta bawah
	warna(255,0,0);
	kirikanan(3, 20, 135, 3,-158); 
	kirikanan(3, 20, 137, 3,-158); 
	depanbelakang(3, 20, 135, 3, -158);
	depanbelakang(3, 20, 135, 3, -161);
	kirikanan(20, 3, 135, 23,-150);
	kirikanan(20, 3, 137, 23,-150);
	depanbelakang(3, 3,135, 23,-150);
	depanbelakang(3, 3, 135, 23,-170);
	atasbawah(3, 20, 135, 23,-150);

	//alas cagak kereta bawah
	warna(0,0,0);
	atasbawah(40, 50, 100, 3, -130);
	depanbelakang(40, 3, 100, 0, -130);
	depanbelakang(40, 3, 100, 0, -180);
	kirikanan(50, 3, 100, 0, -130);
	kirikanan(50, 3, 140, 0, -130);

	//tali
	glBegin(GL_LINES);
	glLineWidth(2.0);
	warna(0,0,0);
	glVertex3f(-132, 123, -155);
	glVertex3f(135, 26, -155);
	glEnd();
	glBegin(GL_LINES);
	glLineWidth(2.0);
	warna(0,0,0);
	glVertex3f(-132, 123, -165);
	glVertex3f(135, 26, -165);
	glEnd();

	//tulang kereta gantung
	glBegin(GL_POLYGON);
	warna(0,0,0);
	glVertex3f(-45, 91,-167);
	glVertex3f(-40, 90,-167);
	glVertex3f(-40, 90,-153);
	glVertex3f(-45, 91,-153);
	glEnd();	

	glBegin(GL_POLYGON);
	glVertex3f(-44, 91.5,-165);
	glVertex3f(-44, 91.5,-162);
	glVertex3f(-44, 80,-162);
	glVertex3f(-44, 80,-165);
	glEnd();	
	glBegin(GL_POLYGON);
	glVertex3f(-42, 91,-165);
	glVertex3f(-42, 91,-162);
	glVertex3f(-42, 80,-162);
	glVertex3f(-42, 80,-165);
	glEnd();	
	glBegin(GL_POLYGON);
	glVertex3f(-44, 91.5,-165);
	glVertex3f(-42, 91.5,-165);
	glVertex3f(-42, 80,-165);
	glVertex3f(-44, 80,-165);
	glEnd();	
	glBegin(GL_POLYGON);
	glVertex3f(-44, 91.5,-162);
	glVertex3f(-42, 91.5,-162);
	glVertex3f(-42, 80,-162);
	glVertex3f(-44, 80,-162);
	glEnd();	

	//kereta gantung
	warna(24,164,225);
	atasbawah(20,20, -50, 80, -158);
	kirikanan(20, 10, -50, 60, -158);
	kirikanan(20, 10, -30, 60, -158);

	depanbelakang(2, 10, -50, 70, -158);
	depanbelakang(2, 10, -50, 70, -178);
	depanbelakang(2, 10, -32, 70, -158);
	depanbelakang(2, 10, -32, 70, -178);
	warna(32,156,218);
	depanbelakang(20,10, -50, 60, -158);
	depanbelakang(20,10, -50, 60, -178);
	warna(4,51,83);
	atasbawah(20,20, -50, 60, -158);
	kirikanan(2, 10, -50, 70, -158);
	kirikanan(2, 10, -50, 70, -176);
	kirikanan(2, 10, -30, 70, -158);
	kirikanan(2, 10, -30, 70, -176);

	//kereta
	warna(62, 62, 71);
	atasbawah(36, 10, -143, 2, -52);
	atasbawah(36, 10, -143, 3, -52);
	depanbelakang(36, 1, -143, 2, -52);
	depanbelakang(36, 1, -143, 2, -62);
	kirikanan(10, 1, -143, 2, -52);
	kirikanan(10, 1, -123, 2, -52);

	atasbawah(6, 2, -109, 2, -57);

	atasbawah(36, 10, -103, 2, -52);
	atasbawah(36, 10, -103, 3, -52);
	depanbelakang(36, 1, -103, 2, -52);
	depanbelakang(36, 1, -103, 2, -62);
	kirikanan(10, 1, -103, 2, -52);
	kirikanan(10, 1, -83, 2, -52);

	warna(52, 46, 55);
	depanbelakang(10, 5, -142, 3, -53);
	depanbelakang(10, 5, -142, 3, -61);
	depanbelakang(10, 5, -130, 3, -53);
	depanbelakang(10, 5, -130, 3, -61);
	depanbelakang(10, 5, -118, 3, -53);
	depanbelakang(10, 5, -118, 3, -61);

	depanbelakang(10, 5, -102, 3, -53);
	depanbelakang(10, 5, -102, 3, -61);
	depanbelakang(10, 5, -90, 3, -53);
	depanbelakang(10, 5, -90, 3, -61);
	depanbelakang(10, 5, -78, 3, -53);
	depanbelakang(10, 5, -78, 3, -61);

	kirikanan(8, 5, -142, 3, -53);
	kirikanan(8, 5, -132, 3, -53);
	kirikanan(8, 5, -130, 3, -53);
	kirikanan(8, 5, -120, 3, -53);
	kirikanan(8, 5, -118, 3, -53);
	kirikanan(8, 5, -108, 3, -53);

	kirikanan(8, 5, -102, 3, -53);
	kirikanan(8, 5, -92, 3, -53);
	kirikanan(8, 5, -90, 3, -53);
	kirikanan(8, 5, -80, 3, -53);
	kirikanan(8, 5, -78, 3, -53);
	kirikanan(8, 5, -68, 3, -53);
	//roda kereta kanan
	glBegin(GL_POLYGON);
	warna(4, 4, 2);
	glVertex3f(-140, 1,-52);
	glVertex3f(-140, 4,-52);
	glVertex3f(-138, 5,-52);
	glVertex3f(-136, 5,-52);
	glVertex3f(-134, 4,-52);
	glVertex3f(-134, 1,-52);
	glVertex3f(-136, 0,-52);
	glVertex3f(-138, 0,-52);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-116, 1,-52);
	glVertex3f(-116, 4,-52);
	glVertex3f(-114, 5,-52);
	glVertex3f(-112, 5,-52);
	glVertex3f(-110, 4,-52);
	glVertex3f(-110, 1,-52);
	glVertex3f(-112, 0,-52);
	glVertex3f(-114, 0,-52);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-94, 1,-52);
	glVertex3f(-94, 4,-52);
	glVertex3f(-96, 5,-52);
	glVertex3f(-98, 5,-52);
	glVertex3f(-100, 4,-52);
	glVertex3f(-100, 1,-52);
	glVertex3f(-98, 0,-52);
	glVertex3f(-96, 0,-52);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-75, 1,-52);
	glVertex3f(-75, 4,-52);
	glVertex3f(-73, 5,-52);
	glVertex3f(-71, 5,-52);
	glVertex3f(-69, 4,-52);
	glVertex3f(-69, 1,-52);
	glVertex3f(-71, 0,-52);
	glVertex3f(-73, 0,-52);
	glEnd();
	//roda kereta kiri
	glBegin(GL_POLYGON);
	warna(4, 4, 2);
	glVertex3f(-140, 1,-62);
	glVertex3f(-140, 4,-62);
	glVertex3f(-138, 5,-62);
	glVertex3f(-136, 5,-62);
	glVertex3f(-134, 4,-62);
	glVertex3f(-134, 1,-62);
	glVertex3f(-136, 0,-62);
	glVertex3f(-138, 0,-62);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-116, 1,-62);
	glVertex3f(-116, 4,-62);
	glVertex3f(-114, 5,-62);
	glVertex3f(-112, 5,-62);
	glVertex3f(-110, 4,-62);
	glVertex3f(-110, 1,-62);
	glVertex3f(-112, 0,-62);
	glVertex3f(-114, 0,-62);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-94, 1,-62);
	glVertex3f(-94, 4,-62);
	glVertex3f(-96, 5,-62);
	glVertex3f(-98, 5,-62);
	glVertex3f(-100, 4,-62);
	glVertex3f(-100, 1,-62);
	glVertex3f(-98, 0,-62);
	glVertex3f(-96, 0,-62);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-75, 1,-62);
	glVertex3f(-75, 4,-62);
	glVertex3f(-73, 5,-62);
	glVertex3f(-71, 5,-62);
	glVertex3f(-69, 4,-62);
	glVertex3f(-69, 1,-62);
	glVertex3f(-71, 0,-62);
	glVertex3f(-73, 0,-62);
	glEnd();

	//katrolnya
	glBegin(GL_POLYGON);
	warna(231, 199, 0);
	glVertex3f(75, 56, 4);
	glVertex3f(75, 59, 4);
	glVertex3f(78, 62, 4);
	glVertex3f(81, 62, 4);
	glVertex3f(84, 59, 4);
	glVertex3f(84, 56, 4);
	glVertex3f(81, 53, 4);
	glVertex3f(78, 53, 4);
	glEnd();	
	glBegin(GL_POLYGON);
	warna(0, 0, 0);
	glVertex3f(78, 56, 4.1);
	glVertex3f(78, 59, 4.1);
	glVertex3f(81, 59, 4.1);
	glVertex3f(81, 56, 4.1);
	glEnd();	
	glBegin(GL_POLYGON);
	warna(231, 199, 0);
	glVertex3f(75, 56, -4);
	glVertex3f(75, 59, -4);
	glVertex3f(78, 62, -4);
	glVertex3f(81, 62, -4);
	glVertex3f(84, 59, -4);
	glVertex3f(84, 56, -4);
	glVertex3f(81, 53, -4);
	glVertex3f(78, 53, -4);
	glEnd();	
	glBegin(GL_POLYGON);
	warna(0, 0, 0);
	glVertex3f(78, 56, -4.1);
	glVertex3f(78, 59, -4.1);
	glVertex3f(81, 59, -4.1);
	glVertex3f(81, 56, -4.1);
	glEnd();	

	//tali katrol
	glBegin(GL_LINES);
	warna(0,0,0);
	glVertex3f(84, 56, -4.1);
	glVertex3f(67, 18, -4.1);
	glEnd();
	glBegin(GL_LINES);
	warna(0,0,0);
	glVertex3f(84, 56, 4.1);
	glVertex3f(67, 18, 4.1);
	glEnd();

	glBegin(GL_LINES);
	warna(0,0,0);
	glVertex3f(78, 62, -4.1);
	glVertex3f(-10, 55, -2.1);
	glEnd();
	glBegin(GL_LINES);
	warna(0,0,0);
	glVertex3f(78, 62, 4.1);
	glVertex3f(-10, 55, 2.1);
	glEnd();
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
        shovel();
		
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