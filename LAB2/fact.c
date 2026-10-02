/*
 * fact.c -- modulo principal do programa de calculo de factoriais
 *
 */

#include <stdio.h>	/* importa definicao de printf() */
#include <stdlib.h>
#include <pthread.h>
#include "fact.h"


/* modos de computacao da funcao factorial(n) */

#define MODO_ITERATIVO 1
#define MODO_RECURSIVO 0

/*
 * programa principal
 */

int main(int argc, char *argv[])
{
    int modo = MODO_ITERATIVO;   
    int i;

    /* preenchimento do vector com valores aleatorios */
    for (i=0; i < DIM_DADOS; i++) {
        dados[i]=rand()%10;
    }

    for (i=0; i < DIM_DADOS; i++) {
        if (modo == MODO_ITERATIVO) {
            if (thr_create(NULL, 0, fact_iterativo, 
                           (void *) &dados[i], THR_NEW_LWP, NULL) != 0) {
                printf("criacao de thread falhada\n");
                exit(1);
            }
        } else {
            if (thr_create(NULL, 0, fact_recursivo, 
                           (void *) &dados[i], THR_NEW_LWP, NULL) != 0) {
                printf("criacao de thread falhada\n");
                exit(1);
            }
        }
    }

		for (i=0; i < DIM_DADOS; i++) {
        thr_join(NULL,NULL,NULL);
		}
    return 0;
}



