/*
  SparkFun Inventor’s Kit
  Circuit 2A - Buzzer

  Play notes using a buzzer connected to pin 10

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int speakerPin = 10;               //the pin that buzzer is connected to

void setup()
{
  pinMode(speakerPin, OUTPUT);    //set the output pin for the speaker
}

void loop()
{
  play('C', 2);       // Twin
  play('C', 2);       // kle
  play('G', 2);       // Twin
  play('G', 2);       // kle
  play('A', 2);       // Lit
  play('A', 2);       // tle
  play('G', 4);       // Star

  play('F', 2);       // How
  play('F', 2);       // I
  play('E', 2);       // Won
  play('E', 2);       // der
  play('D', 2);       // What
  play('D', 2);       // You
  play('C', 4);       // Are

  play('G', 2);       // Up
  play('G', 2);       // A
  play('F', 2);       // bove
  play('F', 2);       // The
  play('E', 2);       // World
  play('E', 2);       // So
  play('D', 4);       // High

  play('G', 2);       // Like
  play('G', 2);       // A
  play('F', 2);       // Dia
  play('F', 2);       // mond
  play('E', 2);       // In
  play('E', 2);       // The
  play('D', 4);       // Sky

  play('C', 2);       // Twin
  play('C', 2);       // kle
  play('G', 2);       // Twin
  play('G', 2);       // kle
  play('A', 2);       // Lit
  play('A', 2);       // tle
  play('G', 4);       // Star

  play('F', 2);       // How
  play('F', 2);       // I
  play('E', 2);       // Won
  play('E', 2);       // der
  play('D', 2);       // What
  play('D', 2);       // You
  play('C', 4);       // Are

  while (true) {}     //get stuck in this loop forever so that the song only plays once
}


void play( char note, int beats)
{
  int numNotes = 14;  // number of notes in our note and frequency array (there are 15 values, but arrays start at 0)

  //Note: these notes are C major (there are no sharps or flats)

  //this array is used to look up the notes
  char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', ' '};
  //this array matches frequencies with each letter (e.g. the 4th note is 'f', the 4th frequency is 175)
  int frequencies[] = {131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 0};

  int currentFrequency = 0;    //the frequency that we find when we look up a frequency in the arrays
  int beatLength = 150;   //the length of one beat (changing this will speed up or slow down the tempo of the song)

  //look up the frequency that corresponds to the note
  for (int i = 0; i < numNotes; i++)  // check each value in notes from 0 to 14
  {
    if (notes[i] == note)             // does the letter passed to the play function match the letter in the array?
    {
      currentFrequency = frequencies[i];   // Yes! Set the current frequency to match that note
    }
  }

  //play the frequency that matched our letter for the number of beats passed to the play function
  tone(speakerPin, currentFrequency, beats * beatLength);
  delay(beats * beatLength);  //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural

}

/* CHART OF FREQUENCIES FOR NOTES IN C MAJOR
  Note      Frequency (Hz)
  c        131
  d        147
  e        165
  f        175
  g        196
  a        220
  b        247
  C        262
  D        294
  E        330
  F        349
  G        392
  A        440
  B        494
*/
