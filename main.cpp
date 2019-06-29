#include <iostream>
#include "Grafo.h"
#include "Leitura.h"
#include <stdlib.h>

using namespace std;

int main() {
    Grafo grafo;
    Leitura leitura;
    leitura.iniciaGrafo(&grafo);
    grafo.guloso(&grafo,0, "guloso");
    return 0;
}