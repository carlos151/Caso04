CXX = g++
CXXFLAGS = -Wall -g

Main: main.o Generador.o
	$(CXX) $(CXXFLAGS) -o main main.o Generador.o

Main.o: main.cpp Generador.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp 

Generador.o: Generador.cpp