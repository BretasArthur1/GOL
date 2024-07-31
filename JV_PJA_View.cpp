#include "JV_PJA_View.h"
#include<stdio.h>
#include <iostream>
#include "JV_PJA_Model.cpp"
void apresentaMensagem(char mens[100])
{
 printf("%s", mens);
}

void printMatriz(){
	printf("    ");
	for(int i = 0; i < tamanho; i++){
		printf("%2d ", i);
	}
	
	printf("\n");
	
	for(int linha = 0; linha < tamanho; linha++){
		printf(" %2d ", linha);
		
		for(int coluna = 0; coluna < tamanho; coluna++){
			printf(" %c ", mapa[linha][coluna]);
		}
		
		printf("\n");
	}
}

void LimparBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
