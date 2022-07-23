#include <Servo.h>
#include<AFMotor.h>

// ULTRASONIC SENSOR 
# define TRIG A0
# define ECO  A1
int DURACION; 
int DISTANCIA;


// ARMS 
Servo Archie; 
Servo Jughead; // Archie is left, Jughead is right

// MOTORS 
AF_DCMotor Betty(1);
AF_DCMotor Veronica(2); // Betty is right, Veronica is left 


void setup() {
  // put your setup code here, to run once:

  // Setting up the motors

  Archie.attach(9);
  Jughead.attach(8);
  Betty.setSpeed(250);
  Veronica.setSpeed(250);

  // Setting up the pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECO,INPUT);
  Serial.begin(9600); // para probar que si jala el primer ultrasonico 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);

  if (DISTANCIA >= 20 && DISTANCIA >= 0){ // robot running forward
    Betty.run(FORWARD); 
    Veronica.run(FORWARD);}

  else if(DISTANCIA <= 20 && DISTANCIA >=0){
    Betty.run(RELEASE);
    Veronica.run(RELEASE);
    Betty.run(BACKWARD);
    for(int i = 90; i <= 180; i=i+90){
    Archie.write(i);
    Jughead.write(i);
    delay(1000);}
  }
}