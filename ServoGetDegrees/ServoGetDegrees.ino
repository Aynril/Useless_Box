#include <Servo.h>

#define flapAttach 9
#define leverAttach 10
#define switchToPress 13
#define displayButton 8

Servo lever;
Servo flap;

short degLever = 90;
short degFlap = 30;
void setup() {
  Serial.begin(9600);
  lever.attach(leverAttach);
  flap.attach(flapAttach);
}

void loop() {
  lever.write(degLever);
  Serial.print("Lever: ");
  Serial.print(degLever);
  flap.write(degFlap);
  Serial.write("  Flap: ");
  Serial.print(degFlap);
  Serial.print("  Switch: ");
  Serial.print(digitalRead(switchToPress));
  Serial.print("  Displaybutton: ");
  Serial.println(digitalRead(displayButton));
}
