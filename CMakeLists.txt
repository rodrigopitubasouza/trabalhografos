cmake_minimum_required(VERSION 3.12)
project(grafos)

set(CMAKE_CXX_STANDARD 14)

add_executable(grafos main.cpp Aresta.cpp Aresta.h Grafo.cpp Grafo.h No.cpp No.h ListaAresta.cpp ListaAresta.h Leitura.cpp Leitura.h)