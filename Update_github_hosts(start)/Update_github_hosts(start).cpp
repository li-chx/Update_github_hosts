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
        printf("无法打开此文件\n");            //如果打不开，就输出打不开
        exit(0);                               //终止程序
    }
    //这个libcurl的代码是我抄来的，我并不完全知道它是怎么运作的
    //大概直到curl_easy_perform之前，都是“准备”部分
    CURL* curl = nullptr;
    CURLcode res;
    curl = curl_easy_init();
    if (curl != nullptr)
    {

        curl_easy_setopt(curl, CURLOPT_URL, "https://raw.hellogithub.com/hosts");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        /*Write content in hosts.txt(装的像吗？)*/
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