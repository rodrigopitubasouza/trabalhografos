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
    void* setProx(No *no) { prox = no; }
    void insereAresta(int idAdjacente, int peso) { lista->insereAresta(idAdjacente, peso); grau++; }
    void removAresta(int idIncidente) { lista->removeAresta(idIncidente); grau--; prox->somaPesoTotalDasArestasNo();}
    void setId(int novoId) { id = novoId; }
    void imprimirArestas() { cout << "No " << id << " possui aresta com : ";  lista->imprimir(); }
    void zerarGrau() { grau = 0; }
    void diminuiu1Grau() { grau--; }
    void somaPesoTotalDasArestasNo() { pesoPonderado = grau/lista->getPesos(); }
    double getPesoPonderado() {return pesoPonderado;}


private:
    int id;
    int grau;
    double pesoPonderado;
    No *prox;
    ListaAresta *lista;
};


#endif //GRAFOS_NO_H
