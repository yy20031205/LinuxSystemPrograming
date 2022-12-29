#include "apue.h"

/*
 打印用户的uid和gid
*/
int main()
{
  printf("uid = %d, gid = %d\n", getuid(), getgid());

  exit(0);
}