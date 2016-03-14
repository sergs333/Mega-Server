#include <Arduino.h>
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



#include "shared_global.h"


char const SELF_NAME[] = "Mega";
char const VERSION[] = "0.14";

byte SELF_MAC[] = {0x00, 0x2A, 0xF5, 0x12, 0x67, 0xFA};
byte SELF_IP[] =  {192, 168, 1, 37};
//byte DNS[] = { , , , };
byte GATEWAY[] = {192, 168, 1, 1};


// mode net work
byte const MODE_ONE = 1;
byte const MODE_MAJOR = 2;
byte modeNetWork = MODE_ONE;

char majorMegaObject[] = "ncMega01";
char majorCommObject[] = "comm_mega01";

// MajorDoMo net settings
byte MAJOR_IP[] = {192, 168, 56, 1};
int MAJOR_PORT = 80;

// EthernetClient object
EthernetClient mclient;

//// SENDING
byte TARGET_IP[] = {192, 168, 2, 8};
int TARGET_PORT = 80;

// EthernetClient object
EthernetClient tclient;


// time provider
byte const TIME_NONE = 0;
byte const TIME_NETWORK = 1;
byte const TIME_RTC = 2;
byte timeProvider = TIME_NETWORK;

// NTP settings

byte TIME_IP[] = {129, 6, 15, 30}; // time-c.nist.gov
unsigned int TIME_PORT = 123;  // alt port
const int timeZone = 3;


EthernetUDP Udp;

time_t prevDisplay = 0; // when the digital clock was displayed
// NTP code

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets
// Uptime

char uptimeString[14];


// free sockets
byte const FREE_SOCKETS_ZERO = 0;
byte const FREE_SOCKETS_ONE = 1;
byte const FREE_SOCKETS_TWO = 2;
byte freeSockets = FREE_SOCKETS_ONE;

// mode work
byte const MODE_SERVER = 1;
byte const MODE_UPDATE = 2;
byte modeWork = MODE_SERVER;



// Server network settings
int SERVER_PORT = 80;
//EthernetServer server(SERVER_PORT); // create a server

// File read & send buffer
byte const MAX_BUFFER_SIZE = 128;
uint16_t rsize;
uint8_t buff[MAX_BUFFER_SIZE];

// Buffer for markers works
byte const MAX_BUFFER_SIZE2 = 128;
uint16_t rsize2;
uint8_t buff2[MAX_BUFFER_SIZE2];

boolean allowMarkers = false;

// Parse HTTP requests
#define REQ_BUF_SIZE 128 // size of buffer used to capture HTTP requests
char HTTP_req[REQ_BUF_SIZE] = {0}; // buffered HTTP request stored as null terminated string
char req_index = 0;
char HTTP_req_temp[REQ_BUF_SIZE] = {0};
char req_index_temp = 0;

// Parse network commands
byte MAX_LEN_REQUEST = 64;
String request = "";

// Files
File webFile; // web page file on the SD card

byte const MARKER = 0x25; // %
byte const HEADER = 0x31; // 1
byte const DASH = 0x32; // 2
byte const MENU = 0x33; // 3
byte const FOOTER = 0x34; // 4
byte const BANNER_BOTTOM = 0x35; // 5

byte const FLOTR2_JS = 0x3F; // ?

byte const TYPE_LINKS = 0x26; // &
byte const SCRIPTS_JS = 0x23; // #
byte const SAMPLE2_ONE = 0x40; // @ (mode one)
byte const SAMPLE2_MAJOR = 0x2B; // + {mode major}
byte const SELF_ADDRESS = 0x21; // !



// duration
time_t prevEventElectroCycle;
time_t prevEventMegaLive;
time_t prevEventRequest;

// modules
byte const MODUL_DISABLE = 0;
byte const MODUL_ENABLE = 1;
byte const MODUL_NOT_COMPILLED = 2;

byte modulEthernet = MODUL_NOT_COMPILLED;
byte modulRtc =      MODUL_NOT_COMPILLED;
byte modulSdCard =   MODUL_NOT_COMPILLED;
byte modulServer =   MODUL_NOT_COMPILLED;
byte modulSend =     MODUL_NOT_COMPILLED;
byte modulMajor =    MODUL_NOT_COMPILLED;
byte modulLaurent =  MODUL_NOT_COMPILLED;
byte modulPing =     MODUL_NOT_COMPILLED;
byte modulUpload =   MODUL_NOT_COMPILLED;
byte modulPirs =     MODUL_NOT_COMPILLED;
byte modulContacts = MODUL_NOT_COMPILLED;
byte modulTemp =     MODUL_NOT_COMPILLED;
byte modulElectro =  MODUL_NOT_COMPILLED;
byte modulLeds =     MODUL_NOT_COMPILLED;
byte modulKeys =     MODUL_NOT_COMPILLED;
byte modulNoo =      MODUL_NOT_COMPILLED;

// design
/*byte const DEFAULT_DESIGN = 0;
byte const HOME_DESIGN = 1;
byte const MODERN_DESIGN = 2;
byte const HACKER_DESIGN = 3;
byte const PART1_DESIGN = 4;
byte const PART2_DESIGN = 5;
byte const PART3_DESIGN = 6;
byte const PART4_DESIGN = 7; */
byte currentDesign = DEFAULT_DESIGN;

// pages
byte const UNKNOWN_PAGE = 0;
byte const THEMES_PAGE = 4;
byte const SETTINGS_PAGE = 5;
byte const PORTS_PAGE = 6;
byte const SUPPLY_PAGE = 7;
byte const ELECTRO_PAGE = 8;
byte currentPage = UNKNOWN_PAGE;

// strings
char buf[200];

// for name serial upload
char fn[20] = "";

// for sample Ajax
boolean LED_state[4] = {0};

// electro
boolean buttonElectro = 0;

// oscill
boolean oscill = false;

// cyclos
unsigned long cyclos = 0;

// timers
unsigned long timeSec; // time in seconds
unsigned long timer1s;  boolean cycle1s = false;
unsigned long timer4s;  boolean cycle4s = false;
unsigned long timer20s; boolean cycle20s = false;
unsigned long timer30s; boolean cycle30s = false;
unsigned long timer1m;  boolean cycle1m = false;
unsigned long timer3m;  boolean cycle3m = false;
unsigned long timer5m;  boolean cycle5m = false;
int startSendTime = 10;

byte const SD_CHIP_SELECT = 4;

Sd2Card card;
SdVolume volume;
SdFile root;
File sdRoot;
File sdDir;
File entry;

// CPU load / Cyclos in second

int summCyclosInSec = 0;
int cyclosInSec = 0;

// CPU load / Cyclos delay

unsigned long pointCpu = 0;
unsigned long oldPointCpu = 0;
unsigned long deltaCpu = 0;
byte const MAX_CPU_BUFFER = 10;
unsigned long bufferCpuLoad[MAX_CPU_BUFFER];
int cyclosDelay = 0;



char basePir[] = "pir";
char baseContact[] = "cont";
char basePower[] = "p";
char baseLine[] = "line";
char baseMAC[] = "mac";
char baseIP[] = "ip";

char inputs_start[] = "<inputs>";
char inputs_end[] = "</inputs>";

char strChecked[] = "checked";
char strUnChecked[] = "unchecked";

String command;
String parameter;

File tempFile;

unsigned long cycle_start = 0;
unsigned long cycle_end = 0;
unsigned long cycle_delta = 0;

byte lifer;
