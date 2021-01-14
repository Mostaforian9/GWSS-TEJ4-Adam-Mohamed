int p1Pin = A5;
int p2Pin = A0;
int StartPin = 12;
int playerPositions[]= {0,0};
int winWidth = 1920;
int winHeight = 1080;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  playerPositions[0] = map(analogRead(p1Pin),0,1023,0,winHeight);
  playerPositions[1] = map(analogRead(p2Pin),0,1023,0,winHeight);
  Serial.print("p1:");
  Serial.print(playerPositions[0]);
  Serial.print(" p2:");
  Serial.println(playerPositions[1]);
  
}
