//this is a code for using a 4 pin hc sr04 sensor as a 3 pin ping sensor By robobot3112
//This is the dummy code for fish tank 
//charging laptop one

#include <NewPing.h>


#define MAX_DIS 20
#define MIN_DIS 5

#define PING_PIN 4 // Arduino pin for both trig and echo
#define PUMP_PIN 5// Arduino pin for pump


NewPing sonar(PING_PIN, PING_PIN );

boolean isPumping = false;

void setup() {

  Serial.begin(9600);
  pinMode(5, OUTPUT);

}

void loop() {

  delay(500); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay

  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  float distance = uS / US_ROUNDTRIP_CM;
  //    Serial.print("Ping: ");
//    Serial.print(distance); // convert time into distance
//    Serial.println("cm");

  if (distance < 2 || (distance <= MAX_DIS && distance >= MIN_DIS) || distance > 300) {
     Serial.println("nothing");
        digitalWrite(5, LOW); 
  }
  else if(distance > MAX_DIS) {
     Serial.println("pumping");
     digitalWrite(5, HIGH);   
     
  }

  
}
