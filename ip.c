#include "ip.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* uintToBin(size_t num, size_t bit){

    char* result;

    size_t ex = 1 << (bit - 1);
    size_t len = bit;

    result = (char*)malloc((len + 1) * (sizeof(char)));
    result[len] = '\0';

    for(size_t i = 0; i < len; i++){
        printf("%u %u %u %u\n", num, i, ex, len);
        if( num >= ex ){
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

char* uintToHex(size_t num, size_t bit){

    char val[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    char* result;

    size_t ex = 1 << (bit - 1);
    size_t len = bit / 4;

    result = (char*)malloc((len + 1) * (sizeof(char)));
    result[len] = '\0';

    size_t index = 0;

    for(size_t i = 0; i < len; i++){
        for( uint8_t a = 15; a >= 0; a-- ){
            if(ex * a <= num){
                result[i] = val[a];
                num -= ex*a;
                break;
            }
        }
        ex = ex >> 4;
    }

    return result;

}