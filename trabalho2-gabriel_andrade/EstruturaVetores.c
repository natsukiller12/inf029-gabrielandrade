		#include <stdio.h>
		#include <stdlib.h>
		#define TAM 10
		#include "EstruturaVetores.h"

	vetoraux vetores[TAM];


	void inicializar(){
		int i;
		for(i=0; i<TAM; i++){
			vetores[i].posicaovetor = 0;
			vetores[i].quantidade = 0;
			vetores[i].existe = 0;
			vetores[i].espaco = 0;
		}
	}
	void finalizar(){
		int i;
		for(i=0; i<TAM; i++)
			free (vetores[i].vetorauxiliar);
	}
	void insertionsort(int posicao, int vetorAux[]){
		int i, j, kaux;
		for(i = 1; i < vetores[posicao].posicaovetor; i++){
				j=i;
				while(j > 0 && vetorAux[j-1] > vetorAux[j]){
					kaux = vetorAux[j];
					vetorAux[j] = vetorAux[j-1];
					vetorAux[j-1] = kaux;
					j--;
				}
		}
	}
	int getQuantidadeElementosEstruturaAuxiliar(int posicao){
	    int retorno = 0;
	    posicao--;
        if(posicao < 0 || posicao > 10){
            retorno = POSICAO_INVALIDA;
            return retorno;
        }
        if(vetores[posicao].existe == 0){
            retorno = SEM_ESTRUTURA_AUXILIAR;
            return retorno;
        }
            
        if(vetores[posicao].quantidade == 0)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        
	    else if (retorno == 0) 
            retorno = vetores[posicao].quantidade;
	    
        return retorno;
	}
	int getQuantidadeElementosTodos(){
		int retorno = 0;
		int i;

		for(i=0; i < 10; i++){
			if(vetores[i].quantidade != 0)
				retorno += vetores[i].quantidade;
		}
		return retorno;
	}
	int criarEstruturaAuxiliar(int tamanho, int posicao){

		int retorno = 0;
		posicao--;
		if(posicao < 0 || posicao >= 10){
		        // se posição é um valor válido {entre 1 e 10}
			retorno = POSICAO_INVALIDA;
			return retorno;
		}
		else if(vetores[posicao].existe != 0){
		        // a posicao pode já existir estrutura auxiliar
			retorno = JA_TEM_ESTRUTURA_AUXILIAR;
			return retorno;
		}
		else if(tamanho < 1){
		        // o tamanho nao pode ser menor que 1
			retorno = TAMANHO_INVALIDO;
			return retorno;
		}
		else{
		        // deu tudo certo, crie
			vetores[posicao].vetorauxiliar = (int *) malloc(tamanho* sizeof (int));
			vetores[posicao].existe = 1;
			vetores[posicao].espaco = tamanho;
			retorno = SUCESSO;
		}
		if(!vetores[posicao].vetorauxiliar)
		        // o tamanho ser muito grande
			retorno = SEM_ESPACO_DE_MEMORIA;
		return retorno;

	}

		/*
		Rertono (int)
		    1 - inserido com sucesso
		    2 - não tem espaço
		    3 - Não tem estrutura auxiliar

		CONSTANTES
		*/
	int inserirNumeroEmEstrutura(int valor, int posicao){

		int retorno = 0;
		int existeEstruturaAuxiliar = 0;
		int temEspaco = 0;
		int posicao_invalida = 0;
		posicao--;

		if (posicao >= 10 || posicao < 0)
			retorno = POSICAO_INVALIDA;
		else{
		        // testar se existe a estrutura auxiliar
			if (vetores[posicao].existe !=0){
				if (vetores[posicao].quantidade < vetores[posicao].espaco){
		            //insere
					vetores[posicao].vetorauxiliar[vetores[posicao].posicaovetor] = valor;
					vetores[posicao].posicaovetor += 1;
					vetores[posicao].quantidade += 1;
					retorno = SUCESSO;
				}else{
					retorno = SEM_ESPACO;
				}
			}else{
				retorno = SEM_ESTRUTURA_AUXILIAR;
			}
		}

		return retorno;

	}

		// se posição é um valor válido {entre 1 e 10}
	int ehPosicaoValida(int posicao){
		int retorno = 0;
		if (posicao < 0 || posicao >= 10){
			retorno = POSICAO_INVALIDA;
		}else retorno = SUCESSO;

		return retorno;

	}
	/*

	Objetivo: retorna os números da estrutura auxiliar da posição 'posicao'.

	os números devem ser armazenados em vetorAux



	Rertono (int)

	    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'

	    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

	    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

	*/
	int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
		posicao--;
		int retorno = 0;
		int i;
		if (ehPosicaoValida(posicao) != SUCESSO){
			retorno = POSICAO_INVALIDA;
		}
		else if(vetores[posicao].existe == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;

		else{
			for( i = 0; i < vetores[posicao].posicaovetor; i++)
				vetorAux[i] = vetores[posicao].vetorauxiliar[i];
			retorno = SUCESSO;
		}

		return retorno;

	}
	/*

	Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao'.

	os números devem ser armazenados em vetorAux



	Rertono (int)

	    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'

	    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

	    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

	*/

	int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
		posicao--;
	    int retorno = 0;
	    int i, j, kaux;
		if (ehPosicaoValida(posicao) != SUCESSO){
			retorno = POSICAO_INVALIDA;
		}
		else if(vetores[posicao].existe == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;

		else{
			for( i = 0; i < vetores[posicao].posicaovetor; i++)
				vetorAux[i] = vetores[posicao].vetorauxiliar[i];

			insertionsort(posicao, vetorAux);
			retorno = SUCESSO;
		}


	    return retorno;
		}
	void dobrar(int *numdobro){

		*numdobro = *numdobro * 2;

	}

		/*

		Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.

		ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].

		Obs. Esta é uma exclusão lógica



		Rertono (int)

		    SUCESSO - excluido com sucesso

		    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia

		    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

		    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

		*/

	int excluirNumeroDoFinaldaEstrutura(int posicao){
		posicao--;
		int retorno = SUCESSO;
		int i;

		if(ehPosicaoValida(posicao) != SUCESSO)
			retorno = POSICAO_INVALIDA;

		else if(vetores[posicao].existe == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;

		else if(vetores[posicao].quantidade == 0)
			retorno = ESTRUTURA_AUXILIAR_VAZIA;

		else{
			vetores[posicao].quantidade -= 1;
			vetores[posicao].posicaovetor -= 1;
		}
		return retorno;

	}


		/*

		Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.

		Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores

		ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]

		Obs. Esta é uma exclusão lógica

		Rertono (int)

		    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'

		    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia

		    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

		    NUMERO_INEXISTENTE - Número não existe

		    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar



		*/

	int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
		posicao--;
		int i, j, k = 0;
		int retorno = SUCESSO;
		int numdeletado = 0;

		if(ehPosicaoValida(posicao) != SUCESSO)
			retorno = POSICAO_INVALIDA;

		else if(vetores[posicao].existe == 0)
			retorno = SEM_ESTRUTURA_AUXILIAR;

		else if(vetores[posicao].quantidade == 0)
			retorno = ESTRUTURA_AUXILIAR_VAZIA;

		for(i = 0; i < vetores[posicao].quantidade; i++){

			if(vetores[posicao].vetorauxiliar[i] == valor){

				for(j = i; j < vetores[posicao].quantidade; j++)

					vetores[posicao].vetorauxiliar[j] = vetores[posicao].vetorauxiliar[j+1];

				numdeletado++;
				k = 1;
			}
		}
		vetores[posicao].quantidade -= numdeletado;
		vetores[posicao].posicaovetor -= numdeletado;
		if (k == 0)
			retorno = NUMERO_INEXISTENTE;

		return retorno;

	}
