#include "stdlib.h"
#include "include/lista_vizinhos.h"
#include "include/grafo.h"
struct no_t {
    int id;
    double pos_x;
    double pos_y;
    lista_vizinhos_t *lista_vizinhos;
};

grafo_t grafo_criar(int tamanho){
    grafo_t grafo = (grafo_t) malloc(tamanho * sizeof(no_t));
    if(grafo == NULL) return NULL;
    return grafo;
}



