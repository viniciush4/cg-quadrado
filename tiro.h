class Tiro {
public:
	float x;
	float y;
	float angulo;

	Tiro();
	Tiro(float x, float y, float angulo);

	void desenharPreenchido();
	
	void mover(float velocidade);
	
	virtual ~Tiro();
};
