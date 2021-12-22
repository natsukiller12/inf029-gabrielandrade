#include <stdio.h>
#include <stdlib.h>
#define tam 20
//codigo que recebe uma letra pra busca e uma string pra ser buscada, imprime o numero de vezes q a letra se repete

void main(int argc, char *argv[]) {
	char vet[tam],l;
	int i,c = 0;
	printf("insira uma letra\n");
	scanf("%c",&l);

	printf("agora insira uma frase\n");

	scanf("%s", vet);
	
	for(i=0;i<tam;i++){	
	printf("%c", vet[i]);
		if(vet[i]==l){
			c++;
		}}
		printf("possui %d letras %c\n",c,l);
		system("pause");
	//esse codigo funciona perfeitamente e responde quantas letras tem a frase em questão
	//system("cls");
	//main;
}