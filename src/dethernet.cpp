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
#include "ageneric.h"



void ethernetInit() {
  Serialprint("Modul Ethernet...\n");
  Ethernet.begin(SELF_MAC, SELF_IP, GATEWAY);
  Serialprint(" MAC: ");
  printMac(SELF_MAC);
  Serial.println();
  Serialprint(" IP: ");
  printIp(SELF_IP);
  Serial.println();
  modulEthernet = MODUL_ENABLE;
  Serialprint("started\n");
}

void enableEthernet()  {pinMode(10, OUTPUT); digitalWrite(10, LOW);}
void disableEthernet() {pinMode(10, OUTPUT); digitalWrite(10, HIGH);}
void enableSdCard()    {pinMode( 4, OUTPUT); digitalWrite( 4, LOW);}
void disableSdCard()   {pinMode( 4, OUTPUT); digitalWrite( 4, HIGH);}
