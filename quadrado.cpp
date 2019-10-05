#include <iostream>
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
    this->angulo_canhao = 0;
    this->angulo_helices = 0;
}

void Quadrado::desenharPreenchido(){
    glPushMatrix();

        glTranslatef(x, y, 0);

        glRotatef(angulo, 0, 0, 1);

        glScalef(escala, escala, 1);

        // Desenha um quadrado
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
            glVertex3f(-lado/2, -lado/2, 0);
            glVertex3f(lado/2, -lado/2, 0);
            glVertex3f(lado/2, lado/2, 0);
            glVertex3f(-lado/2, lado/2, 0);
        glEnd();


        // Desenha um círculo
        glPushMatrix();
        glScalef(escala/4, escala*2, 1);
        int i;
        GLfloat x, y;
        glColor3f(0, 1, 0);
        glPointSize(5);
        glBegin(GL_POINTS);
            for(i=0; i<360; i+=20){
                x = 20 * cos(M_PI*i/180);
                y = 20 * sin(M_PI*i/180);
                glVertex3f(x, y, 0);
            }
        glEnd();
        glPopMatrix();

        // Desenha canhão
        glPushMatrix();
        glTranslatef(lado/2, 0, 0);
        glRotatef(angulo_canhao, 0, 0, 1);
        glScalef(escala*2, escala/2, 1);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
            glVertex3f(0, -lado/2, 0);
            glVertex3f(0, lado/2, 0);
            glVertex3f(lado, lado/2, 0);
            glVertex3f(lado, -lado/2, 0);
        glEnd();
        glPopMatrix();

        // Desenha hélice 1
        glPushMatrix();
        glTranslatef(lado/2, lado*2, 0);
        glScalef(escala/2, escala*2, 1);
        glRotatef(angulo_helices, 1, 0, 0);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
            glVertex3f(-lado/2, -lado/2, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(lado/2, -lado/2, 0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(lado/2, lado/2, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(-lado/2, lado/2, 0);
        glEnd();
        glPopMatrix();

        // Desenha hélice 2
        glPushMatrix();
        glTranslatef(lado/2, -lado*2, 0);
        glScalef(escala/2, escala*2, 1);
        glRotatef(angulo_helices, 1, 0, 0);
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
            glVertex3f(-lado/2, -lado/2, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(lado/2, -lado/2, 0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(lado/2, lado/2, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(-lado/2, lado/2, 0);
        glEnd();
        glPopMatrix();


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

void Quadrado::alterarAnguloCanhao(float velocidade){
    if(this->angulo_canhao + velocidade < 45 && this->angulo_canhao + velocidade > -45){
        this->angulo_canhao += velocidade;
        cout << this->angulo_canhao << endl;
    }
}

void Quadrado::alterarEscala(float velocidade){
    this->escala += velocidade;
}

void Quadrado::andar(float velocidade){
    this->y += sin(this->angulo*(M_PI/180)) * velocidade;
    this->x += cos(this->angulo*(M_PI/180)) * velocidade;
}

void Quadrado::girarHelices(float velocidade){
    this->angulo_helices += velocidade;
}

Quadrado::~Quadrado(){
}
