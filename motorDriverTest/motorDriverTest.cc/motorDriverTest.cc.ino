// connect motor controller pins to Arduino digital pins
// motor one
#include <Servo.h>

int enA = 10;
int in1 = 9;
int in2 = 8;

// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

// servo for the pen
int penServo = 11;
Servo myservo;  // create servo object to control a servo
int pos = 0;

int rightEncoder = 12;
int leftEncoder  = 13;

void setup()
{
  // set all the motor control pins to outputs
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(penServo, OUTPUT);
  myservo.attach(penServo);
}

void motorARange()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  return;
}

void motorBRange()
{
  return;
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed

  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  //analogWrite(enB, 200);
  delay(2000);

  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);

  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible
  // by your hardware
  // turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // accelerate from zero to maximum speed
  for (int i = 0; i < 255; i++)
  {
    Serial.print(i);
    Serial.println();
    analogWrite(enA, i);
    //analogWrite(enB, i);
    delay(20);
  }
  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    Serial.print(i);
    Serial.println();
    analogWrite(enA, i);
    //analogWrite(enB, i);
    delay(20);
  }
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void penDemo()
{
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
  }
}
void fullSpeedPen()
{
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
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

  //demoOne();
  //delay(1000);
  //demoTwo();
  //delay(1000);
  penRest();
  delay(500);
  penWrite();
  delay(1000);
  //penDemo();
  //delay(1000);
}
