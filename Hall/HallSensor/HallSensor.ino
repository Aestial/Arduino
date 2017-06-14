/*
Arduino Hall Effect Sensor Project
by Arvind Sanjeev
Please check out  http://diyhacking.com for the tutorial of this project.
DIY Hacking
*/

volatile byte half_revolutions;
unsigned int rpm;
unsigned long timeold;
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(interruptPin), MagnetDetect, CHANGE);//Initialize the intterrupt pin (Arduino digital pin 2)
  half_revolutions = 0;
  rpm = 0;
  timeold = 0;
}
void loop()//Measure RPM
{
  digitalWrite(ledPin, state);
  if (half_revolutions >= 20) { 
    rpm = 30*1000/(millis() - timeold)*half_revolutions;
    timeold = millis();
    half_revolutions = 0;
    //Serial.println(rpm,DEC);
  }
}
void MagnetDetect()//This function is called whenever a magnet/interrupt is detected by the arduino
{
  half_revolutions++;
  Serial.println("Detect");
  state = !state;
}
