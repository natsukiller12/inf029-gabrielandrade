#include <stdio.h>
#include <stdlib.h>

/* Variaveis globais, constantes, arrays e outros*/

char player = 'X';
char tabuleiro[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int posicao;

/* Exibe o Tabuleiro atualizado a cada Jogada */
void exibirTabuleiro()
{
    printf("|++++|++++|++++|\n|  %c |  %c |  %c |\n|++++|++++|++++|\n|  %c |  %c |  %c |\n|++++|++++|++++|\n|  %c |  %c |  %c |\n|++++|++++|++++|\n", tabuleiro[1], tabuleiro[2], tabuleiro[3], tabuleiro[4], tabuleiro[5], tabuleiro[6], tabuleiro[7], tabuleiro[8], tabuleiro[9]);
}

/* Insere o Caracter do jogador atual no campo do tabuleiro desde que o mesmo esteja livre. */
void lancarJogada()
{
    int contador = 0;
    if (tabuleiro[posicao] != 'X' && tabuleiro[posicao] != 'O')
    {
        tabuleiro[posicao] = player;
        if (player == 'X')
        {
            player = 'O';
            contador++;
            exibirTabuleiro();
        }
        else
        {
            player = 'X';
            contador++;
            exibirTabuleiro();
        }
    }
}

/* Inicia a jogada validando se o campo esta livre para inserir o caracter do respectivo jogador. */
void jogada()
{
    printf("Selecione a posicao que deseja marcar:\n");
    scanf("%d", &posicao);
    switch (posicao)
    {
    case 1:
        lancarJogada();
        break;

    case 2:
        lancarJogada();
        break;
    case 3:
        lancarJogada();
        break;
    case 4:
        lancarJogada();
        break;

    case 5:
        lancarJogada();
        break;

    case 6:
        lancarJogada();
        break;

    case 7:
        lancarJogada();
        break;

    case 8:
        lancarJogada();
        break;

    case 9:
        lancarJogada();
        break;
    default:
        printf("O numero %d é inválido, selecione um valor entre 1 e 9 que não esteja em uso.\n", posicao);
        lancarJogada();
        break;
    }
}


/*Valida a jogada e compara com as possibilidades de vencer, caso seja encontrada alguma declara vencedor. */
void varificarGanhador()
{
	int i;
    /* lista as possibilidades de formar linha ( que sao 8 ). */
    char vetorTabuleiro[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 4, 7, 2, 5, 8, 3, 7, 9, 1, 5, 9, 3, 5, 7}; 

    for ( i = 0; i < 8; i++){
	
        if ((tabuleiro[vetorTabuleiro[i]] == 'X' && tabuleiro[vetorTabuleiro[i] + 1] == 'X' && tabuleiro[vetorTabuleiro[i + 2]] == 'X') || (tabuleiro[vetorTabuleiro[i]] == 'O' || tabuleiro[vetorTabuleiro[i] + 1] == 'O' || tabuleiro[vetorTabuleiro[i] + 2] == 'O'))
        {
            printf("Parabens voce ganhou!.");
        }
        else
        {
            jogada();
        }
		}
}

int main(void)
{

    exibirTabuleiro();
    jogada();
}