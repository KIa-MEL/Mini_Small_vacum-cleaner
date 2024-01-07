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
void setup() {
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(buz, OUTPUT);

  Serial.begin(9600);
}


int forward=50;
int stopping = 200;



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

  //start 
  for (int i = 50 ; i<=300 ; ++i){
    digitalWrite(enA, HIGH);  
    digitalWrite(enB, LOW);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(10);

  }
   digitalWrite(enA, HIGH);  
   digitalWrite(enB, LOW);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  delay(1000);

}

void movingRight(){
   //start 
  for (int i = 50 ; i<=300 ; ++i){
    digitalWrite(enA, LOW);  
    digitalWrite(enB, HIGH);
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(10);

  }
   digitalWrite(enA, LOW);  
   digitalWrite(enB, HIGH);
   analogWrite(pwmA, 50);
   analogWrite(pwmB, 50);

  delay(1000);

}


void loop() {
   //startMovingForward();
   movingLeft();
   delay(3000);




}
