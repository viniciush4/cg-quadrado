#include <iostream>
#include "tiro.h"
#include <math.h>
#include <GL/glut.h>

using namespace std;

Tiro::Tiro(){
    this->x = 0;
    this->y = 0;
    this->angulo = 0;
}

Tiro::Tiro(float x, float y, float angulo){
    this->x = x;
    this->y = y;
    this->angulo = angulo;
}

void Tiro::desenharPreenchido(){
    glPushMatrix();

        glTranslatef(x, y, 0);

        // Desenha um círculo
        int i;
        GLfloat x, y;
        glColor3f(1, 1, 0);
        glPointSize(5);
        glBegin(GL_POINTS);
            for(i=0; i<360; i+=20){
                x = 3 * cos(M_PI*i/180);
                y = 3 * sin(M_PI*i/180);
                glVertex3f(x, y, 0);
            }
        glEnd();

    glPopMatrix();

}

void Tiro::mover(float velocidade){
    this->y += velocidade*sin(M_PI*angulo/180);
    this->x += velocidade*cos(M_PI*angulo/180);
}

Tiro::~Tiro(){
}
