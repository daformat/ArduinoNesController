/*

  Read a NES controller with Arduino
  ==================================
  Mathieu Jouhet (@daformat)
  http://digitalcuisine.fr
  http://mathieujouhet.com
  
  Inspired by Big Oil
  http://forum.arduino.cc/index.php/topic,8481.0.html
  
  Rough schematic of the NES controller
                    _____
                   /
                  /     0  ---  0v (ground)
         +5V  ---  0    0  ---  CLOCK
     nothing  ---  0    0  ---  LATCH
     nothing  ---  0    0  ---  SERIAL OUT
                   ______ 

*/

/* INITIALIZATION */
int latch = 2; // set the latch pin
int clock = 3; // set the clock pin
int datin = 4;// set the data in pin
byte controller_data = 0;

/* CONSTANTS */
#define NES_UP      247 // B11110111
#define NES_DOWN    251 // B11111011
#define NES_LEFT    253 // B11111101
#define NES_RIGHT   254 // B11111110
#define NES_A       127 // B01111111
#define NES_B       191 // B10111111
#define NES_START   239 // B11101111
#define NES_SELECT  223 // B11011111

/* SETUP */
void setup() {
  Serial.begin(9600);
  initNesController();
}

void initNesController() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(datin,INPUT);
  
  digitalWrite(latch,HIGH);
  digitalWrite(clock,HIGH);
}

/* THIS READS DATA FROM THE CONTROLLER */
void controllerRead() {
  controller_data = 0;
  digitalWrite(latch,LOW);
  digitalWrite(clock,LOW);
  
  digitalWrite(latch,HIGH);
  delayMicroseconds(2);
  digitalWrite(latch,LOW);
  
  controller_data = digitalRead(datin);
  
  for (int i = 1; i <= 7; i ++) {
    digitalWrite(clock,HIGH);
    delayMicroseconds(2);
    controller_data = controller_data << 1;
    controller_data = controller_data + digitalRead(datin) ;
    delayMicroseconds(4);
    digitalWrite(clock,LOW);
  }

}

/* DO SOMETHING WHEN ANY BUTTON IS PRESSED */
void loop() {
  controllerRead();
  if (controller_data!=B11111111) {
    /* Serial.println(controller_data, BIN); */

    switch (controller_data) {
      case NES_UP:
        Serial.print( "UP - ");
        Serial.print(NES_UP );
        Serial.print( " - ");
        Serial.println(NES_UP, BIN);
        break;
      case NES_DOWN:
        Serial.print( "DOWN - " );
        Serial.print(NES_DOWN );
        Serial.print( " - ");
        Serial.println(NES_DOWN, BIN);
        break;
      case NES_LEFT:
        Serial.print( "LEFT - " );
        Serial.print(NES_LEFT );
        Serial.print( " - ");
        Serial.println(NES_LEFT, BIN);
        break;
      case NES_RIGHT:
        Serial.print( "RIGHT - " );
        Serial.print(NES_RIGHT );
        Serial.print( " - ");
        Serial.println(NES_RIGHT, BIN);
        break;
      case NES_A:
        Serial.print( "A - " );
        Serial.print(NES_A );
        Serial.print( " - ");
        Serial.println(NES_A, BIN);
        break;
      case NES_B:
        Serial.print( "B - " );
        Serial.print(NES_B );
        Serial.print( " - ");
        Serial.println(NES_B, BIN);
        break;
      case NES_START:
        Serial.print( "START - " );
        Serial.print(NES_START );
        Serial.print( " - ");
        Serial.println(NES_START, BIN);
        break;
      case NES_SELECT:
        Serial.print( "SELECT - " );
        Serial.print(NES_SELECT );
        Serial.print( " - ");
        Serial.println(NES_SELECT, BIN);
        break;        
    }

  }
  
  delay(100);
} 
