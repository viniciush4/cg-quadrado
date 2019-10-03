all: quadrado
	g++ main.cpp -o quadrado quadrado.o -lglut -lGLU -lGL
	@echo "Done."

quadrado: quadrado.cpp
	g++ -c quadrado.cpp
	
clean:
	@rm -f *.o quadrado