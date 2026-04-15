# laboratorio-programacao-avancada3

## Grafo - Rede Sem Fio Estática (Laboratório 03)

### 1. Objetivo

O objetivo deste projeto é a implementação de um Grafo Não-Direcionado para representar uma rede sem fio estática. O sistema modela dispositivos de rede como vértices, estabelecendo conexões (arestas) entre eles com base na proximidade física.

### 2. Estrutura de Dados

Seguindo o modelo de organização de dados para redes esparsas, o projeto utiliza a representação de Lista de Adjacência.
- Grafo (grafo_t): Implementado como um vetor de nós de tamanho N, onde N é a quantidade de dispositivos na rede.
- Nó (no_t): Cada elemento do vetor armazena o ID do dispositivo, suas coordenadas físicas (pos_x e pos_y) e um ponteiro para sua respectiva lista de vizinhos.
- Lista de Vizinhos (lista_vizinhos_t): Uma lista encadeada que armazena os identificadores (inteiros) dos nós vizinhos. Diferente de implementações anteriores que armazenavam estruturas completas, esta lista foca apenas nos IDs.

### 3. Lógica de Vizinhança

A conectividade entre dois nós (i e j) é definida pelo raio de comunicação. Uma aresta existe se a distância euclidiana entre eles for menor que o raio especificado no arquivo de entrada.

- Cálculo da Distância:  (xi − xj)^2 + (yi − yj)^2.
- Atualização: Para cada nó i, o sistema o compara com todos os outros nós j da rede. Se a condição de distância for atendida, i é adicionado à lista de vizinhos de j.

### 4. Fluxo de Execução

O programa é operado via terminal, recebendo o caminho do arquivo de dados como parâmetro (argv).

1. Leitura de Parâmetros: Obtém o número total de nós e o raio de comunicação da primeira linha do arquivo.
2. Criação e Inicialização: Aloca o vetor do grafo e inicializa cada lista de vizinhos como nula (NULL).
3. Processamento: Lê as coordenadas de cada dispositivo e executa a função de atualização de vizinhos.
4.Saída: Imprime a lista de adjacência de cada nó no formato: NÓ X: id1 id2....

### 5. Exemplo de Uso

Para compilar o projeto utilizando o Makefile, basta digitar o comando abaixo no terminal:

```bash
make
```

Após a compilação, execute o programa passando o arquivo de entrada como argumento:

```bash
./grafo arquivo_teste.in
```

### 6. Exemplo de entrada e Saida

Exemplo de Entrada (arquivo_entrada.txt):

```txt
10 38.0
0 6.0 20.5
1 33.4 6.2
2 23.7 41.6
3 51.0 54.8
4 50.9 27.8
5 71.1 7.2
6 79.1 41.9
7 99.6 21.6
8 109.3 51.6
9 128.7 7.3
```

Saída Esperada (./grafo arquivo_entrada.txt):

```bash
NÓ 0: 2 1
NÓ 1: 5 4 2 0
NÓ 2: 4 3 1 0
NÓ 3: 6 4 2
NÓ 4: 6 5 3 2 1
NÓ 5: 7 6 4 1
NÓ 6: 8 7 5 4 3
NÓ 7: 9 8 6 5
NÓ 8: 7 6
NÓ 9: 7
```