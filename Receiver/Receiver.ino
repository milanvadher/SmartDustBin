#include<VirtualWire.h>
int count;
void setup()
{
  Serial.begin(9600);
  Serial.println("setup");
  vw_set_rx_pin(7);
  vw_set_ptt_inverted(true);
  vw_setup(4000);
  vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if(vw_get_message(buf, &buflen))
  {
    int i;
    digitalWrite(13,true);
    Serial.print("Got: ");

    for(i = 0;i<buflen; i++)
    {
      char c = (buf[i]);
      Serial.print(c);
      Serial.print(" ");
    }
    count++;
    Serial.print(count);
    Serial.println("");
    digitalWrite(13,false);
  }
}

