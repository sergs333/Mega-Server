/*
  Modul SD card for Due
  part of Arduino Mega Server project
*/
#ifndef SD_H
#define SD_H

void sdCardInit() ;
  void sdInfoInit() ;
  void cardInfo() ;
  void sdFilesInit() ;
  void printSdContent(File dir, int numTabs) ;
  void printDirectory(File dir) ;
  String strDirectory(File dir) ;
  byte sdType() ;
  byte sdFileSystem() ;
  int sdVolumeSize() ;
  void printSdContent(File dir, int numTabs) ;
  void printDirectory(File dir) ;

#endif