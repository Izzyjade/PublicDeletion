int val = 0;
int val2=0; //vals initialize values to return
unsigned long count=0;
unsigned long count2=0; //counts are the returned values that get added up and divided in order to find the average
int ZeroTrack=0; //counter to determine whether or not the sensors have been calibrated
int ZeroNum=0; //number to calibrate the first sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  }


void loop() {
  // put your main code here, to run repeatedly:
  if (ZeroTrack==0){
    ZeroNum=analogRead(A0); //takes initial sensor values
    ZeroTrack= ZeroTrack+1; // never enter this function again, i.e. don't recalibrate
   }
   
  for (int i =0; i<=499; i++){
     //adds up the sensor values 500 times
    count2=count2+abs(analogRead(A0)-ZeroNum);
  }
  
  //divides (averages) sensor values
  val2=count2/500;
  //resets counts
  count2=0;
  
  Serial.println("IR 2 Reading:");
  Serial.println(val2);

  delay(600); //in order to be able to track the readings
}
