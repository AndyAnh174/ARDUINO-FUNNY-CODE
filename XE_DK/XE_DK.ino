#include <SoftwareSerial.h>
int rx_data1;
char rx_data;
String storedData = "";
String storedData1 = "";
SoftwareSerial mySerial(11, 10); // RX = pin D11, TX = pin D10 RX trước TX sau
//servo

#include <Servo.h>
Servo myservo;          
int servoPin = 45;

int Pot_Val_X = 0;
int Pot_Val_Y = 0;
unsigned char Tx_command =0;
//L298
#define in1 6 
#define in2 4 
#define in3 2 
#define in4 8
//encoder


int pinA = 6;
int pinB = 7;
float encoderPosCount = 0; 
int pinALast, aVal;
boolean bCW;
float distance =0;
float tinhcm = 0;
const float pi = 3.14;  // số pi là 3.14 dùng float để đọc số thập phân
const float D = 8.5;    //bán kính ban đầu là 8.5 dùng float để đọc số thập phân

void setup ()
{
  lcd.begin();
  lcd.backlight();

 mySerial.begin(9600);
 Serial.begin(9600);
 myservo.attach(servoPin);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
}
void loop()
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
  if (rx_data1 >=7)
 {
  
//biến trở
myservo.write(rx_data1);
delay(200);

}
 if(rx_data1 == 1) //tiến
 {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
 }
 else //dùng else để khi xe vừa nhận tín hiện và khi buông joystick thì nó trả về 0 và xe sẽ dừng
 {
   digitalWrite(in1, 0);
   digitalWrite(in2, 0);
   digitalWrite(in3, 0);
   digitalWrite(in4, 0);
 }

 if(rx_data1 == 2) //lùi
 {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
 }
 else //dùng else để khi xe vừa nhận tín hiện và khi buông joystick thì nó trả về 0 và xe sẽ dừng
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
 else   //dùng else để khi xe vừa nhận tín hiện và khi buông joystick thì nó trả về 0 và xe sẽ dừng
 {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
 }
  if(rx_data1 == 4) //phải
 {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
 }
 else   //dùng else để khi xe vừa nhận tín hiện và khi buông joystick thì nó trả về 0 và xe sẽ dừng
 {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
 }
 //cho tín hiệu chạyt

}
lcd.setCursor(0,1);
delay(100);

Serial.println(rx_data1);

  aVal = digitalRead(pinA);
  if (aVal != pinALast){
    if (digitalRead(pinB) != aVal){
      encoderPosCount ++;
      bCW = true; }
      else 
      
      {
        bCW = false;
        encoderPosCount--;
     }
    distance =(encoderPosCount/40);
    tinhcm = distance*(D*pi) ;
    Serial.println(tinhcm);
    mySerial.print(tinhcm);
    delay(200); //tín hiệu hiệu truyền cao cho 300
    pinAlast = aVal ; //cho giá trị của pinAlast = với aVal để khi encoder chạy đc ổn định (ko nhất thiết)]
     }
     
    }
}

