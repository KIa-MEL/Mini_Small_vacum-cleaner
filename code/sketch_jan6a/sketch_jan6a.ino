  /*
  L298P-Motor-Driver-Shield
  made on 09 Nov 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home<iframe class="wp-embedded-content" sandbox="allow-scripts" security="restricted" style="position: absolute; clip: rect(1px, 1px, 1px, 1px);" title="&#8220;Home&#8221; &#8212; Electropeak" src="https://electropeak.com/learn/embed/#?secret=5GQbCuTSNR" data-secret="5GQbCuTSNR" width="600" height="338" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe>
*/


int pwmA = 10;
int pwmB = 11;
int enA = 12;
int enB = 13;
int buz = 4;


long duration;
int distance;
<<<<<<< HEAD:code/sketch_jan6a/sketch_jan6a.ino
#define trig A2
#define echo A1
=======
const int trig = 9;
const int echo = 8;


const int sensor1 = 2;
const int sensor2 = 3;
const int sensor3 = 5;
const int sensor4 = 6;
int val = 0;


>>>>>>> 7b78983d5c59c66e5670d205119b54027f2f426b:sketch_jan6a/sketch_jan6a.ino
   
void setup() {
  //L298
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(buz, OUTPUT);


  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  //ULTRA SONIC
  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(echo, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication



}


int forward=50;
int stopping = 200;


//L298=======================
void startMovingForward(){

  stopping = 200;
  if (true){ //starting to move 

    if (forward!= 200){
      ++forward;
    }

    digitalWrite(enA, HIGH);  //
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, forward);
    analogWrite(pwmB, forward);
    delay(10);

  }
    digitalWrite(buz, LOW);
}

void movingBackward(){

  for (int i = 50 ; i<=300 ; ++i){
    digitalWrite(enA, LOW);  
    digitalWrite(enB, LOW);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(10);

  }
  digitalWrite(enA, LOW);  
   digitalWrite(enB, LOW);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  digitalWrite(buz, LOW);
  
}

void machineStopping(){

  forward = 50;
  if (stopping != 50){
    --stopping;
  }

    digitalWrite(enA, HIGH);  
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, stopping);
    analogWrite(pwmB, stopping);
    delay(10);
}

void movingLeft(){
  int sound = 0 ;

  //start 
  for (int i = 50 ; i<=350 ; ++i){

    digitalWrite(enA, HIGH);  
    digitalWrite(enB, LOW);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(10);
<<<<<<< HEAD:code/sketch_jan6a/sketch_jan6a.ino
    // digitalWrite(buz, HIGH);
=======
    if (sound <= 10){
      digitalWrite(buz, HIGH);
    }else {
      digitalWrite(buz, LOW);
    }

    ++sound;
>>>>>>> 7b78983d5c59c66e5670d205119b54027f2f426b:sketch_jan6a/sketch_jan6a.ino


  }
   digitalWrite(enA, HIGH);  
   digitalWrite(enB, LOW);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  // digitalWrite(buz, LOW);
  delay(1000);

}

void movingRight(){
   //start 
  for (int i = 50 ; i<=400 ; ++i){
    digitalWrite(enA, LOW);  
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    // digitalWrite(buz, HIGH);

    delay(10);

  }
   digitalWrite(enA, LOW);  
   digitalWrite(enB, HIGH);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  // digitalWrite(buz, LOW);
  delay(1000);

}
//HC-SR04=====================
int calculateDistance(){ 
  
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

//INFRARED MODULE =============


int sensor1Val = 0;
int sensor2Val = 0;
int sensor3Val = 0;
int sensor4Val = 0;

bool turningBlock = 0;
void loop() {
  distance = calculateDistance();
  Serial.println(distance); 

  if (distance <= 5 && turningBlock == 0){
    turningBlock = 1;
    machineStopping();
    movingBackward();
    movingLeft();
  }
  else {
    turningBlock = 0;
    startMovingForward();
  }

  // sensor1Val = digitalRead(sensor1);
  // sensor2Val = digitalRead(sensor2);
  // sensor3Val = digitalRead(sensor3);
  // sensor4Val = digitalRead(sensor4);

  //Serial.println(sensor3Val);
  // Serial.println(sensor2Val);
  // Serial.println(sensor3Val);
  // Serial.println(sensor4Val);
  //delay(1000);


}
