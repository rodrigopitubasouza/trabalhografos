//
// Created by rodri on 09/04/2019.
//

#include "ListaAresta.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaAresta::ListaAresta()
{
    primeiro = nullptr;
    ultimo = nullptr;
    quantidadeAresta = 0;
}

ListaAresta::~ListaAresta()
{
    Aresta *arestaParaRemover = primeiro;
    while(arestaParaRemover != nullptr)
    {
        Aresta *proximaAresta = arestaParaRemover->getProx();
        delete arestaParaRemover;
        arestaParaRemover = proximaAresta;
    }
}

/**
*Insere aresta deste no para o no indicado no parametro
*****************************************************************/
void ListaAresta::insereAresta(int id, int peso){
    Aresta *arestaParaAdicionar = new Aresta();
    arestaParaAdicionar->setIdAdjacente(id);
    arestaParaAdicionar->setPeso(peso);
    arestaParaAdicionar->setProx(nullptr);
    quantidadeAresta++;
    if(primeiro == nullptr){
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
void ListaAresta::removeAresta(int idIncidente){
    Aresta *aresta = primeiro;
    Aresta *arestaAnterior;
    if(aresta != nullptr){
        while(aresta != nullptr){
            if(aresta->getIdAdjacente() == idIncidente){
                if(aresta == primeiro){
                    if(primeiro == ultimo){
                        delete primeiro;
                        primeiro = nullptr;
                        ultimo = nullptr;
                        quantidadeAresta--;
                    } else {
                        primeiro = primeiro->getProx();
                        delete aresta;
                        quantidadeAresta--;
                    }
                } else {
                    arestaAnterior->setProx(aresta->getProx());
                    if(aresta == ultimo) ultimo = arestaAnterior;
                    delete aresta;
                    quantidadeAresta--;
                }
            }
            arestaAnterior = aresta;
            aresta = aresta->getProx();
        }
    }
}

/**
*Funcao que imprime a lista de aresta do No
*****************************************************************/
void ListaAresta::imprimir(){
    Aresta* aresta = primeiro;
    while(aresta != nullptr){
        cout << aresta->getIdAdjacente() << "   ";
        aresta = aresta->getProx();
    }
    cout << endl;
}

/**
*Funcao privada para buscar uma determinada aresta na lista
*****************************************************************/
Aresta* ListaAresta::busca(int arestaDesejada){
    Aresta *aresta = primeiro;
    while(aresta != nullptr){
        if(aresta->getIdAdjacente() == arestaDesejada)
            return aresta;
        aresta = aresta->getProx();
    }
    cout << "No nao encontrado. " << endl;
    return aresta;
}

double ListaAresta::getPesos() {
    double peso = 0;
    Aresta* aresta = primeiro;
    for(int i=0 ; i<quantidadeAresta ; i++){
        peso += aresta->getPeso();
        aresta = aresta->getProx();
    }
    return peso;
}