## 项目介绍

> **本项目是本人关于unix环境高级编程(第三版)这本书的学习记录****本项目是本人关于unix环境高级编程(第三版)这本书的学习记录**

## 学习环境

* 系统环境

  * Ubuntu20.04

* apue源码安装

  ```sh
  
   wget http://www.apuebook.com/src.3e.tar.gz
   tar xf src.3e.tar.gz && cd apue.3e/
   make 
   cp apue.3e/include/apue.h /usr/include/
   cp apue.3e/lib/libapue.a  /usr/local/lib/
  
  ```

* make 执行过程中报错解决

```sh
# 报错1:
 /usr/bin/ld: devrdev.c:(.text+0xdb): undefined reference to `major'

解决：
 filedir/devrdev.c添加#include <sys/sysmacros.h>

# 报错2:
  buf.c: In function ‘is_linebuffered’:
  buf.c:90:15: error: ‘FILE’ {aka ‘struct _IO_FILE’} has no member named ‘__pad’; did you mean ‘__pad5’?
   90 | #define _flag __pad[4]
解决：
  修改stdio/buf.c如下：
    #ifdef _LP64
    #define _flag __pad[4]
    #define _ptr __pad[1]
    #define _base __pad[2]
    #endif

    int
    is_unbuffered(FILE *fp)
    {
            return(fp->_flags & _IONBF); // flag修改为flags
    }

    int
    is_linebuffered(FILE *fp)
    {
            return(fp->_flags & _IOLBF); // flag修改为flags
    }

    int
    buffer_size(FILE *fp)
    {
    #ifdef _LP64
            //return(fp->_base - fp->_ptr);
            return(fp->_IO_buf_end - fp->_IO_buf_base); // 修改

    #else
# 报错3:
    can,t find-lbsd
    
  解决：
    apt install libbsd-dev
```



> 参考文档：
>
> 1. https://blog.csdn.net/cxs5534/article/details/109324451
> 2. https://www.codetd.com/article/1091340
> 3. https://blog.csdn.net/cxs5534/article/details/109324451

