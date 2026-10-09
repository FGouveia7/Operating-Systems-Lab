#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 512

#define STDIN 0
#define STDOUT 1

int main(int argc, char *argv[]){
  char buf[BUF_SIZE];
  int bytes_read,bytes_written;

  bytes_read = read(STDIN, buf, BUF_SIZE);
  if (bytes_read < 0){
    printf("Ocorreu um erro na leitura: %s\n", strerror(errno));
    return -1;
  }
  bytes_written = write(STDOUT, buf, bytes_read);
  if (bytes_written < 0){
    printf("Ocorreu um erro na escrita: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}




