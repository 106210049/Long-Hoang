// điều khiển xe đập bóng
#include <control.h>
#include <Setup.h>

int code[4];

// int  yAxis; //attack
// int X, Y; // move

Control Car; // Khai báo biến Move cho class Control để sử dụng
SetUp Read; // Khai báo biến Read cho class SetUp để sử dụng

void setup()
{
  // Serial.begin(9600); // Khởi tạo bắt đầu

  SetUp::Set(); // Khởi tạo bắt đầu cho NRF24L01
  Car.init();

}

void loop()
{

  SetUp::Read(&code, sizeof(code));// Gọi hàm đọc giá trị truyền từ TX
  // Serial.println("mang: ");
  // Serial.print("right-X");
  // Serial.println(code[0]);
  // Serial.print("Right-Y");
  // Serial.println(code[1]);
  // Serial.print("left-X");
  // Serial.println(code[2]);
  // Serial.print("Left-Y");
  // Serial.println(code[3]);
  // delay(100);
  // Move.rightOrLeft();
  //go ahead and go back
  
  if (code[1] >170)// Nếu như giá trị xung nhận được nhỏ hơn 100 thì xe di chuyển về sau
  {
    Car.goBack();
  }
  else if (code[1] <90)// Nếu như giá trị xung nhận được lớn hơn 140 thì xe di chuyển tiến tới phía trước
  {
    Car.goAhead();
  }
  else
  {
    Car.Stop();// nếu không thỏa điều kiện trên thì mô tơ k hoạt động
  }
  //turn right or turn left
  Car.rightOrLeft(code[0]);
  // Serial.print("tron: ");
  // Serial.println(code[2]);
  //attack punch
  Car.Punch(code[3]);// Gọi hàm điều khiển servo cần gạc
  Car.kep(code[2]);
  // delay(20);
}