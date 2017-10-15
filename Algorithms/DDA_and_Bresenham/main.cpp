#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

// Global fields
int choice;
int startX, startY, endX, endY;

// Function prototypes
void makeChoice();
void DDA();
void Bresenham();

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
    glPointSize(4.0);

    if(choice == 1){

        DDA();
    }else if(choice == 2){

        Bresenham();
    }

    glFlush ();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("DDA and Bresenham");
    makeChoice();       // user input for choice
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

void makeChoice(){

    cout << endl << "Enter your choice: " << endl << endl;
    cout << "1. DDA Algorithm" << endl;
    cout << "2. Bresenham" << endl;
    cout << "3. Exit" << endl << endl;
    cin >> choice;

    if(choice == 1){

        cout << endl << "Enter an initial point: ";
        cin >> startX >> startY;

        cout << endl << "Enter an end point: ";
        cin >> endX >> endY;
    }else if(choice == 2){

        cout << endl << "Enter an initial point: ";
        cin >> startX >> startY;

        cout << endl << "Enter an end point: ";
        cin >> endX >> endY;
    }else if(choice == 3){

        exit(1);
    }else{

        cout << endl << "Invalid input!" << endl;
    }
}

void DDA(){

    float length;
    float x = 0, y = 0, xIncrement, yIncrement;

    length = abs((float)endX - (float)startX);

    if(abs((float)endY - (float)startY) > length){

        length = abs((float)endY - (float)startY);
    }

    xIncrement = ((float)endX - (float)startX) / length;
    yIncrement = ((float)endY - (float)startY) / length;

    x = startX + 0.5;
    y = startY + 0.5;

    for(int i=0; i<length; i++){

        glBegin(GL_POINTS);
        glVertex2i(floor(x), floor(y));
        glEnd();

        x += xIncrement;
        y += yIncrement;
    }
}

void Bresenham(){

    int x, y, dx, dy, dT, dS, d;
    int counter = 0;

    x = startX;
    y = startY;
    dx = endX - startX;
    dy = endY - startY;
    dT = 2 * (dy - dx);
    dS = 2 * dy;
    d = (2 * dy) - dx;

    glBegin(GL_POINTS);
    glVertex2i(floor(x), floor(y));
    glEnd();

    while(x < endX){

        x++;
        if(d < 0){

            d += dS;
        }else{

            y++;
            d += dT;
        }

        counter++;
        if((counter%2 == 0) && (counter%3 == 0)){

            glBegin(GL_POINTS);
            glVertex2i(floor(x), floor(y));
            glEnd();
        }
    }
}
