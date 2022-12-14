#include "apue.h"

/*
从标准输入读，并向标准输出写
即实现复制普通文件的第一种实现
*/
#define BUFFSIZE 4096

int main()
{
    int n;
    char buf[BUFFSIZE];

    /*
    STDIN_FILENO(标准输入文件描述符)和STDOUT_FILENO(标准输出描述符)定义在/usr/include/unistd.h
    头文件在apue.h中包含了unistd.h

    read函数，成功会返回读取的字节数，错误则返回-1，具体可以：man read

    */

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error!");
    if (n < 0)
        err_sys("read error");

    exit (0);

}
