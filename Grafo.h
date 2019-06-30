//
// Created by rodri on 09/04/2019.
//

#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include "No.h"

typedef struct grafoComMelhorSolucao {
    int tam;
    int *vet;
} grafoComMelhorSolucao;

class Grafo
{
public:
    Grafo();
    ~Grafo();

    int getTamanho() const { return tamanho;}
    void insereNo(int id, int peso);
    void removeNo(int id);
    void insereArestaDir(int idPrimeiroNo, int idSegundoNo, int peso);
    void insereAresta(int idPrimeiroNo, int idSegundoNo, int peso);
    void removArestaDir(int idPrimeiroNo, int idSegundoNo);
    void removAresta(int idPrimeiroNo, int idSegundoNo);
    void imprimir();
    void imprimirArestas();
    int getGrauNo(int id);
    grafoComMelhorSolucao guloso(Grafo *grafo, double alfa);
    grafoComMelhorSolucao gulosoReativo(Grafo *grafo,int k, int tamAlf);
    void menorCaminhoDijkstra(int v, int vN);
    void algFloyd(int a, int b);




private:
    No *primeiro;
    No *ultimo;
    int tamanho;

    No* busca(int id);
    bool existe(int id);
    int atualizaLista(No **pNo, int remocao, int tamanhoLista);
    void ordenaVetor(No **listaParaOrdenar, int tamanhoDaLista);
    float Qi(float tamMelhorS, float somatorio, float qtd);
    float SomatorioQ(float *q, int tam);
    int RandomPseudoAleatorio(float * prob, int tamAlf);
    bool verificaVisit(bool vet[], int n);

};


#endif //GRAFOS_GRAFO_H
