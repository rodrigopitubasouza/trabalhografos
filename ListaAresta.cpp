//
// Created by rodri on 09/04/2019.
//

#include "ListaAresta.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaAresta::ListaAresta() {
    primeiro = nullptr;
    ultimo = nullptr;
    quantidadeAresta = 0;
}

ListaAresta::~ListaAresta() {
    Aresta *arestaParaRemover = primeiro;
    while (arestaParaRemover != nullptr) {
        Aresta *proximaAresta = arestaParaRemover->getProx();
        delete arestaParaRemover;
        arestaParaRemover = proximaAresta;
    }
}

/**
*Insere aresta deste no para o no indicado no parametro
*****************************************************************/
void ListaAresta::insereAresta(int id) {
    Aresta *arestaParaAdicionar = new Aresta();
    arestaParaAdicionar->setIdAdjacente(id);
    arestaParaAdicionar->setProx(nullptr);
    quantidadeAresta++;
    if (primeiro == nullptr) {
        primeiro = arestaParaAdicionar;
        ultimo = arestaParaAdicionar;
    } else {
        ultimo->setProx(arestaParaAdicionar);
        ultimo = arestaParaAdicionar;
    }
}

/**
* Remove a aresta deste no para o no indicado no parâmetro
*****************************************************************/
void ListaAresta::removeAresta(int idIncidente) {
    Aresta *aresta = primeiro;
    Aresta *arestaAnterior;
    Aresta *proximaAresta;
    if (aresta != nullptr) {
        while (aresta != nullptr) {
            proximaAresta = aresta->getProx();
            if (aresta->getIdAdjacente() == idIncidente) {
                if (aresta == primeiro) {
                    if (primeiro == ultimo) {
                        delete primeiro;
                        primeiro = nullptr;
                        ultimo = nullptr;
                        quantidadeAresta--;
                        return;
                    } else {
                        primeiro = primeiro->getProx();
                        proximaAresta = aresta->getProx();
                        quantidadeAresta--;
                    }
                } else {
                    arestaAnterior->setProx(aresta->getProx());
                    if (aresta == ultimo) ultimo = arestaAnterior;
                    proximaAresta = aresta->getProx();
                    quantidadeAresta--;
                }
            }
            arestaAnterior = aresta;
            aresta = proximaAresta;
        }
    }
}

/**
*Funcao que imprime a lista de aresta do No
*****************************************************************/
void ListaAresta::imprimir() {
    Aresta *aresta = primeiro;
    while (aresta != nullptr) {
        cout << aresta->getIdAdjacente() << "   ";
        aresta = aresta->getProx();
    }
    cout << endl;
}

/**
*Funcao privada para buscar uma determinada aresta na lista
*****************************************************************/
Aresta *ListaAresta::busca(int arestaDesejada) {
    Aresta *aresta = primeiro;
    while (aresta != nullptr) {
        if (aresta->getIdAdjacente() == arestaDesejada)
            return aresta;
        aresta = aresta->getProx();
    }
    cout << "No nao encontrado. " << endl;
    return aresta;
}
