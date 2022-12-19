#include "apue.h"

/*
 1.打印进程id
 2.getpid()会返回进程id，它是一个pid_t类型
*/
int main(void)
{
  printf("hello from process ID: %ld\n", (long)getpid());
  exit (0);
}