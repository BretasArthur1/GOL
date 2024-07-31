
#include "JV_PJA_Controller.h"
#include "JV_PJA_View.cpp"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void fMenuInicial() {
	int opcao;

	do {
        apresentaMensagem("\n\t\t[PRINCIPAL]\n\n\n");
        apresentaMensagem("1 - Mostrar mapa\n");
        apresentaMensagem("2 - Apagar mapa\n");
        apresentaMensagem("3 - Incluir/excluir celulas\n");
        apresentaMensagem("4 - Exibir vizinhos falecidos\n");
        apresentaMensagem("5 - Iniciar Processo\n");
        apresentaMensagem("6 - Salvar Configuração Padrão\n");
        apresentaMensagem("7 - Carregar Configuração Padrão\n");
        apresentaMensagem("0 - Sair\n");
        apresentaMensagem("Insira uma opção: ");


        scanf("%d", &opcao);
		
        switch (opcao) {
	        case 1:
	        	system("cls");
	        	fprintVizinho();
	            break;
	        case 2: 
	            limparMatriz();
	        	system("cls");
	        	fprintVizinho();
	            break;
	        case 3: 
	            system("cls");
				prepararMatriz();
	        	break;
			case 4: 
		        system("cls");
	       		ativarMostrarCelulasVizinhas();
	            break;
            case 5: 
		        system("cls");
	            jogo();
	            break;
	        case 6: 
	            system("cls");
				salvarPreDefinicao();
	        	break;
	        case 7: 
	            system("cls");
				carregarPreDefinicao();
	        	break;
	        case 0: 
	            exit(0);
	            break;
	        default: 
	        	break;
        }
    } while (opcao != 0);
}

void aplicarRegras(){
	Coordenada coordenadaNula;
	coordenadaNula.linha = -1;
	coordenadaNula.coluna = -1;
	
	Node primeiro = criarNode(coordenadaNula, NULL, NULL);
	
	for(int linha = 0; linha < tamanho; linha++){
		for(int coluna = 0; coluna < tamanho; coluna++){
			int vizinhos = contarVizinhos(linha, coluna);
			
			
			if(vizinhos == 3 || (vizinhos == 2 && mapa[linha][coluna] == viva)){
				Coordenada celula;
				celula.coluna = coluna;
				celula.linha = linha;
				
				inserir(primeiro, celula);
			}
			
		}	
	}
	
	for(int linha = 0; linha < tamanho; linha++){
		for(int coluna = 0; coluna < tamanho; coluna++){
            mapa[linha][coluna] = morto;
		}	
	}
	
	Node cursor = primeiro->proximo;
	while(cursor != NULL){
		Coordenada celula = cursor->dados;

        mapa[celula.linha][celula.coluna] = viva;
		
		cursor = cursor->proximo;
	}
	
	apresentaMensagem("Coordenadas Vivos: ");
	printarLista(primeiro);
	printf("\n\n");
	
	
}

int contarVizinhos(int linha, int coluna){
	int vizinhos = 0;	
		
	char vizinhoHorizontal1 = mapa[linha][coluna - 1];
	char vizinhoHorizontal2 = mapa[linha][coluna + 1];
	char vizinhoVertical1 = mapa[linha - 1][coluna];
	char vizinhoVertical2 = mapa[linha + 1][coluna];
	char vizinhoDiagonalPrincipal1 = mapa[linha - 1][coluna - 1];
	char vizinhoDiagonalPrincipal2 = mapa[linha + 1][coluna + 1];
	char vizinhoDiagonalSecundaria1 = mapa[linha + 1][coluna - 1];
	char vizinhoDiagonalSecundaria2 = mapa[linha - 1][coluna + 1];
	
	if(vizinhoHorizontal1 == viva){
		vizinhos++;
	}

	if(vizinhoHorizontal2 == viva){
		vizinhos++;
	}
	
	if(vizinhoVertical1 == viva){
		vizinhos++;
	}
	
	if(vizinhoVertical2 == viva){
		vizinhos++;
	}
	
	if(vizinhoDiagonalPrincipal1 == viva){
		vizinhos++;
	}
	
	if(vizinhoDiagonalPrincipal2 == viva){
		vizinhos++;
	}
	
	if(vizinhoDiagonalSecundaria1 == viva){
		vizinhos++;
	}
	
	if(vizinhoDiagonalSecundaria2 == viva){
		vizinhos++;
	}
	
	return vizinhos;
}

