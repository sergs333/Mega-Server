
#ifndef RTC_H
#define RTC_H
/*
  Modul RTC
  part of Arduino Mega Server project
*/

// NTP settings

void rtcInit() ;
void rtcWorks() ;
void rtcSync() ;
void printDigits(int digits) ;
void serialRTC() ;
void timeStamp() ;
void printRTC();
// NTP code

#ifdef RTC_FEATURE

time_t getNtpTime() ;
// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &address) ;

#endif // RTC_FEATURE

// Duration

void showDuration(time_t duration) ;
void checkEvent(time_t* prevEvent) ;

// Uptime


/* ----------------------------------------------------------
  Function makeUptimeString(char z[], char nop[])
    convert system millis() to formstted string days hh.mm.ss
    Used globsl variable char uptimeString[14];
    Auto reset ~50 days
    TODO: save to EEPROM x50 days periods
------------------------------------------------------------- */

void makeUptimeString(char zero[], char nop[]);
void setLifer() ;

#endif //RTC_H
