#include <stdlib.h>
#include <stdint.h>

#ifndef IP_HEADER
#define IP_HEADER

char* uintToBin(size_t num, uint8_t bitlen);
char* uintToHex(size_t num, uint8_t len);
// char* binToHex(char* bin,  size_t bit);
// size_t binToUint(char* bin,  size_t bit);
// char* hexToBin(char* hex,  size_t bit);
// size_t hexToUint(char* hex, size_t bit);


int isLittleEndian();


#endif //IP_HEADER