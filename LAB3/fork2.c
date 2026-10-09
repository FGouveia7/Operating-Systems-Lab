#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void agarractrl(int i)
{
  printf("Signal INT received\n");
}

int main()
{
  int childpid;
  int x;
  
  signal(SIGCONT, &agarractrl);

  if ((childpid = fork()) == -1){
    printf("can't fork");
    exit(1);
  }
  if (childpid == 0){
    /* child process */
    printf("child: child pid = %d, parent pid = %d\n", getpid(), getppid());
    pause();
    x = 0;
    printf("child: x=%d\n", x);
    exit(0);
  }
  else{
    /* parent process */
    printf("parent: child pid = %d, parent pid = %d\n", childpid, getpid());
    x = 1;
    printf("parent: x=%d\n", x);
    exit(0);
  }
}

