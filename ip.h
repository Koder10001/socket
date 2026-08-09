#include <stdlib.h>
#include <stdint.h>

#ifndef IP_H
#define IP_H


// char* binToHex(char* bin,  size_t bit);
// size_t binToUint(char* bin,  size_t bit);
// char* hexToBin(char* hex,  size_t bit);
// size_t hexToUint(char* hex, size_t bit);

uint32_t ipv4ToInt(char* ip);
uint16_t* ipv6ToInt(char* ip);

uint32_t hexToIP(char* hex);
char* macToint(char* mac);

uint32_t htonl(uint32_t hostbyte);
uint16_t htons(uint16_t hostbyte);



int isLittleEndian();

// . 46
// 0 48
// 1 49
// 2 50
// 3 51
// 4 52
// 5 53
// 6 54
// 7 55
// 8 56
// 9 57
// : 58


#endif //IP_HEADER