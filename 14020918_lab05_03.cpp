// Sinh vien: Nguyen Huu Hong - Lop K59CA
// Ma sinh vien: 14020198
// Bai tap tuan 5 - Do hoa may tinh

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>

void init(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15.0, 15.0, -15.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawFunction(){
	// y = 2*sin(x) + 0.5*cos(x)
	float y = 0;
	for(float x = -720; x <= 720; x += 0.01){
		y = 2*sin(x*3.1412/180) + 0.5*cos(x*3.1412/180);
		glVertex2f(x*3.1412/180, y);
	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	drawFunction();
	glEnd();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Nguyen Huu Hong - Lab 05 - 3");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
