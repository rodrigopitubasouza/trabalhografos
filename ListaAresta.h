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
        void insereAresta(int id, int peso);
        void removeAresta(int idIncidente);
        void imprimir();
        double getPesos();
        int getQuantidadeArestas() {return quantidadeAresta;}

    private:
        Aresta *primeiro;
        Aresta *ultimo;
        int quantidadeAresta;

        Aresta* busca(int arestaDesejada);
};



#endif //GRAFOS_LISTAARESTA_H
