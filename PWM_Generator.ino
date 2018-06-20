//Assume that duration of single signal is 20 ms
//This programm based on PWM and called to get min and max pulses values for servo drive by
//modulation the pulse for min or max value in the loop
//If you use Arduino IDE use Serial Motor tool (CTRL+SHIFT+M) to review the current values
//video inscruction how to use: https://www.youtube.com/watch?v=BW06qeqZyxY

int outPin = 10; // Pin number for PWM signals
int buttonPin = 11; // Pin number for button
int codeExecuteCorrection = 5; // Delay for code executing

int clockwisePulse = 1; // Can be 0 or 1; clockwise is 1
int delayHigh = 1500;   // The approximate middle position for the servo drive is 90 degrees
int interation = 80;    // Amount of signals per loop
int sensitivity = 20;   // Value how much pulse will become londer/shoter per single iteration
int tickDelay = 500;    // Value of delay between signals 

void setup()
{
  Serial.begin(9600);
  pinMode(outPin, OUTPUT);
  int buttonValue = digitalRead(buttonPin);

  for (int i=0; i <= interation; i++){
    
      if(clockwisePulse == 1){
        delayHigh = delayHigh - sensitivity;
      }else{
        delayHigh = delayHigh + sensitivity;
      }
      
      buttonValue = digitalRead(buttonPin);
        
      if(buttonValue == 0){
        Serial.println(delayHigh);
      }else{
        Serial.println(delayHigh);
        Serial.println("^^^ !!! ^^^");
      }
      
      digitalWrite(outPin, HIGH);
      highDelay(delayHigh);
      digitalWrite(outPin, LOW);
      restDelay(delayHigh);
      delay(tickDelay);
  }

}

void loop()
{

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

