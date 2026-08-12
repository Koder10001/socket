#include "header.h"
#include <stdint.h>

enum etype{
    ip4 = (uint16_t)0x0800,
    ip6 = (uint16_t)0x86DD,
    VLAN_tagging = (uint16_t)0x8100,
    ARP = (uint16_t)0x0806,
    wakeOnLan = (uint16_t)0x0842,
};

struct eth_header {
    char destMAC[6];
    char sourceMAC[6];
    char etype[4];
    char *data;
};
struct ipv4_header {
    char version_ihl[1];
    char typeOfService[1];
    char totalLength[2];
    char identification[2];
    char flag[2];
    char TTL[1];
    char protocol[1];
    char checksum[2];
    char sourceIP[4];
    char destIP[4];
    char *data;
};
struct ipv6_header {
    char version_trafficClass_FlowLabel[4];
    char payloadLength[2];
    char nextHeader[1];
    char hopLimit[1];
    char sourceIP[16];
    char destIP[16];
    char *data;
};
struct tcp_header {
    char sourcePort[2];
    char destPort[2];
    char seqNumber[4];
    char ackNumber[4];
    char dataOffset_reserved[1];
    char controlBits[1];
    char window[2];
    char checksum[2];
    char urgentPointer[2];
    char *data;
};
struct udp_header {
    char sourcePort[2];
    char destPort[2];
    char length[2];
    char checksum[2];
    char *data;
};
struct icmp_header {
    char type[1];
    char code[1];
    char checksum[2];
    char identifier[2];
    char sequenceNumber[2];
    char addressMask[4];
};



// void createEtherFrame(eth_h *eth, etype type){
    
// }