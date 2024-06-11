/*
  SparkFun Inventor’s Kit
  Circuit 1B-Potentiometer

  Changes how fast an LED connected to pin 13 blinks, based on a potentiometer connected to pin A0

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int potPosition;       //this variable will hold a value based on the position of the potentiometer
int redLight = 13;
int greenLight = 12;

void setup()
{
  Serial.begin(9600);       //start a serial connection with the computer

  pinMode(13, OUTPUT);      //set pin 13 as an output that can be set to HIGH or LOW
  pinMode(12, OUTPUT);      //set pin 12 as an output that can be set to HIGH or LOW
}

void loop()
{
  //read the position of the pot
  potPosition = analogRead(A0);    //set potPosition to a number between 0 and 1023 based on how far the knob is turned
  Serial.println(potPosition);     //print the value of potPosition in the serial monitor on the computer

  int redTime = potPosition/2;
  int greenTime = potPosition;

  //change the LED blink speed based on the pot value
  digitalWrite(redLight, HIGH);           // Turn on the LED
  digitalWrite(greenLight, HIGH);

  delay(redTime);
  digitalWrite(redLight, LOW);            // Turn off the LED
  delay(redTime);
  digitalWrite(redLight, HIGH);
  digitalWrite(greenLight, LOW);
  delay(redTime);
  digitalWrite(redLight, LOW);
  delay(redTime);
}

