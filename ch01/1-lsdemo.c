#include "apue.h"
#include <dirent.h>

/*
 ls命令的简单实现
*/

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    if(argc != 2)
        err_quit("a Argument(dir_name) is reuqired! Usage: ls <directory_name>");
    if((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);

    while((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp -> d_name);

    closedir(dp);
    exit (0);
}

