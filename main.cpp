#include <iostream>
#include "Grafo.h"
#include "Leitura.h"
#include <stdlib.h>

using namespace std;

int main() {
    Grafo grafo;
    Leitura leitura;
    ofstream f;
    double alfa;
    grafoComMelhorSolucao grafoMelhorSolucao;

    leitura.iniciaGrafo(&grafo);

    grafoMelhorSolucao = grafo.guloso(&grafo,0);
    f.open("../Saidas.txt", ofstream::ios_base::app);
    f << endl << "Solução algoritmo guloso : " << endl;
    for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
        f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
    }

    Grafo grafoRand;
    leitura.iniciaGrafo(&grafoRand);
    alfa = 0.8;
    grafoMelhorSolucao = grafoRand.guloso(&grafoRand,alfa);
    f << endl << "Solução algoritmo guloso randomizado com alfa " << alfa << " e a solução tem tamanho " << grafoMelhorSolucao.tam << ":" << endl;
    for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
        f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
    }

    f.close();
    return 0;
}