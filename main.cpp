#include <iostream>
#include <math.h>
#include "quadrado.h"
#include <GL/glut.h>

using namespace std;

int teclas[256];
int velocidade;
Quadrado quadrado;

void display(void){

	glClear(GL_COLOR_BUFFER_BIT);

	quadrado.desenharPreenchido();
	
	glutSwapBuffers();
}

void idle(void){

	// quadrado.andar(velocidade);

	if(teclas[0] == 1) {
		quadrado.moverParaCima(velocidade);
	}
	if(teclas[1] == 1) {
		quadrado.moverParaBaixo(velocidade);
	}
	if(teclas[2] == 1) {
		quadrado.moverParaEsquerda(velocidade);
	}
	if(teclas[3] == 1) {
		quadrado.moverParaDireita(velocidade);
	}
	if(teclas[4] == 1) {
		quadrado.alterarAngulo(velocidade);
	}
	if(teclas[5] == 1) {
		quadrado.alterarAngulo(-velocidade);
	}
	if(teclas[6] == 1) {
		quadrado.alterarEscala(+1);
	}
	if(teclas[7] == 1) {
		quadrado.alterarEscala(-1);
	}
	if(teclas[8] == 1) {
		quadrado.andar(velocidade);
	}

	// Marca a janela atual como precisando ser reexibida
	glutPostRedisplay();
}

void keyPress(unsigned char key, int x, int y) {	
	switch (key)
	{
		case 'w':
			teclas[0] = 1;
			break;
		case 's':
			teclas[1] = 1;
			break;
		case 'a':
			teclas[2] = 1;
			break;
		case 'd':
			teclas[3] = 1;
			break;
		case 'u':
			teclas[4] = 1;
			break;
		case 'j':
			teclas[5] = 1;
			break;
		case 'i':
			teclas[6] = 1;
			break;
		case 'k':
			teclas[7] = 1;
			break;
		case 'o':
			teclas[8] = 1;
			break;
	
		default:
			break;
	}
}

void keyUp(unsigned char key, int x, int y) {
	switch (key)
	{
		case 'w':
			teclas[0] = 0;
			break;
		case 's':
			teclas[1] = 0;
			break;
		case 'a':
			teclas[2] = 0;
			break;
		case 'd':
			teclas[3] = 0;
			break;
		case 'u':
			teclas[4] = 0;
			break;
		case 'j':
			teclas[5] = 0;
			break;
		case 'i':
			teclas[6] = 0;
			break;
		case 'k':
			teclas[7] = 0;
			break;
		case 'o':
			teclas[8] = 0;
			break;
	
		default:
			break;
	}
}

int main(int argc, char** argv){

	quadrado = Quadrado();
	velocidade = 3;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Quadrado");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250, 250, -250, 250, -1.0, 1.0);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop();

	return 0;
}
