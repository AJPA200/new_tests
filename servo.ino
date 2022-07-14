// C++ code
//
# include <Servo.h>

Servo left;
Servo right;


void setup() {

  left.attach(8);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()){

    int value = Serial.read();
    switch (value){
      
      case 49:
      Serial.println('L');
      left.write(90);
      break; 

      case 48:
      Serial.println('R');
      left.write(0);
      break;
      
    }
  }
}