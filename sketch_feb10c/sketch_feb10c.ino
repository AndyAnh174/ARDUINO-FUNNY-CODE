#define in1 2
#define in2 3
#define in3 4
#define in4 5
void setup()
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    Serial.begin(9600);
}
void loop(){
digitalWrite(in1, 0);
digitalWrite(in2, 1);
digitalWrite(in3, 0);
digitalWrite(in4, 1);
}

