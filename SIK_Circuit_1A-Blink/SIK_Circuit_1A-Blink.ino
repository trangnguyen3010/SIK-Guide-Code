/*
  SparkFun Inventor’s Kit
  Circuit 1A-Blink

  Turns an LED connected to pin 13 on and off. Repeats forever.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int longPulse = 1000;
int shortPulse = 200;
// false is short pulse, and true is long pulse
boolean morseCodes[3][3] = {{false, false, false}, {true, true, true}, {false, false, false}};

void setup() {
    // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  
  // Print a welcome message
  Serial.println("Hello, Serial Monitor!");

  pinMode(13, OUTPUT);      // Set pin 13 to output

    // Loop through the 2D array
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      digitalWrite(13, HIGH);   // Turn on the LED
      if (morseCodes[i][j]) {
        delay(longPulse);              // Wait for two seconds
        Serial.println("long pulse");
      }
      else {
        delay(shortPulse);
        Serial.println("short pulse");
      }
      digitalWrite(13, LOW);    // Turn off the LED
      delay(1000);              // Wait for two seconds
    }
  }

}


void loop() {
//
}

