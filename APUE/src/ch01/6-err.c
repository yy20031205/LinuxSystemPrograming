#include "apue.h"
#include <errno.h>

/*
  显示 EACCES: Permission denied
*/
int main(int argc, char *argv[])
{
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
  errno = ENOENT;
  perror(argv[0]);

  exit(0);
}