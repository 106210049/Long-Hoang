#ifndef SETUP_H
#define SETUP_H
 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE      7
#define CSN     8
const byte address[6] = "00001";

RF24 radio(CE, CSN);
class SetUp
{
  public:
  SetUp()
  {
    Serial.begin(9600);
  }
    static void Set();
    static void Trans(const void *buf, uint8_t len);
};

void SetUp::Set()
{
  // Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(90);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void SetUp::Trans(const void *buf, uint8_t len)
{

  radio.write(buf, len);
}


#endif