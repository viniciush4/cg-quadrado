all: quadrado tiro
	g++ main.cpp -o quadrado quadrado.o tiro.o -lglut -lGLU -lGL
	@echo "Done."

quadrado: quadrado.cpp
	g++ -c quadrado.cpp

tiro: tiro.cpp
	g++ -c tiro.cpp

clean:
	@rm -f *.o quadrado