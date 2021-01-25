// BLinking LED Sketch For Advanced Prototyping
int ledPin =  1;

unsigned long endTime = 0;       
long interval = 500;         // controls speed of blinking LED

int ledBlink = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  unsigned long startTime = millis();         // starts millis timer

  if (startTime - endTime >= interval) {
    endTime = startTime;        // resets timer

    if (ledBlink == LOW) {
      ledBlink = HIGH;
    } else {
      ledBlink = LOW;
    }

    digitalWrite(ledPin, ledBlink);
  }
}
