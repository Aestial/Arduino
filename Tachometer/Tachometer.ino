#include <Bounce2.h>
#define REED_IN 2

// Instantiate a Bounce object
Bounce debouncer = Bounce();

int revolutions = 0;
int f = 0;
int rpm = 0;
int lastmillis = 0;
int lastrev = 0;

void setup() {
 // Communication setup
 Serial.begin(115200);
 // Button setup
 pinMode(REED_IN, INPUT);
 // Debouncer setup
 debouncer.attach(REED_IN);
 debouncer.interval(1);
}

void loop() {
  boolean stateChanged = debouncer.update();
  int state = debouncer.read();
  
  // Detect the falling edge
  if ( stateChanged && state == LOW ) {
    revolutions++;
    //Serial.print("Revolutions: ");
    Serial.print(revolutions);
    Serial.print("/");
    lastrev = millis() - lastmillis;
    lastmillis = millis();
    Serial.println(lastrev);
  }
}
