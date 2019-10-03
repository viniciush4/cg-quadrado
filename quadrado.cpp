#include "quadrado.h"
#include <math.h>
#include <GL/glut.h>

using namespace std;

Quadrado::Quadrado(){
	this->lado = 20;
    this->x = 0;
    this->y = 0;
    this->angulo = 90;
    this->escala = 1;
}

void Quadrado::desenharPreenchido(){
    glPushMatrix();

        glTranslatef(x, y, 0);

        glRotatef(angulo, 0, 0, 1);

        glScalef(escala*2, escala, 1);

        // Desenha um quadrado
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
            glVertex3f(-lado/2, -lado/2, 0);
            glVertex3f(lado/2, -lado/2, 0);
            glVertex3f(lado/2, lado/2, 0);
            glVertex3f(-lado/2, lado/2, 0);
        glEnd();

        glScalef(escala/4, escala*2, 1);

        // Desenha um círculo
        int i;
        GLfloat x, y;
        glColor3f(0, 1, 0);
        glPointSize(3);
        glBegin(GL_POINTS);

        for(i=0; i<360; i+=20){
            x = 20 * cos(M_PI*i/180);
            y = 20 * sin(M_PI*i/180);
            glVertex3f(x, y, 0);
        }

        glEnd();

    glPopMatrix();
}

void Quadrado::moverParaCima(float velocidade){
    this->y += velocidade;
}

void Quadrado::moverParaBaixo(float velocidade){
    this->y -= velocidade;
}

void Quadrado::moverParaEsquerda(float velocidade){
    this->x -= velocidade;
}

void Quadrado::moverParaDireita(float velocidade){
    this->x += velocidade;
}

void Quadrado::alterarAngulo(float velocidade){
    this->angulo += velocidade;
}

void Quadrado::alterarEscala(float velocidade){
    this->escala += velocidade;
}

void Quadrado::andar(float velocidade){
    this->y += sin(this->angulo*(M_PI/180)) * velocidade;
    this->x += cos(this->angulo*(M_PI/180)) * velocidade;
}

Quadrado::~Quadrado(){
}
