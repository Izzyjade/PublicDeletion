// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current debounced reading from the input pin
int lastButtonState = LOW;   // the previous debounced reading from the input pin
int lastReading = LOW;       // the previous raw reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//Serial.println("Initialized");
pinMode(buttonPin, INPUT);
}

void loop() {

  // DEBOUNCE LOGIC
  
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastReading) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
  
  if (buttonState == 1 && lastButtonState == 0) {
  Serial.println(1);  // send serial signal
  }

  // save the reading. Nexst time through the loop, it'll be the lastButtonState:
  lastButtonState = buttonState;
  lastReading = reading;

}
