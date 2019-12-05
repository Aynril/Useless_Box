#include <SPI.h>
#include <Servo.h>
//#include <EEPROM.h>

#define flapAttach 9
#define leverAttach 10
#define switchToPress 13
#define displayButton 8
#define flapOpen 0
#define flapClosed 60
#define leverOut 135
#define leverIn 50

int a = random(1, 50);
int b = random(1, 50);
int counter = 0;
int counter2 = 0;
byte value;

Servo flap;
Servo lever;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  flap.attach(flapAttach);
  lever.attach(leverAttach);
  digitalWrite(LED_BUILTIN, HIGH);
  while (!Serial) {
    ;
  }
  digitalWrite(LED_BUILTIN, LOW);
  
  //u8g2.begin();
  flap.write(flapClosed);
  lever.write(leverIn);
  Serial.println("Init done");
}

void loop() {
  if(!digitalRead(switchToPress)){
    openFlapUsual();
    counter ++;
  }
    /*
    if(counter2 == a == b){
      openflapAttachSpecial();
      counter2 = 0;
      a = random(1, 50);
      b = random(1, 50);
      counter++;
      displayUpdate();
    }
    else if(counter2 == a && a<b){
      openflapAttachSlow();
      counter2 = 0;
      a = random(1, 50);
      counter++;
      displayUpdate();
    }
    else if(counter2 == b && b<a){
      openflapAttachSlow();
      counter2 = 0;
      b = random(1, 50);
      counter++;
      displayUpdate();
    }
    else{
      openflapAttachUsual();
      counter2++;
      counter++;
      displayUpdate();
    }
  }

  if(digitalRead(displayButton)){
    displayShowCount();
  }
  else{
    displayShowAdvise();
  }
  */
  Serial.print("Es haben schon ");
  Serial.print(counter);
  Serial.println(" diesen Knopf gedrückt.");
}

void displayShowAdvise(){
  
}

void displayShowCount(){
  
}

void displayUpdate(){
  Serial.write(counter);  
}

void openFlapUsual(){
  flap.write(flapOpen);
  lever.write(leverOut);
  delay(100);
  lever.write(leverIn);
  flap.write(flapClosed);
}

void openflapAttachSlow(){
  openFlapUsual();
}

void openflapAttachSpecial(){
  openFlapUsual();
}

/*
void printText(){
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 20);
    u8g2.print(F("Hello World!"));
  } while ( u8g2.nextPage() );
  delay(1000);
}

void printCount(){
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 20);
    u8g2.print(F("Hello World!"));
  } while ( u8g2.nextPage() );
  delay(1000);
}

void readEEPROM(){
  value = EEPROM.read(counter);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  counter = counter + 1;
  if (counter == EEPROM.length()) {
    counter = 0;
  }
  delay(500);
}

void writeEEPROM(){
  
}
*/