/*

Objetivo: retorna os números de todas as estruturas auxiliares.

os números devem ser armazenados em vetorAux



Rertono (int)

    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'

    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int i, j, k=0;
    int retorno = 0;
		for(i=0; i < 10; i++){
			if(vetores[i].quantidade == 0)
				continue;
			if(vetores[i].quantidade != 0){
				for(j = 0; j < vetores[i].quantidade; j++){
					vetorAux[k] = vetores[i].vetorauxiliar[j];
					k++;
				}
			}
		}

    return retorno;
}



/*

Objetivo: retorna os números ordenados de todas as estruturas auxiliares.

os números devem ser armazenados em vetorAux



Rertono (int)

    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'

    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
	int i, j, k, kaux;
    int retorno = 0;
		getDadosDeTodasEstruturasAuxiliares(vetorAux);
		k = getQuantidadeElementosTodos();
		for(i = 1; i < k; i++){
				j=i;
				while(j > 0 && vetorAux[j-1] > vetorAux[j]){
					kaux = vetorAux[j];
					vetorAux[j] = vetorAux[j-1];
					vetorAux[j-1] = kaux;
					j--;
				}
		}
    return retorno;



}



/*

Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho'



Rertono (int)

    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar

    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar

    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo

*/

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
	int retorno = 0;
	posicao--;
	int novoespaco = vetores[posicao].espaco;//10
	novoespaco += novoTamanho;//5
	if(ehPosicaoValida(posicao)!= SUCESSO){
		retorno = POSICAO_INVALIDA;
		return retorno;
	}
	else if(novoespaco < 1){
		retorno = NOVO_TAMANHO_INVALIDO;
		return retorno;
	}
	else if(vetores[posicao].existe == 0){
		retorno = SEM_ESTRUTURA_AUXILIAR;
		return retorno;
	}
	else{
		vetores[posicao].vetorauxiliar = (int *) realloc(vetores[posicao].vetorauxiliar, novoespaco * sizeof(int));
		vetores[posicao].espaco += novoTamanho;
		if(vetores[posicao].espaco < vetores[posicao].quantidade ){
            vetores[posicao].quantidade = vetores[posicao].espaco;
            vetores[posicao].posicaovetor = vetores[posicao].espaco;
		}
		retorno = SUCESSO;
	}
	if(!vetores[posicao].vetorauxiliar)
			retorno = SEM_ESPACO_DE_MEMORIA;


    return retorno;
}

void insereDadosNaLista(No* lista, int num){
	No* no = (No* ) malloc(sizeof(No));

	no->conteudo = num;
	no->prox = NULL;

	if(lista->prox == NULL){
			
		lista->prox = no;

	}else{
		No* aux = lista;

		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
		}

}
No* montarListaEncadeadaComCabecote(){
	No* lista = (No*)malloc(sizeof(No));
	lista->prox = NULL;
	int ret, i, num;

	ret=getQuantidadeElementosTodos();
	if(ret==0)
		return NULL;
	else{
		int vetorAux[ret];
		getDadosDeTodasEstruturasAuxiliares(vetorAux);
		for(i=0; i<ret;i++){
			num = vetorAux[i];
			insereDadosNaLista(lista, num);
		}
	return lista;
	}
}
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
	No* aux = inicio->prox;
	int i=0;
	while(aux != NULL){
		vetorAux[i] = aux->conteudo;
		i++;
		aux = aux->prox;
	}


}
void destruirListaEncadeadaComCabecote(No* inicio){
	No* aux = inicio->prox;
	No* atual;

	while(aux!= NULL){
		atual = aux;
		aux =aux->prox;
		free(atual);
	}
	free(inicio);
}
