#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 11
int verificarNumero(char *entrada) {
  int i;

  for (i = 0; entrada[i] != '\0'; i++)
  {
    if (entrada[i] != '/' && !isdigit(entrada[i]))
    {
      return 0;
    }
  }

  return 1;
}

int verificarData(char *entrada)
{
  const char substring[3] = "//";

  if (strstr(entrada, substring) != NULL)
  {
    return 0;
  }

  if (verificarNumero(entrada))
  {
    printf("Sao numericos.\n");
  }
  else
  {
    printf("Nao sao numericos.\n");
    return 0;
  }

  int i = 0;
  long data[3];
  const char delimitador[2] = "/";
  char *token = strtok(entrada, delimitador);

  // Alimenta o vetor de inteiros
  while (token != NULL)
  {
    data[i++] = strtol(token, NULL, 10);
    token = strtok(NULL, delimitador);
  }

  // Realiza suas validações. Se alguma não for atingida, retorne '0'

  printf("Dia: %d\n", data[0]);
  printf("Mes: %d\n", data[1]);
  printf("Ano: %d\n", data[2]);

  // Caso contrário, retorne '1'

  return 1;
}

int main()
{
  char str[tam];

  printf("Digite uma data: ");
  gets(str);

  printf("%d\n", verificarData(str));

  return(0);
}