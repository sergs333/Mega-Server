/*
  Arduino Mega Server
  version 0.14 (W5500 support)
  2016, Hi-Lab.ru

  License: Free, without any warranties
  Home:    http://hi-lab.ru/arduino-mega-server (russian)
           http://hi-lab.ru/english/arduino-mega-server (english)
  Email:   info@hi-lab.ru

  IDE: Arduino 1.6.5 r2
       Processing 1.5.1

  Sketch settings:
  ----------------

  (on this page)

  W5100 (default)
  #include <Ethernet.h>
  #include <EthernetUdp.h>
  //#include <Ethernet2.h>
  //#include <EthernetUdp2.h>

  W5500 (if Ethernet Shield 2 on W5500 chip)
  //#include <Ethernet.h>
  //#include <EthernetUdp.h>
  #include <Ethernet2.h>
  #include <EthernetUdp2.h>

  1. freeSockets = FREE_SOCKETS_ONE (default)
                   FREE_SOCKETS_ZERO (no network functions and fast interface)
  2. modeNetWork = MODE_ONE (default)
                   MODE_MAJOR (tandem with MajorDoMo)
  3. timeProvider = TIME_NETWORK (default)
                    TIME_RTC (hardware RTC)
                    TIME_NONE (no time synchronization)
  4. //#define MAJORDOMO_FEATURE (default)
       #define MAJORDOMO_FEATURE (send data and synchronize time with MajorDoMo)

  (on Ethernet page)
  SELF_IP[] = {192, 168, 1, 37}; (default)
  GATEWAY[] = {192, 168, 1, 1}; (default)

  Tandem mode
  SELF_IP[] = {192, 168, 2, 37}; (AMS)
  192.168.2.8 (MajorDoMo)

  Pathes of project AMS:
  ------------------------------
  \Sketches\ams\Arduino\arduino_mega_server\
  \Sketches\ams\Arduino\libraries\
  \Sketches\ams\Processing\arduino_serial_commander\

  Arduino IDE settings:
  ---------------------
  Sketches folder:
  \Sketches\ams\Arduino

  Loading sketches:
  ------------------
  Arduino Mega Server:      arduino_mega_server_due.ino
  Arduino Serial Commander: arduino_serial_commander.pde

  Quick start:
  ------------
  1. Files from archive SD.zip - to microSD card
  2. Sketch "arduino_mega_server.ino" - to Arduino Mega
  3. Open on your browser address "192.168.1.37"
  4. Enjoy and donate on page
     http://hi-lab.ru/arduino-mega-server/details/donate
*/



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
#include "declarations.h"
#include "ageneric.h"
#include "dethernet.h"
#include "dmajor.h"
#include "dsend.h"
#include "rtc.h"
#include "sd.h"
#include "server.h"
#include "server_ajax.h"
#include "server_commands.h"
#include "server_maker.h"
#include "strings.h"
#include "timers.h"






/* setup
-------------------------------------------------- */

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.print(SELF_NAME);
  Serial.println(F(" started..."));

  #ifdef ETHERNET_FEATURE
    ethernetInit();
  #endif

  sdCardInit();

  #ifdef RTC_FEATURE
    rtcInit();
  #endif

  #ifdef SERVER_FEATURE
    serverInit();
  #endif

  timersInit();

  #ifdef MAJORDOMO_FEATURE
    majordomoInit();
    majordomoMegaLive();
  #endif

  #ifdef LAURENT_FEATURE
    laurentInit();
  #endif

  #ifdef SD_INFO_FEATURE
    sdInfoInit();
  #endif

  #ifdef SD_FILES_FEATURE
    sdFilesInit();
  #endif

  #ifdef PING_FEATURE
    pingInit();
  #endif

  #ifdef UPLOAD_FEATURE
    uploadInit();
  #endif

  #ifdef PIRS_FEATURE
    pirsInit();
  #endif

  #ifdef CONTACTS_FEATURE
    contactsInit();
  #endif

  #ifdef TEMP_FEATURE
    tempInit();
  #endif

  #ifdef ELECTRO_FEATURE
    electroInit();
  #endif

  #ifdef KEYS_FEATURE
    keysInit();
  #endif

  #ifdef LEDS_FEATURE
    ledsInit();
  #endif

  #ifdef NOO_FEATURE
    nooInit();
  #endif

  timeStamp();
  Serialprint("GLOBAL Init DONE\n");
  Serial.println();
  timeStamp();
  Serialprint("AMS WORK\n");
} // setup

/* loop
-------------------------------------------------- */

void loop() {
  #ifdef UPLOAD_FEATURE
    uploadWorks();
  #endif

  if (modeWork == MODE_SERVER) {
    #ifdef RTC_FEATURE
      rtcWorks();
    #endif

    //prof works
    profStart();
    timersWorks();

    #ifdef SERVER_FEATURE
      serverWorks();
    #endif

    #ifdef KEYS_FEATURE
      keysWorks();
    #endif

    #ifdef PIRS_FEATURE
      pirsWorks();
    #endif

    #ifdef CONTACTS_FEATURE
      contactsWorks();
    #endif

    #ifdef TEMP_FEATURE
      if (cycle5m || (timeSec < startSendTime)) {
        tempWorks();
      }
    #endif

    #ifdef ELECTRO_FEATURE
      if (modulElectro == 1) {
        if (cycle20s || (timeSec < startSendTime)) {
          electroWorks();
          freqWorks();
        }
        // network oscilloscope
        if (cycle1s && oscill) {
          freqWorks();
        }
      }
    #endif

    #ifdef MAJORDOMO_FEATURE
      majordomoMegaLive();
    #endif

    #ifdef SD_FILES_FEATURE
      if (cycle30s) {
        //printSdContent(sdRoot, 0);
        //cardInfo();
        //Serial.println("Root SD card:");
        //printDirectory(sdDir);
        //Serial.println("/js/");
        //sdDir = SD.open("/js/");
        //printDirectory(sdDir);
      }
    #endif

    #ifdef PING_FEATURE
      if (cycle30s) {
        pingWorks();
      }
    #endif

    #ifdef LAURENT_FEATURE
      if (cycle3m) {
        sprintf(buf, "$KE");
        sendLaurentRequest();
      }
    #endif

    cyclos++;

    cyclosInSecWork();

    // end loop works
    eraseCyclos();
    profCalc();

    cyclosDelayWork();

  } // if (modeWork == MODE_SERVER)

} // loop
