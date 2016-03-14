#ifndef AGENERIC
#define AGENERIC


int freeMem() ;
void started(char s[]) ;
void initStart(char s[]) ;
void initDone() ;
void printValue(char s[], long n) ;
void printIp(byte ip[]) ;
void printMac(byte mac[]) ;
void sendIpClient(byte ip[], EthernetClient cl) ;
void cyclosInSecCalc() ;
void cyclosInSecWork() ;
void shiftCpuLoad(unsigned long tick) ;
void averageCpuLoad() ;
void cyclosDelayWork() ;

#endif
