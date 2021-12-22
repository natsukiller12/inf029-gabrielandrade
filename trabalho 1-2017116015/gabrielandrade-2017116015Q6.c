#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "gabrielandrade-2017116015.h"



int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;
    int Base[300];
    int Busca[300];
    int contBase = iCont = jCont = controle = contBusca = 0;

	while(numerobase >= 0){
        //preenchendo vetor de int numerobase
		if(numerobase < 10 && numerobase >= 0 ){
			Base[contBase] = numerobase;
			break;
		}
		else{
			Base[contBase] = numerobase % 10;
			numerobase = numerobase / 10;
			contBase++;
		}
	}
	while(numerobusca >= 0){
        //preenchendo vetor numerobusca
		if(numerobusca < 10 && numerobase >= 0){
			Busca[contBusca] = numerobusca;
			break;
		}
		else{
			Busca[contBusca] = numerobusca % 10;
			numerobusca = numerobusca / 10;
			contBusca++;
		}
	}
	//buscando ocorrencias 
	for (iCont = 0; iCont <= contBase; ++iCont){
		if(contBusca == 0){
			if (Busca[0] == Base[iCont]){
				qtdOcorrencias++;
			}
		}
		else{
			if(Busca[jCont] == Base[iCont]){
				controle = 1;
				jCont++;
			}
			else if (Busca[jCont] != Base[iCont]){
				controle = 0;
				jCont = 0;
			}
			if(controle == 1 && jCont == contBusca){
				controle = 0;
				jCont = 0;
				qtdOcorrencias++;
			}
		}
	}
    return qtdOcorrencias;
}