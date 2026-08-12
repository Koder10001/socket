#include "debug.h"
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

char* uintToHex(size_t num, uint8_t byte){

    char val[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
 
    char* result = malloc(8);

    uint8_t len = byte*2;

    // size_t ex = (size_t)1 << (bitlen - 1);
    size_t ex = (size_t)1 << ((len - 1) * 4);

    result = (char*)malloc((len + 1) * (sizeof(char)));
    result[len] = '\0';

    size_t index = 0;

    for(size_t i = 0; i < len; i++){
        // printf("%zu %zu %zu %zu\n", num, i, ex, len);
        
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


uint64_t hexToUint(char* hex){
    uint8_t len = sizeof(hex) / sizeof(hex[0]);
    uint64_t num = 0;
    uint64_t ex = (uint64_t)1 << ((len - 1) * 4);

    for(int i = 0; i < len; i++){
        printf("%u %u %u\n ", num, hex[i], len);
        if(hex[i] >= 48 && hex[i] <= 57){
            num += (hex[i] - 48) * ex;
        }
        else if(hex[i] >= 65 && hex[i] <= 70){
            num += (hex[i] - 55) * ex; // 10 offset
        }
        else if(hex[i] >= 97 && hex[i] <= 102){
            num += (hex[i] - 87) * ex; // 10 offset
        }
        else {
            printf("Error : %c", hex[i]);
            return -1;
            exit(1);
        }
        ex = ex >> 4;
    }
    return num;
}

char* textToHex(char* hex){
    
}


char* printMacFromHex()