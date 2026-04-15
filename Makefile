# Variáveis de compilação
CC = gcc
CFLAGS = -Wall -I include
LIBS = -lm

# Arquivos objeto
OBJ = main.o grafo.o lista_vizinhos.o

# Nome do executável
TARGET = grafo

# Regra principal
all: $(TARGET)

# Ligação do executável
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

# Compilação dos módulos individuais
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

grafo.o: grafo.c
	$(CC) $(CFLAGS) -c grafo.c

lista_vizinhos.o: lista_vizinhos.c
	$(CC) $(CFLAGS) -c lista_vizinhos.c

# Limpeza dos arquivos temporários
clean:
	rm -f *.o $(TARGET)