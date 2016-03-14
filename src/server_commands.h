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
#ifndef SERVER_COMMANDS_H
#define SERVER_COMMANDS_H

void setKey();
void parseCommands(EthernetClient cl);

#endif //SERVER_H
#endif // SERVER_FEATURE
