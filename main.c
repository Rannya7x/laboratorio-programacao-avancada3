#include <stdio.h>
#include "grafo.h"

int main(int argc, char *argv[]){
    //abre o arquivo
    FILE *arquivo = fopen(argv[1], "r");

    //Lê a primeira linha usando o fscanf com o formato "%d\t%lf\n" para ler a quantidade de nós e o raio de comunicação.

    int numero_nos;
    double raio_comunicacao;

    fscanf(arquivo, "%d\t%lf\n", &numero_nos, &raio_comunicacao);

    grafo_t grafo = grafo_criar(numero_nos);

    //Cria um contador i;
    int i;

    //Para cada linha do arquivo de entrada, lê os dados de id, x e y diretamente para o grafo[i] e seta grafo[i].lista_vizinhos = NULL; Incremente i.
    for (i = 0; i < numero_nos; i++){
        int id;
        double x, y;

        fscanf(arquivo, "%d\t%lf\t%lf\n", &id, &x, &y);

        grafo[i].id = id;
        grafo[i].pos_x = x;
        grafo[i].pos_y = y;
        grafo[i].lista_vizinhos = NULL;
    }
    
    //atualiza vizinhos
    grafo_atualizar_vizinhos(numero_nos, raio_comunicacao, grafo);
    //imprime o grafo
    grafo_imprimir(numero_nos, grafo);

    //fecha o arquivo
    fclose(arquivo);
    //destroi o grafo
    grafo_destruir(grafo, numero_nos);

    return 0;
}
