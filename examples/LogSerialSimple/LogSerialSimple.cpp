#include <Arduino.h>

#include <LogSerial.h>

Log logger(115200, 1);

void setup()
{
}

void loop()
{
  int i = 42;
  logger.write("Logging i linewise: "); 
  logger.writeln(i);
  delay(2000);
}
