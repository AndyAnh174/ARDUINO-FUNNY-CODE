#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);
int rx_data1;
char rx_data;
String storedData = "";
String storedData1 = "";
//joystick
int Pot_Val_Y = 0;
int Pot_Val_X = 0;
unsigned char Tx_command = 0;
//Biến trở
#define BTRO A2
int val =0;
//oled
int hienthi =0; 

#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);

void draw(void) {
  // đây là 1 chương trình con của oled dùng lệnh u8g
  u8g.setFont(u8g_font_fur14);
  u8g.drawStr( 0, 22, "CM: ");
  u8g.setPrintPos(0, 50); // dùng này khi dùng để hiển thị biến
  u8g.setFont(u8g_font_fur14);
  u8g.print(hienthi);
}

void setup() 

{
 Serial.begin(9600);
 mySerial.begin(9600);
 pinMode(BTRO, INPUT); //cho cái Biến trở là INPUT
 //chương trình chạy để bật đèn sáng oled
 if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop() 
{
 Pot_Val_Y = analogRead(A1); //khai báo chân joystick ở tín hiệu Y là A1
 Pot_Val_X = analogRead(A0);
 if(Pot_Val_X > 600)   //khai báo chân joystick ở tín hiệu X là A0
 {
  mySerial.println(4); 
  delay(300);
 }
 if(Pot_Val_X < 400) //trái
 {
  mySerial.println(3); 
  delay(300);
 }
 if(Pot_Val_Y > 600) //lùi
 {
  mySerial.println(2); 
  delay(300);
 }
 if(Pot_Val_Y < 400) //tiến
 {
  mySerial.println(1); 
  delay(300);
 }
 {
 int val = analogRead(BTRO);
 val = map(val, 0, 843, 5, 175); //do nguồn điện ko đủ nên phải dùng 843 ko thì dùng 1023. góc độ là 5 độ ban đầu quay tối đa 175 độ
 mySerial.println(val);
 delay(300);
}

  u8g.firstPage();  
 {
 if(mySerial.available())
 {
  while(mySerial.available())  
  {
   rx_data = mySerial.read();       //Dữ liệu sẽ nhận bằng dạng kí tự
   storedData += rx_data;           //Các kí tự sẽ được ghép thành một chuỗi(xâu)
  }
 }
 if(storedData.length() >0)  
 {
  storedData1 = storedData;
  storedData="";                    //Trả chuỗi(xâu) ban đầu về chuỗi(xâu) trắng(không nội dung)
  rx_data1=storedData1.toInt();     //Chuyển từ kiểu chuỗi(xâu) sang kiểu số nguyên
  Serial.println(rx_data1);
 }
 delay(300);  
}
u8g.firstPage();
do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(50);
}





