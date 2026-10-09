#include <stdio.h>	/* Livraria para funções de Input/Output. */
#include <unistd.h> /* Livraria de funções Posix. */
#include <stdlib.h> /* importa a definição do exit */

int main()
{
	int childpid;
	int x;
	if ((childpid = fork()) == -1)
	{
		printf("can't fork");
		exit(1);
	}

	if (childpid == 0)
	{
		/* child process */
		printf("child: child pid = %d, parent pid = %d\n", getpid(), getppid());
		x = 0;
		printf("child: x=%d\n", x);
		exit(0);
	}
	else
	{
		/* parent process */
		printf("parent: child pid = %d, parent pid = %d\n", childpid, getpid());
		x = 1;
		printf("parent: x=%d\n", x);
		exit(0);
	}
}