#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 512
#define STDIN 0

#define FILENAME "test.output"

int main(int argc, char *argv[]){
  char buf[BUF_SIZE];
  int bytes_read,bytes_written;
  int fd;


  /* ler do standard input */
  bytes_read = read(STDIN, buf, BUF_SIZE);
  if (bytes_read < 0){
    printf("Ocorreu um erro na leitura: %s\n", strerror(errno));
    return -1;
  }

  /*
   * Os atributos fornecidos como argumentos para o open sao (por ordem):
   * fd : file descriptor
   * flags : flags de abertura. Neste caso usamos:
   *         - O_CREATE para indicar que o ficheiro deve ser criado caso nao exista
   *         - O_TRUNC para indicar que o tamanho do ficheiro ser 'truncado' a 0 
   *           aquando do open, efectivamente apagando os conteudos previos do mesmo
   *         - O_RDWR para indicar que o ficheiro deve ser aberto para leitura e escrita
   * mode : permissoes de unix usadas aquando da criacao do ficheiro. Neste caso Read Write eXecute para o User actual.
   * para outras flags e modes ver a manpage de open (man 2 open)
   */
  fd = open(FILENAME, O_CREAT | O_TRUNC | O_RDWR , S_IRWXU);
  if (fd < 0){
    printf("Ocorreu um erro na abertura do ficheiro: %s\n", strerror(errno));
    return -1;
  }
  
  /* escrever para o ficheiro */ 
  bytes_written = write(fd, buf, bytes_read);
  if (bytes_written < 0){
    printf("Ocorreu um erro na escrita: %s\n", strerror(errno));
    return -1;
  }
  close(fd);

  return 1;
}








