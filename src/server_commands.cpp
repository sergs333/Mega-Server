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
#include "declarations.h"
#include "server.h"
#include "server_commands.h"

/*
  Modul Netwotk Commands
  part of Arduino Mega Server project

  Key ON:  rele4=1
  Key OFF: rele4=.

  Night mode ON:  night=1
  Night mode OFF: night=.

  Color LEDS: color=white, black, red, blue, green, yellow, magenta, cyan
*/

#ifdef SERVER_FEATURE

void setKey() {
  if (command.indexOf("rele4") >= 0) {
    if (parameter.indexOf("1") >= 0) {
      //setGoLightON();
    } else {
        //setGoLightOFF();
      }
  }
}


/* ----------------------------------------
  Function parseCommands(EthernetClient cl)
    Parse network commands
------------------------------------------- */

void parseCommands(EthernetClient cl) {
  int posBegin;
  int posEnd;
  int posParam;

  if (request.indexOf("?") >= 0) {
    posBegin = request.indexOf("?") + 1;
    posEnd = request.indexOf("HTTP");

    if (request.indexOf("=") >= 0) {
       posParam = request.indexOf("=");
       command = request.substring(posBegin, posParam);
       parameter = request.substring(posParam + 1, posEnd - 1);
    } else {
        command = request.substring(posBegin, posEnd - 1);
        parameter = "";
      }

    Serialprint("command: "); Serial.println(command);
    Serialprint("parameter: "); Serial.println(parameter);

    setKey();

    #ifdef LEDS_FEATURE
      setNightLed();
      setColorLed();
    #endif

    // erase request
    request = "";
  } // if (url.indexOf("?") >= 0)
} // parseCommands

#endif // SERVER_FEATURE
