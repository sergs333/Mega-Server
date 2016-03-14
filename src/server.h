/*
  Modul Server
  part of Arduino Mega Server project
*/

#ifdef SERVER_FEATURE
#ifndef SERVER_H
#define SERVER_H
// Server network settings


// Parse HTTP requests
#define REQ_BUF_SIZE 128 // size of buffer used to capture HTTP requests

void serverInit();
void markersWorks(int pos, EthernetClient cl);
void serverWorks2(EthernetClient sclient);
void serverWorks();



#endif // SERVER_FEATURE
#endif //SERVER_H
