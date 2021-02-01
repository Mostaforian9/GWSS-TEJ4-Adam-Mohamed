#include <Servo.h>

//variables based on rc car, or tinkercad simulations
double wheelRad = 0.01;
double shaftRad = 0.001;
double mass = 0.83;
double maxRPM = 17000;
double torque = 0.004*(wheelRad/shaftRad);
int gearRatio = 4;  //ratio of the diameter of the 2 gears (theoritcal)
int baseAccel = 10; //intended acceleration of the car (approximate)
double friction = 0.42*9.8;//acceleration due to friction
double inertialForce,power,speed; 


int motorFwd= 5;
int motorRev = 4;
int turningMotorPin = 6;
int echo = 3;
int trig = 2;
String control; //getting input

Servo turn;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //calculting for speed under load
  inertialForce = baseAccel*mass;
  power = torque*((maxRPM*2*3.14)/60);
  torque = wheelRad*inertialForce*gearRatio;
  maxRPM = ((power/torque)/(2*3.14)) *60;
  //initilizing pins 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(turningMotorPin,OUTPUT);
  pinMode(motorFwd,OUTPUT);
  pinMode(motorRev,OUTPUT);
  turn.attach(turningMotorPin);
  turn.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){ //collects input 
    control = Serial.read();
  }
  switch (control.toInt()){
  case 87:setSpeed((maxRPM/60) * wheelRad*2*3.14); //sets the speed to the rc cars max speed
    break;
  case 83:reverse();
    break;
  case 65:turnLeft();
    break;
  case 68:turnRight();
    break;
  case 32:stop();
    break;  
  default:break;
  }
  if( (checkDistance()-0.5)/speed < stopTime() ){
      Serial.println("stopping");
      stop();
    }
  control = "";
}

double checkDistance(){
  digitalWrite(trig, LOW); //makes sure the trigger pin starts low
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);//turns the trigger pin up for 10 microseconds to check for sound
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  double duration = pulseIn(echo, HIGH); //checks how long it took for the sound in the trigger to come back
  //multiplies the duration by the speed of sound and divided by 2 becauase the sound goes there and back (m)
  double distance = duration * 0.000343 / 2; 
  return (distance);
}

//checks if the servo can turn in the direction then turns it
void turnLeft(){
  Serial.println(turn.read());
  if(turn.read() <= 90){
    turn.write(turn.read()+45);
  } 
}
void turnRight(){
  Serial.println(turn.read());
  if(turn.read() >= 90){
    turn.write(turn.read()-45);
  } 
}
void reverse(){//makes the car move backwards at top speed (no forward speed so speed is 0)
  digitalWrite(motorFwd,LOW);
  digitalWrite(motorRev,HIGH);
  speed = 0;
}
//makes car move at a specified speed
void setSpeed(double targetSpeed){
  digitalWrite(motorRev,LOW);
  speed = targetSpeed; //lets the sensor know the car is moving at the desired speed
  targetSpeed = targetSpeed/( (maxRPM/60) * wheelRad*2*3.14); //gets % of max speed to find % power
  targetSpeed *= 255;
  analogWrite(motorFwd,(int)targetSpeed);//writes the % of max speed to the motor  
}
void stop(){ //stops the car
  digitalWrite(motorFwd,LOW);
  digitalWrite(motorRev,LOW);
  speed = 0;
}
// finds how long it takes a car moving at a certain speed to stop
double stopTime(){
  return(speed/friction);
}