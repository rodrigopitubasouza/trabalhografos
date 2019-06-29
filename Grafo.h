//
// Created by rodri on 09/04/2019.
//

#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include "No.h"

class Grafo
{
public:
    Grafo();
    ~Grafo();

    int getTamanho() { return tamanho;}
    void insereNo(int id);
    void removeNo(int id);
    void insereArestaDir(int idPrimeiroNo, int idSegundoNo, int peso);
    void insereAresta(int idPrimeiroNo, int idSegundoNo, int peso);
    void removArestaDir(int idPrimeiroNo, int idSegundoNo);
    void removAresta(int idPrimeiroNo, int idSegundoNo);
    void imprimir();
    void imprimirArestas();
    int getGrauNo(int id);
    void guloso(Grafo *grafo);
    void* ordenaVetor(No **listaParaOrdenar);

private:
    No *primeiro;
    No *ultimo;
    int tamanho;

    No* busca(int id);
    bool existe(int id);
};


#endif //GRAFOS_GRAFO_H
