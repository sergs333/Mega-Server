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
#include "rtc.h"
#include "dsend.h"

/* ----------------------------------------------
  Modul Send HTTP request for Due
  part of Arduino Mega Server project
------------------------------------------------- */

#ifdef SEND_FEATURE


void sendInit() {
  initStart("Send");
  modulSend = MODUL_ENABLE;
  initDone();
}

void sendHttpRequest(byte ip[], int port, EthernetClient cl) {
  if (cl.connect(ip, port)) {
    timeStamp();
    Serial.print("Host ");
    printIp(ip);
    Serial.print(" ");
    Serial.println(buf);
    cl.println(buf);
    cl.print("Host: ");
    sendIpClient(SELF_IP, cl);
    cl.println();
    cl.println();
    delay(100);
    cl.stop();
  } else {
      timeStamp();
      Serial.print("Host ");
      printIp(ip);
      Serial.print(" not connected (");
      Serial.print(buf);
      Serial.println(")");
    }
}

void sendRequest(byte ip[], int port, char object[], int value, EthernetClient cl) {
  sprintf(buf, "GET /?%s=%d", object, value);
  sendHttpRequest(ip, port, cl);
}

#endif // SEND_FEATURE
