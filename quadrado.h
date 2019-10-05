class Quadrado {
public:
	float lado;
	float x;
	float y;
	float angulo;
	float escala;
	float angulo_canhao;
	float angulo_canhao_arena;
	float angulo_helices;

	Quadrado();

	void desenharPreenchido();
	
	void moverParaCima(float velocidade);
	void moverParaBaixo(float velocidade);
	void moverParaEsquerda(float velocidade);
	void moverParaDireita(float velocidade);

	void alterarAngulo(float velocidade);
	void alterarAnguloCanhao(float velocidade);
	void alterarEscala(float velocidade);

	void andar(float velocidade);
	void girarHelices(float velocidade);
	
	
	virtual ~Quadrado();
};
