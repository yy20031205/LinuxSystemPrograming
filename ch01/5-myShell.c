#include "apue.h"
#include <sys/wait.h>

/*
1. 该程序从标准输入读取命令，然后执行这些命令，类似于一个简单的shell
*/

int main(void)
{
  char buf[MAXLINE]; /* from apue.h*/
  pid_t pid;
  int status;

  printf("%% "); /* print % */
  while(fgets(buf, MAXLINE, stdin) != NULL)
  {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0; /* replace newline with null */
    }
    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {  /* child */
      execlp(buf, buf, (char *)0);
      err_ret("Could not exec: %s", buf);
      exit(127);
    }
    /* parent */
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error.");
    } 
    printf("%% ");
  }
  exit(0);
}
