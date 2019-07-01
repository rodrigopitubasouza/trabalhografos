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
void ListaAresta::insereAresta(int id, double peso) {
    Aresta *arestaParaAdicionar = new Aresta();
    arestaParaAdicionar->setIdAdjacente(id);
    arestaParaAdicionar->setProx(nullptr);
    arestaParaAdicionar->setPeso(peso);
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

int ListaAresta::getPesoOuInfinito(int i) {
    Aresta *p = primeiro;
    while(p != nullptr){
        if(p->getIdAdjacente() == i)
            return p->getPeso();
        p = p->getProx();
    }
    return 	2147483645;
}

void ListaAresta::insereOrdenado(Aresta* a, int v)
{
    Aresta* p = new Aresta();
    p->setPeso(a->getPeso());
    p->setProx(a->getProx());
    p->setIdAdjacente(a->getIdAdjacente());
    p->setPai(v);
    if(quantidadeAresta == 0){
        primeiro = p;
        ultimo = p;
        p->setProx(NULL);
        quantidadeAresta++;
    }
    else{
        if(p->getPeso() <= primeiro->getPeso()){
            Aresta* q = primeiro;
            p->setProx(q);
            primeiro = p;
            quantidadeAresta++;
        }
        else if(p->getPeso() > ultimo->getPeso()){
            ultimo->setProx(p);
            p->setProx(NULL);
            ultimo = p;
            quantidadeAresta++;
        }
        else{
            Aresta* q = primeiro;
            while(q->getProx()->getPeso() < p->getPeso())
                q = q->getProx();
            Aresta* c = q->getProx();
            q->setProx(p);
            p->setProx(c);
            quantidadeAresta++;
        }
    }
}

void ListaAresta::removeK(Aresta* a)
{
    if(quantidadeAresta == 0)
        cout << "Lista Vazia!!!" << endl;
    else{
        Aresta* p = primeiro;
        if(quantidadeAresta == 1 && p == a){
            delete p;
            primeiro = NULL;
            ultimo = NULL;
            quantidadeAresta--;
        }
        else if(p == a){
            primeiro = p->getProx();
            delete p;
            quantidadeAresta--;
        }
        else{
            while(p != NULL){
                if(p->getProx() != NULL && p->getProx() == a){
                    if(p->getProx() == ultimo){
                        Aresta* q = p->getProx();
                        delete q;
                        p->setProx(NULL);
                        ultimo = p;
                        quantidadeAresta--;
                    }
                    else{
                        Aresta* q = p->getProx();
                        p->setProx(q->getProx());
                        delete q;
                        quantidadeAresta--;
                    }
                }
                p = p->getProx();
            }
        }
    }
}