void fprintVizinho()
{
	if(mostrarCelulasMortas){
		for(int linha = 0; linha < tamanho; linha++){
			for(int coluna = 0; coluna < tamanho; coluna++){
				if (mapa[linha][coluna] == 'O'){
					if(mapa[linha][coluna + 1] != 'O'){
                        mapa[linha][coluna + 1] = '+';
					}
					
					if(mapa[linha][coluna - 1] != 'O'){
                        mapa[linha][coluna - 1] = '+';
					}	  
					
					if(mapa[linha + 1][coluna] != 'O'){
                        mapa[linha + 1][coluna] = '+';
					}	    
					
					if(mapa[linha - 1][coluna] != 'O'){
                        mapa[linha - 1][coluna] = '+';
					}    
					
					if(mapa[linha - 1][coluna + 1] != 'O'){
                        mapa[linha - 1][coluna + 1] = '+';
					}	 
					
					if(mapa[linha - 1][coluna - 1] != 'O'){
                        mapa[linha - 1][coluna - 1] = '+';
					}
					
					if(mapa[linha + 1][coluna - 1] != 'O'){
                        mapa[linha + 1][coluna - 1] = '+';
					}	   
					
					if(mapa[linha + 1][coluna + 1] != 'O'){
                        mapa[linha + 1][coluna + 1] = '+';
					}	 
				}
			}		  
		}
	} else {
		for(int linha = 0; linha < tamanho; linha++){
			for(int coluna = 0; coluna < tamanho; coluna++){
				if(mapa[linha][coluna] == '+'){
                    mapa[linha][coluna] = morto;
				}
			}	
		}
	}
	
	printMatriz();  
		
}

void fprintVizinhosCoordenadas()
{
	Coordenada Vizinhos;
	if(mostrarCelulasMortas){
		apresentaMensagem("Coordenada Vizinhos Mortos: ");
		for(int linha = 0; linha < tamanho; linha++){
			for(int coluna = 0; coluna < tamanho; coluna++){
				if (mapa[linha][coluna] == '+'){
					Vizinhos.linha = linha;
					Vizinhos.coluna = coluna;
					printf(" {%d, %d} ", Vizinhos.linha, Vizinhos.coluna);
				}
			}		  
		}
		
		printf("\n");
	}
}

void obterTamanhoMatriz(){
	do {
		printf("Digite o tamanho desejado para o mapa (10 - 60): ");
		scanf("%d", &tamanho);
		LimparBuffer();
		
		while(tamanho > 60 || tamanho < 10){
            printf("Digite o tamanho desejado para o mapa (10 - 60): ");
            scanf("%d", &tamanho);
			printf("\n Valor Invalido! \n");
		}
		
	} while(tamanho > 60 || tamanho < 10);
}

void gerarMatriz(){
	for(int linha = 0; linha < tamanho; linha++){
		for(int coluna = 0; coluna < tamanho; coluna++){
            mapa[linha][coluna] = morto;
		}	
	}
}

void jogo(){
	char next = 'Y';
	int geracoes;
	int atraso; 
	
	apresentaMensagem("Estado Inicial: \n");
	fprintVizinho();
	
	apresentaMensagem("Defina quantas geracoes e o tempo de atraso: ");
	scanf("%d %d", &geracoes, &atraso);
	
	
	if(atraso == 0)
	{
		int i = 1;
		do {
			if(next != 'N'){
				fprintVizinhosCoordenadas();
				aplicarRegras();
				i++;
				//system("cls");
				fprintVizinho();
			}
			
			apresentaMensagem("Proxima geracao? (Y/N): ");
			scanf(" %c", &next);
			LimparBuffer();
			next = toupper(next);
		
		} while(next != 'N' && i < geracoes);	
	} else {
		
		for (int i = 0; i < geracoes; i++) {
			fprintVizinhosCoordenadas();
			aplicarRegras();
			fprintVizinho();
		//	system("cls");
			
			// ESPERA O ATRASO
			time_t lt1, lt2;
			lt1 = time(NULL);
			lt2 = lt1;
			while (difftime(lt2, lt1) < atraso){
			 	lt2 = time(NULL);
			}	
	    }
	}
}

