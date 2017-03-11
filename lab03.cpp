// Sinh vien: Nguyen Huu Hong
// Lop: K59CA
// Ma sinh vien: 14020918

#include <GL/glut.h>

#define RATIO 1.618
#define WW    100
#define WH    (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001

int WindowWidth;
int WindowHeight;

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
    glutCreateWindow("Tween Demo");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    InitGL();
    glutMainLoop();

}//end main

void Display()
{ 
    float StartShape[9][2] = {{0, 5}, {5 , 10}, {15 , 20}, {30 , 35}, {0 , 0}, {0 , 0}, {0 , 0}, {0 , 0}, {0 , 0}};
    float EndShape[9][2] = {{-25,10},{-25,-20},{-5,-20},{-5,-10},{5,-10},{5,-20},{25,-20},{25,10},{0,20}};
    float IntermediateShape[9][2];
    float VertexColors[9][3]={{1,0,0},{1,0,0},{1,0,0},{0,1,0},{0,1,0},{0,1,0},{0,0,1},{0,0,1},{0,0,1}};

    static float Tween=0.0-deltat;
    if(Tween<1)
    {
        Tween+= deltat;
    }

    for (int Vtx=0;Vtx<9;Vtx++)
    {
        IntermediateShape[Vtx][0]=(1.0-Tween)*StartShape[Vtx][0]+Tween*EndShape[Vtx][0];
        IntermediateShape[Vtx][1]=(1.0-Tween)*StartShape[Vtx][1]+Tween*EndShape[Vtx][1];
    }

    glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
    glColorPointer(3,GL_FLOAT,0,VertexColors);

    for (int i = 0; i < 1000000; i++);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINE_LOOP,0,9);

    glutSwapBuffers();
    glutPostRedisplay();
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
