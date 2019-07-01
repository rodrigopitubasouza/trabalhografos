//
// Created by rodri on 09/04/2019.
//

#ifndef GRAFOS_ARESTA_H
#define GRAFOS_ARESTA_H


class Aresta {
    public:
        Aresta() {}
        ~Aresta() {}

        Aresta* getProx() { return prox; }
        void setProx(Aresta *aresta) { prox = aresta; }
        void setIdAdjacente(int novoId) { idAdjacente = novoId; }
        void setPeso(double peso) { this->peso = peso; }
        int getIdAdjacente()       { return idAdjacente; }
        int getPeso()       { return peso; }

    private:
        int idAdjacente;
        double peso;
        Aresta *prox;
};


#endif //GRAFOS_ARESTA_H
