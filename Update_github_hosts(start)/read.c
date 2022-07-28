#include <stdio.h>
#include <stdlib.h>
int read()
{
    FILE* fp = NULL;
    char ch;
    errno_t err = 1;
    err = fopen_s(&fp, "C:\\Windows\\System32\\drivers\\etc\\hosts", "r");
    if (err != 0)
    {
        printf("无法打开此文件1\n");            //如果打不开，就输出打不开
        exit(0);                               //终止程序
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}