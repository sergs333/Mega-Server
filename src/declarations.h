#ifndef MEGA_DECL_H
#define MEGA_DECL_H


// modules
#define ETHERNET_FEATURE
#define SERVER_FEATURE
#define RTC_FEATURE
#define SEND_FEATURE
#define MAJORDOMO_FEATURE
//#define UPLOAD_FEATURE
#define SD_INFO_FEATURE
#define SD_FILES_FEATURE
//#define PING_FEATURE
//#define LAURENT_FEATURE
//#define PIRS_FEATURE
//#define CONTACTS_FEATURE
//#define TEMP_FEATURE
//#define ELECTRO_FEATURE
//#define LEDS_FEATURE
//#define KEYS_FEATURE
//#define NOO_FEATURE

// debug
//#define ELECTRO_DEBUG
//#define SERVER_PROFILING
//#define EVENTS_CONTACTS
//#define EVENTS_PIRS
//#define TEMP_DEBUG


/* ----------------------------------------------
  Function StrClear(str, length)
    sets every element of str to 0 (clears array)
------------------------------------------------- */

void StrClear(char *str, char length);

/* ------------------------------------------------
  Function StrContains(str, sfind)
    searches for the string sfind in the string str
    returns 1 if string found
    returns 0 if string not found
--------------------------------------------------- */

char StrContains(char *str, char *sfind);

// Serialprint
void StreamPrint_progmem(Print &out,PGM_P format,...);

#define Serialprint(format, ...) StreamPrint_progmem(Serial,PSTR(format),##__VA_ARGS__)
#define Streamprint(stream,format, ...) StreamPrint_progmem(stream,PSTR(format),##__VA_ARGS__)
/// Functions definition

#endif
