/*
  Modul Server Ajax
  part of Arduino Mega Server project
  Parse HTTP requests and XML Ajax functions
  //"Connection: keep-alive"
*/

#ifdef SERVER_FEATURE

#ifndef SERVER_AJAX_H
#define SERVER_AJAX_H

void parseRequest(EthernetClient cl) ;
void sendContacts(EthernetClient cl) ;
void sendFreeRAM(EthernetClient cl) ;
void sendPirs(EthernetClient cl) ;
void sendElectro(EthernetClient cl) ;
void sendModules(EthernetClient cl) ;
void sendDigitalPorts(EthernetClient cl) ;
void sendUptime(EthernetClient cl) ;
void clientPrintDigits(int digits, EthernetClient cl) ;
void sendTime(EthernetClient cl) ;
void sendDay(EthernetClient cl) ;
void sendMonth(EthernetClient cl) ;
void sendWeekday(EthernetClient cl) ;
void sendCPUload(EthernetClient cl) ;
void printHTTPreq(EthernetClient cl) ;
void printHTTPreqTemp(EthernetClient cl) ;
void sendDevicesOnline(EthernetClient cl) ;
void SetLEDs() ;
void responseGeneric(EthernetClient cl) ;
void responseNetwork(EthernetClient cl) ;
void setElectroControl() ;
void responseElectroControl(EthernetClient cl) ;
void setSettings() ;
void responseSettings(EthernetClient cl) ;
void setThemes() ;
void responseThemes(EthernetClient cl) ;
void setControl() ;
void responseControl(EthernetClient cl) ;
void setNoo() ;
void responseNoo(EthernetClient cl) ;
void checkPage() ;
void checkOscill() ;
void responseElectroFreq(EthernetClient cl) ;
void responseSDcard(EthernetClient cl) ;
void responseDash(EthernetClient cl) ;


#endif // SERVER_FEATURE
#endif // SERVER_AJAX
