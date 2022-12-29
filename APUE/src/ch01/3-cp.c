#include "apue.h"

/*
  1.将标准输入复制到标准输出
  2.即复制文件的第二种实现
  3.getc一次读取一个字符，然后putc将此字符写到标准输出
  4.读到最后，getc返回EOF
  5.stdin,stdout，EOF定义在stdio.h
*/

int main(void)
{
  int c;

  while ((c = getc(stdin)) != EOF)
  {
    if (putc(c, stdout) == EOF)
    {
      err_sys("output error.");
    }

  }
  if (ferror(stdin))
  {
    err_sys("input error.");
  }

  exit (0);

}