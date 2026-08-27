#include <stdint.h>
#include <stddef.h>



#ifndef DEBUG_H
#define DEBUG_H


char* uintToBin(size_t num, uint8_t bitlen);
char* uintToHex(size_t num, uint8_t len);
uint64_t hexToUint(char* hex);
uint8_t hexCharToInt(char c);


#endif