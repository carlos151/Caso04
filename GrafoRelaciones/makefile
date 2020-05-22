CXX = g++
CXXFLAGS = -Wall -g

Main: main.o CargaDatos.o
	$(CXX) $(CXXFLAGS) -o main main.o CargaDatos.o

Main.o: main.cpp CargaDatos.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp 

CargaDatos.o: CargaDatos.cpp Grafo.o

Grafo.o: Grafo.cpp Aristas.o

Aristas.o: Aristas.cpp