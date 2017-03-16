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
	gluOrtho2D(-800, 800.0, -800.0, 800.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawDinosaurFromFile(const char* fileName){
	std::ifstream file (fileName);
	int numOfArea = 0;
	float x,y;
	if(file.is_open()){
        file >> numOfArea;
        int num = 0;
        while(numOfArea > 0){
        	file >> num;
			glBegin(GL_POINTS);
        	while(num > 0){
        		file >> x;
        		file >> y;
        		glVertex2f(x, y);
        		num--;
        	}
        	glEnd();
        	numOfArea--;
        }
	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	drawDinosaurFromFile("dinosaur.dat");
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Nguyen Huu Hong - Lab 05 - 1");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
