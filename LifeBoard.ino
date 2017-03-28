/*********************************************************************

Main file

Setup function for ...

Loop function for ...

*********************************************************************/


#include "src/lib/libManager.h"
//#include "lib/includes.c"

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  // Banner
  initBanner();

  // initialize the LED pin as an output:
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

  //deleteFile();
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println("**********************************");
  Serial.println("        Start of loop");
  Serial.println("**********************************");

  // Read file for conf
  int program = readFile();

  // If conf not ok go in AP mode to set it with HTML Form
  while(program){
      program = modeAP();
  }

  // If conf file is ok go in station mode and send temperature to MQTT
  while(!program){
      program = modeStation();
  }

  while(program){
      button();
      program = modeSendData();
  }

  Serial.println("**********************************");
  Serial.println("        End of loop");
  Serial.println("**********************************");

  if(program){
      Serial.println("Halting.");
      while(1) delay(1000);  // Infinite loop to stop the program
  }
}
