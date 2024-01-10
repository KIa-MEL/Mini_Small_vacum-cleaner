    /*
  Dual-Axis-Joystick-Shield
  made on 16 Nov 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home<iframe class="wp-embedded-content" sandbox="allow-scripts" security="restricted" style="position: absolute; clip: rect(1px, 1px, 1px, 1px);" title="&#8220;Home&#8221; &#8212; Electropeak" src="https://electropeak.com/learn/embed/#?secret=70vwtig5W6" data-secret="70vwtig5W6" width="600" height="338" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe>

*/

# define UP 2
# define RIGHT 3
# define DOWN 4
# define LEFT 5
# define E 6
# define F 7
# define Joy_BT 8
# define Joy_X A0
# define Joy_Y A1
 int bottons[]={UP,RIGHT,DOWN,LEFT,E,F,Joy_BT};
 
void setup(){
  for(int i=0;i<7;i++) pinMode(bottons[i],INPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.print("UP:");Serial.print(digitalRead(UP));
  Serial.print("  RIGHT:");Serial.print(digitalRead(RIGHT));
  Serial.print("  DOWN:");Serial.print(digitalRead(DOWN));
  Serial.print("  LEFT:");Serial.print(digitalRead(LEFT));
  Serial.print("  E:");Serial.print(digitalRead(E));
  Serial.print("  F:");Serial.print(digitalRead(F));
  Serial.print("  Joy_BT:");Serial.print(digitalRead(Joy_BT));
  
  Serial.print("  Joy_X:");Serial.print(analogRead(Joy_X));
  Serial.print("  Joy_Y:");Serial.println(analogRead(Joy_Y));

  delay(500); 
}
