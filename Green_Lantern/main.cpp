#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<iostream>

using namespace std;

void drawLantern();

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
    drawLantern();
    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 500);
    glutInitWindowPosition(480, 280);
    glutCreateWindow("Green Lantern");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(myDisplay);
    init();
    glutMainLoop();
}

void drawLantern(){

    // Face Skin
    glColor3ub(255, 205, 180);
    glBegin(GL_QUADS);
    glVertex2i(470, 65);
    glVertex2i(470, 375);
    glVertex2i(180, 375);
    glVertex2i(180, 65);
    glEnd();

    // Ears
    glColor3ub(255, 205, 180);
    glBegin(GL_QUADS);
    glVertex2i(500, 220);
    glVertex2i(500, 290);
    glVertex2i(470, 290);
    glVertex2i(470, 220);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(180, 220);
    glVertex2i(180, 290);
    glVertex2i(150, 290);
    glVertex2i(150, 220);
    glEnd();

    // Hair
//    glColor3ub(150, 80, 50);
//    glBegin(GL_LINE_LOOP);
//    glVertex2i(490, 255);
//    glVertex2i(490, 440);
//    glVertex2i(160, 440);
//    glVertex2i(160, 255);
//    glVertex2i(180, 255);
//    glVertex2i(180, 345);
//    glVertex2i(230, 345);
//    glVertex2i(230, 375);
//    glVertex2i(420, 375);
//    glVertex2i(420, 345);
//    glVertex2i(470, 345);
//    glVertex2i(470, 255);
//    glEnd();

    // Wrinkles
    glColor3ub(237, 172, 144);
    glLineWidth(8.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(470, 170);
    glVertex2i(425, 170);
    glVertex2i(425, 104);
    glVertex2i(355, 104);
    glVertex2i(355, 65);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(180, 170);
    glVertex2i(225, 170);
    glVertex2i(225, 104);
    glVertex2i(295, 104);
    glVertex2i(295, 65);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2i(385, 104);
    glVertex2i(385, 69);
    glVertex2i(265, 69);
    glVertex2i(265, 104);
    glEnd();

    glBegin(GL_LINE_STRIP);     // ear-forehead-ear
    glVertex2i(474, 230);
    glVertex2i(474, 379);
    glVertex2i(345, 379);
    glVertex2i(345, 300);
    glVertex2i(305, 300);
    glVertex2i(305, 379);
    glVertex2i(176, 379);
    glVertex2i(176, 230);
    glEnd();

    // Hair
    glColor3ub(150, 80, 50);    // right ear side
    glBegin(GL_QUADS);
    glVertex2i(490, 255);
    glVertex2i(490, 345);
    glVertex2i(470, 345);
    glVertex2i(470, 255);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(490, 345);
    glVertex2i(490, 375);
    glVertex2i(420, 375);
    glVertex2i(420, 345);
    glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(475, 160);
    glVertex2i(475, 220);
    glEnd();

    glBegin(GL_QUADS);          // left ear side
    glVertex2i(180, 255);
    glVertex2i(180, 345);
    glVertex2i(160, 345);
    glVertex2i(160, 255);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(230, 345);
    glVertex2i(230, 375);
    glVertex2i(160, 375);
    glVertex2i(160, 345);
    glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(175, 160);
    glVertex2i(175, 220);
    glEnd();

    glBegin(GL_QUADS);          // head
    glVertex2i(490, 375);
    glVertex2i(490, 440);
    glVertex2i(160, 440);
    glVertex2i(160, 375);
    glEnd();

    // Nose
    glColor3ub(237, 172, 144);
    glBegin(GL_LINE_LOOP);
    glVertex2i(345, 195);
    glVertex2i(345, 301);
    glVertex2i(305, 301);
    glVertex2i(305, 195);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(380, 195);
    glVertex2i(380, 235);
    glVertex2i(345, 235);
    glVertex2i(345, 195);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(305, 195);
    glVertex2i(305, 235);
    glVertex2i(270, 235);
    glVertex2i(270, 195);
    glEnd();

    // Mask
    glColor4ub(50, 160, 100, 210);
    glBegin(GL_QUADS);
    glVertex2i(390, 190);
    glVertex2i(390, 305);
    glVertex2i(260, 305);
    glVertex2i(260, 190);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(390, 305);
    glVertex2i(390, 230);
    glVertex2i(450, 230);
    glVertex2i(450, 325);
    glVertex2i(350, 325);
    glVertex2i(350, 305);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(260, 305);
    glVertex2i(300, 305);
    glVertex2i(300, 325);
    glVertex2i(200, 325);
    glVertex2i(200, 230);
    glVertex2i(260, 230);
    glEnd();

    // Eyes
    glColor3ub(245, 245, 245);
    glBegin(GL_QUADS);
    glVertex2i(430, 250);
    glVertex2i(430, 305);
    glVertex2i(370, 305);
    glVertex2i(370, 250);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(280, 250);
    glVertex2i(280, 305);
    glVertex2i(220, 305);
    glVertex2i(220, 250);
    glEnd();

    // Mouth
    glColor3ub(40, 40, 40);
    glBegin(GL_QUADS);
    glVertex2i(360, 100);
    glVertex2i(360, 125);
    glVertex2i(290, 125);
    glVertex2i(290, 100);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(380, 125);
    glVertex2i(380, 145);
    glVertex2i(270, 145);
    glVertex2i(270, 125);
    glEnd();

    glColor3ub(250, 250, 250);     // teeth
    glBegin(GL_QUADS);
    glVertex2i(380, 145);
    glVertex2i(380, 160);
    glVertex2i(270, 160);
    glVertex2i(270, 145);
    glEnd();

    // GL
//    glColor3ub(50, 160, 100);
//    glLineWidth(10.0);
//    glBegin(GL_LINE_STRIP);
//    glVertex2i(540, 115);
//    glVertex2i(500, 115);
//    glVertex2i(500, 70);
//    glVertex2i(540, 70);
//    glVertex2i(540, 90);
//    glVertex2i(520, 90);
//    glEnd();
//
//    glBegin(GL_LINE_STRIP);
//    glVertex2i(560, 115);
//    glVertex2i(560, 70);
//    glVertex2i(590, 70);
//    glEnd();
}
