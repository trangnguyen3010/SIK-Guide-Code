/*
  SparkFun Inventor’s Kit
  Circuit 1D-RGB Nightlight

  Turns an RGB LED on or off based on the light level read by a photoresistor.
  Change colors by turning the potentiometer.

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int photoresistor = A0;          //variable for storing the photoresistor value
int potentiometer = A1;          //this variable will hold a value based on the position of the knob
int threshold = 700;            //if the photoresistor reading is lower than this value the light will turn on

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  // Read the value of the photoresistor
  photoresistor = analogRead(A0);
  // Read the value of the potentiometer
  potentiometer = analogRead(A1);

  // Print the values to the Serial Monitor
  Serial.print("Photoresistor value: ");
  Serial.print(photoresistor);
  Serial.print("  Potentiometer value: ");
  Serial.println(potentiometer);

  if (photoresistor < threshold) { // If it's dark, turn the LED on
    if (potentiometer > 0 && potentiometer <= 100)
      red();
    else if (potentiometer > 100 && potentiometer <= 200)
      orange();
    else if (potentiometer > 200 && potentiometer <= 300)
      yellow();
    else if (potentiometer > 300 && potentiometer <= 400)
      lightGreen();
    else if (potentiometer > 400 && potentiometer <= 500)
      green();
    else if (potentiometer > 500 && potentiometer <= 600)
      teal();
    else if (potentiometer > 600 && potentiometer <= 700)
      cyan();
    else if (potentiometer > 700 && potentiometer <= 800)
      blue();
    else if (potentiometer > 800 && potentiometer <= 900)
      purple();
    else if (potentiometer > 900 && potentiometer <= 1000)
      pink();
    else
      white();
  } else { // If it isn't dark, turn the LED off
    turnOff();
  }

  delay(100); // Short delay to make the printout easier to read
}

void red() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}

void orange() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}

void yellow() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}

void lightGreen() {
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}

void green() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 0);
}

void teal() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 100);
}

void cyan() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 255);
}

void blue() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}

void purple() {
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}

void pink() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 255);
}

void white() {
  analogWrite(RedPin, 255);
  analogWrite(GreenPin, 255);
  analogWrite(BluePin, 255);
}

void turnOff() {
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}