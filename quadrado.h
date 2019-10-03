class Quadrado {
public:
	float lado;
	float x;
	float y;
	float angulo;
	float escala;

	Quadrado();

	void desenharPreenchido();
	
	void moverParaCima(float velocidade);
	void moverParaBaixo(float velocidade);
	void moverParaEsquerda(float velocidade);
	void moverParaDireita(float velocidade);

	void alterarAngulo(float velocidade);
	void alterarEscala(float velocidade);

	void andar(float velocidade);
	
	
	virtual ~Quadrado();
};
