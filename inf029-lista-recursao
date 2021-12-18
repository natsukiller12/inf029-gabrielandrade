#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Q1 --> Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N. */
int fatorial(int n) {
	if(n < 2) {
		return 1;
	}
	return n * fatorial(n - 1);
}

/* Q2 --> Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência Fibonacci.
        Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...        */
int fibonacci(int n) {
	if(n < 2) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}
/* Q3 --> Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321 */
int inverte(int n) {
	if((n / 10) == 0) {
		return n;
	}
	return inverte(n / 10) + (n % 10) * pow(10, abs(log10(n)));
}

int inverteSig(int n) {
	if(n < 0) {
		return -1 * inverte(n * -1);
	}
	return inverte(n);
}

/* Q45 Escreva uma função recursiva que calcule a soma dos dígitos de um número inteiro. Por exemplo, se a entrada
for 123, a saída deverá ser 1+2+3 = 6. */

int somaDigitos(int n){
	if(n < 10) return n % 10;
	return somaDigitos(n / 10) + n % 10;
}
/* Q40 Escreva uma função recursiva que calcule a sequência dada por:
F(1) = 1
F(2) = 2
F(n) = 2 * F(n-1) + 3 * F(n-2). */

int sequencia2(int n){
	if(n == 1) return 1;
	if(n == 2) return 2;
	return 2  * sequencia2(n - 1) + 3 * sequencia2(n - 2);
}
/* Q29 Implemente, usando a linguagem C, a função h definida recursivamente por:
    h(m,n) = m + 1 se n = 1
    	   = n - 1 se m = 1
           = h(m, n - 1) + h(m - 1, n) se m > 1 e n > 1*/


int h(int m, int n) {
	if(m < 1 || n < 1) return -1;
	if(n == 1) return m + 1;
	if(m == 1) return n - 1;
	return h(m, n - 1) + h(m - 1, n);
}


/* Q25 --> Os números de Catalan são definidos pela seguinte recursão: C(n) = 1 se n = 0; 2(2n - 1)C(n - 1)/n + 1 se n > 0
Alguns números desta sequência são: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786...
Faça uma função recursiva que receba um número N e retorne o N-ésimo número de Catalan. */
int catalan(int n) {
	if(n == 0) {
		return 1;
	}
	return 2 * (2 * n - 1) * catalan(n - 1) / (n + 1);
}
/* Q23 -->  A sequência de Padovan é uma sequência de naturais P(n) definida pelos valores iniciais
P(0) = P(1) = p(2) = 1 e a seguinte relação recursiva: P(n) = P(n - 2) + P(n - 3) se n > 2
Alguns valores da sequência são: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...
Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da sequência de Padovan. */
int padovan(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return padovan(n - 2) + padovan(n - 3);
}
/* Q16 --> A função fatorial duplo é definida como o produto de todos os números naturais ímpares de 1 até algum
número natural ímpar N. Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15 */

int fatDuplo(int n) {
	if(n == 1) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	return n * fatDuplo(n - 2);
}
/* Q17 --> O fatorial quádruplo de um número N é dado por (2n)!/n! Faça uma função recursiva que receba um número
inteiro positivo N e retorne o fatorial quádruplo desse número. */
int fatQuadruplo(int n) {
	int interna(int n, int k) {
		if(n == k) {
			return  k;
		}
		return n * interna(n - 1, k);
	}
	return interna(2 * n, n + 1);
}
