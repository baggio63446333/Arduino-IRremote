/*
 *  IRcommunicationTest/Main.ino - IR Send/Receive test
 */

#ifdef SUBCORE
#error "Core selection is wrong!!"
#endif

#include <MP.h>

void setup()
{
  int ret = 0;
  int subid;

  Serial.begin(115200);
  while (!Serial);

  /* Boot SubCore */
  for (subid = 1; subid <= 2; subid++) {
    ret = MP.begin(subid);
    if (ret < 0) {
      MPLog("MP.begin(%d) error = %d\n", subid, ret);
    }
  }
}

void loop()
{
  delay(1000);
}

