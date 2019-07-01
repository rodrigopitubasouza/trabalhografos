//
// Created by rodri on 09/04/2019.
//

#ifndef GRAFOS_LISTAARESTA_H
#define GRAFOS_LISTAARESTA_H
#include "Aresta.h"


class ListaAresta
{
    public:
        ListaAresta();
        ~ListaAresta();
        void insereAresta(int id, double peso);
        void removeAresta(int idIncidente);
        void imprimir();
        int getQuantidadeArestas() {return quantidadeAresta;}
        Aresta *getPrimeiro(){ return  primeiro;}
        int getPesoOuInfinito(int i);
        void insereOrdenado(Aresta* a, int v);
        void removeK(Aresta* a);

    private:
        Aresta *primeiro;
        Aresta *ultimo;
        int quantidadeAresta;


        Aresta* busca(int arestaDesejada);
};



#endif //GRAFOS_LISTAARESTA_H
