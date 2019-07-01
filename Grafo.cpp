//
// Created by rodri on 09/04/2019.
//

#include "Grafo.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include <fstream>
#include <unistd.h>
#include <random>
#include <queue>
#include <list>

using namespace std;

Grafo::Grafo() {
    cout << "------------Criando Grafo------------" << endl;
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

Grafo::~Grafo() {
    No *noParaDeletar = primeiro;
    cout << "------------Apagando Grafo------------" << endl;
    while (noParaDeletar != nullptr) {
        No *proximoNo = noParaDeletar->getProx();
        delete noParaDeletar;
        noParaDeletar = proximoNo;
    }
}

/**
*Adiciona um vertice no grafo
*****************************************************************/
void Grafo::insereNo(int id, int peso) {
    No *noParaAdicionar = new No();
    noParaAdicionar->setId(id);
    noParaAdicionar->setProx(nullptr);
    noParaAdicionar->setPeso(peso);


    if (ultimo != nullptr) ultimo->setProx(noParaAdicionar);
    ultimo = noParaAdicionar;

    tamanho++;

    if (tamanho == 1) primeiro = noParaAdicionar;
}

/**
*Remove o vertice do grafo
*****************************************************************/
void Grafo::removeNo(int id) {
    No *noParaRemover = primeiro;
    No *noAnteriorDoRemovido;
    if (noParaRemover != nullptr) {
        while (noParaRemover != nullptr) {
            if (noParaRemover->getId() == id) {
                cout << "Removendo No : " << noParaRemover->getId() << endl;
                if (noParaRemover == primeiro) {
                    if (primeiro == ultimo) {
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
                    if (noParaRemover == ultimo) {
                        ultimo = noAnteriorDoRemovido;
                    }
                    delete noParaRemover;
                    tamanho--;
                }
            }
            noAnteriorDoRemovido = noParaRemover;
            noParaRemover = noParaRemover->getProx();
        }
        for (noParaRemover = primeiro; noParaRemover != nullptr; noParaRemover = noParaRemover->getProx()) {
            noParaRemover->removAresta(id);
        }
    } else {
        cout << "Grafo Vazio (ERRO) : REMOCAO VERTICE" << endl;
    }
}

/**
*Busca um vertice do grafo
*****************************************************************/
No *Grafo::busca(int i) {
    No *noBuscado = primeiro;
    while (noBuscado != nullptr) {
        if (noBuscado->getId() == i) {
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
void Grafo::insereAresta(int idPrimeiroNo, int idSegundoNo) {
    if (!existe(idPrimeiroNo))
        insereNo(idPrimeiroNo, ceil((idPrimeiroNo % 200) + 1));
    if (!existe(idSegundoNo))
        insereNo(idSegundoNo, ceil((idSegundoNo % 200) + 1));
    No *primeiroNo = busca(idPrimeiroNo);
    No *segundoNo = busca(idSegundoNo);
    primeiroNo->insereAresta(idSegundoNo, ceil((idPrimeiroNo % 200) + 1));
    segundoNo->insereAresta(idPrimeiroNo, ceil((idPrimeiroNo % 200) + 1));
}

/**
*Cria uma aresta direcionada se os nos existirem
*****************************************************************/
void Grafo::insereArestaDir(int idSaidaNo, int idEntradaNo, int peso) {
    No *primeiroNo = busca(idSaidaNo);
    if (primeiroNo != nullptr) {
        primeiroNo->insereAresta(idEntradaNo, peso);
    } else {
        cout << "Vertice nao encontrado. " << endl;
    }
}

/**
*Remove um arco entre os Nos
*****************************************************************/
void Grafo::removArestaDir(int idSaidaNo, int idEntradaNo) {
    No *primeiroNo = busca(idSaidaNo);
    if (primeiroNo != nullptr) {
        primeiroNo->removAresta(idEntradaNo);
    } else {
        cout << "Vertice Nao encontrado. " << endl;
    }
}

/**
*Remove uma Aresta entre os Vertices
*****************************************************************/
void Grafo::removAresta(int idPrimeiroNo, int idSegundoNo) {
    No *primeiroNo = busca(idPrimeiroNo);
    if (primeiroNo != nullptr) {
        primeiroNo->removAresta(idSegundoNo);
    } else {
        cout << "Vertice Nao encontrado. " << endl;
    }
    primeiroNo = busca(idSegundoNo);
    if (primeiroNo != nullptr) {
        primeiroNo->removAresta(idPrimeiroNo);
    }
}

/**
*Imprime os vertices do Grafo e diz quais são suas arestas
*****************************************************************/
void Grafo::imprimir() {
    No *no = primeiro;
    cout << "Nos : ";
    while (no != nullptr) {
        cout << no->getId() << "  ";
        no = no->getProx();
    }
    cout << endl;
    imprimirArestas();
}

/**
*Imprime todas as arestas dos vertices do grafo
*****************************************************************/
void Grafo::imprimirArestas() {
    No *no = primeiro;
    while (no != nullptr) {
        no->imprimirArestas();
        no = no->getProx();
    }
    cout << endl;
}

/**
*Calculo o grau de um determinado vertice
*****************************************************************/
int Grafo::getGrauNo(int id) {
    No *noBuscado = busca(id);
    return noBuscado->getGrau();
}

bool Grafo::existe(int id) {
    for (No *no = primeiro; no != nullptr; no = no->getProx()) {
        if (no->getId() == id)
            return true;
    }
    return false;
}

/**
 * Algoritmo gulos randomizado e guloso
 * @param grafo
 * @param alfa quando o alfa = 0 observa-se que estamos falando do algoritmo guloso
 * Utilização do Mersenne Twister para fazermos o randomico
 * @return o resultado do grafoDeRetorno é dado por uma estrutura que tem a quantidade de elementos que entrou na solução
 * e os elementos que entraram
 */
grafoComMelhorSolucao Grafo::guloso(Grafo *grafo, double alfa) {

    No **listaParaOrdernar = new No *[grafo->getTamanho()];
    int tamanhoDaLista = grafo->getTamanho();
    No *prox = grafo->primeiro;
    int pos;
    int remocao;
    int contadorElementosSolucao;
    grafoComMelhorSolucao grafoDeRetorno;
    int *vetorDaSolucao = new int[grafo->getTamanho()];
    for (int i = 0; i < grafo->getTamanho(); ++i) {
        prox->setGrau(prox->getGrauOriginal());
        listaParaOrdernar[i] = prox;
        prox = prox->getProx();
    }
    ordenaVetor(listaParaOrdernar, tamanhoDaLista);
    contadorElementosSolucao = 0;

    while (tamanhoDaLista != 0) {
        pos = ceil(alfa * (tamanhoDaLista - 1));
        // Utilização de engine Mersenne twister para fazer o random.
        std::random_device rd{};
        std::mt19937 engine{rd()};
        std::uniform_int_distribution<int> dist(1, pos);
        remocao = pos != 0 ? dist(engine) : 0;

        vetorDaSolucao[contadorElementosSolucao] = listaParaOrdernar[remocao]->getId();
        contadorElementosSolucao++;
        tamanhoDaLista = atualizaLista(listaParaOrdernar, remocao, tamanhoDaLista);
        ordenaVetor(listaParaOrdernar, tamanhoDaLista);
    }
    grafoDeRetorno.tam = contadorElementosSolucao;
    grafoDeRetorno.vet = vetorDaSolucao;
    return grafoDeRetorno;
}


/**
 * Funcao que ordena o vetor de nos
 * para deixar o No na sua devida posição
 * definida pelo peso/grau.
 * @param listaParaOrdenar Ponteiro para o vetor de Nos
 * @param tamanhoDaLista tamanho que representa a quantidade de nos no vetor
 * @return Função sem retorno
 */
void Grafo::ordenaVetor(No **listaParaOrdenar, int tamanhoDaLista) {
    int i, j;
    double value;
    No *p;
    int gap = 1;
    while (gap < tamanhoDaLista) {
        gap = 3 * gap + 1;
    }
    while (gap > 1) {
        gap /= 3;
        for (i = gap; i < tamanhoDaLista; i++) {
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

/**
 * Funçao que diminui o grau dos nos adjacentes ao no
 * que vai ser removido, remove o nó e remove todos os nós que ficaram com grau 0
 * @param pNo Ponteiro para o vetor
 * @param remocao Posicao do nó que vai ser removido
 * @param tamanhoLista Quantidade de elementos no vetor de nos
 * @return retorna o tamanho da lista apos as remocoes
 */
int Grafo::atualizaLista(No **pNo, int remocao, int tamanhoLista) {
    int idNoRemovido = pNo[remocao]->getId();
    Aresta *listaDeArestasAux = pNo[remocao]->getLista()->getPrimeiro();
    Aresta *listaInicialDeAresta = pNo[remocao]->getLista()->getPrimeiro();
    for (int i = 0; i < tamanhoLista; i++) {
        while (listaDeArestasAux != nullptr) {
            if (pNo[i]->getId() == listaDeArestasAux->getIdAdjacente()) {
                pNo[i]->setGrau(pNo[i]->getGrau() - 1);
            }
            listaDeArestasAux = listaDeArestasAux->getProx();
        }
        listaDeArestasAux = listaInicialDeAresta;

        if (i >= remocao) {
            pNo[i] = pNo[i + 1];
        }
    }
    tamanhoLista = tamanhoLista - 1;
    for (int i = 0; i < tamanhoLista; i++) {
        if (pNo[i]->getGrau() == 0) {
            pNo[i] = pNo[tamanhoLista - 1];
            pNo[tamanhoLista - 1] = nullptr;
            tamanhoLista = tamanhoLista - 1;
            i--;
        }
    }
    return tamanhoLista;

}

/**
 * Algoritmo guloso reativo que faz um vetor com alfas de 0.05 ate 0.5 e chama o randomizado
 * e faz outro vetor de probabilidades, atualizando as probabilidades de acordo com as melhores
 * solucoes geradas por cada alfa, fazendo com que os melhores alfas tenham maiores probabilidades
 * gerando solucoes melhores.
 * @param grafo Ponteiro para o grafo que vai ser feito o guloso.
 * @param k Int de quantas iteracoes serao feitas
 * @param tamAlf Tamanho do vetor de alfas
 * @return Melhor Solucao Gerada
 */
grafoComMelhorSolucao Grafo::gulosoReativo(Grafo *grafo, int k, int tamAlf) {
    float *alfas = new float[tamAlf];
    float b = 0.05;
    int mat[2][tamAlf];//MATRIZ DE MEDIAS
    alfas[0] = 0.05;
    for (int a = 1; a < tamAlf; a++) alfas[a] = alfas[a - 1] + b;//VARIAÇÕES DE ALFAS 0.1 ATÉ 0.5
    grafoComMelhorSolucao *menor = new grafoComMelhorSolucao[tamAlf];

    ////PRIMEIRA ITERAÇÃO = RANDOMIZADO
    menor[0] = guloso(grafo, alfas[0]);
    mat[0][0] = menor[0].tam;
    mat[1][0] = 1;
    int melhor = menor[0].tam;
    for (int c = 1; c < tamAlf; c++) {
        menor[c] = guloso(grafo, alfas[c]);//
        mat[0][c] = menor[c].tam;
        mat[1][c] = 1;
        if (menor[c].tam < melhor) melhor = menor[c].tam; //MELHOR SOLUCAO DA 1º ITERAÇÃO
    }
    float *Q = new float[tamAlf];
    for (int d = 0; d < tamAlf; d++)
        Q[d] = Qi(melhor, mat[0][d],
                  mat[1][d]);//cria o vetor de normalização e atualiza com os resultados da primeira iteração

    //VETOR PROBABILIDADE
    float sum = SomatorioQ(Q, tamAlf);
    float *P = new float[tamAlf];
    P[0] = (1000 * (Q[0] / (float) sum));//cria o vetor de probabilidade e o adequa ao padrão escolhido
    for (int i = 1; i < tamAlf; i++) {
        P[i] = P[i - 1] + (1000 * (Q[i] / (float) sum));
    }

    int i = 1;
    grafoComMelhorSolucao s;
    grafoComMelhorSolucao better = menor[0];
    int in;
    //srand((unsigned) time(NULL));
    while (i < k) {
        //cout << "i " << i << endl;
        in = RandomPseudoAleatorio(P, tamAlf);//  ESCOLHE UM ALFA ALEATORIO
        s = gulosoReativo(grafo, alfas[in], 1);
        if (menor[in].tam > s.tam) menor[in] = s;//atualiza menor solucao no vetor
        mat[0][in] = mat[0][in] + s.tam;//incrementa o somatorio das solucoes
        mat[1][in]++;//incremente o numero de vezes que um alfa foi rodado
        if (s.tam < melhor) {
            melhor = s.tam;    //atualiza a melhor solucao
            better = s;
        }
        if (i % 10 == 0) //atualiza vetor de normalização e o vetor de probabilidade
        {
            for (int f = 0; f < tamAlf; f++) {
                Q[f] = Qi(melhor, mat[0][f], mat[1][f]);
            }
            sum = SomatorioQ(Q, tamAlf);
            P[0] = (1000 * (Q[0] / (float) sum));
            for (int g = 1; g < tamAlf; g++) {
                P[g] = (P[g - 1] + 1000 * (Q[g] / (float) sum));
            }
        }
        i++;
    }
    return better;
}

/**
    Calcula Qi na forma escolhida pelo grupo
*/
float Grafo::Qi(float tamMelhorS, float somatorio, float qtd) {
    return (((float) tamMelhorS) / (((float) somatorio) / ((float) qtd)));
}

/**
    função auxiliar para qualquer somatorio de
    todos os elementos do vetor Q
*/
float Grafo::SomatorioQ(float *q, int tam) {
    float somatorio = 0;
    for (int i = 0; i < tam; i++) somatorio = somatorio + q[i];
    return somatorio;
}

/**
     o vetor de probabilidade foi montado de forma
     crescente de 0 a 1000 diminuindo a perda de precisão
*/
int Grafo::RandomPseudoAleatorio(float *prob, int tamAlf) {
    //sleep(1);
    int x = rand() % 1000;
    for (int i = 0; i < tamAlf; i++) {
        if (x < prob[i]) {
            return i;
        }
    }
    return tamAlf - 1;
}

/**
 * Faz uma matriz com a distancia minima entre todos os Vertices do
 * Grafo.
 * @return Funcao sem retorno
 */
void Grafo::algFloyd(int a, int b) {
    int mat[tamanho][tamanho];
    int posicaoInicio, posicaoFim;
    No *noEmI = primeiro;
    No *noEmJ = primeiro->getProx();
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == j) { mat[i][j] = 0; }
            else {
                mat[i][j] = noEmI->getPesoDaAresta(noEmJ->getId());
                noEmJ = noEmJ->getProx();
            }
        }
        if (a == noEmI->getId()) {
            posicaoInicio = i;
        }
        if (b == noEmI->getId()) {
            posicaoFim = i;
        }
        noEmI = noEmI->getProx();
        noEmJ = primeiro;
    }
    for (int k = 0; k < tamanho; k++) {
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (mat[i][j] > mat[i][k] + mat[k][j] && mat[i][k] + mat[k][j] > 0)
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
    ofstream f;
    f.open("../Saidas.txt", ofstream::ios_base::app);
    if ((a >= 0) && (b >= 0)) {
        f << endl << "Menor Caminho(Floyd) entre " << a << " e " << b << " : " << mat[posicaoInicio][posicaoFim]
          << endl;
        cout << endl << "Menor Caminho(Floyd) entre " << a << " e " << b << " : " << mat[posicaoInicio][posicaoFim]
             << endl;
    } else {
        f << endl << "Vertices Invalidos (ERRO)-Algoritmo Floyd" << endl;
        cout << endl << "Vertices Invalidos (ERRO)-Algoritmo Floyd" << endl;
    }
    f.close();
}

/**
* Algoritmo de Dijkstra para encontrar menor caminho entre dois vertices
* escreve no arquivo de Saida o dist[destino] com a distancia entre os dois nos passados por parâmetro
* e no console
* @param origem id do no de origem.
* @param destino id do no de destino
* @return retorna o valor da distancia entre os nos de origem e destino
*/
int Grafo::algDijkstra(int origem, int destino) {
    int dist[tamanho];
    int visitados[tamanho];
    int idDoNo[9999];

    No *primeiroNo;
    No *todosOsNos = primeiro;

    for (int j = 0; j < 9999; ++j) {
        idDoNo[j] = 0;
    }
    for (int i = 0; i < tamanho; i++) {
        dist[i] = INT_MAX / 2;
        visitados[i] = false;
        idDoNo[todosOsNos->getId()] = i;
        todosOsNos = todosOsNos->getProx();
    }

    priority_queue<pair<int, int>,
            vector<pair<int, int> >, greater<pair<int, int> > > pq;


    dist[idDoNo[origem]] = 0;

    pq.push(make_pair(dist[origem], origem));

    while (!pq.empty()) {
        pair<int, int> p = pq.top(); // extrai o pair do topo
        int u = p.second; // obtém o vértice do pair
        pq.pop(); // remove da fila

        // verifica se o vértice não foi expandido
        if (visitados[idDoNo[u]] == false) {
            // marca como visitado
            visitados[idDoNo[u]] = true;
            primeiroNo = busca(u);
            Aresta *a = primeiroNo->getLista()->getPrimeiro();
            while (a != nullptr) {
                if (dist[idDoNo[a->getIdAdjacente()]] > dist[idDoNo[primeiroNo->getId()]] + a->getPeso()) {
                    dist[idDoNo[a->getIdAdjacente()]] = dist[idDoNo[primeiroNo->getId()]] + a->getPeso();
                    pq.push(make_pair(dist[idDoNo[a->getIdAdjacente()]], a->getIdAdjacente()));
                }
                a = a->getProx();
            }
        }
    }
    return dist[idDoNo[destino]];

}


/**
* Algoritmo de Prim
* Arvore geradora minima,algoritmo que tenta gerar uma árvore de tamanho minimo
* seguindo um caminho que tenha as menores distancias entre todos os vertices que ja esta na solução
* @return retorna o custo para andar em todos os nós da árvore
*/
int Grafo::Prim() {
    int dist[tamanho];
    int visitados[tamanho];
    int idDoNo[9999];

    No *primeiroNo;
    No *todosOsNos = primeiro;

    for (int j = 0; j < 9999; ++j) {
        idDoNo[j] = 0;
    }
    dist[0] = 0;
    for (int i = 1; i < tamanho; i++) {
        dist[i] = INT_MAX / 2;
        visitados[i] = false;
        idDoNo[todosOsNos->getId()] = i;
        todosOsNos = todosOsNos->getProx();
    }

    priority_queue<pair<int, int>,
            vector<pair<int, int> >, greater<pair<int, int> > > pq;


    pq.push(make_pair(dist[0], primeiro->getId()));

    while (true) {
        int davez = -1;

        while (!pq.empty()) {
            int atual = pq.top().second;
            pq.pop();

            if (!visitados[idDoNo[atual]]) {
                davez = atual;
                break;
            }
        }

        if (davez == -1) break;

        visitados[idDoNo[davez]] = true;
        primeiroNo = busca(davez);
        Aresta *a = primeiroNo->getLista()->getPrimeiro();
        while (a != nullptr) {

            // A nova possível distância é dist.
            // Comparamos isso com distancia[atual].
            // Porém, é importante checar se o vértice atual não foi processado ainda
            if (dist[idDoNo[a->getIdAdjacente()]] > a->getPeso() &&
                !visitados[a->getIdAdjacente()]) {// vemos que vale a pena usar o vértice davez
                dist[idDoNo[a->getIdAdjacente()]] = a->getPeso(); // atualizamos a distância
                pq.push(make_pair(dist[idDoNo[a->getIdAdjacente()]], a->getIdAdjacente()));
            }
            a = a->getProx();
        }
    }

    int custo_arvore = 0;
    for(int i = 0;i < tamanho;i++) {
        if(dist[i] != INT_MAX / 2){
            custo_arvore += dist[i];
        }

    }

    return custo_arvore;

}

/**
 * Faz uma arvore geradora minima e printa os caminhos escolhidos
 */
void Grafo::kruskal()
{
    if(tamanho != 0){
        No* p = primeiro;
        int vetArv[tamanho];
        bool visit[tamanho];
        bool condicao[tamanho];
        Aresta* a = p->getLista()->getPrimeiro();
        ListaAresta* lista = new ListaAresta();

        for(int i = 0; i < tamanho; i++){
            vetArv[i] = p->getId();
            visit[i] = false;
            condicao[i] = false;
            p = p->getProx();
        }
        p = primeiro;

        while(p != NULL){
            while(a != NULL){
                if(!visit[a->getIdAdjacente()])
                    lista->insereOrdenado(a, p->getId());
                a = a->getProx();
            }
            visit[p->getId()] = true;
            p = p->getProx();
            if(p != NULL)
                a = p->getLista()->getPrimeiro();
        }

        int cont = 0;
        cout << "Arvore geradora: " << endl;
        while(lista->getQuantidadeArestas() != 0 && cont != tamanho-1){
            if(condicao[lista->getPrimeiro()->getPai()] && condicao[lista->getPrimeiro()->getIdAdjacente()])
                lista->removeK(lista->getPrimeiro());
            else{
                if(lista->getPrimeiro()->getPai() > lista->getPrimeiro()->getIdAdjacente()){
                    cout << "Aresta de " << lista->getPrimeiro()->getPai() << " para " << lista->getPrimeiro()->getIdAdjacente() << " peso: " << lista->getPrimeiro()->getPeso() << endl;
                    condicao[lista->getPrimeiro()->getPai()] = true;
                    lista->removeK(lista->getPrimeiro());
                    cont++;
                }
                else{
                    cout << "Aresta de " << lista->getPrimeiro()->getPai() << " para " << lista->getPrimeiro()->getIdAdjacente() << " peso: " << lista->getPrimeiro()->getPeso() << endl;
                    condicao[lista->getPrimeiro()->getIdAdjacente()] = true;
                    lista->removeK(lista->getPrimeiro());
                    cont++;
                }
            }

        }

        cout << "Numero de aresta na solucao: " << cont << endl;
        cout << "Numero de vertices: " << cont+1 << endl;


        delete lista;
    }
}










