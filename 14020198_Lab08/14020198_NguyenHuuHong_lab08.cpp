// Sinh vien: Nguyen Huu Hong - Lop K59CA
// Ma sinh vien: 14020198
// Bai tap tuan 8 - Do hoa may tinh

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
float spin = 0;
bool readfile = true;
float *pointX, *pointY, *pointZ;
int *triang1, *triang2, *triang3;
int numOfPoint = 0, numOfTriangle = 0;

void init(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void spinDisplay(void)
{
	spin = spin += 0.1;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}
void drawFace(){
	for(int i = 0; i < numOfTriangle; i++){
		glBegin(GL_LINES);
			glVertex3f(pointX[triang1[i]], pointY[triang1[i]], pointZ[triang1[i]]);
			glVertex3f(pointX[triang2[i]], pointY[triang2[i]], pointZ[triang2[i]]);
			glVertex3f(pointX[triang3[i]], pointY[triang3[i]], pointZ[triang3[i]]);
		glEnd();
		glBegin(GL_LINES);
		glVertex3f(-pointX[triang1[i]], pointY[triang1[i]], pointZ[triang1[i]]);
		glVertex3f(-pointX[triang2[i]], pointY[triang2[i]], pointZ[triang2[i]]);
		glVertex3f(-pointX[triang3[i]], pointY[triang3[i]], pointZ[triang3[i]]);
		glEnd();
	}
}

void readFile(const char* fileName){
	std::ifstream file(fileName);
	if(file.is_open()){
		file >> numOfPoint;
		pointX = new float[numOfPoint];
		pointY = new float[numOfPoint];
		pointZ = new float[numOfPoint];
		int temp = numOfPoint;
		int i = 0;
		while(temp > 0){
			file >> pointX[i];
			file >> pointY[i];
			file >> pointZ[i];
			temp--;
			i++;
		}
		file >> numOfTriangle;
		triang1 = new int[numOfTriangle];
		triang2 = new int[numOfTriangle];
		triang3 = new int[numOfTriangle];
		i = 0;
		temp = numOfTriangle;
		while(temp > 0){
			file >> triang1[i];
			file >> triang2[i];
			file >> triang3[i];
			temp--;
			i++;
		}
	}
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	drawFace();
	glPopMatrix();
	glutSwapBuffers();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Nguyen Huu Hong - Lab 08");
	readFile("face.dat");
	glutDisplayFunc(display);
	init();
	glutIdleFunc(spinDisplay);
	glutMainLoop();
	return 0;
}