void prepararMatriz() {
	
	int linha, coluna;
	char remover;
	
	do {
		apresentaMensagem("Onde vc quer jogar? \n");
		apresentaMensagem("Digite -1 -1 para sair \n");
		apresentaMensagem("Redigite uma posicao para remover uma celula \n");
		apresentaMensagem("(linha coluna): ");
		scanf("%d %d", &linha, &coluna);
		LimparBuffer();
		
		
		if (linha > tamanho-1 || linha < -1 || coluna < -1 || coluna > tamanho-1)
		{
			system("cls");
		    apresentaMensagem("Coordenada invalida\n\n");
		}
		
		if(linha != -1 || coluna != -1){
			if (mapa[linha][coluna] == viva)
			{
				apresentaMensagem("Deseja remover esta celula? (Y/N): ");
			    scanf(" %c", &remover);
			    LimparBuffer();
			    remover = toupper(remover);

				if(remover == 'Y'){
                    mapa[linha][coluna] = morto;
				}
				
			} else if(mapa[linha][coluna] == morto || mapa[linha][coluna] == '+'){
                mapa[linha][coluna] = viva;
			}
		
			fprintVizinho();
		}
		
	} while(linha != -1 || coluna != -1);
}

void limparMatriz(){
	gerarMatriz();
}

void ativarMostrarCelulasVizinhas(){
	char option;

	apresentaMensagem("Deseja mostrar as celulas vizinhas? (Y, N): ");
	scanf(" %c", &option);
	
	LimparBuffer();
    option = toupper(option);

	if(option == 'Y'){
        mostrarCelulasMortas = true;
	} else {
        mostrarCelulasMortas = false;
	}
}

Node criarNode(Coordenada data, Node next, Node prev){
	Node node; 
    node = (Node)malloc(sizeof(struct Lista)); 
    node->dados.coluna = data.coluna;
	node->dados.linha = data.linha;
	node->proximo = next;
	node->anterior = prev;
	
	return node;
}

void deletarNode(Node i){
	Node anterior = i->anterior;
	anterior->proximo = i->proximo;
	Node novoValor = i->proximo;
	novoValor->anterior = anterior;
}

void printarLista(Node i){
	Node cursor = i->proximo;
	while(cursor != NULL){
		printf(" {%d, %d} ", cursor->dados.linha, cursor->dados.coluna);
		cursor = cursor->proximo;
	}
	
	
}

void inserir(Node primeiro, Coordenada data){
	Node newNode = criarNode(data, NULL, NULL);
	
   if (primeiro == NULL) {
        primeiro = newNode;
        return;
    }	
	
	while (primeiro->proximo != NULL) {
        primeiro = primeiro->proximo;
    }
    
    primeiro->proximo = newNode;
    newNode->anterior = primeiro;
    
    return;
}

void salvarPreDefinicao(){
	FILE* arquivo;
	
	arquivo = fopen("ARQUIVODODJGR", "w");
	
	if (arquivo == NULL) {
	    fprintf(stderr, "\nErro ao abrir o arquivo.\n");
	    exit(1);
	}

	for(int linha = 0; linha < tamanho; linha++){
		for(int coluna = 0; coluna < tamanho; coluna++){
			fwrite(&mapa[linha][coluna], sizeof(char), 1, arquivo);
		}	
	}
	
	fclose(arquivo);
}

void carregarPreDefinicao(){
	FILE* arquivo;
	
	arquivo = fopen("ARQUIVODODJGR", "r");
	
	if (arquivo == NULL) {
	    fprintf(stderr, "\nErro ao abrir o arquivo.\n");
	    exit(1);
	}
	
	for(int linha = 0; linha < tamanho; linha++){
		for(int coluna = 0; coluna < tamanho; coluna++){
			fread(&mapa[linha][coluna], sizeof(char), 1, arquivo);
		}	
	}
	
	fclose(arquivo);
}
