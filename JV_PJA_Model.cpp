
#include <stdbool.h>

#include"JV_PJA_Model.h"

typedef struct {
	int linha;
	int coluna;
} Coordenada;

struct Lista {
    Coordenada dados;
    struct Lista * proximo;
    struct Lista * anterior;
};

typedef struct Lista* Node;

char mapa[60][60];
int tamanho;
bool mostrarCelulasMortas = false;

char viva = 'O';
char morto = '.';

