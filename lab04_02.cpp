// Sinh vien: Nguyen Huu Hong - Lop K59CA
// Ma sinh vien: 14020198
// Bai tap tuan 4 - Do hoa may tinh

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>

void init(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-8.0, 8.0, -8.0, 8.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(){
	float x, y, radius, theta, maxRadius = 3;
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	for(radius = 0; radius < maxRadius; radius += 0.1){
		for(theta = 0; theta <= 360; theta += 0.01){
			x = radius*(1 + cos(theta*3.1412/180))*cos(theta*3.1412/180);
			y = radius*(1 + cos(theta*3.1412/180))*sin(theta*3.1412/180);
			glVertex2f(x, y);
		}
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cardioid");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
