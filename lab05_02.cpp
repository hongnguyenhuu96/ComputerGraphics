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
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawFunction(){
	// y = x^3 + 2*x^2 + 3
	glBegin(GL_POINTS);
	float y = 0;
	for(float x = -9.0; x <= 5.0; x+=0.01){
		y = x*x*x + 2*x*x + 3;
		glVertex2f(x, y);
	}
	glEnd();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawFunction();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Nguyen Huu Hong - Lab 05 - 2");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
