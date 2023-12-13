#include <SoftwareSerial.h>
int rx_data1;
char rx_data;
String storedData = "";
String storedData1 = "";
SoftwareSerial mySerial(11, 10);
//CT XE ĐIỀU KHIỂN
#define in1 2
#define in2 3
#define in3 4
#define in4 5
void setup();
{
    mySerial.begin(9600);
    Serial.begin(9600);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    Serial.begin(9600);
}
void loop();
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
  storedData="";                    //Trả chuỗi(xâu) ban đầu về chuỗi(xâu) trắng(không nội dung)7
  rx_data1=storedData1.toInt();     //Chuyển từ kiểu chuỗi(xâu) sang kiểu số nguyên
 }
}
if(rx_data1 == 1) //tiến
 {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
 }

 if(rx_data1 == 2) //lùi
 {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
 }
 if(rx_data1 == 3) //trái
 {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
 }

  if(rx_data1 == 4) //phải
 {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
 }
 

