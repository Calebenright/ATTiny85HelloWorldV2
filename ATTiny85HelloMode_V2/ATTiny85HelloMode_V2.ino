// BLinking LED Sketch For Advanced Prototyping
int ledPin =  1;
int butPin = 0;
unsigned long endTime = 0;
unsigned long startTime;
long interval = 100;         // controls speed of blinking LED

int ledBlink = LOW;
int prevButState;
int switchVal = 0;
int butState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(butPin, INPUT);
}

void loop() {
  
  butState = digitalRead(butPin);
  
  if (butState == HIGH && prevButState == LOW) {
    delay(5);
    if (butState == HIGH) {
      if (switchVal == 2) {
        switchVal = 0;
      } else {
        switchVal = switchVal + 1;
      }
    }
  }
  
  switch (switchVal) {
    case 0:
       startTime = millis();         // starts millis timer

      if (startTime - endTime >= interval) {
        endTime = startTime;        // resets timer

        if (ledBlink == LOW) {
          ledBlink = HIGH;
        } else {
          ledBlink = LOW;
        }

        digitalWrite(ledPin, ledBlink);
      }
      break;
    case 1:
      digitalWrite(ledPin, LOW);
      break;
    case 2:
      digitalWrite(ledPin, HIGH);
      break;
  }
    prevButState = butState;
}
