#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

// Global fields
int choice;
int newX, newY;

// Function prototypes
void makeChoice();
void Translation();
//void Rotation();
void Scaling();

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

    glColor3ub(255, 0, 128);
    glBegin(GL_TRIANGLES);
    glVertex2d(280, 100);
    glVertex2d(185, 285);
    glVertex2d(90, 100);
    glEnd();

    if(choice == 1){

        Translation();
    }else if(choice == 2){

//        Rotation();
    }else if(choice == 3){

        Scaling();
    }

    glFlush ();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Transformation");
    makeChoice();       // user input for choice
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}

void makeChoice(){

    cout << endl << "Enter your choice: " << endl << endl;
    cout << "1. Translation" << endl;
    cout << "2. Rotation" << endl;
    cout << "3. Scaling" << endl;
    cout << "4. Exit" << endl << endl;
    cin >> choice;

    if(choice == 1){

        cout << endl << "Enter the value of x coordinate and y coordinate: ";
        cin >> newX >> newY;
    }else if(choice == 2){


    }else if(choice == 3){

        cout << endl << "Enter the value of x coordinate and y coordinate: ";
        cin >> newX >> newY;
    }else if(choice == 4){

        exit(1);
    }else{

        cout << endl << "Invalid input!" << endl;
    }
}

void Translation(){

    glColor3ub(0, 102, 204);
    glBegin(GL_TRIANGLES);
    glVertex2d(280+newX+150, 100+newY);
    glVertex2d(185+newX+150, 285+newY);
    glVertex2d(90+newX+150, 100+newY);
    glEnd();
}

void Scaling(){

    glColor3ub(0, 102, 204);
    glBegin(GL_TRIANGLES);
    glVertex2d(280+newX+150, 100-newY);
    glVertex2d(185+150, 285+newY);
    glVertex2d(90-newX+150, 100-newY);
    glEnd();
}
