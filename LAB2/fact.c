/*
 * fact.c -- modulo principal do programa de calculo de factoriais
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "fact.h"

/* modos de computacao da funcao factorial(n) */
#define MODO_ITERATIVO 1
#define MODO_RECURSIVO 0

int main(int argc, char *argv[])
{
    int modo = MODO_RECURSIVO;
    int i;
    int dados[DIM_DADOS];
    pthread_t ThreadsId[DIM_DADOS];

    /* preenchimento do vector com valores aleatorios */
    for (i = 0; i < DIM_DADOS; i++) {
        dados[i] = rand() % 10;
    }

    /* criacao das threads */
    for (i = 0; i < DIM_DADOS; i++) {
        void *(*fn)(void *) = (modo == MODO_ITERATIVO) ? fact_iterativo
                                                       : fact_recursivo;
        if (pthread_create(&ThreadsId[i], NULL, fn, (void *) &dados[i]) != 0) {
            printf("criacao de thread falhada\n");
            exit(1);
        }
    }

    /* espera pelo fim de todas as threads */
    for (i = 0; i < DIM_DADOS; i++) {
        pthread_join(ThreadsId[i], NULL);
    }

    return 0;
}