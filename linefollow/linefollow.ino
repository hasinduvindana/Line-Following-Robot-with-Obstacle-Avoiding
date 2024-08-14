//IR Sensors
#define ir1 44
#define ir2 46
#define ir3 48
#define ir4 50
#define ir5 52

//Motor Controller
#define RMF 8  //Right Motor MA1
#define RMB 9  //Right Motor MA2
#define LMF 11  //Left Motor MB1
#define LMB 10 //Left Motor MB2
#define RMS 12  //Right Motor Enable Pin EA
#define LMS 13 //Left Motor Enable Pin EB


void setup() {
  
  //Define IR Sensors as INPUT
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(RMS, OUTPUT);
  pinMode(LMS, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  Serial.begin(9600);
}

void loop() {  
 if(digitalRead(ir1)==0 && digitalRead(ir2)==0 && digitalRead(ir3)==1 && digitalRead(ir4)==0 && digitalRead(ir5)==0){
    forward();
  }else if(digitalRead(ir1)==1 && digitalRead(ir2)==1 && digitalRead(ir3)==1 && digitalRead(ir4)==0 && digitalRead(ir5)==0){
    turnLeft();
  }else if(digitalRead(ir1)==0 && digitalRead(ir2)==0 && digitalRead(ir3)==1 && digitalRead(ir4)==1 && digitalRead(ir5)==1){
    turnRight();
  }else if(digitalRead(ir1)==1 && digitalRead(ir2)==1 && digitalRead(ir3)==1 && digitalRead(ir4)==1 && digitalRead(ir5)==1){
    turnLeft();
  }else{
    stop();
  }

}
void forward(){
    digitalWrite(LMF, HIGH);
    digitalWrite(LMB, LOW);
    analogWrite(LMS, 60); 
    digitalWrite(RMF, HIGH);
    digitalWrite(RMB, LOW);
    analogWrite(RMS, 60);
}

void turnLeft(){
    digitalWrite(RMF, HIGH);
    digitalWrite(RMB, LOW);
    analogWrite(RMS, 60); 
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, HIGH);
    analogWrite(LMS, 60); 
}
void turnRight(){
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, HIGH);
    analogWrite(RMS, 60);
    digitalWrite(LMF, HIGH);
    digitalWrite(LMB, LOW);
    analogWrite(LMS, 60);
}
void stop(){
   digitalWrite(LMF, LOW);
  digitalWrite(LMB, LOW);
  
  digitalWrite(RMF, LOW);
  digitalWrite(RMB, LOW);
}
