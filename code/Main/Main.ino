
int pwmA = 10;
int pwmB = 11;
int enA = 12;
int enB = 13;
int buz = 4;


long duration;
int distance;
const int trig = 9;
const int echo = 8;


const int sensor1 = 2;
const int sensor2 = 3;
const int sensor3 = 5;
const int sensor4 = 6;
int val = 0;


   
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

    if (forward!= 100){
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

void startMovingForward2(){

  stopping = 100;
  if (true){ //starting to move 

    if (forward!= 100){
      ++forward;
    }

    digitalWrite(enA, HIGH);  //
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, forward);
    analogWrite(pwmB, forward);
    delay(10);

  }

  if (digitalRead(sensor4) || (digitalRead(sensor2) || digitalRead(sensor3)) || digitalRead(sensor1)){

    digitalWrite(buz , HIGH);
    delay(10);
    digitalWrite(buz , LOW);


  }
}


void movingBackward(){

  for (int i = 50 ; i<=100 ; ++i){
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

  
  if (digitalRead(sensor4) || (digitalRead(sensor2) || digitalRead(sensor3)) || digitalRead(sensor1)){

    digitalWrite(buz , HIGH);
    delay(10);
    digitalWrite(buz , LOW);


  }
  
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

void movingRight(){
  int sound = 0 ;

  //start 
  for (int i = 50 ; i<=350 ; ++i){

    digitalWrite(enA, HIGH);  
    digitalWrite(enB, LOW);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(10);
    // if (sound <= 10){
    //   digitalWrite(buz, HIGH);
    // }else {
    //   digitalWrite(buz, LOW);
    // }

    ++sound;


  }
   digitalWrite(enA, HIGH);  
   digitalWrite(enB, LOW);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  digitalWrite(buz, LOW);
  delay(1000);

}

void movingLeft(){
   //start 
  for (int i = 50 ; i<=400 ; ++i){
    digitalWrite(enA, LOW);  
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    digitalWrite(buz, HIGH);

    delay(10);

  }
   digitalWrite(enA, LOW);  
   digitalWrite(enB, HIGH);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  digitalWrite(buz, LOW);
  delay(1000);

}


void movingLeftSides(){
  int n = 50;
  while (digitalRead(sensor4) && (digitalRead(sensor2) && digitalRead(sensor3)) && !digitalRead(sensor1) ){
    if (n!= 200){
      ++n;
    }

    digitalWrite(enA, LOW);  //
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, n);
    analogWrite(pwmB, n);
    delay(10);


  }

}

void movingRightSides(){
  int n = 50;
  while ( digitalRead(sensor1) && (digitalRead(sensor2) && digitalRead(sensor3)) && !digitalRead(sensor4)){
    if (n!= 200){
      ++n;
    }

    digitalWrite(enA, HIGH);  //
    digitalWrite(enB, LOW);
    analogWrite(pwmA, n);
    analogWrite(pwmB, n);
    delay(10);
  }

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


void walkInLine(){
     if (digitalRead(sensor4) && (digitalRead(sensor2) && digitalRead(sensor3)) && !digitalRead(sensor1)){
      machineStopping();
      movingLeftSides(); 
    }
    
    else if (digitalRead(sensor1) && (digitalRead(sensor2) && digitalRead(sensor3)) && !digitalRead(sensor4)){
      machineStopping();
      movingRightSides();
    }

    else if (!digitalRead(sensor4) && (digitalRead(sensor2) && digitalRead(sensor3)) && !digitalRead(sensor1)){
      startMovingForward();
    }
     else {
      movingBackward();
    }

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
    startMovingForward2();

    turningBlock = 0;

  }
  
  delay (1000);

}
