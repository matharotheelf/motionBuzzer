int led1Pin = 10;
int led2Pin = 11;
int led3Pin = 12;
int led4Pin = 13;
int buzzerPin = 3;
int motionDetectorPin = 2;
unsigned long int motionStartTime;
unsigned long int motionDuration;
int motionDetectorValuePrevious;
int motionDetectorValueCurrent;
unsigned long int loopStartTime;
unsigned long int cycleStartTime;

  
void setup() 
  
{
  Serial.begin(9600);
  pinMode(motionDetectorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
}
  
 
  
void loop()
  
{
  loopStartTime = millis();
  
  motionDetectorValuePrevious = motionDetectorValueCurrent;
  motionDetectorValueCurrent = digitalRead(motionDetectorPin);

  if(cycleStartTime != 0) {    
    if ((loopStartTime - cycleStartTime) > motionDuration) {
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
      digitalWrite(led3Pin, LOW);
      digitalWrite(led4Pin, LOW);
      cycleStartTime = loopStartTime;
    } else if ((loopStartTime - cycleStartTime) > 4*motionDuration/5) {
       digitalWrite(led4Pin, HIGH);
    } else if((loopStartTime - cycleStartTime) > 3*motionDuration/5) {
       digitalWrite(led3Pin, HIGH);
    } else if((loopStartTime - cycleStartTime) > 2*motionDuration/5) {
       digitalWrite(led2Pin, HIGH);
    } else if((loopStartTime - cycleStartTime) > motionDuration/5) {
       digitalWrite(led1Pin, HIGH);
    }
  }

  if (motionDetectorValuePrevious == LOW && motionDetectorValueCurrent == HIGH) {   // pin state change: LOW -> HIGH
    // set initial start time for counter
      if(motionStartTime == 0) {
        digitalWrite(led1Pin, HIGH);
        motionStartTime = loopStartTime;
        cycleStartTime = 0;
      } else if(motionDuration == 0) {
        motionDuration = loopStartTime - motionStartTime;
        tone(buzzerPin, map(motionDuration, 500, 100000, 10000, 50));
        Serial.println("Values");
        Serial.println(motionDuration);
        Serial.println(map(motionDuration, 500, 10000, 10000, 50));
        cycleStartTime = loopStartTime;
      } else {
        motionStartTime = 0;
        motionDuration = 0;
        cycleStartTime = 0;
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
        digitalWrite(led4Pin, LOW);
        noTone(buzzerPin);
      }
  }
}
