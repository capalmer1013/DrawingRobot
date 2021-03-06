#include <Servo.h>

int MOTOR_A = 3;
int en1 = 4;
int en2 = 2;

int MOTOR_B = 6;
int en3 = 7;
int en4 = 8;

int pos = 0;

int rightEncoder = 12;
int leftEncoder = 13;

int left = 0;
int right = 1;

int penServo = 11;
Servo myservo;  // create servo object to control a servo

void setup()
{
  pinMode(MOTOR_A, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
  pinMode(en3, OUTPUT);
  pinMode(en4, OUTPUT);
  pinMode(penServo, OUTPUT);
  myservo.attach(penServo);
  Serial.begin(9600);
}

void driveForward(int travelSpeed)
{
 //Both motors forward
  digitalWrite(en1, LOW);
  digitalWrite(en2, HIGH);
  analogWrite(MOTOR_A, travelSpeed);
  digitalWrite(en3, HIGH);
  digitalWrite(en4, LOW);
  analogWrite(MOTOR_B, travelSpeed);
  delay(1000);
}

void stopMotors()
{
//Both motors stop
digitalWrite(en1, LOW);
digitalWrite(en2, LOW);
digitalWrite(en3, LOW);
digitalWrite(en4, LOW);
delay(2000); 
}
void turn(int direction)
{
  //Turn right using Motor A
  if(direction)
  {
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
    analogWrite(MOTOR_A, 85);
    delay(500);
  }
  else
  {
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
    analogWrite(MOTOR_B, 100);
    delay(500);
  }
  
}
void penRest()
{
  myservo.write(180);
}
void penWrite()
{
  myservo.write(90);
}
void loop()
{
  for(int i = 0; i < 255; i ++)
  {
      driveForward(255);
      Serial.print(i);
      Serial.println();
      delay(10);
  }
  for(int i =255; i >=0; i --)
  {
    driveForward(i);
    Serial.print(i);
    Serial.println();
    delay(10);
  }

  stopMotors();
}
