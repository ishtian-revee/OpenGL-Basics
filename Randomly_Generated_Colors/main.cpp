#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

// Global fields
int choice;
int numOfPixels;
int red, green, blue;
int xAxisLimit, yAxisLimit;
int rows = 640;
int column = 480;
int pointSize = 10;

// Prototypes
void makeChoice();
void generateRandomColorPixels();
void generateRandomColorFullScreen();

void myInit(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void myDisplay(void){

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(pointSize);

    if(choice == 1){

        generateRandomColorPixels();
    }else if(choice == 2){

        generateRandomColorFullScreen();
    }

    glFlush ();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Randomly Generated Colors");
    makeChoice();              // user input for choice
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

void makeChoice(){

    cout << endl << "Enter your choice no: ";
    cin >> choice;

    if(choice == 1){

        cout << endl << "Enter the number of pixels to be colored: ";
        cin >> numOfPixels;
    }else if(choice == 2){


    }else if(choice == 3){

        exit(1);
    }else{

        cout << endl << "WRONG INPUT!!!" << endl;
    }
}

void generateRandomColorPixels(){

    for(int i=0; i<numOfPixels; i++){

        red = rand() % 255;
        green = rand() % 255;
        blue = rand() % 255;

        xAxisLimit = rand() % 640;
        yAxisLimit = rand() % 480;

        glColor3ub(red, blue, green);
        glBegin(GL_POINTS);
        glVertex2d(xAxisLimit, yAxisLimit);
        glEnd();
    }
}

void generateRandomColorFullScreen(){

    for(int i=0; i<rows; i+=pointSize){

        for(int j=0; j<column; j+=pointSize){

            red = rand() % 255;
            green = rand() % 255;
            blue = rand() % 255;

            glColor3ub(red, blue, green);
            glBegin(GL_POINTS);
            glVertex2d(i+(pointSize/2), j+(pointSize/2));
            glEnd();
        }
    }
}
