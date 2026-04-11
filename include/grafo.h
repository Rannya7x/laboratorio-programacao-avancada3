#ifndef GRAFO_H
#define GRAFO_H
#include <stdbool.h>
#include "lista_vizinhos.h"
typedef struct no_t no_t;
typedef no_t* grafo_t; 
grafo_t grafo_criar(int tamanho);
bool lista_vizinhos_adicionar(int vizinho, lista_vizinhos_t **lista);
void lista_vizinhos_imprimir(lista_vizinhos_t *lista);
void grafo_atualizar_vizinhos(int tam, double raio_comunicacao, grafo_t grafo);
void grafo_imprimir(int tam, grafo_t grafo);
void grafo_destruir(int tam, grafo_t grafo);
#endif
