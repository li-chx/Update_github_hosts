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
        printf("�޷��򿪴��ļ�1\n");            //����򲻿���������򲻿�
        exit(0);                               //��ֹ����
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}