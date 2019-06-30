//
// Created by rodri on 09/04/2019.
//

#include "Leitura.h"
#include "Grafo.h"
#include <iostream>
#include <cstdlib>
#include <string>

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
        leitor >> quantidadeNos;
        cout << "Numeros de Nos : " << quantidadeNos << endl;
        while(!leitor.eof()){
            leitor >> idPrimeiroNo >> idSegundoNo >> peso;
            grafo->insereAresta(idPrimeiroNo, idSegundoNo, peso);
        }
    }
    leitor.close();
}