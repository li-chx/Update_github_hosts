#include <stdio.h>
#include <stdlib.h>
int copy()
{
    FILE* fp  = NULL;
    FILE* fp1 = NULL;
    char ch;
    errno_t err = 1;
    err = fopen_s(&fp, "hosts.bak", "r");
    if (err != 0)
    {
        printf("无法打开此文件1\n");            //如果打不开，就输出打不开
        exit(0);                               //终止程序
    }
    err = fopen_s(&fp1, "hosts", "w");
    if (err != 0)
    {
        printf("无法打开此文件2\n");            //如果打不开，就输出打不开
        exit(0);                               //终止程序
    }
    while ((ch = fgetc(fp)) != EOF) 
    {
        putchar(ch);
        fputc(ch, fp1);
    }
    if (fp1 == NULL)	//无该条件判断将会出现警告Warning C6387
        return 0;
    fclose(fp);
    fclose(fp1);
    return 0;
}