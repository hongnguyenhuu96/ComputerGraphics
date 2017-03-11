#include<stdio.h>
#include<math.h>
#include <GL/glut.h>

void myinit()
{
      glClearColor(1.0, 1.0, 1.0, 1.0);
      glColor3f(1.0, 0.0, 0.0);

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-25.0, 25.0, -25.0, 25.0);
      glMatrixMode(GL_MODELVIEW);
}

void draw_ngon(int N)
{
     float theta;
     int i, j;
     GLfloat x[N], y[N];
     theta=360.0/N;

     for(i=0; i<N; i++)
     {
              x[i]=25*cos(i*theta*3.142/180.0);
              y[i]=25*sin(i*theta*3.142/180.0);

     }

     for(i=0; i<N-1; i++)
     {

              glBegin(GL_LINE_LOOP);
              for(j=i+1; j<N; j++)
              {
                        glVertex2f(x[i], y[i]);
                        glVertex2f(x[j], y[j]);
              }
              glEnd();
              glFlush();
     }


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
      draw_ngon(5);
    glFlush();
 }

int main(int argc, char** argv)
{

/* Standard GLUT initialization */

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("N-gon Diagonals");
    glutDisplayFunc(display);

    myinit();

    glutMainLoop();

return 0;

}
