/*
 * PIR sensor program
 */
 
int ledPin = 13;                // choose the pin for the LED
int input1Pin = 2;              // choose the input pin (for first PIR sensor)
int input2Pin = 3;              // choose the input pin (for second PIR sensor)
int power1Pin = 4;             // Freshener 1 power output pin
int power2Pin = 5;             // Freshener 2 power output pin
int output1Pin = 6;             // Freshener 1 spray output pin
int output2Pin = 7;             // Freshener 2 spray output pin
int pir1State = LOW;            // we start, assuming no motion detected
int pir2State = LOW;            // we start, assuming no motion detected
int val1 = 0;                   // variable for reading the first input pin status
int val2 = 0;                   // variable for reading the second input  pin status
unsigned long lastMillis1 = 0;
unsigned long lastMillis2 = 0;
unsigned long pauseMillis = 600000;
unsigned long sprayMillis = 10000;

void setup() {
  pinMode(ledPin, OUTPUT);        // declare LED as output
  pinMode(power1Pin, OUTPUT);    // declare Freshener 1 power as output
  pinMode(power2Pin, OUTPUT);    // declare Freshener 2 power as output
  pinMode(output1Pin, OUTPUT);    // declare Freshener 1 power as output
  pinMode(output2Pin, OUTPUT);    // declare Freshener 2 power as output
  pinMode(input1Pin, INPUT);      // declare sensor 1 as input
  pinMode(input2Pin, INPUT);      // declare sensor 2 as input
  Serial.begin(9600);
}
 
void loop(){
  val1 = digitalRead(input1Pin);  // first read input value
  val2 = digitalRead(input2Pin);  // second read input value
  
  if (val1 == HIGH) {           // check if the first input is HIGH
    digitalWrite(ledPin, HIGH); // turn LED ON
    if (pir1State == LOW && (millis() - lastMillis1 > pauseMillis) ) {
      // we have just turned on
      Serial.println("Motion detected in first sensor and Freshener 1 activated!");
      digitalWrite(power1Pin, HIGH);
      lastMillis1 = millis();
      //digitalWrite(output1Pin, HIGH);
      //delay(1000);
      // We only want to print on the output change, not state
      pir1State = HIGH;
    }
  } 
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pir1State == HIGH && (millis() - lastMillis1 > sprayMillis) ){
      // we have just turned off
      Serial.println("Motion ended in first sensor!");
      digitalWrite(power1Pin, LOW);
      //digitalWrite(output1Pin, LOW);
      // We only want to print on the output change, not state
      pir1State = LOW;
    }
  }
  
  if (val2 == HIGH) {           // check if the first input is HIGH
    if (pir2State == LOW && (millis() - lastMillis2 > pauseMillis)) {
      // we have just turned on
      Serial.println("Motion detected in second sensor and Freshener 2 activated!");
      digitalWrite(power2Pin, HIGH);
      lastMillis2 = millis();
      digitalWrite(output2Pin, HIGH);
      delay(1000);
      // We only want to print on the output change, not state
      pir2State = HIGH;
    }
  } 
  else {
    if (pir2State == HIGH && (millis() - lastMillis2 > sprayMillis) ){
      // we have just turned off
      Serial.println("Motion ended in second sensor!");
      digitalWrite(power2Pin, LOW);
      // We only want to print on the output change, not state
      pir2State = LOW;
    }
  }
}


