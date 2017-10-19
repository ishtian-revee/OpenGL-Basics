#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int xCoordinate, yCoordinate, radius;

// function prototypes
void getInput();
void plot(int x, int y);
void MidPointCircle();

void init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void){

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    MidPointCircle();
    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 400);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("Mid Point Circle Algorithm");
    getInput();
    glutDisplayFunc(myDisplay);
    init();
    glutMainLoop();
}

void getInput(){

    cout << endl << "Enter the x coordinate: ";
    cin >> xCoordinate;

    cout << endl << "Enter the y coordinate: ";
    cin >> yCoordinate;

    cout << endl << "Enter the radius: ";
    cin >> radius;
}

void plot(int x, int y){

    glBegin(GL_POINTS);
	glVertex2i(x+xCoordinate, y+yCoordinate);
	glEnd();
}

void MidPointCircle(){

    int x = 0;
	int y = radius;
	float d = 5/4 - radius;
	plot(x, y);

	while (y > x){

		if (d < 0){

			x++;
			d += 2*x+1;
		}else{

			y--;
			x++;
			d += 2*(x-y)+1;
		}

		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}
