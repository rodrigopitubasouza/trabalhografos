#include <iostream>
#include "Pilha.h"

using namespace std;

Pilha::Pilha()
{
    topo = NULL;
}

Pilha::~Pilha()
{
    NoPilha* p = topo;
    while(topo != NULL)
    {
        topo = p->getProx();
        delete p;
        p = topo;
    }
}

void Pilha::empilha(int val)
{
    NoPilha * p = new NoPilha();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
}

void Pilha::desempilha()
{
    NoPilha* p;
    if(topo != NULL)
    {
        p = topo;
        topo = p->getProx();
        delete p;
    }
}

void Pilha::imprime()
{
    NoPilha* p = topo;
    if(p != NULL){
        while(p != NULL){
            cout << p->getInfo() << " \t ";
            p = p->getProx();
        }
        cout << endl;
    }
    else cout << "Pilha vazia!" << endl;
}

int Pilha::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();

}

bool Pilha::vazia()
{
    if(topo == NULL)
        return true;
    else return false;
}