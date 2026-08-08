#include <stdint.h>
#include <stddef.h>



#ifndef DEBUG_H
#define DEBUG_H

void printMacAddress(char* mac);
char* uintToBin(size_t num, uint8_t bitlen);
char* uintToHex(size_t num, uint8_t len);


#endif