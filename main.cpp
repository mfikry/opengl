#include <stdlib.h>
#include <GL/glut.h>

int w = 600, h = 500;
int a, b;

void renderScene(void){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
GLfloat LightPosition[] = {10.0f, 20.0f, 30.0f, 0.0f};
LightPosition[0] = a;
LightPosition[1] = b;
glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
glEnable(GL_COLOR_MATERIAL);

//Membuat dinding rumah
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslatef(0, 0, -100);
glRotatef(50, 1, 1 ,0);
glColor3f(1, 1, 1);
glutSolidCube(20);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//Membuat atap rumah
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glTranslatef(1, 7, -80);
glScalef(20, 10, 20);
glRotatef(100, -3, -10, 1);
glColor3f(1, 1, 0);
glutSolidOctahedron();
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

//Membuat pintu rumah
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(0.5f, 1.0f, 1.0f);
glTranslatef(-9,-6, -90);
glRotatef(140, -2, -3, 5);
glScalef(5,10,1);
glutSolidCube(1);
glPopMatrix();

//Membuat jendela rumah
glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(2.0f, 0.5f, 1.0f);
glTranslatef(-5,-3, -90);
glRotatef(150, -2, -1, 5);
glScalef(1,2,1);
glutSolidCube(1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(2.0f, 0.5f, 1.0f);
glTranslatef(-8,-1, -94);
glRotatef(150, -2, -1, 5);
glScalef(1,2,1);
glutSolidCube(1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);
glColor3f(2.0f, 0.5f, 1.0f);
glTranslatef(-11,1, -98);
glRotatef(150, -2, -1, 5);
glScalef(1,2,1);
glutSolidCube(1);
glDisable(GL_COLOR_MATERIAL);
glPopMatrix();

glutSwapBuffers();
}

void resize(int w1, int h1){
glViewport(0,0,600,600);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(40.0,(float) w1/(float) h1, 1.0,200.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
a = x-(w/2);
b = (h/2)-y;
}


void init(){
GLfloat LightAmbient[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat LightDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat LightSpecular[] = {0.5f, 10.0f, 20.0f, 10.0f};
GLfloat Shine[] = {80};
glShadeModel(GL_SMOOTH);
glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
glClearDepth(1.0f);
glEnable(GL_DEPTH_TEST);
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpecular);
glMaterialfv(GL_FRONT, GL_SHININESS, Shine);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
return;
}

int main (int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
glutInitWindowPosition(100,100);
glutInitWindowSize(w,h);
glutCreateWindow("UAS GrafKomP - 2018104204 - Muhammad Fikry");
init();
glutDisplayFunc(renderScene);
glutReshapeFunc(resize);
glutMouseFunc(mouse);
glutMainLoop();
}
