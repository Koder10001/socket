


#ifndef HEADER_H
#define HEADER_H

typedef enum etype etype;
typedef struct eth_header eth_h;
typedef struct ipv4_header ipv4_h;
typedef struct ipv6_header ipv6_h;
typedef struct tcp_header tcp_h;
typedef struct udp_header udp_h;
typedef struct icmp_header icmp_h;
typedef struct arp_header arp_h;

void createEtherFrame(eth_h*);
void createIPv4Header(ipv4_h*);
void createIPv6Header(ipv6_h*);
void createTCPHeader(tcp_h*);
void createUDPHeader(udp_h*);
void createICMPHeader(icmp_h*);

#endif