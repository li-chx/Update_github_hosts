#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include "copy.c"
#include "read.c"
int main(int argc, char* argv[])
{
    read();
    printf("Are you sure you want to delete this hosts file?\n");
    printf("This is the last caution!\n");
    remove("hosts");
    copy();
    errno_t err = 1;
    FILE* fp = NULL;
    err = fopen_s(&fp, "C:\\Windows\\System32\\drivers\\etc\\hosts", "a");
    if (err != 0)
    {
        printf("�޷��򿪴��ļ�\n");            //����򲻿���������򲻿�
        exit(0);                               //��ֹ����
    }
    //���libcurl�Ĵ������ҳ����ģ��Ҳ�����ȫ֪��������ô������
    //���ֱ��curl_easy_perform֮ǰ�����ǡ�׼��������
    CURL* curl = nullptr;
    CURLcode res;
    curl = curl_easy_init();
    if (curl != nullptr)
    {

        curl_easy_setopt(curl, CURLOPT_URL, "https://raw.hellogithub.com/hosts");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        /*Write content in hosts.txt(װ������)*/
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    fclose(fp);
    printf("This is the new hosts file");
    read();
    system("ipconfig /flushdns");
    return 0;
}