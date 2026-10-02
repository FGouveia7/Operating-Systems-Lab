/*
 * fact_iter.c -- computacao de factoriais de forma iterativa
 */
#include <stdio.h>	/* importa definicao de printf() */
#include <pthread.h>    /* importa defini��es das primitivas de pthreads */
#include "fact.h"

/*
 * fact_iterativo: calcula, de forma iterativa, o factorial de um 
 * numero passado como argumento e retorna o resultado
 */

void * fact_iterativo (void * n)
{
    int i;
    int valor = *((int *) n);
    int factorial = 1;
    for (i = valor; i > 0; i = i - 1) {
			factorial = factorial * i;
    }
    printf("tarefa %lu: factorial(%.2i)=%i\n",
       (unsigned long) pthread_self(), valor, factorial);
    return NULL;
}


