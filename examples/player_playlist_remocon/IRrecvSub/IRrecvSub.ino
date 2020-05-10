/*
 * IRrecvSub - Receive IR on Spresense SubCore and send IR codes to MainCode
 *
 * This is derived from the following sketch.
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#ifndef SUBCORE
#error "This sketch runs on Spresense SubCore!!"
#endif

#include <IRremote.h>
#include <MP.h>
#include "common.h"

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  MP.begin();
  //Serial.begin(115200);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  //Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  //Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    MP.Send(MSGID_IR, results.value);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
