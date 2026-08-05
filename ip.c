#include "ip.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* uintToBin(size_t num, uint8_t bitlen){

    char* result;

    size_t ex = (size_t)1 << (bitlen - 1);

    result = (char*)malloc((bitlen + 1) * (sizeof(char)));
    result[bitlen] = '\0';

    for(size_t i = 0; i < bitlen; i++){
        if( num >= ex  && ex != 0){
            num -= ex;
            result[i] = '1';
        }
        else {
            result[i] = '0';
        }

        ex = ex >> 1;
    }

    return result;
}

char* uintToHex(size_t num, uint8_t len){

    char val[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
 
    char* result;

    // size_t ex = (size_t)1 << (bitlen - 1);
    size_t ex = (size_t)1 << ((len - 1) * 4);

    result = (char*)malloc((len + 1) * (sizeof(char)));
    result[len] = '\0';

    size_t index = 0;

    for(size_t i = 0; i < len; i++){
        printf("%zu %zu %zu %zu\n", num, i, ex, len);
        
        if(ex <= num && ex != 0){
            size_t a = 15;
            while (a > 0){
                if(ex * a <= num){
                    break; 
                }

                a--;
            }
            num -=  ex * a;
            result[i] = val[a];
        }
        else {
            result[i] = '0';
        }
        
        ex = ex >> 4;
    }

    return result;

}

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