# Musical Note Sequencer

This code is meant to run on an Arduino with [LittleBits](http://littlebits.cc "LittleBits homepage") hardware. 

The user will be able to enter notes and durations, and when done, the notes will play back through the LittleBits oscillator and speaker. 

## Input and Output Quantization

There is a big issue with how Arduino numerics interact with analogRead and analogWrite values. The short version is that analogRead reads the voltage into a 10-bit number (range 0-1023), while analogWrite interprets an 8-bit value to generate the voltage. 

If your code simply stores what it gets from analogRead and then uses that value for analogWrite, your values will **sawtooth** every time the value crosses a boundary multiple of 256. You **need** to divide what you sample by 4 and analogWrite that. 
