#include "stdlib.h"
#include "math.h"
#include "include/lista_vizinhos.h"
#include "include/grafo.h"


grafo_t grafo_criar(int tamanho){
    grafo_t grafo = (grafo_t) malloc(tamanho * sizeof(no_t));
    if(grafo == NULL) return NULL;
    return grafo;
}

void grafo_atualizar_vizinhos(int tam, double raio_comunicacao, grafo_t grafo){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(i != j){
                double distancia = sqrt(pow(grafo[i].pos_x - grafo[j].pos_x, 2) + pow(grafo[i].pos_y - grafo[j].pos_y, 2));
                if(distancia < raio_comunicacao){
                    lista_vizinhos_adicionar(grafo[i].id, &grafo[j].lista_vizinhos);
                }
            }
        }
    }
}