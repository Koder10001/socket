#include "frame.h"
#include <linux/if.h>
#include <linux/if_ether.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>

#include <stdio.h> // printf


char* getSourceMacAddress(int socket, char* iface){

    struct ifreq buffer;
    char *mac = (char*)malloc(ETH_ALEN);
    memset(&buffer, 0x00, sizeof(buffer));
    strncpy(buffer.ifr_name, iface, IFNAMSIZ);
    if(ioctl(socket, SIOCGIFHWADDR, &buffer) < 0){
        perror("SIOCGIFHWADDR");
        exit(1);  // handle this later ? 
    }

    memcpy(mac, buffer.ifr_hwaddr.sa_data, ETH_ALEN);
    return mac;
}

int getIfaceIndex(int socket, char* iface){
    struct ifreq buffer;
    int ifindex;
    memset(&buffer, 0x00, sizeof(buffer));
    strncpy(buffer.ifr_ifrn.ifrn_name, iface, IFNAMSIZ);
    if(ioctl(socket,SIOCGIFINDEX, &buffer) < 0){
        perror("SIOCGIFINDEX");
        exit(1); // handle this later ? 
    }
    ifindex = buffer.ifr_ifru.ifru_ivalue;
    return ifindex;

}

char* getNextNodeIP(char* iface){
    char* result = malloc(8);

    FILE *f;
    char c;
    size_t matchLen = 0;
    size_t tabCount = 0;



    f = fopen("/proc/net/route", "r");

    if(f == NULL){
        perror("/proc/net/route");
        exit(1);
    }

    while((c = fgetc(f)) != EOF){
        // if(c == '\n'){
        //     printf("%u", lineCount);
        //     lineCount = 0;
        // }
        // else if (c == ' ') {
        //     c = '_';
        // }
        // else if (c == '\t')
        // {
        //     c = '.';
        // }
        if(c == iface[matchLen] && tabCount < 1){
            matchLen++;
        }
        else if(c == '\t' && matchLen != 0){
            tabCount++;
        }
        else if(c == '0' && tabCount == 1){
            
        }
        else {
            matchLen = 0;
            tabCount = 0;
        }

        if(tabCount == 2){
            for(int i = 0; i <8; i++){
                result[i] = fgetc(f);
                // printf("%c", result[i]);
            }
            break;
        }

        // printf("%c", result);
        // lineCount++;
    }

    fclose(f);

    return result;
}