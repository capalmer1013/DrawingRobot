#include <Servo.h>

int MOTOR_A = 3;
int en1 = 4;
int en2 = 2;

int MOTOR_B = 6;
int en3 = 7;
int en4 = 8;

int penServo = 11;
Servo myservo;
int pos = 0;

int rightEncoder = 12;
int leftEncoder = 13;

int left = 0;
int rigt = 1;

void setup()
{
pinMode(MOTOR_A, OUTPUT);
pinMode(en1, OUTPUT);
pinMode(en2, OUTPUT);
pinMode(MOTOR_B, OUTPUT);
pinMode(en3, OUTPUT);
pinMode(en4, OUTPUT);
}

void driveStraight()
{
 //Both motors forward
  digitalWrite(en1, HIGH);
  digitalWrite(en2, LOW);
  analogWrite(MOTOR_A, 85);
  digitalWrite(en3, LOW);
  digitalWrite(en4, HIGH);
  analogWrite(MOTOR_B, 100);
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
void loop()
{
  for(int i; i < 4; i++)
  {
    driveStraight();
    stopMotors();
    turn(right);
    stopMotors();
  }
  
}
