// Program for calibration the zero position for servo drive
// use the button to stop the rotating and fix the zero point where you want

int outPin = 10; // Pin number for PWM signals
int buttonPin = 11; // Pin number for button
int codeExecuteCorrection = 5; // Delay for code executing

int clockwisePulse = 1; // Can be 0 or 1; clockwise is 1
int zeroMin = 380; // The min pulse for servo drive discovert by PWM_Generator
int stableMin = 550; // The min pulse calculated by the formula (min = zeroMin*1.45)
int tickDelay = 500;    // Value of delay between signals 
int buttonValue = digitalRead(buttonPin);
int trigger = 0; // using to stop the rotating

void setup()
{
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
}

void loop()
{
  
  buttonValue = digitalRead(buttonPin);
  
  if(buttonValue == 0 && trigger == 0){
    digitalWrite(outPin, HIGH);
    highDelay(stableMin);
    digitalWrite(outPin, LOW);
    restDelay(stableMin);
    delay(tickDelay);
    //--------------------------
    digitalWrite(outPin, HIGH);
    highDelay(zeroMin);
    digitalWrite(outPin, LOW);
    restDelay(zeroMin);
    delay(tickDelay);
  }else{
    trigger = 1;      
  }
  
}

int highDelay (int delayHigh)
{
  if(delayHigh <= 1000){
    delayMicroseconds(delayHigh);
  }else{
    int restSmall = delayHigh % 1000;
    int restBig = delayHigh / 1000;
    delay(restBig);
    delayMicroseconds(restSmall); 
  }
}

int restDelay (int delayHigh)
{
  int delayLow = 20000 - delayHigh - codeExecuteCorrection;
  int restSmall = delayLow % 1000;
  int restBig = delayLow / 1000;
  
  delay(restBig);
  delayMicroseconds(restSmall); // max value for argument is 16383 (microseconds)
}

