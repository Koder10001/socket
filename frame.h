
#ifndef FRAME_H
#define FRAME_H

char* getSourceMacAddress(int socket, char* iface);
int getIfaceIndex(int socket, char* iface);
char* getNextNodeIP(char* iface);


#endif