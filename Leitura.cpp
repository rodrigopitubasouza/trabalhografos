//
// Created by rodri on 09/04/2019.
//

#include "Leitura.h"
#include "Grafo.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

/**
 *Le o arquivo de entrada e inicia o Grafo com seus nos e respectivas
 * arestas.
 *****************************************************************/
void Leitura::iniciaGrafo(Grafo *grafo, string caminhoDoArquivoEntrada) {
    leitor.open(caminhoDoArquivoEntrada);
    if(!leitor.is_open())
        cout << "Erro ao abrir o Arquivo." << endl;
    else{
        int quantidadeNos,idPrimeiroNo, idSegundoNo, peso;
        leitor.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        leitor >> quantidadeNos >> peso >> peso;
        cout << "Numeros de Nos : " << quantidadeNos << endl;
        int i = 1;
        while(!leitor.eof()){
            leitor >> idPrimeiroNo >> idSegundoNo;
            grafo->insereAresta(idPrimeiroNo, idSegundoNo);
        }
    }
    leitor.close();
}