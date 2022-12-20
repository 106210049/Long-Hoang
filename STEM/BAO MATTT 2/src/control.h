#ifndef CONTROL_H
#define CONTROL_H
#include <Arduino.h>
#include <Servo.h>

#define IN1 6 // khởi tạo chân mô tơ điều khiển bánh xe
#define IN2 5
#define IN3 4
#define IN4 3
#define SERVO1 10
#define SERVO2 9

Servo punch; // Khai báo động cơ servo
Servo turn;  // Khai báo động cơ servo
Servo KEP;
bool check = false;
class Control // Lập 1 class để điều khiển
{
public:
    Control() { Serial.begin(9600); }
    void init();
    void Punch(int b);       // Hàm điều khiển cần gạc
    void rightOrLeft(int y); // Hàm điều khiển rẽ phải rẽ trái
    void Stop();
    void kep(int b);
    void goAhead(); // Hàm điều khiển bánh xe đi lên phía trước
    void goBack();  // Hàm điều khiển bánh xe đi lùi về sau
};

void Control::init()
{
    pinMode(IN1, OUTPUT); // Thiết lập chân số IN1 là chân OUTPUT
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    KEP.attach(SERVO1); // khởi tạo/ thiết lập chân 8 cho servo
    punch.attach(SERVO2);

    KEP.write(0);
    punch.write(0);
    Stop();
}

void Control::Punch(int b) // Định nghĩa hàm Punch
{
    // SetUp::Init();// Gọi hàm đọc giá trị nhận từ modul NRF24L01
    int pos = map(b, 0, 255, 0, 120); // biến đổi giá trị xung từ 0-255 thành 0-120 độ
    if (pos < 57)
        pos = 57;
    punch.write(pos); // Điều khiển servo quay với góc pos độ
    // Serial.println("pos: ");
    // Serial.println(pos);
    // punch.detach();
}

void Control::kep(int b) // Định nghĩa hàm Punch
{
    int goc;
    if (b == 1)
    {
        check = !check;
    }
    goc = check * 90;

    // SetUp::Init();// Gọi hàm đọc giá trị nhận từ modul NRF24L01
    int pos = map(goc, 0, 255, 0, 180); // biến đổi giá trị xung từ 0-255 thành 0-120 độ
    KEP.write(pos);                     // Điều khiển servo quay với góc pos độ
    delay(30);

    // punch.detach();
}

void Control::rightOrLeft(int y) // Định nghĩa hàm rẽ trái rẽ phải
{

    // Serial.println("R or L");
    // int pos = map (y, 0, 255, 0, 100); // Biến đổi giá trị xung từ 0-255 thành 0-100 độ
    // turn.write(y < 80 ? 60 : (y > 180? 120 :90));// Điều khiển servo quay với góc pos độ
    if (y > 170) // rẽ phải
    {
        Serial.println("rẽ phải");
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
    }
    if (y < 90) // rẽ trái
    {
        Serial.println("rẽ trái");
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }

    delay(30);
}
void Control::Stop() // Định nghĩa hàm dừng xe
{
    Serial.println("stop");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void Control::goBack() // Định nghĩa hàm chạy lui về sau
{
    Serial.println("Go back");

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
}

void Control::goAhead() // Định nghĩa hàm điều khiển xe chạy tới về phía trước
{
    Serial.println("Go ahead");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

#endif