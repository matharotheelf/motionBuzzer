// LEDs to show timer duration
int led1Pin = 10;
int led2Pin = 11;
int led3Pin = 12;
int led4Pin = 13;
// Buzzer
int buzzerPin = 3;
// Motion detector which triggers timer
int motionDetectorPin = 2;

// Start time of hand motions
unsigned long int motionStartTime;
// Duration of time between tqo hand motions
unsigned long int motionDuration;

// Value of motion detector reading in current and previous loop iterations
int motionDetectorValuePrevious;
int motionDetectorValueCurrent;

// Start time of loop iteration of Arduino
unsigned long int loopStartTime;

// Start time of LED light cycle
unsigned long int cycleStartTime;

  
void setup() 
  
{
  // Register Input and output pins
  pinMode(motionDetectorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
}
  
 
  
void loop()
  
{
  // Register loop time
  loopStartTime = millis();

  // Read motion detector values
  motionDetectorValuePrevious = motionDetectorValueCurrent;
  motionDetectorValueCurrent = digitalRead(motionDetectorPin);

  // Logic for turning on and off lights to display duration
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

  // Register new mmotion detection
  if (motionDetectorValuePrevious == LOW && motionDetectorValueCurrent == HIGH) {   // pin state change: LOW -> HIGH
    // set initial start time for counter
      if(motionStartTime == 0) {
        digitalWrite(led1Pin, HIGH);
        motionStartTime = loopStartTime;
        cycleStartTime = 0;
    // Close timer for second hand movement
      } else if(motionDuration == 0) {
        motionDuration = loopStartTime - motionStartTime;
        tone(buzzerPin, map(motionDuration, 500, 100000, 10000, 50));
        cycleStartTime = loopStartTime;
     // Reset state after third hand movement
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
