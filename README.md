# Arduino_adventure
Assume that duration of single signal is 20 ms

This programm based on PWM and called to get min and max pulses values for servo drive by
modulation the pulse for min or max value in the loop
If you use Arduino IDE use Serial Motor tool (CTRL+SHIFT+M) to review the current values

Video inscruction how to use: https://www.youtube.com/watch?v=BW06qeqZyxY

#Calibration algorithm
 - define minimum value with PWM_Generator and calculate with formula (min = min*1.45);
 - using min value set the 0 position and calculate value for 180 degree using scale picture and PWM_Generator
 - that it! You have a min and max values which can be used for servo drive libraries from any languages.
