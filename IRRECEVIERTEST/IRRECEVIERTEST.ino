#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {

Serial.begin(9600);
pinMode(13,OUTPUT);
irrecv.enableIRIn();

}

void loop() {

if (irrecv.decode(&results))

{ Serial.println(results.value, HEX);

irrecv.resume(); }
if(results.value == 0xACB7B6A0){
  digitalWrite(13,HIGH);
}
else if(results.value == 0x8BCCC675){
  digitalWrite(13,LOW);
}
}
