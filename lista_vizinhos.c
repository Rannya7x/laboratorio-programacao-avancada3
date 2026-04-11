#include "stdlib.h"
#include "include/lista_vizinhos.h"
struct lista_vizinhos_t{
    int vizinho;
    struct lista_vizinhos_t *proximo;
};

bool lista_vizinhos_adicionar(int vizinho, lista_vizinhos_t **lista){
    lista_vizinhos_t *nova_lista = (lista_vizinhos_t*)malloc(sizeof(lista_vizinhos_t));
    if(nova_lista == NULL) return false;
    nova_lista->vizinho = vizinho;
    nova_lista->proximo = *lista;
    *lista = nova_lista;
    return true;
}

