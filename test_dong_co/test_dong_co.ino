int pinA = 26;
int pinB = 30;
float encoderPosCount = 0; 
int pinALast, aVal;
boolean bCW;
float distance =0;
float tinhcm = 0;
const float pi = 3.14;  // số pi là 3.14 dùng float để đọc số thập phân
const float D = 8.5;    //bán kính ban đầu là 8.5 dùng float để đọc số thập phân
void setup() {
  Serial.begin(9600);
}
void loop()
aVal = digitalRead();
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
