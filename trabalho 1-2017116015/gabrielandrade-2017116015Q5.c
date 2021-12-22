#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "gabrielandrade-2017116015.h"





int q5(int num){
    int retorno = 0;
    int i = 1;

    while (i <= n)
    {
        retorno = retorno * 10;
        retorno = retorno + (n % (i*10)- n % i)/ i;
        i = i * 10;
    }

    return retorno;
}
