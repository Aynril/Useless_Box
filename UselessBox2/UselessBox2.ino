#include <Servo.h>
//#include <EEPROM.h>

#define flapAttach 9
#define leverAttach 10
#define switchToPress 13
#define displayButton 8
#define flapOpen 0
#define flapShut 60
#define leverOut 135
#define leverIn 50
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5;
int counter = 0;
byte value;
int addr = 0;

Servo flap;
Servo lever;

void setup() {
  Serial.begin(9600);
  flap.attach(flapAttach);
  lever.attach(leverAttach);
  flap.write(flapShut);
  lever.write(leverIn);
  Serial.println("Init done");
}

void loop() {
  counter = readEEPROM();
  if (!digitalRead(switchToPress)) {
    openFlapUsual();
  }
  writeEEPROM(counter);
  Serial.println(counter);
}

void openFlapUsual() {
  flap.write(flapOpen);
  lever.write(leverOut);
  delay(100);
  lever.write(leverIn);
  flap.write(flapShut);
  counter++;
}

void writeEEPROM(int count) {
  countStore = static_cast<int>(count/8);
  EEPROM.write(addr, countStore);
  addr = addr + 1;
  if (addr == EEPROM.length()) {
    addr = 0;
  }
  delay(100);
}

int readEEPROM(){
  value  = EEPROM.read(address);
  addresss++;
  if(address == EEPROM.length()){
    address = 0;
  }
  delay(500);
}
