
// v1.00 - Got the metering working, tested with sensor - viable code

const char releaseNumber[6] = "1.00";              // Displays the release on the menu


// Declare temperature variable here
float CurrentTemperature=0;
float previousTemperature=0;

// Declare all pins here
int tempPin = 0;

void setup() 
{
//   Initialise the sensor here. 
}

void loop() 
{
   if (ReadTemperature)
   {
      Serial.println(CurrentTemperature);
   }
  }
bool myDelay(int del) 
{
  unsigned long myPrevMillis = millis();
  while (millis()- myPrevMillis <= del);
}

/*
   This will check the absolute value of current and previousTemperature. 
   If it crosses the threshold then it will return 1 else 0. 
 */
bool ReadTemperature()
{
  if abs((CurrentTemperature - previousTemperature) >=1)
   {
      CurrentTemperature = analogRead(tempPin);
      previousTemperature = CurrentTemperature;
      return 1;
   }
   else return 0;
}
