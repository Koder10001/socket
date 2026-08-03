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
        printf("%u %u %u %u\n", num, i, ex, len);
        
        if(ex < num && ex != 0){
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