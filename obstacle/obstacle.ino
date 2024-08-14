//Ultrasonic
#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);
int distance;
//Servo Motor
#include <Servo.h>
Servo myservo;
int pos = 0;
void setup() {
  //Serial Monitor Begin
  Serial.begin(9600);
  //Servo Motor
  myservo.attach(9);

}

void loop() {
    //Ultrasonic  
    distance = ultrasonic.read();  
    Serial.print("Distance in CM: ");
    Serial.println(distance);
    delay(1000);
        if(distance <= 50){
          for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15 ms for the servo to reach the position
        }
        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15 ms for the servo to reach the position
        }
  }

}
