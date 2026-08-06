#include "ip.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int isLittleEndian(){
    uint16_t i = 1;
    char* a = (char*)&i;
    return (int)a[0];
}

uint32_t htonl(uint32_t hostbyte){
    if(isLittleEndian() == 0){
        return hostbyte;
    }

    return ((hostbyte & 0xFF000000) >> 24) | ((hostbyte & 0x00FF0000) >> 8) | ((hostbyte & 0x0000FF00) << 8) | ((hostbyte & 0x000000FF) << 24);
}

uint16_t htons(uint16_t hostbyte){
    if(isLittleEndian() == 0){
        return hostbyte;
    }

    return (hostbyte >> 8) | (hostbyte << 8);
}



uint32_t ipv4ToInt(char* ip){
    char* ptr = ip;
    uint32_t ipNum = 0;
    // printf("%zu bytes %s\n", sizeof(ip), ip);
    uint8_t dotCount = 0;
    uint32_t octet = 0;
    while(*ptr != '\0'){
        if(*ptr == '.'){
            
            ipNum = ipNum | (octet << (3 - dotCount) * 8);

            octet = 0;
            dotCount++;
        }
        else if(*ptr >= 48 && *ptr <= 57){
            octet *= 10;
            octet += *ptr - 48;
        }
        else {
            printf("Error: Failed to parse ip\n");
            exit(1);
        }

        ptr++;

    }
    ipNum = ipNum | octet;
    return ipNum;
}

uint16_t* ipv6ToInt(char* ip){
    char *ptr = ip;
    uint16_t ipNum[8];
    uint16_t hextet = 0;
    uint8_t tmp;
    uint8_t colonCount = 0;

    while(*ptr != '\0'){
        if (*ptr = ':'){ // :
            hextet = 0;
            ptr++;
            colonCount++;
            
            continue;
        }
        else if(*ptr >= 65 && *ptr <= 70){ // A-F
            tmp = *ptr - 55;
        }
        else if(*ptr - 32 >= 65 && *ptr - 32 <= 70){ // a-f
            *ptr -= 32;
            tmp = *ptr - 55;
        }
        else if (*ptr >= 48 && *ptr <= 57) { // 0-9
            tmp = *ptr - 48;
        }
        hextet *= 10;
        hextet += tmp;
        ptr++;

    }
}