// Sinh vien: Nguyen Huu Hong
// Lop: K59CA
// Ma sinh vien: 14020918
// Bai tap chuyen dong nguoi 2D

#include <GL/glut.h>
#include <iostream>

#define RATIO 1.618
#define WW    100
#define WH    (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .03

int WindowWidth;
int WindowHeight;

void Draw(int&);
void InitGL();
void Display();
void Reshape(int,int);

int main(int argc, char **argv)
{
	glutInit(&argc,argv);   
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

	WindowWidth  = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.8); 
	WindowHeight = (int)(WindowWidth/RATIO);

	glutInitWindowSize(WindowWidth,WindowHeight); 
	glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1),(glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(WindowHeight/2));
	glutCreateWindow("Chuyen dong nguoi 2D");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	InitGL();
	glutMainLoop();

}//end main

int numState = 21;
float State[21][17][2] = {
	{{0,25},{-10,20},{0,20},{0,10},{-10,8},{0,9},{0,0},{-10,-15},{0,-4},{10,-15},{0,0},{0,9},{10,8},{0,10},{0,20},{10,20},{0,25}},
	{{2,25},{-8,20},{2,20},{2,10},{-8,12},{2,9},{2,0},{-16.027,0},{2,-4},{20.027,0},{2,0},{2,9},{12,12},{2,10},{2,20},{12,20},{2,25}},
	{{4,25},{-6,20},{4,20},{4,10},{-6,8},{4,9},{4,0},{-6,-15},{4,-4},{14,-15},{4,0},{4,9},{14,8},{4,10},{4,20},{14,20},{4,25}},
	{{6,25},{-4,20},{6,20},{6,10},{-4,12},{6,9},{6,0},{-12.027,0},{6,-4},{24.027,0},{6,0},{6,9},{16,12},{6,10},{6,20},{16,20},{6,25}},
	{{8,25},{-2,20},{8,20},{8,10},{-2,8},{8,9},{8,0},{-2,-15},{8,-4},{18,-15},{8,0},{8,9},{18,8},{8,10},{8,20},{18,20},{8,25}},
	{{10,25},{0,20},{10,20},{10,10},{0,12},{10,9},{10,0},{-8.027,0},{10,-4},{28.027,0},{10,0},{10,9},{20,12},{10,10},{10,20},{20,20},{10,25}},
	{{12,25},{2,20},{12,20},{12,10},{2,8},{12,9},{12,0},{2,-15},{12,-4},{22,-15},{12,0},{12,9},{22,8},{12,10},{12,20},{22,20},{12,25}},
	{{14,25},{4,20},{14,20},{14,10},{4,12},{14,9},{14,0},{-4.027,0},{14,-4},{32.027,0},{14,0},{14,9},{24,12},{14,10},{14,20},{24,20},{14,25}},
	{{16,25},{6,20},{16,20},{16,10},{6,8},{16,9},{16,0},{6,-15},{16,-4},{26,-15},{16,0},{16,9},{26,8},{16,10},{16,20},{26,20},{16,25}},
	{{18,25},{8,20},{18,20},{18,10},{8,12},{18,9},{18,0},{0.027,0},{18,-4},{36.027,0},{18,0},{18,9},{28,12},{18,10},{18,20},{28,20},{18,25}},
	{{20,25},{10,20},{20,20},{20,10},{10,8},{20,9},{20,0},{10,-15},{20,-4},{30,-15},{20,0},{20,9},{30,8},{20,10},{20,20},{30,20},{20,25}},

	{{18,25},{8,20},{18,20},{18,10},{8,12},{18,9},{18,0},{0.027,0},{18,-4},{36.027,0},{18,0},{18,9},{28,12},{18,10},{18,20},{28,20},{18,25}},
	{{16,25},{6,20},{16,20},{16,10},{6,8},{16,9},{16,0},{6,-15},{16,-4},{26,-15},{16,0},{16,9},{26,8},{16,10},{16,20},{26,20},{16,25}},
	{{14,25},{4,20},{14,20},{14,10},{4,12},{14,9},{14,0},{-4.027,0},{14,-4},{32.027,0},{14,0},{14,9},{24,12},{14,10},{14,20},{24,20},{14,25}},
	{{12,25},{2,20},{12,20},{12,10},{2,8},{12,9},{12,0},{2,-15},{12,-4},{22,-15},{12,0},{12,9},{22,8},{12,10},{12,20},{22,20},{12,25}},
	{{10,25},{0,20},{10,20},{10,10},{0,12},{10,9},{10,0},{-8.027,0},{10,-4},{28.027,0},{10,0},{10,9},{20,12},{10,10},{10,20},{20,20},{10,25}},
	{{8,25},{-2,20},{8,20},{8,10},{-2,8},{8,9},{8,0},{-2,-15},{8,-4},{18,-15},{8,0},{8,9},{18,8},{8,10},{8,20},{18,20},{8,25}},
	{{6,25},{-4,20},{6,20},{6,10},{-4,12},{6,9},{6,0},{-12.027,0},{6,-4},{24.027,0},{6,0},{6,9},{16,12},{6,10},{6,20},{16,20},{6,25}},
	{{4,25},{-6,20},{4,20},{4,10},{-6,8},{4,9},{4,0},{-6,-15},{4,-4},{14,-15},{4,0},{4,9},{14,8},{4,10},{4,20},{14,20},{4,25}},
	{{2,25},{-8,20},{2,20},{2,10},{-8,12},{2,9},{2,0},{-16.027,0},{2,-4},{20.027,0},{2,0},{2,9},{12,12},{2,10},{2,20},{12,20},{2,25}},
	{{0,25},{-10,20},{0,20},{0,10},{-10,8},{0,9},{0,0},{-10,-15},{0,-4},{10,-15},{0,0},{0,9},{10,8},{0,10},{0,20},{10,20},{0,25}}
};
float VertexColors[17][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

void Display()
{
	static int state = 0;
	if(state < numState - 1){
		Draw(state);
	}
}

void Draw(int &i){
	float IntermediateShape[17][2];
	static float Tween=0.0-deltat;
	if(Tween<1)
	{
		Tween+= deltat;
		// std::cout << "Tween = " << Tween << std::endl;
		for (int Vtx=0;Vtx<17;Vtx++)
		{
			IntermediateShape[Vtx][0]=(1.0-Tween)*State[i][Vtx][0]+Tween*State[i+1][Vtx][0];
			IntermediateShape[Vtx][1]=(1.0-Tween)*State[i][Vtx][1]+Tween*State[i+1][Vtx][1];
		}
		glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
		glColorPointer(3,GL_FLOAT,0,VertexColors);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_LINE_LOOP,0,17);
		glutSwapBuffers();
		glutPostRedisplay();
	}else{
		i = (i + 1)%(numState-1);
		Tween = 0.0 - deltat;
	}
}

void Reshape(int w,int h)
{
	glutReshapeWindow(w,(int)(w/RATIO));
	WindowWidth=w;
	WindowHeight=(int)(w/RATIO);
	InitGL();
}


void InitGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-HALFX,HALFX,-HALFY,HALFY);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(1, 1, 1, 1);
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_COLOR_ARRAY);
	glShadeModel(GL_SMOOTH);
	glViewport(0,0,WindowWidth,WindowHeight);   
}
