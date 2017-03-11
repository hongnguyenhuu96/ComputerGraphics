// Sinh vien: Nguyen Huu Hong - Lop K59CA
// Ma sinh vien: 14020198
// Bai tap tuan 4 - Do hoa may tinh


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

static GLfloat spin = 0.0;
GLfloat oldx = -45, oldy = 30*sqrt(3)/2;
GLint color = 1;
void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void drawLine(GLfloat dir, GLfloat len, GLint iter) {
	color = (++color)%3;
	if(color == 1){
		glColor3f(1.0, 1.0, 0.0);
	} else if(color == 2){
		glColor3f(1.0, 1.0, 1.0);
	}else {
		glColor3f(0.0, 0.0, 1.0);
	}
	GLdouble dirRad = 0.0174533 * dir;  
	GLfloat newX = oldx + len * cos(dirRad);
	GLfloat newY = oldy + len * sin(dirRad);
	if (iter==0) {
		glVertex3f(oldx, oldy, 0.0);
		glVertex3f(newX, newY, 0.0);
		oldx = newX;
		oldy = newY;
	}
	else {
		iter--;
		//draw the four parts of the side _/\_ 
		drawLine(dir, len, iter);
		dir += 60.0;
		drawLine(dir, len, iter);
		dir -= 120.0;
		drawLine(dir, len, iter);
		dir += 60.0;
		drawLine(dir, len, iter);
	}
}

void drawSnow(){
	glBegin(GL_LINES);
		drawLine(0.0, 10.0, 2);
		drawLine(-120.0, 10.0, 2);
		drawLine(120.0, 10.0, 2);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	drawSnow();
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin = spin + 50;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) 
{
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
		case GLUT_MIDDLE_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); 
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
