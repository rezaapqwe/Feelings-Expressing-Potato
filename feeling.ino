// Pin assignments
int touchPin = 2;     // Touch sensor signal pin
int redLED = 9;       // Red LED pin
int greenLED = 10;    // Green LED pin
int blueLED = 11;     // Blue LED pin

int currentLED = 0;   // 0 = Red, 1 = Green, 2 = Blue

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  // Read the touch sensor
  if (digitalRead(touchPin) == HIGH) {
    // Turn off all LEDs first
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);

    // Decide which LED to blink
    if (currentLED == 0) {
      blinkLED(redLED);
    } else if (currentLED == 1) {
      blinkLED(greenLED);
    } else if (currentLED == 2) {
      blinkLED(blueLED);
    }

    // Move to next LED for next touch
    currentLED = (currentLED + 1) % 3;

    delay(300); // Debounce delay
  }
}

// Blink function
void blinkLED(int ledPin) {
  for (int i = 0; i < 3; i++) { // Blink 3 times
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}