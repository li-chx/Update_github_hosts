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
        printf("�޷��򿪴��ļ�1\n");            //����򲻿���������򲻿�
        exit(0);                               //��ֹ����
    }
    err = fopen_s(&fp1, "hosts", "w");
    if (err != 0)
    {
        printf("�޷��򿪴��ļ�2\n");            //����򲻿���������򲻿�
        exit(0);                               //��ֹ����
    }
    while ((ch = fgetc(fp)) != EOF) 
    {
        putchar(ch);
        fputc(ch, fp1);
    }
    if (fp1 == NULL)	//�޸������жϽ�����־���Warning C6387
        return 0;
    fclose(fp);
    fclose(fp1);
    return 0;
}