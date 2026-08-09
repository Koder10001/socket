#ifndef BIT_H
#define BIT_H

#define setBit(value, index) ( value | ((uint32_t)1 << index));

#define readBit(value, index) ( ( value & ((uint32_t)1 << index) ) >> index);

#endif