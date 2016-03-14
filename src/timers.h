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
/*
  Modul Timers
  part of Arduino Mega Server project
*/

#ifndef TIMERS_H
#define TIMERS_H

void timersInit() ;
void timersWorks() ;
void eraseCyclos();

void profStart() ;

void profCalc() ;
#endif //TIMERS_H
