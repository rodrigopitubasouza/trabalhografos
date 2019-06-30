//
// Created by rodri on 09/04/2019.
//

#ifndef GRAFOS_LEITURA_H
#define GRAFOS_LEITURA_H
#include <fstream>
#include "Grafo.h"

using namespace std;

class Leitura {
private:
    ifstream leitor;

public:
    void iniciaGrafo(Grafo *grafo, string caminhoDoArquivoEntrada);
};


#endif //GRAFOS_LEITURA_H
