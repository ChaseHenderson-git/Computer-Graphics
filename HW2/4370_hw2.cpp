/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
    #include <GLUT/glut.h>
#else
    #include <glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
    // TODO: Your code here!
	for (int i = 0; i < 360; i += 36) 
	{
		glPushMatrix();
		glRotatef(i, 0.0f, 0.0f, 1.0f);
		glTranslatef(1, 0, 0);
		glutSolidTeapot(.2);
		glPopMatrix();
	}
}

void problem2() {
    // TODO: Your code here!
	float height = 1;
	glPushMatrix();
	glTranslatef(-1.5, 0, 0);  //center
	for (int i = 0; i < 15; i++)
	{
		glPushMatrix();
		glScalef(1, height, 1);
		glTranslatef(i *.2 , .1, 0);
		glutSolidCube(.2);
		glPopMatrix();
		height += .15;
	}
	glPopMatrix();
}

void problem3() {
    // TODO: Your code here!
	glPushMatrix();
	float height = 0;
	glTranslatef(-1.2, 0, 0); //center
	for (int i = 6; i > 0; i--)
	{
		glTranslatef(.2, 0, 0);
		for (int j = 0; j < i; j++)
		{
			glPushMatrix();
			glTranslatef(j * .4, height, 0);
			glutSolidTeapot(.1);
			glPopMatrix();
		}
		height += .2;
	}
	glPopMatrix();
}

void problem4() {
    // TODO: Your code here!
	// plan: thumbs up

	//palm
	glBegin(GL_TRIANGLES);
	glVertex3f(.3, -.6f, 0);
	glVertex3f(.3, .6f, 0);
	glVertex3f(-1.2f, 0, 0);
	glEnd();

	//thumb ---------------------------------------------------------------
	glPushMatrix();
	glTranslatef(-.3, .3, 0); //base p1
	glRotatef(160, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.24);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-.24, .5, 0); //base p2
	glRotatef(160, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.24);
	glPopMatrix();
	//thumb knuckle 1
	glPushMatrix();
	glTranslatef(-.14, .7, 0);
	glRotatef(140, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.24);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, .85, 0);
	glRotatef(140, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.24);
	glPopMatrix();
	//thumb knuckle 2
	glPushMatrix();
	glTranslatef(.1, .95, 0);
	glRotatef(140, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.24);
	glPopMatrix();

	//index finger  --------------------------------------------------------
	glPushMatrix();
	glTranslatef(.4, .5, 0);
	glutSolidCube(0.23);
	glPopMatrix();
	// knuckle
	glPushMatrix();
	glTranslatef(.4, .5, .23);
	glutSolidCube(0.23);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.4, .5, .46);
	glutSolidCube(0.23);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.17, .5, .46);
	glutSolidCube(0.23);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.17, .4, 0);
	glutSolidCube(0.23);
	glPopMatrix();

	//middle finger  --------------------------------------------------------
	glPushMatrix();
	glTranslatef(.4, .2, 0);
	glutSolidCube(0.23);
	glPopMatrix();
	// knuckle
	glPushMatrix();
	glTranslatef(.4, .2, .23);
	glutSolidCube(0.23);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.4, .2, .46);
	glutSolidCube(0.23);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.17, .2, .46);
	glutSolidCube(0.23);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.17, .1, 0);
	glutSolidCube(0.23);
	glPopMatrix();
	
	//ring finger  --------------------------------------------------------
	glPushMatrix();
	glTranslatef(.4, -.1, 0);
	glutSolidCube(0.23);
	glPopMatrix();
	// knuckle
	glPushMatrix();
	glTranslatef(.4, -.1, .23);
	glutSolidCube(0.23);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.4, -.1, .46);
	glutSolidCube(0.23);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.17, -.1, .46);
	glutSolidCube(0.23);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.17, -.2, 0);
	glutSolidCube(0.23);
	glPopMatrix();

	//pinky finger  --------------------------------------------------------
	glPushMatrix();
	glTranslatef(.4, -.4, 0);
	glutSolidCube(0.21);
	glPopMatrix();
	// knuckle
	glPushMatrix();
	glTranslatef(.4, -.4, .21);
	glutSolidCube(0.21);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.4, -.4, .42);
	glutSolidCube(0.21);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.19, -.4, .42);
	glutSolidCube(0.21);
	glPopMatrix();
	//knuckle
	glPushMatrix();
	glTranslatef(.19, -.5, 0);
	glutSolidCube(0.21);
	glPopMatrix();
	
}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
