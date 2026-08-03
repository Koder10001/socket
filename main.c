#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include "ip.h"

// #include <arpa/inet.h>



void printErr();
int ipv4ToBin(char* ip, size_t len);
int ipv6ToBin(char* ip, size_t len);

const char ip[] = "192.168.1.252";

int main(){
    int sock = socket(AF_INET, SOCK_DGRAM, 0);


    if(sock == -1){
        printErr();
    }
    printf("succesfully created socket\r\n");

    uint32_t host = 192;
    uint32_t h = htonl(host);
    char* binhost = uintToHex(host, 64/4);
    char* binh = uintToHex(h, 64/4);
    printf("%u\n%u\n%s\n%s\n\r\n", host, h, binhost, binh);

    // address.sin_addr

    printf("end\n");
}


void printErr(){
    printf("Error code: %d\r\n", errno);
    printf("Error message: %s\r\n", strerror(errno));
}