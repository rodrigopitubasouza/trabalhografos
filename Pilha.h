#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "NoPilha.h"

class Pilha
{
public:
    Pilha();
    ~Pilha();
    void empilha(int val);
    void desempilha();
    int getTopo();
    void imprime();
    bool vazia();

private:
    NoPilha * topo;
};

#endif // PILHA_H_INCLUDED