/*
Motor Control with a Transistor example 
Example code: http://www.arduino.cc/en/Tutorial/TransistorMotorControl

 This example code is in the public domain.

 added tiltswitch and code
 */

const int tiltSwitch = 2;
//bool done;

// the transistor which controls the motor will be attached to digital pin 9
int motorControl = 9;

int tiltSensorPreviousValue = 0;
int tiltSensorCurrentValue = 0;
long lastTimeMoved = 0;
int shakeTime = 50;

void setup() {
  // make the pushbutton's pin an input:
  pinMode(tiltSwitch, INPUT);

  // make the transistor's pin an output:
  pinMode(motorControl, OUTPUT);
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
//done = true;

  tiltSensorCurrentValue = digitalRead(tiltSwitch);
    if (tiltSensorPreviousValue != tiltSensorCurrentValue) {
        lastTimeMoved = millis();
        tiltSensorPreviousValue = tiltSensorCurrentValue;
    }
    if (millis() - lastTimeMoved < shakeTime) {  // ramp up motor
        for(int x = 0; x <= 255; x++) {
        analogWrite(motorControl, x);
        Serial.println(x);
        }
        delay(50);
    
    } else if (digitalRead(tiltSwitch) == LOW) {

    // ramp down the motor speed
    
//      done = false;
//      Serial.println("its low");
//     if (done == false) {
//      moveSlower();
//     }
    for(int x = 255; x >= 0; x--){
      analogWrite(motorControl, x);
      Serial.println(x);
      delay(50);
    }    
  }
  
  delay(1);        // delay in between reads for stability
}


    
// read the state of the button and check if it is pressed
//  if(digitalRead(tiltSwitch) == HIGH){ 
////    done = false;
//    Serial.println("its High");
////    if (done == false) {
////      moveFaster();
////    }

//
//    }
//  } 

//void moveFaster() {
//
//  for(int x = 0; x <= 255; x++){
//      analogWrite(motorControl, x);
//        Serial.println(x);
//      delay(50);
//    }
//    done = true;
//}
//
//void moveSlower() {
//
//
//    for(int x = 255; x >= 0; x--){
//      analogWrite(motorControl, x);
//        Serial.println(x);
//      delay(50);
//    } 
//    done = true;
//}




