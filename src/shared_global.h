
#include <avr/pgmspace.h>
#include <SPI.h>

// W5100
#include <Ethernet.h>
#include <EthernetUdp.h>

// W5500
//#include <Ethernet2.h>
//#include <EthernetUdp2.h>

#include <SD.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#ifndef SHARED_GLOBAL_H
#define SHARED_GLOBAL_H

extern char const SELF_NAME[];
extern char const VERSION[];

extern byte SELF_MAC[];
extern byte SELF_IP[];
//extern byte DNS[] = { , , , };
extern byte GATEWAY[];


// mode net work
extern byte const MODE_ONE;
extern byte const MODE_MAJOR;
extern byte modeNetWork;

extern char majorMegaObject[];
extern char majorCommObject[];

// MajorDoMo net settings
extern byte MAJOR_IP[];
extern int MAJOR_PORT;

// EthernetClient object
extern EthernetClient mclient;

//// SENDING
extern byte TARGET_IP[];
extern int TARGET_PORT;

// EthernetClient object
extern EthernetClient tclient;


// time provider
extern byte const TIME_NONE;
extern byte const TIME_NETWORK;
extern byte const TIME_RTC;
extern byte timeProvider;

// NTP settings

extern byte TIME_IP[]; // time-c.nist.gov
extern unsigned int TIME_PORT;  // alt port
extern const int timeZone;

//extern IPAddress timeServer(TIME_IP);

extern EthernetUDP Udp;

extern time_t prevDisplay; // when the digital clock was displayed
// NTP code

extern const int NTP_PACKET_SIZE; // NTP time is in the first 48 bytes of message
extern byte packetBuffer[]; //buffer to hold incoming & outgoing packets
// Uptime

extern char uptimeString[14];


// free sockets
extern byte const FREE_SOCKETS_ZERO;
extern byte const FREE_SOCKETS_ONE;
extern byte const FREE_SOCKETS_TWO;
extern byte freeSockets;

// mode work
extern byte const MODE_SERVER;
extern byte const MODE_UPDATE;
extern byte modeWork;



// Server network settings
extern int SERVER_PORT;

// File read & send buffer
extern byte const MAX_BUFFER_SIZE;
extern uint16_t rsize;
extern uint8_t buff[];

// Buffer for markers works
extern byte const MAX_BUFFER_SIZE2;
extern uint16_t rsize2;
extern uint8_t buff2[];

extern boolean allowMarkers;

// Parse HTTP requests
extern char HTTP_req[]; // buffered HTTP request stored as null terminated string
extern char req_index;
extern char HTTP_req_temp[];
extern char req_index_temp;

// Parse network commands
extern byte MAX_LEN_REQUEST;
extern String request;

// Files
extern File webFile; // web page file on the SD card

extern byte const MARKER; // %
extern byte const HEADER; // 1
extern byte const DASH; // 2
extern byte const MENU; // 3
extern byte const FOOTER; // 4
extern byte const BANNER_BOTTOM; // 5

extern byte const FLOTR2_JS; // ?

extern byte const TYPE_LINKS; // &
extern byte const SCRIPTS_JS; // #
extern byte const SAMPLE2_ONE; // @ (mode one)
extern byte const SAMPLE2_MAJOR; // + {mode major}
extern byte const SELF_ADDRESS; // !



// duration
extern time_t prevEventElectroCycle;
extern time_t prevEventMegaLive;
extern time_t prevEventRequest;

// modules
extern byte const MODUL_DISABLE;
extern byte const MODUL_ENABLE;
extern byte const MODUL_NOT_COMPILLED;

extern byte modulEthernet;
extern byte modulRtc;
extern byte modulSdCard;
extern byte modulServer;
extern byte modulSend;
extern byte modulMajor;
extern byte modulLaurent;
extern byte modulPing;
extern byte modulUpload;
extern byte modulPirs;
extern byte modulContacts;
extern byte modulTemp;
extern byte modulElectro;
extern byte modulLeds;
extern byte modulKeys;
extern byte modulNoo;

// design
byte const DEFAULT_DESIGN = 0;
byte const HOME_DESIGN    = 1;
byte const MODERN_DESIGN  = 2;
byte const HACKER_DESIGN  = 3;
byte const PART1_DESIGN = 4;
byte const PART2_DESIGN = 5;
byte const PART3_DESIGN = 6;
byte const PART4_DESIGN = 7;
extern byte currentDesign;

// pages
extern byte const UNKNOWN_PAGE ;
extern byte const THEMES_PAGE ;
extern byte const SETTINGS_PAGE ;
extern byte const PORTS_PAGE ;
extern byte const SUPPLY_PAGE ;
extern byte const ELECTRO_PAGE ;
extern byte currentPage ;

// strings
extern char buf[200];

// for name serial upload
extern char fn[20];

// for sample Ajax
extern boolean LED_state[4] ;

// electro
extern boolean buttonElectro;

// oscill
extern boolean oscill ;

// cyclos
extern unsigned long cyclos ;

// timers
extern unsigned long timeSec; // time in seconds
extern unsigned long timer1s;
extern boolean cycle1s;
extern unsigned long timer4s;
extern boolean cycle4s;
extern unsigned long timer20s;
extern boolean cycle20s ;
extern unsigned long timer30s;
extern boolean cycle30s ;
extern unsigned long timer1m;
extern   boolean cycle1m;
extern unsigned long timer3m;
extern   boolean cycle3m ;
extern unsigned long timer5m;
extern   boolean cycle5m ;
extern int startSendTime ;

extern byte const SD_CHIP_SELECT;

extern Sd2Card card;
extern SdVolume volume;
extern SdFile root;

extern File sdRoot;
extern File sdDir;
extern File entry;

// CPU load / Cyclos in second

extern int summCyclosInSec;
extern int cyclosInSec;

// CPU load / Cyclos delay

extern unsigned long pointCpu;
extern unsigned long oldPointCpu;
extern unsigned long deltaCpu;
extern byte const MAX_CPU_BUFFER;
extern unsigned long bufferCpuLoad[];
extern int cyclosDelay;



extern char basePir[];
extern char baseContact[];
extern char basePower[];
extern char baseLine[];
extern char baseMAC[];
extern char baseIP[];

extern char inputs_start[];
extern char inputs_end[];

extern char strChecked[];
extern char strUnChecked[];

extern String command;
extern String parameter;

extern File tempFile;

extern unsigned long cycle_start;
extern unsigned long cycle_end;
extern unsigned long cycle_delta;

extern byte lifer;

#endif
