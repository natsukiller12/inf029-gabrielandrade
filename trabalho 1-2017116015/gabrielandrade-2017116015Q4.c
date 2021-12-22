#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include "gabrielandrade-2017116015.h"


int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int iCont, jCont, kCont, xCont, yCont, Cont01, Cont02, Cont3;
    int qtdOcorrencias; 
    
    xCont = yCont = jCont = kCont = Cont01 = Cont02 = qtdOcorrencias = 0;

    if(strlen(strBusca) == 1){
        for(iCont = 0; strTexto[i]!='\0'; iCont++){
            if(strTexto[iCont] == strBusca[0])
                Cont01++;
        }
        return Cont01;
    }

    for(iCont = 0; strTexto[iCont]!='\0'; iCont++){
        Cont01 = 0;
    if(strTexto[iCont] == -95 || strTexto[iCont] == -87 || strTexto[iCont] == -83 || strTexto[iCont] == -77 || strTexto[iCont] == -70 || strTexto[iCont] == -93 || strTexto[iCont] == -89)
       Cont3++;
        if(strTexto[iCont] == strBusca[jCont]){
            for(xCont = iCont + 1, kCont = jCont + 1; strBusca[kCont] == strTexto[xCont]; xCont++ ,kCont++)
                Cont01++;
        }
        if(Cont01 == strlen(strBusca)-1){
            posicoes[yCont++] = (iCont + 1)- Cont3;
            posicoes[yCont++] = xCont - Cont3;
            qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}