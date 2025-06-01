#include "CmdMessenger.h"


char field_separator   = ',';
char command_separator = ';';
char escape_separator  = '/';


CmdMessenger cmdMessenger = CmdMessenger(Serial, field_separator, command_separator);


enum
{
  kSendStatus,
  kStart,
  kStop,
};


void OnStart() {
  digitalWrite(LED_BUILTIN, HIGH);
  cmdMessenger.sendCmd(kSendStatus, "LED now high");
}


void OnStop() {
  digitalWrite(LED_BUILTIN, LOW);
  cmdMessenger.sendCmd(kSendStatus, "LED now low");
}


void OnStatus() {}


void OnUnknownCommand()
{
  cmdMessenger.sendCmd(kSendStatus, "Unknown command");
}


void attachCommandCallbacks() {
  cmdMessenger.attach(kStart, OnStart);
  cmdMessenger.attach(kStop, OnStop);
  cmdMessenger.attach(kSendStatus, OnStatus);
  cmdMessenger.attach(OnUnknownCommand);
}


void setup() {
  Serial.begin(115200); 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  attachCommandCallbacks();
}


void loop() {
  cmdMessenger.feedinSerialData();
  delay(20);
}
