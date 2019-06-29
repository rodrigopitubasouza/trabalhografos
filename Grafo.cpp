//
// Created by rodri on 09/04/2019.
//

#include "Grafo.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Grafo::Grafo()
{
    cout << "------------Criando Grafo------------" << endl;
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

Grafo::~Grafo()
{
    No *noParaDeletar = primeiro;
    cout << "------------Apagando Grafo------------" << endl;
    while(noParaDeletar != nullptr)
    {
        No *proximoNo = noParaDeletar->getProx();
        delete noParaDeletar;
        noParaDeletar = proximoNo;
    }
}

/**
*Adiciona um vertice no grafo
*****************************************************************/
void Grafo::insereNo(int id){
    No* noParaAdicionar = new No();
    noParaAdicionar->setId(id);
    noParaAdicionar->setProx(nullptr);

    if(ultimo != nullptr) ultimo->setProx(noParaAdicionar);
    ultimo = noParaAdicionar;

    tamanho++;

    if(tamanho == 1) primeiro = noParaAdicionar;
}

/**
*Remove o vertice do grafo
*****************************************************************/
void Grafo::removeNo(int id){
    No *noParaRemover = primeiro;
    No *noAnteriorDoRemovido;
    if(noParaRemover != nullptr){
        while(noParaRemover != nullptr){
            if(noParaRemover->getId() == id){
                cout << "Removendo No : " << noParaRemover->getId() << endl;
                if(noParaRemover == primeiro){
                    if(primeiro == ultimo){
                        delete primeiro;
                        primeiro = nullptr;
                        ultimo = nullptr;
                        tamanho--;
                    } else {
                        primeiro = primeiro->getProx();
                        delete noParaRemover;
                        tamanho--;
                    }
                } else {
                    noAnteriorDoRemovido->setProx(noParaRemover->getProx());
                    if(noParaRemover == ultimo) {
                        ultimo = noAnteriorDoRemovido;
                    }
                    delete noParaRemover;
                    tamanho--;
                }
            }
            noAnteriorDoRemovido = noParaRemover;
            noParaRemover = noParaRemover->getProx();
        }
        for(noParaRemover = primeiro ; noParaRemover != nullptr ; noParaRemover=noParaRemover->getProx()){
            noParaRemover->removAresta(id);
        }
    } else {
        cout << "Grafo Vazio (ERRO) : REMOCAO VERTICE" << endl;
    }
}

/**
*Busca um vertice do grafo
*****************************************************************/
No* Grafo::busca(int i){
    No *noBuscado = primeiro;
    while(noBuscado != nullptr){
        if(noBuscado->getId() == i){
            return noBuscado;
        }
        noBuscado = noBuscado->getProx();
    }
    return noBuscado;
}

/**
*Cria uma aresta nao direcionada entre os nos
********
 * *********************************************************/
void Grafo::insereAresta(int idPrimeiroNo, int idSegundoNo, int peso){
    if(!existe(idPrimeiroNo))
        insereNo(idPrimeiroNo);
    if(!existe(idSegundoNo))
        insereNo(idSegundoNo);
    No* primeiroNo = busca(idPrimeiroNo);
    No* segundoNo = busca(idSegundoNo);
    primeiroNo->insereAresta(idSegundoNo, peso);
    segundoNo->insereAresta(idPrimeiroNo, peso);
}

/**
*Cria uma aresta direcionada se os nos existirem
*****************************************************************/
void Grafo::insereArestaDir(int idSaidaNo, int idEntradaNo, int peso){
    No* primeiroNo = busca(idSaidaNo);
    if(primeiroNo != nullptr){
        primeiroNo->insereAresta(idEntradaNo, peso);
    } else {
        cout << "Vertice nao encontrado. " << endl;
    }
}

/**
*Remove um arco entre os Nos
*****************************************************************/
void Grafo::removArestaDir(int idSaidaNo, int idEntradaNo){
    No* primeiroNo = busca(idSaidaNo);
    if(primeiroNo != nullptr){
        primeiroNo->removAresta(idEntradaNo);
    } else {
        cout << "Vertice Nao encontrado. " << endl;
    }
}

/**
*Remove uma Aresta entre os Vertices
*****************************************************************/
void Grafo::removAresta(int idPrimeiroNo, int idSegundoNo){
    No* primeiroNo = busca(idPrimeiroNo);
    if(primeiroNo != nullptr){
        primeiroNo->removAresta(idSegundoNo);
    } else {
        cout << "Vertice Nao encontrado. " << endl;
    }
    primeiroNo = busca(idSegundoNo);
    if(primeiroNo != nullptr){
        primeiroNo->removAresta(idPrimeiroNo);
    }
}

/**
*Imprime os vertices do Grafo e diz quais são suas arestas
*****************************************************************/
void Grafo::imprimir(){
    No* no = primeiro;
    cout << "Nos : ";
    while(no != nullptr){
        cout << no->getId() << "  ";
        no = no->getProx();
    }
    cout << endl;
    imprimirArestas();
}

/**
*Imprime todas as arestas dos vertices do grafo
*****************************************************************/
void Grafo::imprimirArestas(){
    No* no = primeiro;
    while(no != nullptr){
        no->imprimirArestas();
        no = no->getProx();
    }
    cout << endl;
}

/**
*Calculo o grau de um determinado vertice
*****************************************************************/
int Grafo::getGrauNo(int id){
    No* noBuscado = busca(id);
    return noBuscado->getGrau();
}

bool Grafo::existe(int id) {
    for(No* no = primeiro ; no != nullptr ; no = no->getProx()){
        if(no->getId() == id)
            return true;
    }
    return false;
}
void Grafo::guloso(Grafo *grafo) {
    No *solucao = new No[grafo->getTamanho()];
    No **listaParaOrdernar = new No*[grafo->getTamanho()];
    No *prox = grafo->primeiro;

    for (int i = 0; i <grafo->getTamanho() ; ++i) {
        listaParaOrdernar[i] = prox;
        prox = prox.getProx();
    }

    ordenaVetor(listaParaOrdernar);
    while(listaParaOrdernar != vazio){
        solucao = listaParaOrdernar[0];
        removo posicao 0
        {
        atualiza grau do no
        atualizo a fracao
        exclui elementos com fracao ==0
        }
        ordeno de novo

    }
}

void Grafo::ordenaVetor(No **listaParaOrdenar) {
    int i , j ;
    double value;
    No* p;
    int gap = 1;
    while(gap < tamanho) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < tamanho; i++) {
            value = listaParaOrdenar[i]->getPesoPonderado();
            p = listaParaOrdenar[i];
            j = i - gap;

            while (j >= 0 && value < listaParaOrdenar[j]->getPesoPonderado()) {
                listaParaOrdenar[j + gap] = listaParaOrdenar[j];
                j -= gap;
            }
            listaParaOrdenar[j + gap] = p;
        }
    }
}



