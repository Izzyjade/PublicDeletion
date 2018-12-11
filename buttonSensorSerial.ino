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

// set up for sensor
int val = 0;
int ZeroTrack=0; //to make sure that the sensors don't recalibrate
int ZeroNum=0; //calibration numbers for sensors
unsigned long count=0;
int IRPortReading = 0; //initializing

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


  // put your main code here, to run repeatedly:
  if (ZeroTrack==0){
    ZeroNum=analogRead(A0); //takes initial sensor values
    ZeroTrack= ZeroTrack+1; // never enter this function again, i.e. don't recalibrate
   }
   
  for (int i =0; i<=499; i++){
     //adds up the sensor values 500 times
    count=count+abs(analogRead(A0)-ZeroNum);
  }
  
  //divides (averages) sensor values
  val=count/500;
  //resets counts
  count=0;
  
    if (val>=200) {
    Serial.println("D"); 
    delay(10000); //in order to be able to track the readings

    }
 

}
