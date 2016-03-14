#ifndef SERVER_MAKER_H
#define SERVER_MAKER_H

void openBlockStyle(EthernetClient cl);
void closeBlockStyle(EthernetClient cl);
void openStyle(char style[], EthernetClient cl);
void closeStyle(EthernetClient cl);
void insertIpAttr(char first[], char last[], EthernetClient cl);
void addStyleHome(EthernetClient cl);
void addStyleModern(EthernetClient cl);
void insertBlock(uint8_t typeOperation, EthernetClient cl);

#endif
