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

// Current color variables
int currentRed = 0;
int currentGreen = 0;
int currentBlue = 0;

// Function to smoothly transition from one color to another
void transitionColor(int endRed, int endGreen, int endBlue, int steps, int delayTime) {
  int startRed = currentRed;
  int startGreen = currentGreen;
  int startBlue = currentBlue;

  for (int i = 0; i <= steps; i++) {
    int red = startRed + ((endRed - startRed) * i) / steps;
    int green = startGreen + ((endGreen - startGreen) * i) / steps;
    int blue = startBlue + ((endBlue - startBlue) * i) / steps;

    analogWrite(RedPin, red);
    analogWrite(GreenPin, green);
    analogWrite(BluePin, blue);
    delay(delayTime);
  }

  // Update current color to the new color
  currentRed = endRed;
  currentGreen = endGreen;
  currentBlue = endBlue;
}

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);

  // Set the RGB LED pins as output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  // Read the value of the photoresistor
  photoresistor = analogRead(A0);
  // Read the value of the potentiometer
  potentiometer = analogRead(A1);

<<<<<<< Updated upstream
  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);          //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentiometer);          //print the potentiometer value to the serial monitor

  if (photoresistor < threshold) {        //if it's dark (the photoresistor value is below the threshold) turn the LED on
    //These nested if statements check for a variety of ranges and
    //call different functions based on the current potentiometer value.
    //Those functions are found at the bottom of the sketch.
    if (potentiometer > 0 && potentiometer <= 150)
      red();
    if (potentiometer > 150 && potentiometer <= 300)
      orange();
    if (potentiometer > 300 && potentiometer <= 450)
      yellow();
    if (potentiometer > 450 && potentiometer <= 600)
      green();
    if (potentiometer > 600 && potentiometer <= 750)
      cyan();
    if (potentiometer > 750 && potentiometer <= 900)
      blue();
    if (potentiometer > 900)
      magenta();
  }
  else {                                //if it isn't dark turn the LED off

    turnOff();                            //call the turn off function
=======
  // Print the values to the Serial Monitor
  Serial.print("Photoresistor value: ");
  Serial.print(photoresistor);
  Serial.print("  Potentiometer value: ");
  Serial.println(potentiometer);
>>>>>>> Stashed changes

  if (photoresistor < threshold) { // If it's dark, turn the LED on
    if (potentiometer > 0 && potentiometer <= 100 && (currentRed != 255 || currentGreen != 0 || currentBlue != 0))
      transitionColor(255, 0, 0, 50, 10); // Transition to red
    else if (potentiometer > 100 && potentiometer <= 200 && (currentRed != 255 || currentGreen != 100 || currentBlue != 0))
      transitionColor(255, 100, 0, 50, 10); // Transition to orange
    else if (potentiometer > 200 && potentiometer <= 300 && (currentRed != 255 || currentGreen != 255 || currentBlue != 0))
      transitionColor(255, 255, 0, 50, 10); // Transition to yellow
    else if (potentiometer > 300 && potentiometer <= 400 && (currentRed != 100 || currentGreen != 255 || currentBlue != 0))
      transitionColor(100, 255, 0, 50, 10); // Transition to light green
    else if (potentiometer > 400 && potentiometer <= 500 && (currentRed != 0 || currentGreen != 255 || currentBlue != 0))
      transitionColor(0, 255, 0, 50, 10); // Transition to green
    else if (potentiometer > 500 && potentiometer <= 600 && (currentRed != 0 || currentGreen != 255 || currentBlue != 100))
      transitionColor(0, 255, 100, 50, 10); // Transition to teal
    else if (potentiometer > 600 && potentiometer <= 700 && (currentRed != 0 || currentGreen != 255 || currentBlue != 255))
      transitionColor(0, 255, 255, 50, 10); // Transition to cyan
    else if (potentiometer > 700 && potentiometer <= 800 && (currentRed != 0 || currentGreen != 0 || currentBlue != 255))
      transitionColor(0, 0, 255, 50, 10); // Transition to blue
    else if (potentiometer > 800 && potentiometer <= 900 && (currentRed != 100 || currentGreen != 0 || currentBlue != 255))
      transitionColor(100, 0, 255, 50, 10); // Transition to purple
    else if (potentiometer > 900 && potentiometer <= 1000 && (currentRed != 255 || currentGreen != 0 || currentBlue != 255))
      transitionColor(255, 0, 255, 50, 10); // Transition to pink
    else if ((currentRed != 255 || currentGreen != 255 || currentBlue != 255))
      transitionColor(255, 255, 255, 50, 10); // Transition to white
  } else { // If it isn't dark, turn the LED off
    if (currentRed != 0 || currentGreen != 0 || currentBlue != 0)
      transitionColor(0, 0, 0, 50, 10); // Transition to off
  }

  delay(100); // Short delay to make the printout easier to read
}