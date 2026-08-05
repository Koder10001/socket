#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <math.h>
#include "ip.h"
#include "frame.h"

// linux only
#include <linux/if_ether.h>

// #include <arpa/inet.h>



void printErr();

const char ip[] = "192.168.1.252";

int main(){


    int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));


    printf("%x\n", getMacAddress(sock, (char *)"wlp4s0"));


    // if(sock == -1){
    //     printErr();
    //     exit(errno);
    // }
    // printf("succesfully created socket\r\n");

    // uint32_t host = 67000;
    // uint32_t h = htonl(host);
    // char* binhost = uintToHex(host, 32/4);
    // char* binh = uintToHex(h, 32/4);
    // printf("%u\n%u\n%s\n%s\n\r\n", host, h, binhost, binh);

    // address.sin_addr

    // char* a = "192.168.5.42";
    // uint32_t ip = ipv4ToInt(a);
    // printf("==%s %zu==\n", uintToBin(ip, 32), ip);



    printf("end\n");

}


void printErr(){
    printf("Error code: %d\r\n", errno);
    perror("Error");
}