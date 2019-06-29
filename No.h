//
// Created by rodri on 09/04/2019.
//

#ifndef GRAFOS_NO_H
#define GRAFOS_NO_H
#include "ListaAresta.h"
#include <iostream>

using namespace std;

class No
{
public:
    No() {lista = new ListaAresta; grau = 0; }
    ~No() {delete lista;}

    int getId() { return id; }
    int getGrau() { return grau; }
    No* getProx() { return prox; }
    void setPeso(int peso){this->peso = peso;}
    void* setProx(No *no) { prox = no; }
    void insereAresta(int idAdjacente) { lista->insereAresta(idAdjacente); grau++; }
    void removAresta(int idIncidente) { lista->removeAresta(idIncidente); grau--;}
    void setId(int novoId) { id = novoId; }
    void imprimirArestas() { cout << "No " << id << " possui aresta com : ";  lista->imprimir(); }
    void zerarGrau() { grau = 0; }
    void diminuiu1Grau() { grau--; }
    int getPeso() { return peso; }
    double getPesoPonderado() {return pesoPonderado = peso/grau;}
    ListaAresta *getLista() {return lista;}


private:
    int id;
    int grau;
    double pesoPonderado;
    int peso;
    No *prox;
    ListaAresta *lista;
};


#endif //GRAFOS_NO_H
