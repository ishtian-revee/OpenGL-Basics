#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>

using namespace std;

void drawBreakingBad();

void init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    drawBreakingBad();
    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 500);
    glutInitWindowPosition(480, 280);
    glutCreateWindow("Breaking Bad");
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glutDisplayFunc(myDisplay);
    init();
    glutMainLoop();
}

void drawBreakingBad(){

    // Br box
    glColor3ub(50, 190, 95);
    glBegin(GL_QUADS);
    glVertex2i(240, 290);
    glVertex2i(240, 390);
    glVertex2i(150, 390);
    glVertex2i(150, 290);
    glEnd();

    // 'B'
    glColor3ub(245, 245, 245);
    glLineWidth(6.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(190, 340);
    glVertex2i(190, 370);
    glVertex2i(160, 370);
    glVertex2i(160, 340);
    glEnd();

    // 'B'
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 310);
    glVertex2i(200, 340);
    glVertex2i(160, 340);
    glVertex2i(160, 310);
    glEnd();

    // 'r'
    glBegin(GL_LINE_STRIP);
    glVertex2i(215, 310);
    glVertex2i(215, 340);
    glEnd();

    // 'r'
    glBegin(GL_LINE_STRIP);
    glVertex2i(215, 332);
    glVertex2i(230, 332);
    glEnd();

    // 'e'
    glColor3ub(50, 190, 95);
    glBegin(GL_LINE_STRIP);
    glVertex2i(270, 325);
    glVertex2i(270, 340);
    glVertex2i(255, 340);
    glVertex2i(255, 310);
    glVertex2i(270, 310);
    glEnd();

    // 'a'
    glBegin(GL_LINE_STRIP);
    glVertex2i(285, 340);
    glVertex2i(300, 340);
    glVertex2i(300, 310);
    glVertex2i(285, 310);
    glVertex2i(285, 325);
    glEnd();

    // 'k'
    glBegin(GL_LINE_STRIP);
    glVertex2i(315, 380);
    glVertex2i(315, 310);
    glEnd();

    // 'k'
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2i(340, 355);
    glVertex2i(330, 345);
    glVertex2i(320, 335);
    glVertex2i(330, 325);
    glVertex2i(340, 315);
    glEnd();

    // 'i'
    glBegin(GL_LINE_STRIP);
    glVertex2i(355, 340);
    glVertex2i(355, 310);
    glEnd();

    // 'i'
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2i(355, 355);
    glEnd();

    // 'n'
    glBegin(GL_LINE_STRIP);
    glVertex2i(370, 310);
    glVertex2i(370, 340);
    glVertex2i(385, 340);
    glEnd();

    // 'n'
    glBegin(GL_LINE_STRIP);
    glVertex2i(390, 335);
    glVertex2i(390, 310);
    glEnd();

    // 'g'
    glBegin(GL_LINE_STRIP);
    glVertex2i(430, 310);
    glVertex2i(405, 310);
    glVertex2i(405, 340);
    glVertex2i(430, 340);
    glVertex2i(430, 295);
    glVertex2i(405, 295);
    glEnd();

    // Ba box
    glColor3ub(50, 190, 95);
    glBegin(GL_QUADS);
    glVertex2i(330, 190);
    glVertex2i(330, 290);
    glVertex2i(240, 290);
    glVertex2i(240, 190);
    glEnd();

    // 'B'
    glColor3ub(245, 245, 245);
    glLineWidth(6.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(280, 240);
    glVertex2i(280, 270);
    glVertex2i(250, 270);
    glVertex2i(250, 240);
    glEnd();

    // 'B'
    glBegin(GL_LINE_LOOP);
    glVertex2i(290, 210);
    glVertex2i(290, 240);
    glVertex2i(250, 240);
    glVertex2i(250, 210);
    glEnd();

    // 'a'
    glBegin(GL_LINE_STRIP);
    glVertex2i(305, 240);
    glVertex2i(320, 240);
    glVertex2i(320, 210);
    glVertex2i(305, 210);
    glVertex2i(305, 225);
    glEnd();

    // 'd'
    glColor3ub(50, 190, 95);
    glBegin(GL_LINE_STRIP);
    glVertex2i(360, 265);
    glVertex2i(360, 210);
    glVertex2i(345, 210);
    glVertex2i(345, 240);
    glVertex2i(360, 240);
    glEnd();
}
