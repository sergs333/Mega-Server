#ifndef MAJORDOMO_H
#define MAJORDOMO_H
/* ----------------------------------------------
  Modul MajorDoMo
  part of Arduino Mega Server project

  sprintf(buf, "GET /objects/?script=testScript");
  sendHTTPRequest();
------------------------------------------------- */

#ifdef MAJORDOMO_FEATURE


void majordomoInit() ;

/* ---------------------
  Function sendRequest
    object:   <...>
    method:   "update"
    variable: "v"
    value:    <...>
------------------------ */

void sendRequestM(char object[], int value);

/* --------------------------------------------
  Function sendRequestMinus
    Посылка объект - значение с дробной частью
    и подстановкой знака перед значением
    object:   <...>
    method:   "update"
    variable: "v"
    value:    minus<...>.<...>
----------------------------------------------- */

void sendRequestMinusM(char object[], char minus[], int value, int value_);

/* -----------------------------
  Function sendRequestVariable ?
    object:   <...>
    method:   "update"
    variable: <...>
    value:    <...>
-------------------------------- */

void sendRequestVariableM(char object[], char variable[], int value) ;

/* -------------------------------------------
  Function sendReqSensor ?
    Посылка объект - значение с дробной частью
    (метод и переменная заранее заданы)
    object:   ...
    method:   "update"
    variable: "v"
    value:    "..."."..."
---------------------------------------------- */

void sendReqSensorM(char object[], int value, int value_) ;
/* ----------------------------------------------------
  Function sendReqSensor_ ?
    Посылка объект - значение с дробной частью
    с условием если дробная часть < 10, добавляется s2,
    если > 10, то добавляется s3
    object:   ...
    method:   "update"
    variable: "v"
    value:    "...".zero"..."
------------------------------------------------------ */

void sendReqSensorM_(char object[], char zero[], char empty[], int value, int value_) ;

/* ---------------------------------------------------------
  Function sendReqSensorFloat ?
    Стандартная посылка объект - значение с плавающей точкой
    (метод и переменная заранее заданы)
    object:   ...
    method:   "update"
    variable: "v"
    value:    ...
------------------------------------------------------------ */

void sendReqSensorFloatM(char object[], float value) ;

/* ------------------------------------------------------
  Function majordomoMegaLive
    Уведомление MajorDomo о том, что Mega жива и работает
--------------------------------------------------------- */

void majordomoMegaLive() ;

#endif // MAJORDOMO_FEATURE
#endif //MAJORDOMO_H
