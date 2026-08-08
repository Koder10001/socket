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

};
struct ipv4_header {

};
struct ipv6_header {

};
struct tcp_header {

};
struct udp_header {

};
struct icmp_header {

};

