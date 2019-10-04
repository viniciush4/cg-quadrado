#include <iostream>
#include <math.h>
#include "quadrado.h"
#include <GL/glut.h>

using namespace std;

int teclas[256];
int velocidade;
Quadrado quadrado;

void calcula_teleporte(){
	double m = tanf(quadrado.angulo * M_PI / 180);
	double E = quadrado.y - 0;
	double A = 1+m*m;
	double B = -2*0 -2*m*m*quadrado.x + 2*E*m;
	double C = E*E - 2*E*m*quadrado.x + m*m*quadrado.x*quadrado.x + 0*0 - 200*200;

	double x1 = (-B + sqrt(B*B - 4*A*C))/(2*A);
	double x2 = (-B - sqrt(B*B - 4*A*C))/(2*A);

	double y1 = quadrado.y + m*(x1-quadrado.x);
	double y2 = quadrado.y + m*(x2-quadrado.x);

	if(fabs(quadrado.x - x1) < fabs(quadrado.x - x2)){
		quadrado.x = x2;
		quadrado.y = y2;
	}else{
		quadrado.x = x1;
		quadrado.y = y1;
	}

}

void desenharArena(){
    float theta = 0.0;
    glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
    for(int i=0; i < 50; i++){
        glVertex3f(200 * cos(theta), 200 * sin(theta), 0.0);
        theta += 2*3.1415926f/50;
    }
    glEnd();
}

void verificarColisao(){
	float distancia = sqrt(pow(quadrado.x,2)+pow(quadrado.y,2));
	if(distancia > 200){
		calcula_teleporte();
	}
}

void display(void){

	glClear(GL_COLOR_BUFFER_BIT);

	desenharArena();

	quadrado.desenharPreenchido();
	
	glutSwapBuffers();
}

void idle(void){

	// quadrado.andar(velocidade);
	
	verificarColisao();

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
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Quadrado");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300, 300, -300, 300, -1.0, 1.0);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop();

	return 0;
}
