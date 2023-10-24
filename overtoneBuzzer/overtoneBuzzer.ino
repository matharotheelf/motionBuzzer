int buzzerPin = 3;
int motionDetectorPin = 2;
int motionStartTime;
int motionDuration;
int motionDetectorValuePrevious;
int motionDetectorValueCurrent;

  
void setup() 
  
{
  Serial.begin(9600);
  pinMode(motionDetectorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}
  
 
  
void loop()
  
{
  motionDetectorValuePrevious = motionDetectorValueCurrent;
  motionDetectorValueCurrent = digitalRead(motionDetectorPin);

  if (motionDetectorValuePrevious == LOW && motionDetectorValueCurrent == HIGH) {   // pin state change: LOW -> HIGH
    // set initial start time for counter
      if(motionStartTime == 0) {
        motionStartTime = millis();
      } else if(motionDuration == 0) {
        motionDuration = millis() - motionStartTime;
        tone(buzzerPin, map(motionDuration, 10000, 500, 50, 1000));
      } else {
        motionStartTime = millis();
        motionDuration = 0;
        noTone(buzzerPin);
      }
  }

  Serial.println(motionDuration);
}
