
/* Sequencer for LittleBits Korg Analog Synth bits.
 *  
 *  A "One Button User Interface" is used. 
 *  
 *  Initial Setup and Calibration
 *  - Set number of measures sequence will have
 *  - Calibrate the voltage of the Keyboard
 *  
 *  Input Sequence Steps
 *  - Choose note using keyboard
 *  - Choose duration using slider
 *  - Single-click to enter and go to next step
 *  - Double-click to have a rest instead of a note
 *  - Triple-click to back up a step
 *  - Long-click to enter playback mode
 *  
 *  Playback Mode
 *  - Use slider to set speed of playback
 *  
 *  Daniel Henderson, Christmas, 2016
 */

// Input ports on device will have
// specific Bits attached to them.
byte button = 0;
byte keyboard = A0;
byte slider = A1;

byte soundOne = 9;
byte bargraph = 1;
byte meter = 5;

// Global variables
bool buttonDown;
int slideValue;
int keyboardValue;


void setup() {
  // initialize input and output ports
  pinMode(button, INPUT);
  pinMode(keyboard, INPUT);
  pinMode(slider, INPUT);
  
  pinMode(soundOne, OUTPUT);
  pinMode(bargraph, OUTPUT);
  pinMode(meter, OUTPUT);  


}

void nextNote(int *note) {
  int adjustedNote = *note / 4;
  analogWrite(soundOne, (adjustedNote));
  
}

void loop() {
  // main event loop.
  buttonDown = digitalRead(button);

  if (buttonDown) {
    digitalWrite(bargraph, 1);
  } else {
    digitalWrite(bargraph, 0);
  }

  Serial.println("Button value is:");
  Serial.println(buttonDown);

  slideValue = analogRead(slider);

  analogWrite(meter, slideValue);
  
  Serial.println("Slider value is:");
  Serial.println(slideValue);

  while (slideValue > 0) {
    Serial.print("*");
    slideValue -= 10;
  }
  Serial.println();

  keyboardValue = analogRead(keyboard);

  nextNote(&keyboardValue);
  
  Serial.println("Keyboard value is:");
  Serial.println(keyboardValue);


}
