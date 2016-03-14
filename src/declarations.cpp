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
#include "declarations.h"
/* ----------------------------------------------
  Function StrClear(str, length)
    sets every element of str to 0 (clears array)
------------------------------------------------- */

void StrClear(char *str, char length) {
  for (int i = 0; i < length; i++) {
    str[i] = 0;
  }
}

/* ------------------------------------------------
  Function StrContains(str, sfind)
    searches for the string sfind in the string str
    returns 1 if string found
    returns 0 if string not found
--------------------------------------------------- */

char StrContains(char *str, char *sfind) {
  char found = 0;
  char index = 0;
  char len;

  len = strlen(str);
  if (strlen(sfind) > len) {return 0;}

  while (index < len) {
    if (str[index] == sfind[found]) {
      found++;
      if (strlen(sfind) == found) {return 1;}
    } else {
        found = 0;
      }
    index++;
  }
  return 0;
}

// Serialprint
void StreamPrint_progmem(Print &out,PGM_P format,...) {
  // program memory version of printf - copy of format string and result share a buffer so as to avoid too much memory use
  char formatString[128], *ptr;
  strncpy_P(formatString, format, sizeof(formatString)); // copy in from program mem
  // null terminate - leave last char since we might need it in worst case for result's \0
  formatString[sizeof(formatString) - 2] = '\0';
  ptr = &formatString[strlen(formatString) + 1]; // our result buffer...
  va_list args;
  va_start(args, format);
  vsnprintf(ptr, sizeof(formatString) - 1 - strlen(formatString), formatString, args);
  va_end(args);
  formatString[sizeof(formatString) - 1] = '\0';
  out.print(ptr);
}
