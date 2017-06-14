// ArduinoSerial.h

#ifdef ARDUINOSERIAL_EXPORTS
#define ARDUINOSERIAL_API __declspec(dllexport) 
#else
#define ARDUINOSERIAL_API __declspec(dllimport) 
#endif

ARDUINOSERIAL_API float circleArea(float radius);
ARDUINOSERIAL_API float ReadValue(float port);
