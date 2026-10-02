/*
 * fact_recurs.c -- computacao de factoriais de forma recursiva 
 */

#include <stdio.h>
#include <pthread.h>
#include "fact.h"
/*
 * fact_recursivo: calcula, de forma recursiva, o factorial de um 
 * numero passado como argumento e retorna o resultado
 *
 *  a computacao recursiva faz-se do seguinte modo:
 *  
 *  se n = 0, factorial(n) = 1; 
 *  caso contrario, factorial(n) = n * factorial(n -1)
 *
 */
int calcula_fact(int valor)
{
	if(valor <= 1){
    return 1;
  }
  else{
    return valor * calcula_fact(valor - 1);
  }	
}

void *fact_recursivo(void *n)
{
    int valor = *((int *) n);
    int factorial = calcula_fact(valor);

    printf("tarefa %lu: factorial(%.2i)=%i\n",
       (unsigned long) pthread_self(), valor, factorial);
    return NULL;
}


