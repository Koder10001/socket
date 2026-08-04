#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "ip.h"

// #include <arpa/inet.h>



void printErr();

const char ip[] = "192.168.1.252";

int main(){
    int sock = socket(AF_PACKET, SOCK_RAW, 256);


    if(sock == -1){
        printErr();
        exit(errno);
    }
    printf("succesfully created socket\r\n");

    // uint32_t host = 67000;
    // uint32_t h = htonl(host);
    // char* binhost = uintToHex(host, 32/4);
    // char* binh = uintToHex(h, 32/4);
    // printf("%u\n%u\n%s\n%s\n\r\n", host, h, binhost, binh);

    // address.sin_addr

    char* a = "0123456789.:";
    // uint32_t ip = ipv4ToInt(a);
    // printf("==%zu==\n", &ip);

    for(size_t i = 0; i < 256; i++){
        printf("%c %zu\n", i, i);
    }

    printf("end\n");
}


void printErr(){
    printf("Error code: %d\r\n", errno);
    printf("Error message: %s\r\n", strerror(errno));
}