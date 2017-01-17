#include <VirtualWire.h>

void setup()
{
  Serial.begin(9600);
  Serial.println("setup");
  vw_set_tx_pin(12);
  vw_set_ptt_inverted(true);
  vw_setup(4000);
}

void loop()
{
  const char *msg = " dada ";
  digitalWrite(13, true);
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
  digitalWrite(13, false);
  delay(5000);
}

