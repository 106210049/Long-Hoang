//#include <PS2X_lib.h>
#include <PS2X_lib/PS2X_lib.h>
#include <Arduino.h>
#include <SetUp.h>

#define PS2_DAT 9  // data
#define PS2_CMD 5  // command
#define PS2_SEL 10 // attention
#define PS2_CLK 6  // clock

// #define pressures   true
#define pressures false
// #define rumble      true
#define rumble false

PS2X ps2x; // tạo PS2 điều khiển lớp
int error = 0;
byte type = 0;
byte vibrate = 0;
// int xAxis, yAxis, X, Y;
int mang[4] = {0, 0, 0, 0};
uint8_t code[4] = {0, 0, 0, 0};

void xuly()
{
  for (int i = 0; i <= 3; i++)
  {
    if (mang[i] < 50)
      code[i] = 0;
    else if (mang[i] > 200)
      code[i] = 2;
    else
      code[i] = 1;
  }
}

void setup()
{
  Serial.begin(9600);
  SetUp::Set();
  // radio.begin();
  delay(300);

  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  if (error == 0)
  {
    Serial.print("Đã tìm thấy bộ điều khiển ");
    Serial.print("pressures = ");
    if (pressures)
      Serial.println("true ");
    else
      Serial.println("false");
    Serial.print("rumble = ");
    if (rumble)
      Serial.println("true)");
    else
      Serial.println("false");
    Serial.println("Hãy thử tất cả các nút;");
    Serial.println("giữ L1 hoặc R1 sẽ in ra các giá trị analog.");
  }
  else if (error == 1)
    Serial.println("Không kết nối đc, thử lại...");

  else if (error == 2)
    Serial.println("Bộ điều khiển tìm thấy nhưng không chấp nhận lệnh");

  else if (error == 3)
    Serial.println("Bộ điều khiển từ chối để vào chế độ Pressures ");
}

void loop()
{
  if (error == 1)
    return;

  if (type == 2)
  {
    ps2x.read_gamepad();
  }
  else
  {
    ps2x.read_gamepad(false, vibrate);
    mang[0] = ps2x.Analog(PSS_RX); // Right - X
    mang[1] = ps2x.Analog(PSS_RY); // Right - Y
    mang[2] = ps2x.Button(PSB_CIRCLE);
    mang[3] = ps2x.Analog(PSS_LY); // Left - Y

    xuly();

    // Serial.print("circle: ");
    // Serial.println(mang[2]);
    
    Serial.print("right x: ");
    Serial.println(mang[0]);
    Serial.print("right y: ");
    Serial.println(mang[1]);
    Serial.print("left x: ");
    Serial.println(mang[2]);
    Serial.print("left y: ");
    Serial.println(mang[3]);

    SetUp::Trans(&mang, sizeof(mang));
    delay(30);
  }
}