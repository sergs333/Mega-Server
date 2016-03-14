
#ifndef DSEND_H
#define DSEND_H
/* ----------------------------------------------
  Modul Send HTTP request for Due
  part of Arduino Mega Server project
------------------------------------------------- */

#ifdef SEND_FEATURE


void sendInit() ;

void sendHttpRequest(byte ip[], int port, EthernetClient cl) ;

void sendRequest(byte ip[], int port, char object[], int value, EthernetClient cl) ;

#endif // SEND_FEATURE
#endif //DSEND_H
