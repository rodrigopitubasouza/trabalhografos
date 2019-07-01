#include <iostream>
#include "Grafo.h"
#include "Leitura.h"
#include <stdlib.h>
#include <chrono>
#include <time.h>


using namespace std;

//int main(int argc, char *argv[ ]) {
int main() {

    srand(static_cast<unsigned int>(time(nullptr)));
    /*
    if(argc == 1) {
    cout << "Faltam Argumentos" << endl;
    exit(1);
    }
    */

    Grafo grafo;
    Leitura leitura;
    ofstream f;
    double alfa;
    int espacamento, iteracoes;
    grafoComMelhorSolucao grafoMelhorSolucao;

    //leitura.iniciaGrafo(&grafo, argv[1]);
    //leitura.iniciaGrafo(&grafo, "../Arquivo/p-hat1500-2.mtx");

    /*int flag = 99;
    while (flag != 0) {
        if (flag == 1) {
            grafoMelhorSolucao = grafo.guloso(&grafo, 0);
            f.open("../Saidas.txt", ofstream::ios_base::app);
            f << endl << "Solução algoritmo guloso tem " << grafoMelhorSolucao.tam << " nós"<< endl;
            for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
                f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
            }
            f.close();
        } else if (flag == 2) {
            cout << "Digite o Alfa (Entre 0 e 1) : ";
            cin >> alfa;
            if (alfa > 1 || alfa < 0) {
                cout << "Digite o Alfa (Entre 0 e 1) : ";
            } else {
                grafoComMelhorSolucao aux = grafo.guloso(&grafo, alfa);
                f.open("../Saidas.txt", ofstream::ios_base::app);
                f << endl << "Solução algoritmo guloso randomizado com alfa " << alfa << " e a solução tem "
                  << grafoMelhorSolucao.tam << " nós:" << endl;
                for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
                    f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
                }
                f.close();
            }
        } else if (flag == 3) {
            espacamento = 10;
            iteracoes = 50;
            grafoComMelhorSolucao aux = grafo.gulosoReativo(&grafo, iteracoes, espacamento);
            f.open("../Saidas.txt", ofstream::ios_base::app);
            f << endl << "Solução algoritmo guloso Reativo com " << grafoMelhorSolucao.tam << " nós:" << endl;
            for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
                f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
            }
            f.close();

        } else if (flag == 4) {
            int a, b;
            cout << "Digite o primeiro Vertice : ";
            cin >> a;
            cout << "Digite o segundo Vertice : ";
            cin >> b;
            grafo.algFloyd(a, b);
        } else if (flag == 5) {
            int a, b;
            cout << "Digite o primeiro Vertice : ";
            cin >> a;
            cout << "Digite o segundo Vertice : ";
            cin >> b;
            int dist = grafo.algDijkstra(a, b);
            f.open("../Saidas.txt", ofstream::ios_base::app);
            f << endl << "Menor Caminho(Dijkstra) entre " << a << " e " << b << " : " << dist << endl;
            cout << endl << "Menor Caminho(Dijkstra) entre " << a << " e " << b << " : " << dist << endl;
            f.close();
        } else if (flag == 6) {
            int dist = grafo.Prim();
            f.open("../Saidas.txt", ofstream::ios_base::app);
            f << endl << "O custo da árvore é : " << dist << endl;
            cout << endl << "O custo da árvore é : " << dist << endl;
            f.close();
        } else if (flag == 7) {
            grafo.kruskal();
            flag = 98;
        }

        if (flag != 98) {
            cout << endl;
            cout << "------------------ Selecione uma opcao ------------------" << endl;
            cout << " 1 - Algoritmo Guloso de Cobertura de Vertice" << endl;
            cout << " 2 - Algoritmo Guloso Randomizado " << endl;
            cout << " 3 - Algoritmo Guloso Reativo " << endl;
            cout << " 4 - Algoritmo de Floyd" << endl;
            cout << " 5 - Algoritmo de Dijkstra" << endl;
            cout << " 6 - Algoritmo de Prim" << endl;
            cout << " 7 - Algoritmo de Kruskal" << endl;
            cout << " 0 - Sair" << endl;
            cin >> flag;
        }else {
            cin >> flag;
            flag = 0;
        }
    }*/
    leitura.iniciaGrafo(&grafo, "../Arquivo/p-hat1500-2.mtx");
 //   leitura.iniciaGrafo(&grafo, "../Arquivo/brock800-4.mtx");
 //   leitura.iniciaGrafo(&grafo, "../Arquivo/brock200-4.mtx");

    // FUNCAO UTILIZADA PARA CONTAGEM DE TEMPO
    auto inicio = std::chrono::high_resolution_clock::now();

    grafoMelhorSolucao = grafo.guloso(&grafo, 0);
    f.open("../Saidas.txt", ofstream::ios_base::app);
    f << endl << "Solução algoritmo guloso : " << endl;
    for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
        f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
    }
/*
    alfa = 0.2;
    grafoMelhorSolucao = grafo.guloso(&grafo, alfa);
    f << endl << "Solução algoritmo guloso randomizado com alfa " << alfa << " e a solução tem "
      << grafoMelhorSolucao.tam << " nós:" << endl;
    for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
        f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
    }

   iteracoes = 10;
    espacamento = 10;
    grafoMelhorSolucao = grafo.gulosoReativo(&grafo, iteracoes, espacamento);
    f << endl << "Solução algoritmo guloso Reativo com " << grafoMelhorSolucao.tam << " nós:" << endl;
    for (int i = 0; i < grafoMelhorSolucao.tam; ++i) {
        f << endl << grafoMelhorSolucao.vet[i] << " " << endl;
    }
*/
    f.close();


//ALGORITMO A SER TESTADO

    auto resultado = std::chrono::high_resolution_clock::now() - inicio;
    long long seconds = std::chrono::duration_cast<std::chrono::seconds>(resultado).count();
    cout << seconds << "segundos" << endl;
    cin >> alfa;
    return 0;

}