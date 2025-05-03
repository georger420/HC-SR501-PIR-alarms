#include <Bounce2.h> 

#define LEDYELLOW_PIN PB0
#define LEDMAG_PIN PB1
#define BUZZ_PIN PB4
#define PIR_PIN PB2
#define BUTT_PIN PB3

Bounce2::Button button = Bounce2::Button();

boolean active_buzzer;
boolean armed;
int i;


void setup() {
    // Set variable "active_buzzer" = true if the active buzzer (KY-12) is used
    // or set "active_buzzer" = false if the passive buzzer (KY-006) is used.
    active_buzzer = true;
    pinMode(LEDYELLOW_PIN, OUTPUT);
    pinMode(LEDMAG_PIN, OUTPUT);
    pinMode(BUZZ_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
    button.attach ( BUTT_PIN , INPUT_PULLUP );
    button.interval(5);
    button.setPressedState(LOW); 
    armed = false;
    digitalWrite(LEDMAG_PIN, LOW);

}

void loop() {
    button.update();
      if ( button.pressed() ) {
          if (armed == false) {
              armed = true;
          } else {
              armed = false;
          }
      }

      if (armed == true) {
          digitalWrite(LEDMAG_PIN, HIGH);
      } else {
          digitalWrite(LEDMAG_PIN, LOW);
      }

      if (digitalRead(PIR_PIN) == HIGH) {
        digitalWrite(LEDYELLOW_PIN, HIGH);
          if (armed) {
              pipip();
          }
      } else {
          digitalWrite(LEDYELLOW_PIN, LOW);
          digitalWrite(BUZZ_PIN, LOW);
      }
}

void pipip() {
    if (active_buzzer) {
        digitalWrite(BUZZ_PIN, HIGH);
        delay(300);
        digitalWrite(BUZZ_PIN, LOW);
        delay(150);
    } else {
          for (i=0; i<= 600; i++) {
              digitalWrite(BUZZ_PIN, HIGH);
              delayMicroseconds(300);
              digitalWrite(BUZZ_PIN, LOW);
              delayMicroseconds(300);
          }
          delay(200);
    }
}
