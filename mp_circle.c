#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	
	//glColor3f(1.0,0.2,1.0);

	//glPointSize(10.0);	
	glMatrixMode(GL_PROJECTION);	

	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void midpoint(float xc, float yc, float r)
{
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glPointSize(5);
	float p=1-r;
  float x=0;
  float y=r;

  while(x<=y)
  {
		glVertex2i(xc+x, yc+y);
		glVertex2i(xc-x, yc+y);
		glVertex2i(xc+x, yc-y);
		glVertex2i(xc-x, yc-y);
		glVertex2i(xc+y, yc+x);
		glVertex2i(xc-y, yc+x);
		glVertex2i(xc+y, yc-x);
		glVertex2i(xc-y, yc-x);

		if(p<0)
       p+=2*x+1;
    else{
				y--;
       p+=2*x+1-2*y;
    }
		x++;
  }

	glEnd();
}

void  display()
{
	glClear(GL_COLOR_BUFFER_BIT);
  midpoint(0,0,50);
  glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(30,30);
	glutInitWindowSize(500,500);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("MP Circle Algo");
	init();
  glutDisplayFunc(display);
  glutMainLoop();
}
