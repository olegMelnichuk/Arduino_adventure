# Arduino_adventure
Program for calibration the zero position for servo drive
use the button to stop the rotating and fix the zero point where you want

The Flow:
it sends the min zero pulse to servo drive to go to zero position (it is not move the gears forward but shifts the potentiometr scale). And then sends min stable pulse which turn back a bit gears and potentiometr and repead this again. 

![Scema image](https://github.com/olegMelnichuk/Arduino_adventure/blob/Zero_calibration/img.png)

P.S.
Maybe I am broking the servo drive but my MG90S still working fine :)
