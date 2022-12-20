#ifndef SETUP_H
#define SETUP_H
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE  7
#define CSN 8
#define Chanel 90 // Thiết lập kênh truyền/nhận cho RF24L01
#define Bandwidth 250 // Thiết lập tốc độ nhận truyền của NRF24L01

RF24 radio(CE, CSN); // CE, CSN
const byte address[6] = "00001";


class SetUp // Tạo class  cho NRF24L01
{
  public:
    static void Set(); // hàm khởi tạo setup
    static void Read(void* code, uint8_t len); // hàm đọc giá trị
};

void SetUp::Set() // Định nghĩa hàm Set trong class SetUp
{
    Serial.println("setup...");
    radio.begin(); // Bắt đầu khởi động radio(NRF24L01)
    radio.openReadingPipe(1, address);
    radio.setPALevel(RF24_PA_MIN);// cai dat bo khuech dai cong suat o muc MAX, HiGH, LOW, MIN (0, -6, -12, -18 dBm)
    radio.setChannel(Chanel);// 125 kenh tu 0-124, TX va RX phai cung kenh
    radio.setDataRate(RF24_250KBPS);//Toc do truyen du lieu trong khong khi
    radio.startListening();// cai dat module la RX
}

void SetUp::Read(void *code, uint8_t len)// Định nghĩa hàm đọc giá trị truyền của NRF24L01
{
    Serial.println("read ......");
    if (radio.available())// Nếu radio tồn tại cùng với nhau thì thực hiện
    {
        radio.read(code, len);// Đọc các giá trị truyền từ TX(NRF24L01)
        // Serial.println("read ...");
    }
}

#endif