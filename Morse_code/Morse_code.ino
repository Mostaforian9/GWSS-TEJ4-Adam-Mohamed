#include <Stepper.h>
  int m393Signal = 3; //initilizing pins for motor controller and stepper motor
  int stepperPin1 = 8;
  int stepperPin2 = 9;
  int stepperPin3 = 10;
  int stepperPin4 = 11;
   
  int rpmStepper = 100; //defining rpm values for each motor
  int rpm393 = 240;
  
  int stepCount = 64; //amount of steps in stepper motor
  int wheelCirc = 7*3.14; //circumfrence of the wheel in stepper motor
  Stepper stepMot = Stepper(stepCount,stepperPin1,stepperPin2,stepperPin3,stepperPin4);  

  String message = "hello";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stepperPin1, OUTPUT);
  pinMode(stepperPin2, OUTPUT);
  pinMode(stepperPin3, OUTPUT);
  pinMode(stepperPin4, OUTPUT);

  stepMot.setSpeed(rpmStepper);
}

void loop() {
  // put your main code here, to run repeatedly:
  space(2);
  /*for (int index = 0; index < message.length() ; index++){ //reads each charecter in the message
    int letterNum = (int)toLowerCase(message[index]); //converts to int (the switch needs integers)
    switch (letterNum){  //calls on the proper function to draw the appropriate charecter
      case 97  : a(); break;
      case 98  : b(); break;
      case 99  : c(); break;
      case 100 : d(); break;
      case 101 : e(); break;
      case 102 : f(); break;
      case 103 : g(); break;
      case 104 : h(); break;
      case 105 : i(); break;
      case 106 : j(); break;
      case 107 : k(); break;
      case 108 : l(); break;
      case 109 : m(); break;
      case 110 : n(); break;
      case 111 : o(); break;
      case 112 : p(); break;
      case 113 : q(); break;
      case 114 : r(); break;
      case 115 : s(); break;
      case 116 : t(); break;
      case 117 : u(); break;
      case 118 : v(); break;
      case 119 : w(); break;
      case 120 : x(); break;
      case 121 : y(); break;
      case 122 : z(); break;
    }

    if (index != message.length()-1){ //to prevent an out of range error
      if ((int)toLowerCase(message[index + 1]) == 32){ //creates a space between words or letters (depending if the next char is a space)
        space(7);
      }
      else{
        space(3);
      }
    } 
    }*/
  }


void liftPen(){
  analogWrite (m393Signal,206); // set 393 motor to quarter speed forward (1.75 ms period) for the duration of 1 round
  Serial.println("FWD start");
  delay( ( 4/(rpm393/60.0) ) *1000);
  analogWrite (m393Signal,191);
  Serial.println("FWD end");
}
void dropPen(){
  analogWrite (m393Signal,175); // set 393 motor to quarter speed backwards (1.25 ms period) for the duration of 1 round
  Serial.println("BWD start");
  delay( ( 4/(rpm393/60.0) ) *1000);
  analogWrite (m393Signal,191);
  Serial.println("BWD end");
}
void space(int len){
  stepMot.step( (1*len/wheelCirc) * stepCount); //turns the wheel to pull the paper by "len" amounts op spaces, each space is 1 centimeter
  delay(50);
}
void dot(){ //functions to write charecters
  dropPen();
  delay(50);
  liftPen();
  delay(50);
}
void dash(){
  dropPen();
  space(3);
  liftPen();
}
void a(){ //writing each letter in morse code
  dot();
  space(1);
  dash();
}
void b(){
  dash();
  space(1);  
  dot();
  space(1);
  dot();
  space(1);
  dot();  
}
void c(){
  dash();
  space(1);
  dot();
  space(1);
  dash();
  space(1);
  dot();
}
void d(){
  dash();
  space(1);
  dot();
  space(1);
  dot();
}
void e(){
  dot();
}
void f(){
  dot();
  space(1);
  dot();
  space(1);
  dash();
  space(1);
  dot();
}
void g(){
  dash();
  space(1);
  dash();
  space(1);
  dot();
}
void h(){
  dot();
  space(1);
  dot();
  space(1);
  dot();
  space(1);
  dot();
}
void i(){
  dot();
  space(1);
  dot();
}
void j(){
  dot();
  space(1);
  dash();
  space(1);
  dash();
  space(1);
  dash();
}
void k(){
  dash();
  space(1);
  dot();
  space(1);
  dash();
}
void l(){
  dot();
  space(1);
  dash();
  space(1);
  dash();
  space(1);
  dash();
}
void m(){
  dash();
  space(1);
  dash();
}
void n(){
  dash();
  space(1);
  dot();
}
void o(){
  dash();
  space(1);
  dash();
  space(1);
  dash();
}
void p(){
  dot();
  space(1);
  dash();
  space(1);
  dash();
  space(1);
  dot();
}
void q(){
  dash();
  space(1);
  dash();
  space(1);
  dot();
  space(1);
  dash();
}
void r(){
  dot();
  space(1);
  dash();
  space(1);
  dot();
}
void s(){
  dot();
  space(1);
  dot();
  space(1);
  dot();
}
void t(){
  dash();
}
void u(){
  dot();
  space(1);
  dot();
  space(1);
  dash();
}
void v(){
  dot();
  space(1);
  dot();
  space(1);
  dot();
  space(1);
  dash();
}
void w(){
  dot();
  space(1);
  dash();
  space(1);
  dash();
}
void x(){
  dash();
  space(1);
  dot();
  space(1);
  dot();
  space(1);
  dash();
}
void y(){
  dash();
  space(1);
  dot();
  space(1);
  dash();
  space(1);
  dash();
}
void z(){
  dash();
  space(1);
  dash();
  space(1);
  dot();
  space(1);
  dot();
}
